#pragma once
#include "Monster.hpp"

class Troll : public Monster
{
    Troll()
    {
        m_stats.strength = 14;
        m_stats.speed = 4;
        m_stats.defense = 4;
        m_stats.stealth = 3;
        m_stats.level = 7;
        m_stats.wisdom = 6; 
    }
    void Start() override
    {
        m_character = 'T';
    }
    void Update() override
    {

    }

};