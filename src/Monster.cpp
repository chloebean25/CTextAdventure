#include "Monster.hpp"
#include "Room.hpp"

void Monster::Start()
{
    m_character = 'M';
}

void Monster::Update()
{

}
void Monster::TakeDamage(int damage)
{
    m_stats.health -= damage;
    if(m_stats.health<0)
    {
        m_stats.health =0;
    }
}