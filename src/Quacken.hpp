#pragma once
#include "Monster.hpp"

class Quacken : public Monster
{
    Quacken()
    {
        m_stats.strength = 20;
        m_stats.speed = 5;
        m_stats.defense = 5.5;
        m_stats.stealth = 4.5;
        m_stats.level = 10;
        m_stats.wisdom = 9; 
    }
    void Start() override
    {
        // its a quacken instead of a kraken. 
        m_character = 'Q';
    }
    void Update() override
    {

    }

};