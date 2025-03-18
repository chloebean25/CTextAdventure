#pragma once
#include "Entity.hpp"

class Monster;

class Player : public Entity
{
public:
    int health = 10;
    void Start();
    void Update();
    void Fight(Monster* enemy) {}
private:
    int m_keyCount = 0;
};