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

}





void startDungeon1(Person &character){
    vector<Creature*> enemies;
    dungeonCreatures(enemies);
    int cont;
    Creature *goblin = new Creature("Goblin", 12, 3, 0, 8, 10, "Bloody Book", 2, "Creature");
    cout << "The Pub" << endl;
    cout << "" << endl;
    cout << "You push open the door to the pub and step inside, but to your surprise the place is completely empty." << endl;
    cout << "The air is stale and there's a musty smell that seems to have settled in every corner of the room." << endl;
    cout << "Just as you're about to turn and leave, you catch a glimpse of movement out of the corner of your eye." << endl;
    cout << "You turn to face the source of the movement and see a small goblin hiding behind a table in the corner of the room." << endl;
    cout << "It looks up at you, eyes wide with fear, and you realize that you're not the only one who's surprised to see someone here." << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");


    cout << "1. Talk to the goblin" << endl;
    cout << "2. Attack the goblin" << endl;
    int option;
    cin >> option;
    if (option != 1 && option != 2) {
        cout << "while you took your time typing an invalid action you fall down and take 2 damage" << endl;
        character.setLife(character.getLife() - 2);
        cout << "the goblin takes advantage of your stupidity and attacks you" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        battle(character, *goblin);


    }
    switch (option)
    {
    case 1:
        cout << "You try starting a converstation with the goblin but it doesn't seem as eager to have a converstation" << endl;
        cout << "Goblin: SCREEEEEEEEEEEEEECH" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        battle(character, *goblin);

       

        
        break;
    case 2:
        cout << "As the goblin approaches you it gives out a horrible screech" << endl;
        cout << "Goblin: SCREEEEEEEEEEEEEECH" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        battle(character, *goblin);
        
  
    default:
       
        break;
    }
    if (deathCheck(character)) {
            return;
        }
    theLongHallway(character, enemies);

}

void theLongHallway(Person &character, vector <Creature*> &enemies) {
    int cont;
    Creature *slime = new Creature("Green Slime", 20, 1, 0, 5, 15, "slime", 1, "Creature");
    Creature *slime1 = new Creature("Blue Slime", 20, 1, 0, 8, 15, "slime", 1, "Creature");
    Creature *slimeBoss = new Creature("Giant green slime", 25, 3, 0, 8, 15, "Size", 3, "Creature");
    Creature *leftSlimeBoss = new Creature("Green Slime", 15, 1, 0, 5, 15, "slime", 2, "Creature");
    Creature *rightSlimeBoss = new Creature("Green Slime", 15, 1, 0, 5, 15, "slime", 2, "Creature");




    cout << "With the goblin dead you get a few seconds to gather your thoughts" << endl;
    cout << "You see a open door infront of you that leads to a long hallway" << endl;
    searchRoom(character);
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");


    cout << "You walk down the long hallway, trying to open several doors, but they are all locked" << endl;
    cout << "As you keep moving forward, you suddenly hear a creaking noise," << endl;
    cout << "and a door pops open" << endl;
    cout << "A green slime suddenly jumps out of the room and lands in front of you with a squishy sound" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    battle(character, *slime);
    if (deathCheck(character)) {
            return;
        }
    cout << "You enter the room the slime jumped" << endl;
    // make a 50% chance for another slime to spawn
    int chance = rand() % 2;
    if (chance == 1) {
        cout << "As you enter the room you hear a squishy noise" << endl;
        cout << "A blue slime jumps out of the room and lands in front of you with a squishy sound" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        battle(character, *slime1);
        if (deathCheck(character)) {
            return;
        }
    }
    searchRoom(character);
    cout << "You continue walking down the long hallway, your footsteps echoing off the stone walls." << endl;
    cout << "As you make your way deeper into the dungeon, you come across a huge door." << endl;
    cout << "You push the door open and step inside, finding yourself face to face with the boss of this hallway: a massive, green slime." << endl;
    cout << "The slime's body towers over you, and its slimy tentacles twitch as it senses your presence." << endl;
    cout << "You can feel your heart pounding in your chest as you steel yourself for the battle ahead." << endl;
    cout << "The slime lets out a low, guttural growl, and begins to move towards you, ready to attack." << endl; 
    cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
    battle(character, *slimeBoss);
        if (deathCheck(character)) {
            return;
        }
    battle(character, *leftSlimeBoss);
        if (deathCheck(character)) {
            return;
        }
    battle(character, *rightSlimeBoss);
        if (deathCheck(character)) {
            return;
        }


    
    

        
}