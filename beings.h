#include <string>
#include <iostream>
#include <map>

using namespace std;

class Being {

    public:
    Being(string name, int life, int strength, int AC, int perception, string type);

    string name;
    int life;
    int maxLife;
    int strength;
    int perception;
    int AC;
    string type;

    string getName() {
        return name;
    }

    int getLife() {
        return life;
    }
    int getMaxLife() {
        return maxLife;
    }

    string getType() {
        return type;
    }

    int getStrength() {
        return strength;
    }

    int getPerception() {
        return perception;
    }

    int getAC() {
        return AC;
    }

    void setAC(int AC) {
        this->AC = AC;
    }

    void setLife(int life) {
        this->life = life;
    }
    void setMaxLife(int maxLife) {
        this->maxLife = maxLife;
    }

    void setStrength(int strength) {
        this->strength = strength;
    }

    void setPerception(int perception) {
        this->perception = perception;
    }

    void restoreMaxLife() {
        this->life = maxLife;
    }

};

class Person : public Being {
    

    public:
    Person(string name, int life, int strength, int perception, int AC, string gender, int level, int experience, string weaponName, string weaponType, int weaponStat, string armorName, int consumables, string specialAction, int specialActionCount, string race, string playerClass, string type);

    string gender;
    string type;
    int level;
    int experience;
    string weaponName;
    string weaponType;
    int weaponStat;
    string armorName;
    int consumables;
    string specialAction;
    int specialActionCount;
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
        cout << "Perception: " << perception << endl;
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

    void addConsumable(int amount) {
        this->consumables += amount;
    }

    string getWeaponType() {
        return this->weaponType;
    }

    void setWeaponType(string type) {
        this->weaponType = type;
    }

    string getWeaponName() {
        return this->weaponName;
    }
    int getWeaponStat() {
        return this->weaponStat;
    }
    int getConsumables() {
        return this->consumables;
    }
    void setWeaponStat(int weaponStat) {
        this->weaponStat = weaponStat;
    }
    void setWeaponName(string weaponName) {
        this->weaponName = weaponName;
    }

    string getArmorName() {
        return this->armorName;
    }

    void setArmorName(string armorName) {
        this->armorName = armorName;
    }

    string getSpecialAction() {
        return this->specialAction;
    }

    int getSpecialActionCount() {
        return this->specialActionCount;
    }

    void setSpecialActionCount(int specialActionCount) {
        this->specialActionCount = specialActionCount;
    }

    void restoreSpecialActionCount() {
        this->specialActionCount = 3;
    }
    string getPlayerClass() {
        return this->playerClass;
    }
};

class Creature : public Being {

    public:
    Creature(string name, int life, int strength, int perception, int AC, int experience, string weaponName, int weaponStat, string type);
    string type;
    string weaponName;
    int weaponStat;
    int experience;

    void showTemplate() {
        cout << "---------- " << name << " ----------" << endl;
        cout << "Life: " << life << endl;
        cout << "Strength: " << strength << endl;
        cout << "Perception: " << perception << endl;
    }

    int getExperience () {
        return this->experience;
    }

    int getWeaponStat() {
        return this->weaponStat;
    }
};


