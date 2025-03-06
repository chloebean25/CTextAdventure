#pragma once
#include "Monster.hpp"

class Ogre : public Monster
{
    Ogre()
    {
        m_stats.strength = 10;
        m_stats.speed = 3;
        m_stats.defense = 3;
        m_stats.stealth = 2;
        m_stats.level = 5;
        m_stats.wisdom = 4; 
    }
    void Start() override
    {
        m_character = 'O';
    }
    void Update() override
    {

    }

};