#include "utils.hpp"
#include <fstream>

int main() {
    std::string s;
    while (getline(std::cin, s)) {
        os << s << std:: endl;
        std::cout << UpReg(s) << '\n';
    }
    return 0;
}