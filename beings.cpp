#include "beings.h"

Being::Being(string name, int life, int strength, int intelligence, int AC, string type) {
    this->name = name;
    this->life = life;
    this->strength = strength;
    this->intelligence = intelligence;
    this->AC = AC;
    this->type = type;

    
};

Person::Person(string name, int life, int strength, int intelligence, int AC, string gender, int level, int experience, string weaponName, int weaponStat, string armorName, map<string, int> consumables, string specialAction, string race, string playerClass, string type = "Person") 
: Being(name, life, strength, intelligence, AC, type) {
    this->gender = gender;
    this->type = type;
    this->level = level;
    this->experience = experience;
    this->weaponName = weaponName;
    this->weaponStat = weaponStat;
    this->armorName = armorName;
    this->consumables = consumables;
    this->race = race;
    this->playerClass = playerClass;
    this->specialAction = specialAction;
}

Creature::Creature(string name, int life, int strength, int intelligence, int AC, int experience, string weaponName, int weaponStat, string type = "Creature")
    : Being(name, life, strength, intelligence, AC, type) {
    this->experience = experience;
    this->weaponName = weaponName;
    this->weaponStat = weaponStat;
    this->type = type;
}

Boss::Boss(string name, int life, int strength, int intelligence, int AC, int experience, string weponName, int weaponStat, string specialAction, string type = "Boss")
    : Creature(name, life, strength, intelligence, AC, experience, weaponName, weaponStat, type) {
    this->type = type;
    this->specialAction = specialAction;

}









