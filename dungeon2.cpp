#include "beings.h"
#include "service.h"
#include "dungeon2.h"
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

void startDungeon2(Person &character) {
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