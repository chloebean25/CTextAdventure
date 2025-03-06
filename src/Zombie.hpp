#pragma once
#include "Monster.hpp"

class Zombie : public Monster
{
    Zombie()
    {
        m_stats.strength = 2;
        m_stats.speed = 1;
        m_stats.defense = 1;
        m_stats.stealth = 0;
        m_stats.level = 1;
        m_stats.wisdom = 0;
    }
    void Start() override
    {
        m_character = 'Z';
    }
    void Update() override
    {

    }
};