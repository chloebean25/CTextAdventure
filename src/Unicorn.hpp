#pragma once
#include "Monster.hpp"

class Unicorn : public Monster
{
    Unicorn()
    {
        m_stats.strength = 16;
        m_stats.speed = 4;
        m_stats.defense = 4.5;
        m_stats.stealth = 3.5;
        m_stats.level = 8;
        m_stats.wisdom = 7; 
    }
    void Start() override
    {
        m_character = 'U';
    }
    void Update() override
    {

    }

};