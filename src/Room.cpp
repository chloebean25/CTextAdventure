#include "Room.hpp"
#include "Monster.hpp"
#include "Player.hpp"

void Room::Update()
{
    Draw();
    if (m_player != nullptr)
    {
        Player& player = *(Player*)m_player;

        if(player.health <= 0)
        {
            //handle death
            exit(0);

        }
        player.room = this;
        player.Update();
    }

    for ( Entity* monster : m_monsters)
    {
        monster->room = this;
        monster->Update();

    }
}

void Room::Draw()
{
    for (int y = 0; y < m_map.size(); y++)
    {
        for (int x = 0; x < m_map[y].size(); x++)
        {
            printf("%c ", GetLocation(Vector2D(x, y)));
        }
        printf("\n");
    }
}

char Room::GetLocation(Vector2D _pos)
{
    if (_pos.y >= m_map.size())
        return ' ';
    
    if (_pos.x >= m_map[_pos.y].size())
        return ' ';

    if (m_player != nullptr)
        if (m_player->GetPosition() == _pos)
            return m_player->Draw();
    for (Entity* monster : m_monsters)
        if(monster->GetPosition()== _pos)
            return monster->Draw();
    
    return m_map[_pos.y][_pos.x];
}

void Room::SetLocation(Vector2D _pos, char _char)
{
    m_map[_pos.y][_pos.x] = _char;
}

void Room::ClearLocation(Vector2D _pos)
{
    if (_pos.y >= m_map.size())
        return;
    
    if (_pos.x >= m_map[_pos.y].size())
        return;
    
    m_map[_pos.y][_pos.x] = ' ';
}

void Room::OpenDoor(Vector2D _pos)
{
    for(int i = 0; i < m_doors.size(); i++)
    {
        if (m_doors[i].pos == _pos)
        {
            Load(m_doors[i].path);
        }
    }
}
Monster* Room::GetMonsterAt(const Vector2D& position) {
    for (Monster* monster : m_monsters) { 
        if (monster->GetPosition() == position) {
            return monster;  
        }
    }
    return nullptr;  
}
