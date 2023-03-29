#include <string>
#include <iostream>
#include <map>

using namespace std;

class Being {

    public:
    Being(string name, int life, int strength, int AC, int intelligence, string type);

    string name;
    int life;
    int maxLife;
    int strength;
    int intelligence;
    int AC;
    string type;

    string getName() {
        return name;
    }

    int getLife() {
        return life;
    }

    int getStrength() {
        return strength;
    }

    int getIntelligence() {
        return intelligence;
    }

    int getAC() {
        return AC;
    }

    void setLife(int life) {
        this->life = life;
    }

    void restoreMaxLife() {
        this->life = maxLife;
    }

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

    void addExperience(int experience) {
        this->experience += experience;
    }

    void addConsumable(string consumable, int amount) {
        consumables[consumable] += amount;
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

    int getExperience () {
        return this->experience;
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


