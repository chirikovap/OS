#ifndef OS_LABS_PARENT_HPP
#define OS_LABS_PARENT_HPP

#include "utils.hpp"


#include <sys/wait.h>
#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> ParentRoutine(char const *pathToChild1, char const *pathToChild2,
                                       const std::vector<std::string> &input);


#endif