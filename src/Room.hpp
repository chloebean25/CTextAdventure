#pragma once
#include "fogpi/Math.hpp"

#include <string>
#include <vector>

#include "Monster.hpp"
#include "Entity.hpp"
#include "Door.hpp"

class Monster;

class Room {
public:
    void Load(std::string _path);
    void Draw();
    void Update();

    bool StillPlaying() { return true; }

    
    Entity& GetPlayer() { return *m_player; }
    Monster* GetMonsterAt(const Vector2D& position);
    const std::vector<std::vector<char>>& GetMap() { return m_map; }
    char GetLocation(Vector2D _pos);
    void ClearLocation(Vector2D _pos);
    void SetLocation(Vector2D _pos,char _char);
    void OpenDoor(Vector2D _pos);
private:
    Entity *m_player = nullptr;
    std::vector<Monster*> m_monsters;
    std::vector<std::vector<char>> m_map;
    std::vector<Door> m_doors;
};