#include "mathematical-analysis.hpp"
#include <iostream>
#include <dlfcn.h>
#include <sstream>
#include <vector>

#ifndef LIBRARY1
#define LIBRARY1 "libmath-analysis1.so"
#endif

#ifndef LIBRARY2
#define LIBRARY2 "libmath-analysis2.so"
#endif

int main() {
    std::string string, cin_buffer;
    std::vector<float> args;
    void * function;

    void * handle = dlopen(LIBRARY1, RTLD_LAZY);
    int current_library = 0;

    if (handle == NULL) {
        fprintf(stderr, "dlopen: %s\n", dlerror());
        exit(1);
    }

    while (1) {
        args.clear();
        std::cout << "Enter your command:\n";
        std::getline(std::cin, string);

        if (string == "") {
            continue;
        }

        if (string == "(quit)") {
            break;
        }
        if (string == "0") {
            std::cout << "Current contracts type : ";
            if (current_library == 0) {
                handle = dlopen(LIBRARY2, RTLD_LAZY);
            } else {
                handle = dlopen(LIBRARY1, RTLD_LAZY);
            }
            current_library = (current_library + 1) % 2;
            std::cout << (current_library + 1) << "\n";
            continue;
        }

        std::stringstream buffer(string);

        while (std::getline(buffer, cin_buffer, ' ')) {
            args.push_back(std::stof(cin_buffer));
        }

        if (args[0] == 1) {
            if (args.size() < 3) {
                std::cout << "Not enough arguments (expected 2).\n";
                continue;
            }

            function = dlsym(handle, "Derivative");
            if (function == NULL) {
                fprintf(stderr, "dlsym: %s\n", dlerror());
                exit(2);
            }

            float (*Derivative)(float, float) = (float (*)(float, float))dlsym(handle, "Derivative");

            std::cout << "Derivative cos(A) = " << Derivative(args[1], args[2]) << "\n";
        } else if(args[0] == 2) {
            if (args.size() < 2) {
                std::cout << "Not enough arguments (expected 1).\n";
                continue;
            }

            function = dlsym(handle, "E");
            if (function == NULL) {
                fprintf(stderr, "dlsym: %s\n", dlerror());
                exit(2);
            }

            float (*E)(int) = (float (*)(int))dlsym(handle, "E");

            std::cout << "E(x) = " << E((int)args[1]) << "\n";
        }
    }

    dlclose(handle);

    return 0;
}
