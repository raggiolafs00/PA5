#include "beings.h"
#include "service.h"
#include "dungeon1.h"
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
// Creature::Creature(string name, int life, int strength, int intelligence, int AC, int experience, string weaponName, int weaponStat, string type = "Creature")

void dungeonCreatures(vector <Creature*> &enemies) {
    Creature *goblin = new Creature("Goblin", 12, 3, 0, 8, 10, "Bloody Book", 2, "Creature");
    Creature *slime = new Creature("Green Slime", 20, 1, 0, 8, 15, "", 1, "Creature");
    Creature *goblin2 = new Creature("Goblin", 20, 3, 0, 8, 10, "Dagger", 4, "Creature");
    enemies.push_back(goblin);
    // enemies.push_back(goblin1);
    // enemies.push_back(goblin2);
    // enemies.push_back(goblin2);
    // enemies.push_back(goblin2);
    // enemies.push_back(goblin);

}

bool deathCheck(Person &character) {
    if (character.getLife() <= 0) {
        return true;
    }
    else {
        return false;
    }
}

void startDungeon(Person &character){
    vector<Creature*> enemies;
    dungeonCreatures(enemies);

    cout << "You are in the entrance of the dungeon" << endl;
    cout << "You see a little goblin infront of you" << endl;

    cout << "1. Talk to the goblin" << endl;
    cout << "2. Attack the goblin" << endl;
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "You approach the goblin and try asking it for directions" << endl;
        cin.get();
        system("clear");
        cout << "Goblin: I don't understand non goblin speak" << endl;
        cin.get();
        system("clear");
        cout << "Goblin: SCREEEEEEEEEEEEEECH" << endl;
        cin.get();
        system("clear");
        battle(character, *enemies[1]);
        if (deathCheck(character)) {
            return;
        }
        
        break;
    case 2:

        battle(character, *enemies[1]);
        startDungeon(character);
     
    default:
        break;
    }

}

void room1Empty (Person &character, vector <Creature*> &enemies) {
    cout << "You are in an empty room" << endl;
    cout << "There is nothing here" << endl;
}