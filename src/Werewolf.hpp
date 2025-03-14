#pragma once
#include "Monster.hpp"
#include "Stats.hpp"

class Werewolf : public Monster
{
    Werewolf()
    {
        m_stats.strength = 6;
        m_stats.speed = 2;
        m_stats.defense = 2;
        m_stats.stealth = 1;
        m_stats.level = 3;
        m_stats.wisdom = 2; 
    }
    void Start() override
    {
        m_character = 'W';
    }
    void Update() override
    {

    }

};