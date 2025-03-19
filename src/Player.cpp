#include "Player.hpp"
#include "Room.hpp"
#include "Monster.hpp"
#include "Dice.hpp"
#include "Combat.hpp"
#include <algorithm>

void Player::Start()
{
    m_character = 'P';
}
void Player::TakeDamage(int damage)
{
    m_stats.health -= damage;
    if(m_stats.health<0)
    {
        m_stats.health = 0;
    }
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
        bool combatResolved = false;
        while (!combatResolved)  // Keep rolling if it's a tie
        {
            Die playerDice(6);
            Die monsterDice(6);
            int playerRoll = playerDice.roll();
            int monsterRoll = monsterDice.roll();
    
            printf("Player rolls: %d\n", playerRoll);
            printf("Monster rolls: %d\n", monsterRoll);
    
            if (playerRoll > monsterRoll)
            {
                int damage = playerRoll - monsterRoll;
                printf("You hit the monster for %d damage!\n", damage);
                enemy->TakeDamage(damage);
                
                
                if(enemy->GetStats().health<=0)
                {
                printf("You have defeated the monster!\n");
                room->ClearLocation(enemy->GetPosition());
                combatResolved = true; 
                }
            }
            else if (playerRoll < monsterRoll)
            {
                int damage = monsterRoll - playerRoll;
                printf("The monster hit you for %d damage!\n", damage);
                this->TakeDamage(damage);
                
                
                
    
                if (this->GetStats().health <= 0)
                {
                    printf("You have died! Exiting the game...\n");
                    exit(0);
                }
                combatResolved = true;
            }
            else 
            {
                printf("It's a tie! Rerolling...\n");
                
            }
        
        
        //this doesnt work but it breaks my code when deleted so I just left it
        if (enemy)
        {


            Combat::Battle(this,enemy);

            
            if (enemy->GetStats().health <= 0)
            {
                printf("You defeated the monster!\n");
                room->ClearLocation(tryPos);
            }
        }
        return;  
    }
    if(room->GetLocation(tryPos)==' ')
    {
        m_position =tryPos;
    }
    
    if (enemy->GetStats().health > 0)
    {
        printf("The monster is ready for another round!\n");
    }
    else
    {
        room->ClearLocation(enemy->GetPosition());  // Remove defeated monster
    }
}
    if (room->GetLocation(tryPos) == ' ') 
        m_position = tryPos;

    printf("%c\n", directionInput);
}
