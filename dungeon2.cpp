#include "beings.h"
#include "service.h"
#include "dungeon2.h"
#include "dungeon1.h"
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

vector <Creature*> enemies;

void createEnemies(vector <Creature*> &enemies) {
    // create enemies
    
    Creature *enemy2 = new Creature("Undead Knight", 20, 4, 2, 16, 30, "Longsword", 10, "Creature");
    Creature *enemy3 = new Creature("Undead Knight", 20, 4, 2, 16, 30, "Longsword", 10, "Creature");
    
    Creature *enemy5 = new Creature("Undead Bowman", 15, 4, 2, 12, 20, "Longbow", 12, "Creature");
    Creature *enemy6 = new Creature("Undead Bowman", 15, 4, 2, 12, 20, "Longbow", 12, "Creature");
    Creature *enemy7 = new Creature("Undead Hound", 10, 3, 0, 10, 10, "Bite", 8, "Creature");
    Creature *enemy8 = new Creature("Undead Hound", 10, 3, 0, 10, 10, "Bite", 8, "Creature");
    Creature *enemy9 = new Creature("Undead Hound", 10, 3, 0, 10, 10, "Bite", 8, "Creature");
    Boss *boss1 = new Boss("Godrick the Hollow", 100, 5, 3, 20, 50, "Longsword", 12, "Death Plague", "Boss");
    // add enemies to vector
}

void hallBattle (Person &character, int distance) {
    int option, cont, attackRoll, damageRoll;
    Creature *bowman = new Creature("Undead Bowman", 15, 4, 2, 12, 20, "Longbow", 12, "Creature");
    if (character.getWeaponType() == "Ranged") {
        cout << "You have a ranged weapon, you can attack the undead bowman from here." << endl;
        battle(character, *bowman);
        return;
    }

    cout << "You need to close the distance to the undead bowman." << endl;
    cout << "You take " << 5 - distance << " turns to get to the bowman." << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    while (distance != 5) {
        cout << "The undead bowman fires again!" << endl;
        attackRoll = (rand() % 20 + 1) + bowman->getStrength();
        if (attackRoll > character.getAC()) {
            damageRoll = (rand() % bowman->getWeaponStat() + 1) + bowman->getStrength();
            character.setLife(character.getLife() - damageRoll);
            cout << "He hits you for " << damageRoll << " damage" << endl;
        } else {
            cout << "He missed!" << endl;
        }
        if (deathCheck(character))
            return;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        distance++;

    }
    cout << "You manage to reach the undead bowman and are now in attacking range." << endl;
    battle(character, *bowman);
}

void theCastleHall(Person &character) {
    int option, cont;
    int distance = 0;
    cout << "You enter the castle courtyard, and the once-beautiful gardens are now overgrown and unkempt." << endl;
    cout << "Remains of dead knights and soldiers lie scattered across the ground, their armor rusted and their weapons broken." << endl;
    cout << "The wooden doors to the castle are long gone. The way is clear." << endl;
    cout << endl;
    cout << "Enter 0 to enter the castle: " << endl;
    cin >> cont;
    system("clear");
    cout << "Once inside, you find yourself in a vast, cavernous hall, with a high ceiling supported by pillars of stone. " << endl;
    cout << "The walls are lined with faded tapestries depicting scenes of great battles and noble feats, now moth-eaten and frayed." << endl;
    cout << "The air is musty and filled with the scent of age and decay, and the only sound is the rustle of your own footsteps and the occasional scurrying of small creatures" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "What do you do?" << endl;
    cout << "1. Venture further into the castle" << endl;
    cout << "2. Look around for survivors" << endl;
    cout << "3. Return to the courtyard" << endl;
    cin >> option;
    system("clear");
    switch (option) {
        case 1: 
            cout << "You venture further into the hall." << endl;
            cout << "As you are walking you hear the sound of an arrow being nocked to a bow" << endl;
            cout << "You turn around to see an undead bowman standing in the shadows, his bow drawn back and an arrow nocked." << endl;
            cout << "He lets loose a shot, and the arrow flies straight and true, piercing your shoulder." << endl;
            cout << "You take 5 damage." << endl;
            if (deathCheck(character))
                return;
            character.setLife(character.getLife() - 5);
            cout << "You have " << character.getLife() << " life left." << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            break;
        case 2:
            cout << "You look around for survivors." << endl;
            cout << "As you scan the room, you see a lone archer hiding in the shadows, his bow drawn back and an arrow nocked." << endl;
            cout << "He lets loose a shot but you manage to dodge it." << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            break;
        case 3:
            cout << "The moment you turn around and start walking towards the courtyard, an arrow pierces your shoulder." << endl;
            cout << "You turn around and see a lone archer hiding in the shadows, his bow drawn back and an arrow nocked." << endl;
            cout << "You take 5 damage." << endl;
            character.setLife(character.getLife() - 5);
            if (deathCheck(character))
                return;
            cout << "You have " << character.getLife() << " life left." << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            break;
    }
    return hallBattle(character, distance);

    
}

void theCastleWalls(Person &character) {
    int option, cont;
    Creature *undeadKnight = new Creature("Undead Knight", 20, 4, 2, 16, 30, "Longsword", 10, "Creature");
    cout << "As you approach the abandoned castle, the once-majestic stone walls loom up like ancient sentinels, standing tall and proud against the sky." << endl;
    cout << "The battlements and turrets, once symbols of power and strength, now stand broken and crumbling, their jagged edges sharp against the clouds." << endl;
    cout << "The entrance is a gaping maw, with ivy and other plants reclaiming the space that once belonged to the castle gates." << endl;
    cout << endl;

    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");

    cout << "A lone knight in a rusted suit of armor stands between you and the enterance to the castle." << endl;
    cout << "His posture is rigid and still, as if frozen in time, and his eyes stare straight ahead, unseeing." << endl;
    cout << "A longsword hangs at his side, and a shield is slung over his back." << endl;
    cout << "At first glance, it seems as though he is merely a statue, a relic of the castle's past" << endl;
    cout << endl;

    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");

    cout << "What do you do?" << endl;
    cout << "1. Walk past the knight" << endl;
    cout << "2. Attack the knight" << endl;
    cout << "3. Walk up to the knight and poke him" << endl;
    cin >> option;
    system("clear");
    switch (option)
    {
        case 1:
            cout << "You walk past the knight." << endl;
            cout << "You make it five steps before you hear the all familiar sound of a sword slicing through the air." << endl;
            cout << "You turn around to see the knight's sword coming down at you." << endl;
            cout << "You try to dodge, but the knight's sword is too fast." << endl;
            character.setLife(character.getLife() - 5);
            cout << "You take 5 damage." << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            battle(character, *undeadKnight);
            break;
        case 2:
            cout << "As you ready your attack, the knight's eyes suddenly lock onto yours and he raises his sword and shield in a ready position." << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            battle(character, *undeadKnight);
            break;
        case 3:
            cout << "You walk up to the knight and poke him." << endl;
            cout << "The knight's eyes suddenly lock onto yours and he punches you in the face, knocking you back a few feet." << endl;
            character.setLife(character.getLife() - 3);
            cout << "You take 3 damage." << endl;
            cout << "The knight raises his sword and shield in a ready position." << endl;
            cout << "Enter 0 to continue: " << endl;
            cin >> cont;
            system("clear");
            battle(character, *undeadKnight);
            break;
    }
    if (character.getLife() <= 0) {
        return;
    } else {
        cout << "You manage to defeat the knight and the enterance to the castle is no longer blocked. You may enter." << endl;
        cout << "Enter 0 to enter the castle: " << endl;
        cin >> cont;
        system("clear");
        return theCastleHall(character);

    }
};

void startDungeon2(Person &character) {
    // import creatures and bosses from file
    // vector <Boss*> bosses;
    createEnemies(enemies);
    cout << "ENTER PROLOGUE TEXT HERE!" << endl;
    theCastleWalls(character);
    if (deathCheck(character)) {
        cout << "You have died." << endl;
        cout << "GAME OVER" << endl;
    } else {
        cout << "You have defeated the final boss." << endl;
        cout << "You have won the game!" << endl;
    }
    // start dungeon
    // reset life of character
    character.restoreMaxLife();
    character.restoreSpecialActionCount();
    return;

};