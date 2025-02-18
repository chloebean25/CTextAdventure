#pragma once

#include "fogpi/Math.hpp"

// forward defin
class Room;

class Entity {
public:
    Room *room;

    virtual void Start() {}
    virtual void Update() {}
private:
    Vector2D m_position;
    char m_character;
    //char m_color = '[0;31m';
};