#include "utils.hpp"
#include <fstream>

int main() {
    std::string s;
    while (getline(std::cin, s)) {
        os << WithoutDoubleSpace(s) << std:: endl;
        std::cout << WithoutDoubleSpace(s) << '\n';
    }
    return 0;
}