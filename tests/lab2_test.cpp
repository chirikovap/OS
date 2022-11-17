#include <gtest/gtest.h>
#include <stdio.h>
#include <array>
#include <stdlib.h>
#include <memory>
#include "parent.hpp"
#include <vector>

#include <iostream>
#include <fstream>
#include <sys/wait.h>

TEST(FirstLabTests, SimpleTest) {


    std::vector<std::string> inputIN {
            "abcde  GG",
            "AAAA aaa  Laba"

    };

    std::vector<std::string> expectedOutput {
            "ABCDE GG",
            "AAAA AAA LABA"

    };
    std::vector <std::string> output = ParentRoutine("../lab2/child1", "../lab2/child2", inputIN);
        EXPECT_EQ(output, expectedOutput);


}