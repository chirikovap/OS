#include <iostream>
#include <string>

#include "utils.hpp"



std::string UpReg(const std::string& s) {
    std::string upRegStr;
    upRegStr.reserve(s.size());
    for (char i : s) {
       upRegStr += toupper(i);
    }
    return upRegStr;
}

std::string WithoutDoubleSpace(const std::string& s) {
    std::string outDoubleSpace;
    outDoubleSpace += s[0];
    for (size_t i = 1; i < s.length(); i++) {
        if (s[i - 1] != ' ' || s[i] != ' ') {
            outDoubleSpace += s[i];
        }
    }
    return outDoubleSpace;
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

void GetExecError(const std:: string& executableFile) {
    std::cout << "Exec \"" << executableFile << "\" error." << std::endl;
}
