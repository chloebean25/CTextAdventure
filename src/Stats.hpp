#pragma once
#include "Dice.hpp"

struct Stats{
    int strength =0;
    int level = 0;
    int wisdom = 0;
    int speed =0;
    int defense = 0;
    int stealth = 0;
    int health = 10;
    int diceSides;

    Stats(int hp, int dieSides) : health(hp), diceSides(dieSides){}

    int RollAttack()
    {
        Die attackDie {diceSides};
        return attackDie.roll();
    }
};