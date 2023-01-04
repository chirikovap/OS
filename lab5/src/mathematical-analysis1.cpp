#include "mathematical-analysis.hpp"
#include <iostream>

float E(int x) {
    return pow((1.0 + 1.0 / (float) x), x);
}

float Derivative(float A, float deltaX) {
    float deltaY = cos(A + deltaX) - cos(A);
    return deltaY / deltaX;
}