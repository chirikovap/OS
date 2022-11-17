#ifndef OS_LABS_UTILS_HPP
#define OS_LABS_UTILS_HPP

#include <iostream>
#include <string>
#include <sys/wait.h>

enum PipeEnd {
    READ_END,
    WRITE_END
};

void CreatePipe(int fd[]);
void GetForkError();
void MakeDup2(int oldFd, int newFd);
void GetExecError(std::string const &executableFile);
std::string UpReg(std::string s);

std::string WithoutDoubleSpace(std::string s);

#endif