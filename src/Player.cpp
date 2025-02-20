#include "Player.hpp"
#include "fogpi/fogpi.hpp"

#include "Room.hpp"

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
    
    
    printf("%c\n", directionInput);
}