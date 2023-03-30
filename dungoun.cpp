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
// Creature::Creature(string name, int life, int strength, int perception, int AC, int experience, string weaponName, int weaponStat, string type = "Creature")

using namespace std;

void dungeonCreatures(vector <Creature*> &enemies) {
    Creature *leftSlimeBoss = new Creature("Slimes left half", 15, 1, 0, 5, 15, "slime", 2, "Creature");
    Creature *rightSlimeBoss = new Creature("Slimes right half", 15, 1, 0, 5, 15, "slime", 2, "Creature");
    enemies.push_back(leftSlimeBoss);
    enemies.push_back(rightSlimeBoss);


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

    cout << "  ,     ," << endl;
    cout << " / ~~~ \\ " << endl;
    cout << "{  O  O }" << endl;
    cout << "(       )" << endl;
    cout << " \\  *  / " << endl;
    cout << "  \\   /  " << endl;
    cout << "    -   " << endl;
    cout << "1. Talk to the goblin" << endl;
    cout << "2. Attack the goblin" << endl;
    int option;
    cin >> option;
    system("clear");
    if (option != 1 && option != 2) {
        cout << "while you took your time typing an invalid action you fall down and take 2 damage" << endl;
        character.setLife(character.getLife() - 2);
        cout << "the goblin takes advantage of your stupidity and attacks you" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");


    }
    switch (option)
    {
    case 1:
        cout << "You try starting a converstation with the goblin but it doesn't seem as eager to have a converstation" << endl;
        cout << "Goblin: SCREEEEEEEEEEEEEECH" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");

       

        
        break;
    case 2:
        cout << "As the goblin approaches you it gives out a horrible screech" << endl;
        cout << "Goblin: SCREEEEEEEEEEEEEECH" << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        
  
    default:
       
        break;
    }
    battle(character, *goblin);
    if (deathCheck(character)) {
            character.restoreMaxLife();
            character.restoreSpecialActionCount();
            return;
        }
    theLongHallway(character, enemies);

}

void theLongHallway(Person &character, vector <Creature*> &enemies) {
    int cont, option;
    
    Creature *slime = new Creature("Green Slime", 20, 1, 0, 5, 15, "slime", 1, "Creature");
    Creature *slime1 = new Creature("Blue Slime", 20, 1, 0, 8, 15, "slime", 1, "Creature");
    Creature *slimeBoss = new Creature("Giant green slime", 25, 3, 0, 8, 15, "Size", 3, "Creature");
    Creature *leftSlimeBoss = new Creature("Slimes left half", 15, 1, 0, 5, 15, "slime", 2, "Creature");
    Creature *rightSlimeBoss = new Creature("Slimes right half", 15, 1, 0, 5, 15, "slime", 2, "Creature");




    cout << "With the goblin dead you get a few seconds to gather your thoughts" << endl;
    cout << "You see a open door infront of you that leads to a long hallway" << endl;
    searchRoom(character);

    cout << "You walk down the long hallway, trying to open several doors, but they are all locked" << endl;
    cout << "As you keep moving forward, you suddenly hear a creaking noise," << endl;
    cout << "and a door pops open" << endl;
    cout << "A green slime suddenly jumps out of the room and lands in front of you with a squishy sound" << endl;
    cout << "" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    battle(character, *slime);
    if (deathCheck(character)) {
        character.restoreMaxLife();
        character.restoreSpecialActionCount();
        return;
        }
    cout << "The slime explodes as you kill it, you notice the room that it jumped from" << endl;
    cout << "What do you do?" << endl;
    cout << "1. Enter the room" << endl;
    cout << "2. Keep going down the hall" << endl;
    cin >> option;
    system("clear");
    cout << "You enter the room the slime jumped from" << endl;
    if (option == 1){
        int chance = rand() % 2;
        if (chance == 1) {
            cout << "As you enter the room you hear a squishy noise" << endl;
            cout << "A blue slime jumps out of the room and lands in front of you with a squishy sound" << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            battle(character, *slime1);
            if (deathCheck(character)) {
                character.restoreMaxLife();
                character.restoreSpecialActionCount();
                return;
            }
           
        }
         searchRoom(character);
    }

    
   
    
    cout << "You continue walking down the long hallway" << endl;
    cout << "As you make your way deeper into the dungeon, you come across a huge door." << endl;
    cout << "You push the door open and step inside, finding yourself face to face with a massive, green slime." << endl;
    cout << "The slime's body towers over you, and its slimy tentacles twitch as it senses your presence." << endl;
    cout << "You can feel your heart pounding in your chest as you steel yourself for the battle ahead." << endl;
    cout << "The slime lets out a low growl, and begins to move towards you, ready to attack." << endl; 
    cout << "" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    battle(character, *slimeBoss);
        if (deathCheck(character)) {
            character.restoreMaxLife();
            character.restoreSpecialActionCount();
            return;
        }
    cout << "You dodge the slimy tentacle and land a solid hit on the slime, causing it to split into two smaller slimes." << endl;
    cout << "The slime's body begins to shrink as it splits, and the two smaller slimes begin to move towards you." << endl;
    cout << "" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    doubleBattle(character, *leftSlimeBoss, *rightSlimeBoss);
        if (deathCheck(character)) {
            character.restoreMaxLife();
            character.restoreSpecialActionCount();
            return;
        }

    cout << "With the slimes finally defeated, you take a few moments to catch your breath." << endl;
    cout << "You look around the room and notice a chest in one of the piles of slime." << endl;
    cout << "You cautiously approach the chest and open it, revealing a brand new weapon and a few potions for your journy." << endl;
    cout << "" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    if (character.getPlayerClass() == "Rogue") {
        cout << "You found a dagger" << endl;
        cout << "this one is a little sharper than the last one" << endl;
        if (character.getWeaponName() != "Dagger") {
            character.setWeaponStat(character.getWeaponStat() + 1);
        }
        else {
            character.setWeaponName("slimy dagger");
            character.setWeaponStat(character.getWeaponStat() + 3);
        }
  
    }
    else if (character.getPlayerClass() == "Warrior") {
        cout << "You found a sword" << endl;
        cout << "It's a little slimy but definetly an upgrade!" << endl;
        if (character.getWeaponName() != "Short Sword") {
            character.setWeaponStat(character.getWeaponStat() + 1);
        }
        else {
            character.setWeaponName("slippery sword");
            character.setWeaponStat(character.getWeaponStat() + 3);
        }

    }
    else {
        cout << "You found a bow!" << endl;
        cout << "It's smells a bit but nothing a small wash won't take care of" << endl;
        if (character.getWeaponName() != "Long Bow") {
            character.setWeaponStat(character.getWeaponStat() + 1);
        }
        else {
            character.setWeaponName("Bow of slips");
            character.setWeaponStat(character.getWeaponStat() + 3);
        }

    }
    character.addConsumable(2);
    cout << "" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "As you begin to pocket the loot, you notice a strange, shimmering portal in the corner of the room." << endl;
    cout << "Without hesitation, you step into the portal, eager to see where it leads." << endl;
    cout << "" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    character.restoreMaxLife();
    character.restoreSpecialActionCount();
   
    


    
    

        
}