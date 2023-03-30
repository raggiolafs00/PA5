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

/*
As you step out of the portal, you find yourself standing on a dark and desolate plain, the ground cracked and barren. 
The air around you is thick with an eerie mist that obscures your vision, and the only sound you can hear is the distant rumble of thunder in the sky above.
*/

void theDarkPlains(Person &character) {
    string option, cont;
    cout << "As you step out of the portal, you find yourself standing on a dark and desolate plain, the ground cracked and barren. " << endl;
    cout << "The air around you is thick with an eerie mist that obscures your vision, and the only sound you can hear is the distant rumble of thunder in the sky above." << endl;
    cout << endl;
    cout << "Enter any key to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "Suddenly, you hear the voice of Godrick the Wizard echo through the air: " << endl;
    cout << "Godrick the Wizard: 'I see you have followed me through the portal. You fool!'" << endl;
    cout << "Godrick the Wizard: 'You have no idea what you have gotten yourself into!'" << endl;
    cout << "Godrick the Wizard: 'This is my domain, and I will not let you leave alive!'" << endl;
    cout << endl;
    cout << "Enter any key to continue: " << endl;
    cin >> cont;
    system("clear");
    cout << "You suddenly hear a growl coming from behind you. The mist is so thick that you can't see anything, but you can feel the presence of something large and dangerous." << endl;
    cout << "What do you do?" << endl;
}