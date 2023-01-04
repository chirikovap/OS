#include "mathematical-analysis.hpp"
#include <iostream>

unsigned long long Factorial(int n) {
    unsigned long long result = 1;

    while (n > 0) {
        result *= n;
        n--;
    }

    return result;
}

float E(int x) {
    float result = 0;

    for (int n = 0; n <= x; n++) {
        result += 1.0 / ((float)Factorial(n));
    }

    return result;
}

float Derivative(float A, float deltaX) {
    float deltaY = cos(A + deltaX) - cos(A - deltaX);
    return deltaY / 2.0 / deltaX;
}