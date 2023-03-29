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
// Creature::Creature(string name, int life, int strength, int intelligence, int AC, int experience, string weaponName, int weaponStat, string type = "Creature")
bool searched = false;

void dungeonCreatures(vector <Creature*> &enemies) {
    Creature *goblin = new Creature("Goblin", 12, 3, 0, 8, 10, "Bloody Book", 2, "Creature");
    Creature *slime = new Creature("Green Slime", 20, 1, 0, 8, 15, "", 1, "Creature");
    Creature *goblin2 = new Creature("Goblin", 20, 3, 0, 8, 10, "Dagger", 4, "Creature");
    enemies.push_back(goblin);
    enemies.push_back(goblin);
    enemies.push_back(goblin);
    enemies.push_back(goblin);
    // enemies.push_back(goblin1);
    // enemies.push_back(goblin2);
    // enemies.push_back(goblin2);
    // enemies.push_back(goblin2);
    // enemies.push_back(goblin);

}

void startDungeon1(Person &character){
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
    case 3:
  
        startDungeon(character);
    default:
        break;
    }

}

void room1Empty (Person &character, vector <Creature*> &enemies) {
    cout << "With the goblin dead you take a little time to gather your thoughts" << endl;
    int option;
    while (option != 1) {
        cout << "1. Continue to the next room" << endl;
        cout << "2. Search the room" << endl;
        cout << "3. Main menu" << endl;
        cout << "" << endl;
        cin >> option;
        switch (option)
        {  
        case 1:
            // room2(character, enemies);
            break;
        case 2:
            if (searched == false) {
                searchRoom(character);
                searched = true;
            }
            else {
                cout << "You have already searched this room" << endl;
                cin.get();
                system("clear");
            }
            break;
        case 3:
     
            break;
        }

    }

}




void searchRoom(Person &character){
    // random number generator from 1 to 10
    srand(time(NULL));
    int random = rand() % 10 + 1;
    if (random <= 6) {
        cout << "You find nothing" << endl;
        cin.get();
        system("clear");
    }
    else if (random > 6 && random <= 8) {
        cout << "You find a potion" << endl;
        cin.get();
        system("clear");
        // add potion to inventory
    }
    else if (random > 9 && random <= 10) {
        cout << "You find a weird shrine" << endl;
        cin.get();
        cout << "Do you feel lucky?" << endl;
        system("clear");
        int option;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            random = rand() % 20 + 1;
            if (random == 1) {
                cout << "";

            }
            else if (random <= 5) {
                cout << "You feel a surge of energy" << endl;
                cin.get();
                system("clear");
                character.setLife(character.getLife() + 10);
                cout << "You have gained 10 life" << endl;
                cin.get();
                system("clear");
            }
            else {
                cout << "You feel a surge of energy" << endl;
                cin.get();
                system("clear");
                character.setLife(character.getLife() + 20);
                cout << "You have gained 20 life" << endl;
                cin.get();
                system("clear");
            }
        case 2:
            cout << "You decide not to touch the shrine" << endl;
            cin.get();
            system("clear");
            break;
            
    }

}}