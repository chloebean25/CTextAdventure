#pragma once

#include <string>
#include <vector>

#include "Entity.hpp"

class Room {
public:
    void Load(std::string _path) {}
    void Draw();
    void Update();

private:
    Entity *m_player = nullptr;
    std::vector<Entity*> m_monsters = {};
    std::vector<std::vector<char>> m_map = {};
};