#include "Room.hpp"
#include "Monster.hpp"
#include "Player.hpp"

#include <fstream>
#include <string>

void Room::Load(std::string _path)
{
    m_map.clear();
    m_doors.clear();
    m_monsters.clear();

    std::ifstream file;
    file.open(_path);

    if (!file.is_open())
    {
        printf("file not found at: %s \n", _path.c_str());
        exit(1);
    }

    std::string word;
    int number;

    while (file >> word)
    {
        if (word == "level")
        {
            if (file >> number)
            {
                printf("open level: %i\n", number);
            }
        }

        if (word == "next_level")
        {
            if (file >> word)
            {
                m_doors.push_back(Door());
                m_doors[m_doors.size() - 1].path = word;
            }
        }

        if (word == "map")
        {
            m_map.push_back(std::vector<char>());
            int y =0;
            while(file >> word)
            {
                if (word == "-2")
                {
                    break;
                }

                if (word == "-1")
                {
                    m_map.push_back(std::vector<char>());
                    continue;
                }

                if (word == "0")
                    m_map[m_map.size() - 1].push_back(' ');
                else
                    m_map[m_map.size() - 1].push_back(word[0]);
                if(word == "M")
                {
                    Monster* newMonster = new Monster(10,6);
                    newMonster->SetPosition(Vector2D(m_map[y].size()-1,y));
                    m_monsters.push_back(newMonster);
                }
            }
        }
    }

    int doorCount = 0;

    for (int y = 0; y < m_map.size(); y++)
    {
        for (int x = 0; x < m_map[y].size(); x++)
        {
            if (m_map[y][x] == 'S')
            {
                if (m_player == nullptr)
                    m_player = (Entity*)new Player();
                
                m_player->Init(Vector2D(x, y));
                m_player->Start();
                m_map[y][x] = ' ';
            }

            if (m_map[y][x] == 'D' || m_map[y][x] == 'L')
            {
                if (m_doors.size() - 1 >= doorCount)
                {
                    m_doors[doorCount].pos.x = x;
                    m_doors[doorCount].pos.y = y;
                    doorCount++;
                }
            }
        }
    }
}


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
