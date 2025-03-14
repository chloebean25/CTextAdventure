#pragma once

#include "Entity.hpp"

class Monster : public Entity
{
public:
    void Start();
    void Update();
    void Fight();
    Stats& GetStats(){return m_stats;}
private:
    Stats m_stats;
};