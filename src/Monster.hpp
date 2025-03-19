#pragma once

#include "Entity.hpp"

class Monster : public Entity
{
public:
    void Start();
    void Update();
    void Fight();
    void TakeDamage(int amount);
    Monster(int health, int diceSides): m_stats(health, diceSides){}
    void SetPosition(const Vector2D& pos) { m_position = pos;}
    Stats& GetStats() {return m_stats;}
    private:
    Stats m_stats;
    Vector2D m_position;
};