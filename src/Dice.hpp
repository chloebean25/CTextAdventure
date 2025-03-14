#pragma once
#include "fogpi/fogpi.hpp"
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

struct Die {
    int sides = 6;

    int roll() const {
        return (std::rand() % sides) + 1;
    }
};