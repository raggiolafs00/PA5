#include "beings.h"
#include "service.h"
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
    int attackRoll, damageRoll;
    while (character.getLife() > 0 && enemy.getLife() > 0) {
        cout << "Choose an action: " << endl;
        cout << "1. Attack" << endl;
        cout << "2. Use Item" << endl;
        cout << "3. Use Special Action" << endl;
        cout << "4. Run" << endl;
        int option;
        cin >> option;
        system("clear");
        switch (option)
        {
        case 1:
            // attack
            attackRoll = (rand() % 20 + 1) + character.getStrength();
            if (attackRoll > enemy.getAC()) {
                damageRoll = (rand() % 6 + 1) + character.getStrength();
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
            break;
        case 4:
            // run
            break;
        default:
            break;
        }

        // enemy attack
        if (enemy.getLife() <= 0) {
            break;
        }
        attackRoll = (rand() % 20 + 1) + enemy.getStrength();
        if (attackRoll > character.getAC()) {
            damageRoll = (rand() % 6 + 1) + enemy.getStrength();
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
        character.addExperience(enemy.getExperience());
        return;
    }
    
};

void startDungeon(Person &character) {
    // import creatures and bosses from file
    // vector <Creature*> creatures;
    // vector <Boss*> bosses;

    cout << "You enter the dungeon" << endl;

    Creature *goblin = new Creature("Goblin", 20, 3, 0, 8, 10, "Dagger", 4, "Creature");
    battle(character, *goblin);
    // reset life of character
    character.restoreMaxLife();
    return;

};