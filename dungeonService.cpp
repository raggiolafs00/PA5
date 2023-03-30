#include "beings.h"
#include "service.h"
#include "dungeon1.h"
#include "dungeon2.h"
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
        int attackRoll = (rand() % 20 + 1) + character.getStrength();
        if (attackRoll > enemy.getAC()) {
            int damageRoll = (rand() % character.getWeaponStat() + 1) + character.getStrength();
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
        bool repeatMove;
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
                if (character.getSpecialActionCount() > 0) {
                cout << "You used " << character.getSpecialAction() << endl;
                useSpecialAction(character.getSpecialAction(), character, enemy);
                character.setSpecialActionCount(character.getSpecialActionCount() - 1);
            }
            else {
                cout << "You have no special actions left" << endl;
            }
            break;
            case 4:
                // run
                break;
            default:
                break;
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


void searchRoom(Person &character){
    // random number generator from 1 to 10
    int cont;
    cout << "As you walk around you ";
    srand(time(NULL));
    int random = rand() % 10 + 1;
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
        cout << "find a weird shrine." << endl;
        int option;
        cout << "When you approach it an aura surrounds you" << endl;
        cout << "" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");

        random = rand() % 20 + 1;
        if (random == 1) {
            cout << "You feel as if you have been cursed!" << endl;
            character.setStrength(character.getStrength() - 1);
            

        }
        else if (random < 6) {
            cout << "You suddenly feel as if you just refreshed as if all your ailments have dissapeared" << endl;
            character.getMaxLife();
          
        }
        else if (random < 13) {
            cout << "You feel as if you have been blessed" << endl;
            character.setStrength(character.getStrength() + 1);
            character.setIntelligence(character.getIntelligence() + 1);
            character.restoreMaxLife();
           
        }
        else if (random < 20) {
            cout << "Your weapon has been blessed with the power of the gods" << endl;
            character.setWeaponStat(character.getWeaponStat() + 3);
            character.setWeaponName("Blessed " + character.getWeaponName());
           
            }
        else {
            cout << "You feel as if you have been blessed with the power of the gods" << endl;
            character.setStrength(character.getStrength() + 2);
            character.setIntelligence(character.getIntelligence() + 2);
            character.setWeaponStat(character.getWeaponStat() + 5);
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
    cout << "3. idk man ? " << endl;
    cout << "4. Exit" << endl;
    int option;
    cin >> option;
    system("clear");
    switch (option) {
        case 1:
        startDungeon1(character);
        break;
        case 2:
        startDungeon2(character);
        break;
        case 3:
        //startDungeon3(character);
        break;
        case 4:
        return;

    }

}
