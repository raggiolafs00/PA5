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

void levelUp(Person &character) {
    int option, cont;
    if (character.getExperience() >= 50) {
        character.setLevel(character.getLevel() + 1);
        character.setExperience(character.getExperience() - 50);
        cout << "You leveled up! You are now level " << character.getLevel() << endl;
        cout << "Choose a stat to increase: " << endl;
        cout << "1. Life" << endl;
        cout << "2. Strength" << endl;
        cout << "3. Intelligence" << endl;
        cin >> option;
        system("clear");
        switch (option)
        {
        case 1:
            character.setLife(character.getLife() + 15);
            break;
        case 2:
            character.setStrength(character.getStrength() + 2);
            break;
        case 3:
            character.setIntelligence(character.getIntelligence() + 2);
            break;
        }
        character.showTemplate();
        cout << "Enter 0 to continue: " << endl;
        cin >> cont;
        system("clear");
    } else {
        cout << "You need " << 50 - character.getExperience() << " more experience to level up" << endl;
        return;
    }
}

void createCharacter(vector <Person*> &characters, ofstream &characterFile) {
    string race, playerClass, specialAction, gender, name, weaponName, weaponType, armorName;
    int life, strength, intelligence, level, experience, AC, weaponStat, armorStat, specialActionCount;
    int consumables;
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
        weaponType = "Melee";
        weaponStat = 8;
        armorName = "Chain Mail";
        consumables = 4;
        AC = 12;
        specialAction = "Frenzy";
        specialActionCount = 3;
        break;

        case 2:
        playerClass = "Ranger";
        life -= 1;
        intelligence += 2;
        weaponName = "Long Bow";
        weaponType = "Ranged";
        weaponStat = 10;
        armorName = "Leather Armor";
        consumables = 4;
        AC = 10;
        specialAction = "True shot";
        specialActionCount = 3;
        break;

        case 3:
        playerClass = "Rogue";
        life -= 1;
        strength += 1;
        intelligence += 1;
        weaponName = "Dagger";
        weaponType = "Melee";
        weaponStat = 6;
        armorName = "Leather Armor";
        consumables = 4;
        AC = 10;
        specialAction = "Sneak Attack";
        specialActionCount = 3;
        break;
    }

    cout << "Choose gender: " << endl;
    cin >> gender;
    system("clear");
    cout << "Choose a name: " << endl;
    cin >> name;
    system("clear");
    cout << "Your character is: " << endl;
    Person *character = new Person(name, life, strength, intelligence, AC, gender, level, experience, weaponName, weaponType, weaponStat, armorName, consumables, specialAction, specialActionCount, race, playerClass, "Person");
    // cout << character->race << endl;
    // cout << character->playerClass << endl;
    // cout << character->specialAction << endl;
    characters.push_back(character);
}

void writeCharactersToFile(vector <Person*> &characters, std::ofstream &characterFile) {
    // Write header row
    characterFile << "Name,Life,Strength,Intelligence,Type,AC,Gender,Level,Experience,WeaponName,WeaponType,WeaponStat,ArmorName,Consumables,SpecialAction,SpecialActionCount,Race,PlayerClass\n";
    string weaponName, weaponType, armorName;
    int weaponStat, consumables;
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
                << characters[i]->experience << ","
                << characters[i]->weaponName << ","
                << characters[i]->weaponType << ","
                << characters[i]->weaponStat << ","
                << characters[i]->armorName << ","
                << characters[i]->consumables << ","
                << characters[i]->specialAction << ","
                << characters[i]->specialActionCount << ","
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
            string race, playerClass, specialAction, type, gender, name, weaponName, weaponType, armorName;
            int life, strength, intelligence, level, experience, AC, weaponStat, consumables, specialActionCount;
            map<string, int> weapons, armor;
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
            getline(ss, weaponType, ',');
            ss >> weaponStat;
            ss.ignore();
            getline(ss, armorName, ',');
            ss >> consumables;
            ss.ignore();
            getline(ss, specialAction, ',');
            ss >> specialActionCount;
            ss.ignore();
            getline(ss, race, ',');
            getline(ss, playerClass, '\n');


            Person *character = new Person(name, life, strength, intelligence, AC, gender, level, experience, weaponName, weaponType, weaponStat, armorName, consumables, specialAction, specialActionCount, race, playerClass, type);
            characters.push_back(character);
        }
    }
    file.close();
}

void printCharacter(Person &character) {
    character.showTemplate();
    cout << "[1] Level up character!" << endl;
    cout << "[0] Back to main menu" << endl;
    int choice;
    cin >> choice;
    system("clear");
    if (choice == 1) {
        levelUp(character);
    }
    else {
        return;
    }
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
            printCharacter(*characters[choice - 1]);
            return choice;
        }
    }
    return choice;
}