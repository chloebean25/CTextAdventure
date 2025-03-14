#pragma once
#include "Monster.hpp"
#include "Entity.hpp"

class Player : public Entity
{
public:
    int health = 10;
    void Start();
    void Update();
    void Fight(Monster* enemy);
    Stats& GetStats() {return m_stats;}
    const Stats& GetStats() const {return m_stats;}
private:
    int m_keyCount = 0;
};