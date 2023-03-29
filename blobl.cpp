#include "beings.h"
#include "service.h"
#include "dungeon1.h"
#include "dungeon2.h"
#include "dungeonService.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
// #include <sstream>
#include <vector>
#include <map>
// include random library
#include <cstdlib>
#include <ctime>
// Creature::Creature(string name, int life, int strength, int intelligence, int AC, int experience, string weaponName, int weaponStat, string type = "Creature")

using namespace std;

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

void theLongHallway(Person &character, vector <Creature*> &enemies) {
    cout << "With the goblin dead you get a few seconds to gather your thoughts" << endl;
    cout << "You see a open door infront of you that leads to a long hallway" << endl;
    searchRoom(character);
    
    int option;

        cout << "1. Continue to the next room" << endl;

        cout << "" << endl;
        cin >> option;
        // switch (option)
        // {  
        // case 1:
        //     // room2(character, enemies);
        //     break;
        // case 2:
        //         searchRoom(character);
            
          

        //         cin.get();
        //         system("clear");
            
        //     break;
        // case 3:
     
        //     break;
        // }
}


void searchRoom(Person &character){
    // random number generator from 1 to 10
    cout << "As you walk around you ";
    srand(time(NULL));
    int random = rand() % 10 + 1;
    if (random <= 2) {
        cout << "You find nothing" << endl;
        cin.get();
        system("clear");
    }
    else if (random <= 6) {
        cout << "You find a healing potion" << endl;
        character.addConsumable(1);
        cin.get();
        system("clear");
        // add potion to inventory
    }
     else if (random <= 9) {
        cout << "You find 2 healing potions" << endl;
        character.addConsumable(2);
        cin.get();
        system("clear");
        // add potion to inventory
    }
    else {
        cout << "You find a weird shrine" << endl;
        cin.get();
        system("clear");
        int option;
        cout << "when you approach it an aura surrounds you" << endl;

        random = rand() % 20 + 1;
        if (random == 1) {
            cout << "you feel as if you have been cursed" << endl;
            character.setStrength(character.getStrength() - 1);

        }
        else if (random < 6) {
            cout << "You suddenly feel as if you just refreshed as if all your ailments have dissapeared" << endl;
            character.getMaxLife();
            cin.get();
            system("clear");
        }
        else if (random < 13) {
            cout << "You feel as if you have been blessed" << endl;
            character.setStrength(character.getStrength() + 1);
            character.setIntelligence(character.getIntelligence() + 1);
            character.restoreMaxLife();
            cin.get();
            system("clear");
        }
        else if (random < 20) {
            cout << "your weapon has been blessed with the power of the gods" << endl;
            character.setWeaponStat(character.getWeaponStat() + 3);
            character.setWeaponName("Blessed " + character.getWeaponName());
            cin.get();
            system("clear");
            }
        else {
            cout << "You feel as if you have been blessed with the power of the gods" << endl;
            character.setStrength(character.getStrength() + 2);
            character.setIntelligence(character.getIntelligence() + 2);
            character.setWeaponStat(character.getWeaponStat() + 5);
            character.setWeaponName("Blessed " + character.getWeaponName());
            character.restoreMaxLife();
            cin.get();
            system("clear");

        }

      
            
    

}}

void startDungeon1(Person &character){
    vector<Creature*> enemies;
    dungeonCreatures(enemies);
    Creature *goblin = new Creature("Goblin", 12, 3, 0, 8, 10, "Bloody Book", 2, "Creature");
    cout << "The Pub" << endl;
    cout << "" << endl;
    cout << "You push open the door to the pub and step inside, but to your surprise the place is completely empty." << endl;
    cout << "The air is stale and there's a musty smell that seems to have settled in every corner of the room." << endl;
    cout << "Just as you're about to turn and leave, you catch a glimpse of movement out of the corner of your eye." << endl;
    cout << "You turn to face the source of the movement and see a small goblin hiding behind a table in the corner of the room." << endl;
    cout << "It looks up at you, eyes wide with fear, and you realize that you're not the only one who's surprised to see someone here." << endl;
    cin.get();
    system("clear");

    cout << "1. Talk to the goblin" << endl;
    cout << "2. Attack the goblin" << endl;
    int option;
    cin >> option;
    if (option != 1 || option != 2) {
        cout << "while you took your time typing an invalid action you fall down and take 2 damage" << endl;
        character.setLife(character.getLife() - 5);
        cin.get();
        system("clear");
        cout << "the goblin takes advantage of your stupidity and attacks you" << endl;
        option = 2;

    }
    switch (option)
    {
    case 1:
        cout << "You try starting a converstation with the goblin but it doesn't seem as eager to have a converstation" << endl;
        cin.get();
        system("clear");
        cout << "Goblin: SCREEEEEEEEEEEEEECH" << endl;
        cin.get();
        system("clear");
        battle(character, *goblin);
        if (deathCheck(character)) {
            return;
        }

        
        break;
    case 2:
        cout << "As the goblin approaches you it gives out a horrible screech" << endl;
        cin.get();
        system("clear");
        cout << "Goblin: SCREEEEEEEEEEEEEECH" << endl;
        cin.get();
        system("clear");
        battle(character, *goblin);
        if (deathCheck(character)) {
            return;
        }
  
    default:
        break;
    }
    theLongHallway(character, enemies);

}