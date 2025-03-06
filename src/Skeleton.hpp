#pragma once
#include "Monster.hpp"

class Skeleton : public Monster
{
    Skeleton()
    {
        m_stats.strength = 12;
        m_stats.speed = 3;
        m_stats.defense = 3.5;
        m_stats.stealth = 2.5;
        m_stats.level = 6;
        m_stats.wisdom = 5; 
    }
    void Start() override
    {
        m_character = 'S';
    }
    void Update() override
    {

    }

};