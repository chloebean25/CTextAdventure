#pragma once
#include "Monster.hpp"

class Vampire : public Monster
{
    Vampire()
    {
        m_stats.strength = 4;
        m_stats.speed = 1;
        m_stats.defense = 1.5;
        m_stats.stealth = 0.5;
        m_stats.level = 2;
        m_stats.wisdom = 1; 
    }
    void Start() override
    {
        m_character = 'V';
    }
    void Update() override
    {

    }

};