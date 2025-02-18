#ifdef _WIN32
#include <windows.h>

#endif

#include <iostream>
#include <vector>
#include "fogpi/Math.hpp"
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "Dice.hpp"
#include "Entity.hpp"

int Add(int &_a, int &_b)
{
    _a = _a * 2;
    return _a + _b;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));

    char e = 'a';

    const char* message = "Hello, World!";

    int a[] = {1,2,3,4};

    printf("%s\n", message);

    using namespace std;

    vector<Die> dice = {};

    Die d6 = {};
    d6.sides = 6;

    Die die2 = { .sides = 12 };

    dice.push_back(d6);
    dice.push_back(die2);
    dice.push_back(Die{.sides = 20});

    RollStats stats = RollDice(dice);

    PrintRollStats(stats);
  
    return 0;
}
