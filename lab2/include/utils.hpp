#ifndef OS_LABS_UTILS_HPP
#define OS_LABS_UTILS_HPP

#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

enum PipeEnd {
    READ_END,
    WRITE_END
};

void CreatePipe(int fd[]);
void GetForkError();
void MakeDup2(int oldFd, int newFd);
void GetExecError(std::string const &executableFile);
std::string UpReg(const std::string& s);

std::string WithoutDoubleSpace(const std::string& s);

#endif