#pragma once
#include "Monster.hpp"

class Rast : public Monster
{
    Rast()
    {
        m_stats.strength = 18;
        m_stats.speed = 5;
        m_stats.defense = 5;
        m_stats.stealth = 4;
        m_stats.level = 9;
        m_stats.wisdom = 8; 
    }
    void Start() override
    {
        m_character = 'R';
    }
    void Update() override
    {

    }

};