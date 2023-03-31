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

vector <Creature*> enemies;

void theInnerSanctum(Person &character) {
    string option, cont;
    Creature *godrick = new Creature("Godrick the Hollow", 60, 5, 3, 20, 50, "Fireball", 12, "Creature");
    cout << "As you struggle to regain your senses, you hear a slow clap echo through the chamber" << endl;
    cout << "You look up and see a massive throne made of black stone, and sitting on it is a figure in a hooded robe" << endl;
    cout << "The figure is tall and thin, with a long, bony face and a long, pointed nose" << endl;
    cout << "The figure's eyes are hidden behind a pair of dark glasses, but you can see a faint smile playing on his lips" << endl;
    cout << "The figure stands up and walks towards you, his robes billowing behind him" << endl;
    cout << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "'I see you have defeated my champion. Well done, " << character.getName() << ".'" << endl;
    cout << "'But now, you must face me if you wish to leave this place.'" << endl;
    cout << "Enter 0 to fight Godrick!" << endl;
    cin >> cont;
    system("clear");
    battle(character, *godrick);
    if (deathCheck(character)) {
        return;
    }
    cout << "Godrick falls to his knees, his robes billowing around him as he gasps for breath" << endl;
    cout << "'You are a formidable foe, " << character.getName() << ".'" << endl;
    cout << "'But I have one last trick up my sleeve.'" << endl;
    cout << "Godrick summons all the strength he has left to open up a portal beneath him" << endl;
    cout << "The energy from the portal knocks you to the ground, preventing you from stopping Godrick." << endl;
    cout << "'I will see you again, " << character.getName() << ".'" << endl;
    cout << "'And next time, I will not be so merciful.'" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "Godrick disappears through the portal." << endl;
    cout << "You have the chance to follow him, but there is no turning back." << endl;
    cout << "What do you do?" << endl;
    cout << "1. Follow Godrick" << endl;
    cout << "2. Follow Godrick?" << endl;
    cout << "3. Follow Godrick!" << endl;
    cin >> option;
    system("clear");
    cout << "You summon all your bravery and jump through the portal after Godrick!" << endl;
    cout << "Continue to dungeon 3 to see what happens next!" << endl;
    return;

}

void castleSecondFloor(Person &character) {
    string option, cont;
    Creature *giantKnight = new Creature("Giant Knight", 40, 6, 2, 18, 50, "Longsword", 12, "Creature");

    cout << "As you climb the winding staircase, you feel a sense of unease creeping over you" << endl;
    cout << "The stairs are slick with moss and the air is heavy with the scent of decay" << endl;
    cout << "As you reach the top of the stairs, you are greeted by a towering figure in armor" << endl;
    cout << "The knight is massive, with broad shoulders and rippling muscles that strain against his metal plates" << endl;
    cout << "His face is hidden behind a helmet, but you can sense the weight of his gaze as he turns to face you" << endl;
    cout << "With a heavy clang, the knight raises his sword and points it towards the large door behind him" << endl;
    cout << "The door is intricately carved with ancient symbols and seems to radiate a faint glow" << endl;
    cout << "You realize that this must be the entrance to some sort of inner sanctum, but you also know that you will have to face the knight in order to pass" << endl;
    cout << "With your heart pounding in your chest, you draw your weapon and prepare for battle" << endl;
    cout << "The knight charges towards you, his sword whistling through the air" << endl;
    cout << endl;
    cout << "Enter 0 to start the fight: " << endl;
    cin >> cont;
    system("clear");

    battle(character, *giantKnight);
    if (deathCheck(character)) {
        return;
    }
    cout << "As your final blow lands, the massive knight staggers backwards and falls to the ground with a deafening crash." << endl;
    cout << "For a moment, there is silence in the chamber as you catch your breath and survey the aftermath of the battle." << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "But then, something strange begins to happen." << endl;
    cout << "The knight's armor begins to glow with an eerie light, and you feel a sudden blast of heat as the air around you starts to ripple and warp." << endl;
    cout << "Suddenly there is an explosion of energy that sends you hurtling through the air." << endl;
    cout << "You fly backwards, crashing through the door behind you!" << endl;
    cout << endl;
    character.setLife(character.getLife() - 20 + character.getPerception());
    cout << "You take 20 damage from the explosion!" << endl;
    if (deathCheck(character)) {
        cout << "The blast of energy burns your flesh and you fall to the ground" << endl;
        return;
    }
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    return theInnerSanctum(character);
}

void castleArmory(Person &character) {
    string option, cont;
    cout << "The room is filled with weapons and armor. Some are rusted and broken, others look like they were forged yesterday." << endl;
    bool chosen = false;
    while (!chosen) {
        cout << "Choose an weapon or an armor: " << endl;
        cout << "1. Claymore - 1d12" << endl;
        cout << "2. Spear - 1d12" << endl;
        cout << "3. Hunters bow - 1d12" << endl;
        cout << "4. Plated armor - AC 16" << endl;
        cout << "5. Leather armor - AC 12" << endl;
        cin >> option;
        system("clear");
        if (option == "1") {
            character.setWeaponName("Claymore");
            character.setWeaponStat(12);
            chosen = true;
        } else if (option == "2") {
            character.setWeaponName("Spear");
            character.setWeaponStat(12);
            chosen = true;
        } else if (option == "3") {
            character.setWeaponName("Hunters bow");
            character.setWeaponStat(12);
            chosen = true;
        } else if (option == "4") {
            if (character.getStrength() >= 5) {
                character.setArmorName("Plated armor");
                character.setAC(16);
                chosen = true;
                break;
            } else {
                cout << "You are not strong enough to wear this armor." << endl;
                cout << endl;
                break;
            }
        } else if (option == "5") {
            character.setArmorName("Leather armor");
            character.setAC(12);
            chosen = true;
        } else {
            cout << "Invalid option, try again." << endl;
        }
    }
    cout << "You have looted the armory and see there is no way forward than to go back into the hall." << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
    return;
}

void hallBattle (Person &character, int distance) {
    string option, cont;
    int attackRoll, damageRoll;
    Creature *bowman = new Creature("Undead Bowman", 15, 4, 2, 12, 20, "Longbow", 12, "Creature");
    if (character.getWeaponType() == "Ranged") {
        cout << "You have a ranged weapon, you can attack the undead bowman from here." << endl;
        battle(character, *bowman);}
        
    else {

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
    
    if (deathCheck(character))
        return;
    cout << "As you gather your thoughts after that riveting battle, you see a closed door in front of you." << endl;
    cout << "What do you do?" << endl;
    cout << "1. Open the door" << endl;
    cout << "2. Find a different way forward, this looks suspicious" << endl;
    cin >> option;
    system("clear");
    
    if (option == "1") {
        cout << "You open the door and find yourself in an armory." << endl;
        castleArmory(character);
    } else if (option == "2") {
        cout << "You decide to look for another way forward." << endl;
        searchRoom(character);
        cout << "You continue your search for a way forward and find a staircase that leads upwards." << endl;
        cout << "Enter 0 to start your ascent: " << endl;
        cin >> cont;
        system("clear");
    }
    castleSecondFloor(character);
    
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
    if (option == 1) {
        cout << "You venture further into the hall." << endl;
        cout << "As you are walking you hear the sound of an arrow being nocked to a bow" << endl;
        cout << "You turn around to see an undead bowman standing in the shadows, his bow drawn back and an arrow nocked." << endl;
        cout << "He lets loose a shot, and the arrow flies straight and true, piercing your shoulder." << endl;
        cout << "You take 5 damage." << endl;
        if (deathCheck(character))
            return;
        character.setLife(character.getLife() - 5);
        distance = 1;
        cout << "You have " << character.getLife() << " life left." << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
    } else if (option == 2) {
        cout << "You look around for survivors." << endl;
        cout << "As you scan the room, you see a lone archer hiding in the shadows, his bow drawn back and an arrow nocked." << endl;
        cout << "He lets loose a shot but you manage to dodge it." << endl;
        cout << "Enter 0 to continue: " << endl;
        distance = 3;
        cin >> cont;
        system("clear");
    } else if (option == 3) {
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
    }
    return hallBattle(character, distance);
}

void theCastleWalls(Person &character) {
    string option, cont;
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
    if (option == "1") {
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
    } else if (option == "2") {
        cout << "As you ready your attack, the knight's eyes suddenly lock onto yours and he raises his sword and shield in a ready position." << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        battle(character, *undeadKnight);
    } else if (option == "3") {
        cout << "You walk up to the knight and poke him." << endl;
        cout << "The knight's eyes suddenly lock onto yours and he punches you in the face, knocking you back a few feet." << endl;
        character.setLife(character.getLife() - 3);
        cout << "You take 3 damage." << endl;
        cout << "The knight raises his sword and shield in a ready position." << endl;
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
        battle(character, *undeadKnight);
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
    string cont;
    cout << "As you slowly open your eyes, you find yourself standing in front of an abandoned castle." << endl;
    cout << "The landscape around you is barren and desolate, with no signs of life or civilization in sight." << endl;
    cout << "Confused and disoriented, you try to recall how you ended up in this strange and eerie place." << endl; 
    cout << "The last thing you remember is stepping through a shimmering portal, but everything else is a blur" << endl;
    cout << "Enter 0 to continue: " << endl;
    cin >> cont;
    system("clear");
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