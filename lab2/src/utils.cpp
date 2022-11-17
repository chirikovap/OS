#include <iostream>
#include <string>

#include "utils.hpp"



std::string UpReg(const std::string& s) {
    std::string ch;
    std::string UpRegStr;
    for (char i : s) {
       ch = toupper(i);
       UpRegStr += ch;
    }
    return UpRegStr;
}

std::string WithoutDoubleSpace(const std::string& s) {
    std::string ch;

    std::string OutDoubleSpace;
    OutDoubleSpace += s[0];
    for (size_t i = 1; i < s.length(); i++) {
        if (s[i - 1] != ' ' || s[i] != ' ') {
            OutDoubleSpace += s[i];
        }
    }
    return OutDoubleSpace;
}

void CreatePipe(int fd[]) {
    if (pipe(fd) != 0) {
        std::cout << "Couldn't create pipe" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void GetForkError() {
    std::cout << "fork error" << std::endl;
    exit(EXIT_FAILURE);
}

void MakeDup2(int oldFd, int newFd) {
    if (dup2(oldFd, newFd) == -1) {
        std::cout << "dup2 error" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void GetExecError(std::string const &executableFile) {
    std::cout << "Exec \"" << executableFile << "\" error." << std::endl;
}
