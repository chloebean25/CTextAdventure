#include "Player.hpp"
#include "Room.hpp"
#include "Monster.hpp"
#include "Dice.hpp"
#include "Combat.hpp"
#include "Entity.hpp"
#include <algorithm>

void Player::Start()
{
    m_character = 'P';
}

void Player::Update()
{
    char directionInput;
    
    do {
        directionInput = request_char("wasd and Enter to move");
    } while (directionInput != 'w' &&
             directionInput != 'a' &&
             directionInput != 's' &&
             directionInput != 'd');
    
    Vector2D direction(0.0f);

    switch (directionInput)
    {
    case 'w': direction = {0.0f, -1.0f}; break;
    case 'a': direction = {-1.0f, 0.0f}; break;
    case 's': direction = {0.0f, 1.0f}; break;
    case 'd': direction = {1.0f, 0.0f}; break;
    default: direction = {0.0f, 1.0f}; break;
    }

    Vector2D tryPos = m_position + direction;

    // Check for a key
    if (room->GetLocation(tryPos) == 'K')
    {
        m_keyCount++;
        room->ClearLocation(tryPos);
    }

    // Check for locked door
    if (room->GetLocation(tryPos) == 'L')
    {
        if (m_keyCount <= 0)
        {
            printf("NO KEY!!!\n");
            return;
        }

        m_keyCount--;
        room->SetLocation(tryPos, 'D');
        return;
    }

    // Open door
    if (room->GetLocation(tryPos) == 'D')
    {
        room->OpenDoor(tryPos);
    }

    
    if (room->GetLocation(tryPos) == 'M') 
    {
        printf("You encountered a monster!\n");

       
        Monster* enemy = room->GetMonsterAt(tryPos);
        if (enemy)
        {
            
            Combat::Battle(this, enemy);  

            
            if (enemy->GetStats().health <= 0)
            {
                printf("You defeated the monster!\n");
                room->ClearLocation(tryPos);
            }
        }
        return;  
    }

    
    if (room->GetLocation(tryPos) == ' ') 
        m_position = tryPos;

    printf("%c\n", directionInput);
}
