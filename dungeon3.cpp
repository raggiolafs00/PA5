#include "beings.h"
#include "service.h"
#include "dungeon1.h"
#include "dungeon2.h"
#include "dungeon3.h"
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

void finalFightEncounter(Person &character) {
    Creature *dragon = new Creature("Drake of the Void", 70, 7, 4, 16, 100, "Claws", 12, "Creature");
    Creature *godrick = new Creature("Godrick", 40, 5, 5, 14, 100, "Sword", 12, "Creature");
    doubleBattle(character, *dragon, *godrick);
    if (deathCheck(character)) {
        cout << "You have defeated Godrick and the Drake of the Void!" << endl;
        cout << "You have saved the world!" << endl;
        cout << "You have won the game!" << endl;
        cout << "Thank you for playing!" << endl;
        return;
    } else {
        return;
    }
}

void finalFightPrologue(Person &character) {
    string option, cont;
    cout << "You reach the top of the tower and find Godrick standing before you. " << endl;
    cout << "He is holding a large, ornate sword in his hand. " << endl;
    cout << "'You have come far, " << character.getName() << ". But this is where your journey ends! " << endl;
    cout << "Godrick points his sword to the sky and says this: " << endl;
    cout << "'I summon you, Drake of the Void!'" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "A large, black dragon descends from the sky. It's scales are as black as the infinite space around it." << endl;
    cout << "The dragon lands beside Godrick." << endl;
    cout << "You realize that you must fight the dragon and Godrick at the same time." << endl;
    cout << "Enter 0 to start the final fight! " << endl;
    cin >> cont;
    system("clear");
    finalFightEncounter(character);
}

void theDarkTower(Person &character) {
    string option, cont;
    cout << "You notice that the thick mist has cleared and before you stands a massive dark tower. " << endl;
    cout << "The enterance to the tower is a large wooden door, embroidered with ancient symbols you have never seen before. " << endl;
    cout << "As you examine the door, it suddenly swings opens." << endl;
    cout << "Enter 0 to step inside: " << endl;
    cin >> cont;
    system("clear");
    cout << "You enter the tower and find yourself in a large, dimly lit room. " << endl;
    cout << "The walls are covered in ancient runes, and the only light in the room comes from a single torch on the wall." << endl;
    cout << "You hear a voice echo through the room: " << endl;
    cout << "'Riddle me this!...'" << endl;
    cout << "The door behind you closes, and you are left alone in the dark room." << endl;
    cout << "Enter 0 to hear the riddle: " << endl;
    cin >> cont;
    system("clear");
    while (true) {
        cout << "'I am the beginning of the end, and the end of time and space. I am essential to creation, and I surround every place. What am I?'" << endl;
        cin >> option;
        system("clear");
        if (option == "e") {
            cout << "'Correct!'" << endl;
            cout << "'You may pass.'" << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            break;
        } else {
            cout << "'Incorrect!'" << endl;
            cout << "You feel a sharp pain in your head" << endl;
            character.setLife(character.getLife() - 3);
            cout << "You take 3 psychic damage" << endl;
            cout << "'Try again.'" << endl;
            cout << "Enter 0 to try again: " << endl;
            cin >> cont;
            system("clear");
        }
    }
    cout << "A staircase appears in front of you, leading up to the top of the tower." << endl;
    cout << "Enter 0 to climb the stairs: " << endl;
    cin >> cont;
    system("clear");
    return finalFightPrologue(character);

}

void startDungeon3(Person &character) {
    string option, cont;
    Creature *beast = new Creature("Dark Beast", 30, 3, 0, 10, 20, "Claws", 12, "Creature");
    cout << "You find yourself laying on a dark and desolate plain, the ground cracked and barren. " << endl;
    cout << "The air around you is thick with an eerie mist that obscures your vision, and the only sound you can hear is the distant rumble of thunder in the sky above." << endl;
    cout << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "Suddenly, you hear the voice of Godrick the Wizard echo through the air: " << endl;
    cout << "'I see you have followed me through the portal. You fool!'" << endl;
    cout << "'You have no idea what you have gotten yourself into!'" << endl;
    cout << "'This is my domain, and I will not let you leave alive!'" << endl;
    cout << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "You suddenly hear a growl coming from behind you. The mist is so thick that you can't see anything, but you can feel the presence of something large and dangerous." << endl;
    cout << "What do you do?" << endl;
    cout << "1. Turn around and face the ominous sound" << endl;
    cout << "2. RUN!" << endl;
    cin >> option;
    system("clear");
    if (option == "1") {
        cout << "You turn around and face the ominous sound, and you see a large, hulking beast standing in front of you." << endl;
        cout << "It's eyes are glowing red, and it's mouth is filled with sharp, jagged teeth." << endl;
        cout << "You have no idea what it is, but you know that you have to fight it." << endl;
        cout << "Enter 0 to fight! " << endl;
        cin >> cont;
        system("clear");
    } else if (option == "2") {
        cout << "You turn around and run as fast as you can, but the beast is too fast for you." << endl;
        cout << "It catches up to you in a matter of seconds, and you are forced to fight it." << endl;
        cout << "Enter 0 to fight! " << endl;
        cin >> cont;
        system("clear");
    }
    battle(character, *beast);
    if (deathCheck(character)) {
        return;
    }
    theDarkTower(character);
    character.restoreMaxLife();
    character.restoreSpecialActionCount();
    return;
    
}