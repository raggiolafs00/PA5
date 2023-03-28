#include <string>
#include <iostream>
#include <map>

using namespace std;

class Being {

    public:
    Being(string name, int life, int strength, int AC, int intelligence, string type);

    string name;
    int life;
    int strength;
    int intelligence;
    int AC;
    string type;


    virtual void dummy() {}
};

class Person : public Being {
    

    public:
    Person(string name, int life, int strength, int intelligence, int AC, string gender, int level, int experience, string weaponName, int weaponStat, string armorName, map<string, int> consumables, string specialAction, string race, string playerClass, string type);

    string gender;
    string type;
    int level;
    int experience;
    string weaponName;
    int weaponStat;
    string armorName;
    map<string, int> consumables;
    string specialAction;
    string race;
    string playerClass;

    virtual void showTemplate() {
        cout << "---------- " << name << " ----------" << endl;
        cout << "Race: " << race << endl;
        cout << "Class: " << playerClass << endl;
        cout << "Life: " << life << endl;
        cout << "Level: " << level << endl;
        cout << "Experience: " << experience << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Gender: " << gender << endl;
        cout << "Special Action: " << specialAction << endl;
    }
};

class Creature : public Being {

    public:
    Creature(string name, int life, int strength, int intelligence, int AC, int experience, string weaponName, int weaponStat, string type);
    string type;
    string weaponName;
    int weaponStat;
    int experience;

    virtual void showTemplate() {
        cout << "---------- " << name << " ----------" << endl;
        cout << "Life: " << life << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
    }
};

class Boss : public Creature {
    public:
    Boss(string name, int life, int strength, int intelligence, int AC, int experience, string weaponName, int weaponStat, string specialAction, string type);
    string type;
    string weaponName;
    int weaponStat;
    string specialAction;

    virtual void showTemplate() {
        cout << "---------- " << name << " ----------" << endl;
        cout << "Life: " << life << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
    }
};


