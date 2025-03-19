#pragma once
#include "Entity.hpp"

class Monster;

class Player : public Entity
{
public:
    int health = 10;
    void Start();
    void Update();
    void TakeDamage(int amount);
    void Fight(Monster* enemy) {}
    Stats& GetStats() {return m_stats;}
private:
    int m_keyCount = 0;
    Stats m_stats;
};