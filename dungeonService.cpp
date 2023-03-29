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
    const string battleOptions = " _______________________\n"
                                 "|   Choose an action    |\n"
                                 "|_______________________|\n"
                                 "| 1. Attack             |\n"
                                 "| 2. Use Item           |\n"
                                 "| 3. Use Special Action |\n"
                                 "| 4. Run                |\n"
                                 "|_______________________|\n ";
    cout << "You have encountered a " << enemy.getName() << endl;
    while (character.getLife() > 0 && enemy.getLife() > 0) {

        cout << "You have " << character.getLife() << " life" << endl;
        cout << enemy.getName() << " has " << enemy.getLife() << " life" << endl;

        cout << battleOptions << endl;
        int option;
        cin >> option;
        system("clear");
        switch (option)
        {
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
            // use item
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