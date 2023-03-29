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

    void setStrength(int strength) {
        this->strength = strength;
    }

    void setIntelligence(int intelligence) {
        this->intelligence = intelligence;
    }

    void restoreMaxLife() {
        this->life = maxLife;
    }

};

class Person : public Being {
    

    public:
    Person(string name, int life, int strength, int intelligence, int AC, string gender, int level, int experience, string weaponName, string weaponType, int weaponStat, string armorName, map<string, int> consumables, string specialAction, string race, string playerClass, string type);

    string gender;
    string type;
    int level;
    int experience;
    string weaponName;
    string weaponType;
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

    void setExperience(int experience) {
        this->experience = experience;
    }

    int getExperience() {
        return this->experience;
    }

    int getLevel() {
        return this->level;
    }

    void setLevel(int level) {
        this->level = level;
    }

    void addConsumable(string consumable, int amount) {
        consumables[consumable] += amount;
    }

    string getWeaponType() {
        return this->weaponType;
    }

    int getWeaponStat() {
        return this->weaponStat;
    }
};

class Creature : public Being {

    public:
    Creature(string name, int life, int strength, int intelligence, int AC, int experience, string weaponName, int weaponStat, string type);
    string type;
    string weaponName;
    int weaponStat;
    int experience;

    void showTemplate() {
        cout << "---------- " << name << " ----------" << endl;
        cout << "Life: " << life << endl;
        cout << "Strength: " << strength << endl;
        cout << "Intelligence: " << intelligence << endl;
    }

    int getExperience () {
        return this->experience;
    }

    int getWeaponStat() {
        return this->weaponStat;
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


