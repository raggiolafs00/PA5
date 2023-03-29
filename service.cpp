#include "beings.h"
#include "service.h"
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

void createCharacter(vector <Person*> &characters, ofstream &characterFile) {
    string race, playerClass, specialAction, gender, name, weaponName, armorName;
    int life, strength, intelligence, level, experience, AC, weaponStat, armorStat;
    map<string, int> consumables;
    cout << "Choose a race: " << endl;
    cout << "1. Human" << endl;
    cout << "2. Elf" << endl;
    cout << "3. Dwarf" << endl;
    int option;
    cin >> option;
    system("clear");
    switch (option)
    {
        case 1:
        race = "Human";
        life = 12;
        strength = 3;
        intelligence = 1;
        level = 1;
        experience = 0;
        break;
        case 2:
        race = "Elf";
        life = 10;
        strength = 2;
        intelligence = 3;
        level = 1;
        experience = 0;
        break;
        case 3:
        race = "Dwarf";
        life = 14;
        strength = 4;
        intelligence = 0;
        level = 1;
        experience = 0;
    }
    cout << "Choose a class: " << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Ranger" << endl;
    cout << "3. Rogue" << endl;
    cin >> option;
    system("clear");
    switch (option)
    {
        case 1:
        playerClass = "Warrior";
        life += 2;
        strength += 2;
        intelligence -= 1;
        weaponName = "Short Sword";
        weaponStat = 8;
        armorName = "Chain Mail";
        consumables["Potion of Healing"] = 4;
        AC = 12;
        specialAction = "Frenzy";
        break;

        case 2:
        playerClass = "Ranger";
        life -= 1;
        intelligence += 2;
        weaponName = "Long Bow";
        weaponStat = 10;
        armorName = "Leather Armor";
        consumables["Potion of Healing"] = 4;
        AC = 10;
        specialAction = "Volley";
        break;

        case 3:
        playerClass = "Rogue";
        life -= 1;
        strength += 1;
        intelligence += 1;
        weaponName = "Dagger";
        weaponStat = 6;
        armorName = "Leather Armor";
        consumables["Potion of Healing"] = 4;
        AC = 10;
        specialAction = "Sneak Attack";
        break;
    }

    cout << "Choose gender: " << endl;
    cin >> gender;
    system("clear");
    cout << "Choose a name: " << endl;
    cin >> name;
    system("clear");
    cout << "Your character is: " << endl;
    Person *character = new Person(name, life, strength, intelligence, AC, gender, level, experience, weaponName, weaponStat, armorName, consumables, specialAction, race, playerClass, "Person");
    // cout << character->race << endl;
    // cout << character->playerClass << endl;
    // cout << character->specialAction << endl;
    characters.push_back(character);
}

void writeCharactersToFile(vector <Person*> &characters, std::ofstream &characterFile) {
    // Write header row
    characterFile << "Name,Life,Strength,Intelligence,Type,AC,Gender,Level,Experience,WeaponName,WeaponStat,ArmorName,ConsumablesName,ConsumableStat,SpecialAction,Race,PlayerClass\n";
    string weaponName, armorName, consumablesName;
    int weaponStat, consumableStat;
    // Write data rows
    for (int i = 0; i < characters.size(); i++) {
        characterFile << characters[i]->name << ","
                << characters[i]->life << ","
                << characters[i]->strength << ","
                << characters[i]->intelligence << ","
                << characters[i]->type << ","
                << characters[i]->AC << ","
                << characters[i]->gender << "," 
                << characters[i]->level << ","
                << characters[i]->experience << ",";
                for (auto it = characters[i]->consumables.begin(); it != characters[i]->consumables.end(); ++it) {
                    consumablesName = it->first;
                    consumableStat = it->second;
                }
                characterFile << characters[i]->weaponName << ","
                    << characters[i]->weaponStat << ","
                    << characters[i]->armorName << ","
                    << consumablesName << ","
                    << consumableStat << ","
                    << characters[i]->specialAction << ","
                    << characters[i]->race << ","
                    << characters[i]->playerClass << "\n";
    };
    // Close file
    characterFile.close();
}

void readBeingsFromFile(vector <Person*> &characters, string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        // Read header line and ignore it
        getline(file, line);

        while (getline(file, line)) {
            cout << "Read character" << endl;
            string race, playerClass, specialAction, type, gender, name, weaponName, armorName, consumablesName;
            int life, strength, intelligence, level, experience, AC, weaponStat, consumableStat;
            map<string, int> weapons, armor, consumables;
            // Read data from line
            istringstream ss(line);
            getline(ss, name, ',');
            ss >> life;
            ss.ignore();
            ss >> strength; 
            ss.ignore();
            ss >> intelligence;
            ss.ignore();
            getline(ss, type, ',');
            ss >> AC;
            ss.ignore();
            getline(ss, gender, ',');
            ss >> level;
            ss.ignore();
            ss >> experience;
            ss.ignore();
            getline(ss, weaponName, ',');
            ss >> weaponStat;
            ss.ignore();
            getline(ss, armorName, ',');
            getline(ss, consumablesName, ',');
            ss >> consumableStat;
            ss.ignore();
            getline(ss, specialAction, ',');
            getline(ss, race, ',');
            getline(ss, playerClass, '\n');

            consumables[consumablesName] = consumableStat;
            Person *character = new Person(name, life, strength, intelligence, AC, gender, level, experience, weaponName, weaponStat, armorName, consumables, specialAction, race, playerClass, type);
            characters.push_back(character);
        }
    }
    file.close();
}

int showCharacters(vector <Person*> &characters) {
    int choice = 10;
    // show the created characters
    while (choice != 0) {
        cout << "-----------Characters----------" << endl;
        for (int i = 0; i < characters.size(); i++) {
            cout << i + 1 << "." << " " << characters[i]->name << endl;
        }
        cout << "0. Back to main menu" << endl;
        cin >> choice;

        system("clear");
        if (choice == 0) {
            return choice;
        }
        else {
            return choice;
        }
    }
    return choice;
}