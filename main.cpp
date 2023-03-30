#include "beings.h"
#include "service.h"
#include "dungeon2.h"
#include "dungeon1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "dungeonService.h"

// include random library
#include <cstdlib>
#include <ctime>


using namespace std;

// vector that stores characters

int main () {
    vector<Person*> characters;
    Person *character;
    
    system("clear");
    int option;
    int selected_char = 0;
    readBeingsFromFile(characters, "characters.txt");
    cout << "Welcome to Dungeon Crawler" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    // create a file to save the characters
    ofstream characterFile;
    characterFile.open("characters.txt");
    

    while (option != 6) {
        cout << "Choose an option: " << endl;
        cout << "1. Create Character" << endl;
        cout << "2. Show Character List" << endl;
        cout << "3. Enter Dungeon" << endl;
        cout << "4. Exit" << endl;
        cin >> option;
        system("clear");
        switch (option)
        {
        case 1:
            createCharacter(characters, characterFile);
            break;
        case 2:
            selected_char = showCharacters(characters);
            break;
         
        case 3:
            character = characters[0];
            dungeonSelector(*character);
            // startDungeon1(*character);
            break;
        case 4:
            writeCharactersToFile(characters, characterFile);
            exit(0);
            break;
        case 5:
            character = characters[0];
            startDungeon2(*character);
            break;
        default:
            exit(0);
        }
    }
        return 0;
}