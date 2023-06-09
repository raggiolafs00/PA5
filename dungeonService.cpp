#include "beings.h"
#include "service.h"
#include "dungeon1.h"
#include "dungeon2.h"
#include "dungeon3.h"
#include "dungeonService.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
// include random library
#include <cstdlib>
#include <ctime>

using namespace std;

bool deathCheck(Being &character) {
    if (character.getLife() <= 0) {
        return true;
    }
    else {
        return false;
    }
}

void useSpecialAction(string specialAction, Person &character, Creature &enemy) {
    if (specialAction == "Frenzy") {
        cout << "You surge with energy and attack the enemy 5 times!" << endl;
        for (int i = 0; i < 5; i++) {
            if (enemy.getLife() <= 0) {
                return;
            }
            int attackRoll = (rand() % 20 + 1) + character.getStrength();
            if (attackRoll > enemy.getAC()) {
                int damageRoll = (rand() % character.getWeaponStat() + 1) + character.getStrength();
                enemy.setLife(enemy.getLife() - damageRoll);
                cout << "You hit the enemy for " << damageRoll << " damage" << endl;
            }
            else {
                cout << "You missed" << endl;
            }
        }
        return;
    } 
    else if (specialAction == "True shot") {
        cout << "You focus your aim and fire a true shot at the enemy!" << endl;
        int damageRoll = character.getWeaponStat() * 3;
        enemy.setLife(enemy.getLife() - damageRoll);
        cout << "You hit the enemy for " << damageRoll << " damage" << endl;
        return;
    }
    else {
        cout << "You attack the enemy with a vicious strike, gaining life in return!" << endl;
        int attackRoll = (rand() % 20 + 2) + character.getStrength() + character.getPerception();
        if (attackRoll > enemy.getAC()) {
            int damageRoll = (rand() % character.getWeaponStat() + 1) + character.getStrength() + character.getPerception();
            enemy.setLife(enemy.getLife() - damageRoll);
            cout << "You hit the enemy for " << damageRoll << " damage" << endl;
            character.setLife(character.getLife() + damageRoll);
            cout << "You heal for " << damageRoll << " life" << endl;
        }
        else {
            cout << "You missed" << endl;
        }
        return;
    }
}

void battle(Person &character, Creature &enemy) {
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    // battle system
    int attackRoll, damageRoll, pot_amount; 
    string cont;
    const string battleOptions = " _______________________\n"
                                 "|   Choose an action    |\n"
                                 "|_______________________|\n"
                                 "| 1. Attack             |\n"
                                 "| 2. health potion      |\n"
                                 "| 3. Use Special Action |\n"
                                 "|_______________________|\n ";
    cout << "You have encountered a " << enemy.getName() << endl;
    while (character.getLife() > 0 && enemy.getLife() > 0) {
        string option;
        bool repeatMove;
        do {
            repeatMove = false;
            cout << "You have " << character.getLife() << " life" << endl;
            cout << enemy.getName() << " has " << enemy.getLife() << " life" << endl;

            cout << battleOptions << endl;

            cin >> option;
            system("clear");
            if (option == "1") {
                attackRoll = (rand() % 20 + 1) + character.getStrength();
                if (attackRoll > enemy.getAC()) {
                    damageRoll = (rand() % character.getWeaponStat() + 1) + character.getStrength();
                    enemy.setLife(enemy.getLife() - damageRoll);
                    cout << "You hit the enemy for " << damageRoll << " damage" << endl;
                }
                else {
                    cout << "You missed" << endl;
                }
            }
            else if (option == "2") {
                if (character.getConsumables() > 0) {
                     if (character.getLife() > character.getMaxLife()) {
                        cout << "Rogues are sometimes so healthy that they don't need a drink" << endl;
                    }
                    else if (character.getLife() + (10 * character.getLevel()) > character.getMaxLife()) {
                        character.setLife(character.getMaxLife());
                        character.addConsumable(-1);
                        cout << "You used a health potion" << endl;
                        cout << "You have " << character.getConsumables() << " health potions left" << endl;
                    }
                    else {
                        character.setLife(character.getLife() + (10 * character.getLevel()));
                        character.addConsumable(-1);
                        cout << "You used a health potion" << endl;
                        cout << "You have " << character.getConsumables() << " health potions left" << endl;

                    }
            
                }
                else {
                    cout << "You don't have any health potions" << endl;
                }
                repeatMove = true;
                }
            else if (option == "3") {
       
                if (character.getSpecialActionCount() > 0) {
                cout << "You used " << character.getSpecialAction() << endl;
                useSpecialAction(character.getSpecialAction(), character, enemy);
                character.setSpecialActionCount(character.getSpecialActionCount() - 1);
            }
                else {
                    cout << "You have no special actions left" << endl;
                    repeatMove = true;
            }
            }
            else {
                cout << "Invalid option you lose your turn" << endl;
          
            }
        } while (repeatMove);
        
        if (enemy.getLife() <= 0) {
            break;
        }
        // enemy attack
        attackRoll = (rand() % 20 + 1) + enemy.getStrength();
        if (attackRoll > character.getAC()) {
            damageRoll = (rand() % enemy.getWeaponStat() + 1) + enemy.getStrength();
            character.setLife(character.getLife() - damageRoll);
            cout << "The enemy hit you for " << damageRoll << " damage" << endl;
        }
        else {
            cout << "Your enemy missed" << endl;
        }

    }
    if (character.getLife() <= 0) {
        return;
    }
    else if (enemy.getLife() <= 0) {
        cout << "" << endl;
        cout << "You have killed the enemy!" << endl;
        // add experience to character
        cout << "You gain " << enemy.getExperience() << " experience!" << endl;
        character.setExperience(character.getExperience() + enemy.getExperience());
        cout << "" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        return;
    }
};
void doubleBattle(Person &character, Creature &enemy1, Creature &enemy2) {
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    // battle system

    int attackRoll, damageRoll, pot_amount; 
    string cont;
    const string battleOptions = " _______________________\n"
                                 "|   Choose an action    |\n"
                                 "|_______________________|\n"
                                 "| 1. Attack             |\n"
                                 "| 2. health potion      |\n"
                                 "| 3. Use Special Action |\n"
                                 "|_______________________|\n ";

    while (character.getLife() > 0 && ((enemy1.getLife() > 0) || (enemy2.getLife() > 0))) {
        string option, enemyOption;
        bool repeatMove;
        bool availableAttack = false;
        do {
            repeatMove = false;
            cout << "You have " << character.getLife() << " life" << endl;
            if (enemy1.getLife() > 0) {
                cout << enemy1.getName() << " has " << enemy1.getLife() << " life" << endl;
            }
            else {
                cout << enemy1.getName() << " has 0" << " life (Dead)" << endl;
            }
            if (enemy2.getLife() > 0) {
                cout << enemy2.getName() << " has " << enemy2.getLife() << " life" << endl;
            }
            else {
                cout << enemy2.getName() << " has 0" << " life (Dead)" << endl;
            }
            cout << battleOptions << endl;

            cin >> option;
            system("clear");
            if (option == "1") {
                // attack
                do {
                    cout << "Select Attack Option" << endl;
                    if (enemy1.getLife() > 0) {
                        cout << "1. " << enemy1.getName() << endl;
                    }
                    else {
                        cout << "1. " << enemy1.getName() << " (Dead)" << endl;
                    }
                    if (enemy2.getLife() > 0) {
                        cout << "2. " << enemy2.getName() << endl;
                    }
                    else {
                        cout << "2. " << enemy2.getName() << " (Dead)" << endl;
                    }

                    cin >> enemyOption;
                    if (enemyOption == "1" && enemy1.getLife() > 0) {
                        availableAttack = true;

                    }
                    else if (enemyOption == "2" && enemy2.getLife() > 0) {
                        availableAttack = true;
                 
                    }
                    else {
                        system("clear");
                        cout << "You can't attack that enemy" << endl;
                    }
                } while (!availableAttack);
                attackRoll = (rand() % 20 + 1) + character.getStrength();

                if (enemyOption == "1") {
                    if (attackRoll > enemy1.getAC()) {
                        damageRoll = (rand() % character.getWeaponStat() + 1) + character.getStrength();
                        enemy1.setLife(enemy1.getLife() - damageRoll);
                        cout << "You hit the enemy for " << damageRoll << " damage" << endl;
                    }
                    else {
                        cout << "You missed" << endl;
                    }}

                else {
                    if (attackRoll > enemy2.getAC()) {
                        damageRoll = (rand() % character.getWeaponStat() + 1) + character.getStrength();
                        enemy2.setLife(enemy2.getLife() - damageRoll);
                        cout << "You hit the enemy for " << damageRoll << " damage" << endl;
                    }
                    else {
                        cout << "You missed" << endl;
                    }}
               }
            if (option == "2") {
                if (character.getConsumables() > 0) {
                     if (character.getLife() > character.getMaxLife()) {
                        cout << "Rogues are sometimes so healthy that they don't need a drink" << endl;
                    }
                    else if (character.getLife() + (10 * character.getLevel()) > character.getMaxLife()) {
                        character.setLife(character.getMaxLife());
                        character.addConsumable(-1);
                        cout << "You used a health potion" << endl;
                        cout << "You have " << character.getConsumables() << " health potions left" << endl;
                    }
                    else {
                        character.setLife(character.getLife() + (10 * character.getLevel()));
                        character.addConsumable(-1);
                        cout << "You used a health potion" << endl;
                        cout << "You have " << character.getConsumables() << " health potions left" << endl;

                    }
                }
                else {
                    cout << "You don't have any health potions" << endl;
                }
                repeatMove = true;
                }
           if (option == "3") {
                do {
                    cout << "Select Enemy to Attack:" << endl;
                    if (enemy1.getLife() > 0) {
                        cout << "1. " << enemy1.getName() << endl;
                    }
                    else {
                        cout << "1. " << enemy1.getName() << " (Dead)" << endl;
                    }
                    if (enemy2.getLife() > 0) {
                        cout << "2. " << enemy2.getName() << endl;
                    }
                    else {
                        cout << "2. " << enemy2.getName() << " (Dead)" << endl;
                    }

                    cin >> enemyOption;
                    system("clear");
                    if (enemyOption == "1" && enemy1.getLife() > 0) {
                        availableAttack = true;

                    }
                    else if (enemyOption == "2" && enemy2.getLife() > 0) {
                        availableAttack = true;
                 
                    }
                    else {
                        system("clear");
                        cout << "You can't attack that enemy" << endl;
                    }
                } while (!availableAttack);
                if (character.getSpecialActionCount() > 0) {
                cout << "You used " << character.getSpecialAction() << endl;
                if (enemyOption == "1") {
                    useSpecialAction(character.getSpecialAction(), character, enemy1);
                }
                else {
                    useSpecialAction(character.getSpecialAction(), character, enemy2);
                }
                character.setSpecialActionCount(character.getSpecialActionCount() - 1);
            }
            else {
                cout << "You have no special actions left" << endl;
                repeatMove = true;
            }
           }

        } while (repeatMove);
        
        if (enemy1.getLife() > 0) {
            attackRoll = (rand() % 20 + 1) + enemy1.getStrength();
            if (attackRoll > character.getAC()) {
                damageRoll = (rand() % enemy1.getWeaponStat() + 1) + enemy1.getStrength();
                character.setLife(character.getLife() - damageRoll);
                cout << "The enemy hit you for " << damageRoll << " damage" << endl;
            }
            else {
                cout << enemy1.getName() <<" missed" << endl;
            }

        }
        if (enemy2.getLife() > 0) {
            attackRoll = (rand() % 20 + 1) + enemy2.getStrength();
            if (attackRoll > character.getAC()) {
                damageRoll = (rand() % enemy2.getWeaponStat() + 1) + enemy2.getStrength();
                character.setLife(character.getLife() - damageRoll);
                cout << "The enemy hit you for " << damageRoll << " damage" << endl;
            }
            else {
                cout << enemy2.getName() <<" missed" << endl;
            }

        }
    }
    if (character.getLife() <= 0) {
        return;
    }
    else  {
        cout << "" << endl;
        cout << "You have killed the enemies!" << endl;
        // add experience to character
        cout << "You gain " << enemy1.getExperience() + enemy2.getExperience() << " experience!" << endl;
        character.setExperience(character.getExperience() + enemy1.getExperience() + enemy2.getExperience());
        cout << "" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        return;
    }
};

void searchRoom(Person &character){
    // random number generator from 1 to 10
    string cont;
    cout << "As you walk around you ";
    srand(time(NULL));
    int random = rand() % 10 + 1;
    random += character.getPerception() / 2;
    if (random <= 2) {
        cout << "find nothing" << endl;
        
    }
    else if (random <= 6) {
        cout << "find a healing potion" << endl;
        character.addConsumable(1);
        
    }
     else if (random <= 9) {
        cout << "find 2 healing potions" << endl;
        character.addConsumable(2);
        
    }
    else {
        cout << "You find a weird shrine" << endl;
        
        cout << "When you approach it an aura surrounds you" << endl;
        cout << "" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        
        random = rand() % 20 + 1;
        random += character.getPerception();
        if (random == 1) {
            cout << "feel as if you have been cursed!" << endl;
            character.setStrength(character.getStrength() - 1);
            

        }
        else if (random < 6) {
            cout << "suddenly feel as if you just refreshed as if all your ailments have dissapeared" << endl;
            character.getMaxLife();
          
        }
        else if (random < 13) {
            cout << "feel as if you have been blessed" << endl;
            character.setStrength(character.getStrength() + 1);
            character.setPerception(character.getPerception() + 1);
            character.restoreMaxLife();
           
        }
        else if (random < 20) {
            cout << "feel your weapon has been blessed with the power of the gods" << endl;
            character.setWeaponStat(character.getWeaponStat() + 2);
            character.setWeaponName("Blessed " + character.getWeaponName());
           
            }
        else {
            cout << "feel as if you have been blessed with the power of the gods" << endl;
            character.setStrength(character.getStrength() + 2);
            character.setPerception(character.getPerception() + 2);
            character.setWeaponStat(character.getWeaponStat() + 2);
            character.setWeaponName("Blessed " + character.getWeaponName());
            character.restoreMaxLife();
        }
}
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");

}

void dungeonSelector(Person &character){
    cout << "Choose an option: " << endl;
    cout << "1. The Lonely Saloon" << endl;
    cout << "2. The Abandoned Castle" << endl;
    cout << "3. The Dark Plains" << endl;
    cout << "4. Exit" << endl;
    string option;
    cin >> option;
    system("clear");
    if (option == "1") {
        startDungeon1(character);
     }
    else if (option == "2") {
        startDungeon2(character);
}
    else if (option == "3") {
        cout << "You should only enter this dungeon if you have completed the other two dungeons!" << endl;
        cout << "Are you sure you want to enter? (y/n)" << endl;
        string option;
        cin >> option;
        system("clear");
        if (option == "y") {
            
            startDungeon3(character);
        }
        else {
            return;
        }
}
    else {
        return;

    }

}
