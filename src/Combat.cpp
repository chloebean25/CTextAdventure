#include "Combat.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include <iostream>

void Combat::Battle(Player* player, Monster* enemy) {
    std::cout << "A battle has started between you and the monster!\n";

    while (player->GetStats().health > 0 && enemy->GetStats().health > 0) {
        
        Die attackDie{6};
        int playerRoll = player->GetStats().RollAttack();
        int enemyRoll = enemy->GetStats().RollAttack();

        std::cout << " You rolled: " << playerRoll << " | Monster rolled: " << enemyRoll << "\n";

        if (playerRoll > enemyRoll) {
            enemy->GetStats().health -= playerRoll;
            std::cout << "You hit the monster for " << playerRoll << " damage!\n";
        } else {
            player->GetStats().health -= enemyRoll;
            std::cout << "The monster hit you for " << enemyRoll << " damage!\n";
        }

       
        if (player->GetStats().health <= 0) {
            std::cout << "You have died! Game Over.\n";
            exit(0);
        }

        
        if (enemy->GetStats().health <= 0) {
            std::cout << "You defeated the monster!\n";
            return;
        }
    }
}
