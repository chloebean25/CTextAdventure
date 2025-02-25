#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    int health = 0;
    void Start();
    void Update();
private:
    int m_keyCount = 0;
};