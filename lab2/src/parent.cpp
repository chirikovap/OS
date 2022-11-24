#include <sys/wait.h>
#include <unistd.h>

#include "parent.hpp"
#include "utils.hpp"


std::vector<std::string> ParentRoutine(char const *pathToChild1, char const *pathToChild2,
                                const std::vector<std::string> &input) {
    std::vector<std::string> output;

    int firstPipe[2];
    CreatePipe(firstPipe);
    int pipeBetweenChildren[2];
    CreatePipe(pipeBetweenChildren);

    int pid = fork();

    if (pid == 0) {

        close(firstPipe[WRITE_END]);
        close(pipeBetweenChildren[READ_END]);

        MakeDup2(firstPipe[READ_END], STDIN_FILENO);
        MakeDup2(pipeBetweenChildren[WRITE_END], STDOUT_FILENO);

        if (execl(pathToChild1, "", nullptr) == -1) {
            GetExecError(pathToChild1);
        }
        close(firstPipe[READ_END]);
        close(firstPipe[WRITE_END]);
    } else if (pid == -1) {
        GetForkError();
    } else {
        close(firstPipe[READ_END]);
        for (const std::string &s: input) {
            auto str = s + "\n";
            write(firstPipe[WRITE_END], str.c_str(), str.size());
        }
        close(firstPipe[WRITE_END]);

        int secondPipe[2];
        CreatePipe(secondPipe);

        pid = fork();

        if (pid == 0) {
            close(secondPipe[READ_END]);
            close(pipeBetweenChildren[WRITE_END]);

            MakeDup2(pipeBetweenChildren[READ_END], STDIN_FILENO);
            MakeDup2(secondPipe[WRITE_END], STDOUT_FILENO);

            if (execl(pathToChild2, "", nullptr) == -1) {
                GetExecError(pathToChild2);
            }
        } else if (pid == -1) {
            GetForkError();
        } else {
            close(secondPipe[WRITE_END]);
            close(pipeBetweenChildren[WRITE_END]);
            close(pipeBetweenChildren[READ_END]);
            wait(nullptr);
            char ch;
            std::string s;
            for(size_t i = 0; i < input.size(); ++i) {
                s.clear();
                while(read(secondPipe[READ_END], &ch, 1) && ch != '\n') {
                    s += ch;
                }
                output.push_back(std::move(s));
            }
            std::cout << std::endl;
            close(secondPipe[READ_END]);
        }
    }
    return output;
}