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
    string option;
    int selected_char = 0;
    readBeingsFromFile(characters, "characters.txt");
    cout << "Welcome to Dungeon Crawler" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    // create a file to save the characters
    ofstream characterFile;
    characterFile.open("characters.txt");
    

    while (option != "Exit") {
        cout << "Choose an option: " << endl;
        cout << "1. Create Character" << endl;
        cout << "2. Show Character List" << endl;
        cout << "3. Enter Dungeon" << endl;
        cout << "4. Exit" << endl;
        cin >> option;
        system("clear");
        if (option == "1") {
            createCharacter(characters, characterFile);
         }
        else if (option == "2") {
            selected_char = showCharacters(characters);
     }
         
        else if (option == "3") {
            character = characters[0];
            dungeonSelector(*character);
     }
        else if (option == "4") {
            writeCharactersToFile(characters, characterFile);
            exit(0);
        }
        else {
            cout << "Invalid option" << endl;
        }
    }
        return 0;
}