#pragma once
#include "Monster.hpp"

class Ghost : public Monster
{
    Ghost()
    {
        m_stats.strength = 8;
        m_stats.speed = 2;
        m_stats.defense = 2.5;
        m_stats.stealth = 1.5;
        m_stats.level = 4;
        m_stats.wisdom = 3; 
    }
    void Start() override
    {
        m_character = 'G';
    }
    void Update() override
    {

    }

};