#include "lab3.h"

#include <iostream>

int main()
{
    int ch;
    int threadCount;
    std::cin >> ch >> threadCount;
    if (threadCount == 0)
    {
        threadCount = 1;
    }
    TVector chisla(ch);
    for (int i = 0; i < ch; ++i)
    {
        std::cin >> chisla[i];
    }

    int min = MinVector(chisla, threadCount);
    std::cout << min << std::endl;
}