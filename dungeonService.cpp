#include "beings.h"
#include "service.h"
#include "dungeon1.h"
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


void battle(Person &character, Creature &enemy) {
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));
    // battle system
    int attackRoll, damageRoll, cont; 
    int pot_amount;
    const string battleOptions = " _______________________\n"
                                 "|   Choose an action    |\n"
                                 "|_______________________|\n"
                                 "| 1. Attack             |\n"
                                 "| 2. health potion      |\n"
                                 "| 3. Use Special Action |\n"
                                 "| 4. Run                |\n"
                                 "|_______________________|\n ";
    cout << "You have encountered a " << enemy.getName() << endl;
    while (character.getLife() > 0 && enemy.getLife() > 0) {
        int option;
        bool repeatMove = false;
        do {
            repeatMove = false;
            cout << "You have " << character.getLife() << " life" << endl;
            cout << enemy.getName() << " has " << enemy.getLife() << " life" << endl;

            cout << battleOptions << endl;

            cin >> option;
            system("clear");
            switch (option) {
            case 1:
                // attack
                attackRoll = (rand() % 20 + 1) + character.getStrength();
                if (attackRoll > enemy.getAC()) {
                    damageRoll = (rand() % character.getWeaponStat() + 1) + character.getStrength();
                    enemy.setLife(enemy.getLife() - damageRoll);
                    cout << "You hit the enemy for " << damageRoll << " damage" << endl;
                }
                else {
                    cout << "You missed" << endl;
                }
                break;
            case 2:
                if (character.getConsumables() > 0) {
                    if (character.getLife() + (10 * character.getLevel()) > character.getMaxLife()) {
                        character.setLife(character.getMaxLife());
                    }
                    else {
                        character.setLife(character.getLife() + (10 * character.getLevel()));
                    }
                    character.addConsumable(-1);
                    cout << "You used a health potion" << endl;
                    cout << "You have " << character.getConsumables() << " left" << endl;
                }
                else {
                    cout << "You don't have any health potions" << endl;
                }
                repeatMove = true;
                break;
            case 3:
                // use special action
                break;
            case 4:
                // run
                break;
            default:
                break;
            }
        } while (repeatMove);
        // enemy attack
        if (enemy.getLife() <= 0) {
            break;
        }
        attackRoll = (rand() % 20 + 1) + enemy.getStrength();
        if (attackRoll > character.getAC()) {
            damageRoll = (rand() % enemy.getWeaponStat() + 1) + enemy.getStrength();
            character.setLife(character.getLife() - damageRoll);
            cout << "The enemy hit you for " << damageRoll << " damage" << endl;
        }
        else {
            cout << "The enemy missed" << endl;
        }

    }
    if (character.getLife() <= 0) {
        cout << "You died" << endl;
        return;
    }
    else if (enemy.getLife() <= 0) {
        cout << "You killed the enemy" << endl;
        // add experience to character
        cout << "You gained " << enemy.getExperience() << " experience" << endl;
        character.setExperience(character.getExperience() + enemy.getExperience());
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        return;
    }
};

