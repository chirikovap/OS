#include <gtest/gtest.h>
#include <stdio.h>
#include <array>
#include <stdlib.h>
#include <memory>
#include "mathematical-analysis.hpp"
#include <vector>

#include <iostream>
#include <sstream>

TEST(FirstLabTests, SimpleTest) {


    std::vector<std::string> inputDerivative {
            "0.1 1",
            "-100 0.01",
            "0 10",
    };

    std::vector<std::string> expectedOutputDerivative {
            "-0.541408",
            "-0.510776",
            "-0.183907",
    };

    std::vector <std::string> outputDerivative;

    for (unsigned long int i = 0; i < inputDerivative.size(); i++) {
        std::istringstream iss(inputDerivative[i]);
        std::vector<float> args;
        std::string line;
        while (getline(iss, line, ' ')) {
                args.push_back(std::stof(line));
        }
        outputDerivative.push_back(std::to_string(Derivative(args[0], args[1])));
    }


    EXPECT_EQ(outputDerivative, expectedOutputDerivative);

    std::vector<std::string> inputE {
            "0",
            "10",
            "100",
    };

    std::vector<std::string> expectedOutputE {
            "1.000000",
            "2.593742",
            "2.704814"
    };

    std::vector <std::string> outputE;

    for (unsigned long int i = 0; i < inputE.size(); i++) {
        std::istringstream iss(inputE[i]);
        std::vector<float> args;
        std::string line;
        while (getline(iss, line, ' ')) {
                args.push_back(std::stof(line));
        }
        outputE.push_back(std::to_string(E(args[0])));
    }


    EXPECT_EQ(outputE, expectedOutputE);
}