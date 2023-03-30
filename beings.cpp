#include "beings.h"

Being::Being(string name, int life, int strength, int perception, int AC, string type) {
    this->name = name;
    this->life = life;
    this->strength = strength;
    this->perception = perception;
    this->AC = AC;
    this->maxLife = life;
    this->type = type;
};

Person::Person(string name, int life, int strength, int perception, int AC, string gender, int level, int experience, string weaponName, string weaponType, int weaponStat, string armorName, int consumables, string specialAction, int specialActionCount, string race, string playerClass, string type = "Person") 
: Being(name, life, strength, perception, AC, type) {
    this->gender = gender;
    this->type = type;
    this->level = level;
    this->experience = experience;
    this->weaponName = weaponName;
    this->weaponType = weaponType;
    this->weaponStat = weaponStat;
    this->armorName = armorName;
    this->consumables = consumables;
    this->race = race;
    this->playerClass = playerClass;
    this->specialAction = specialAction;
    this->specialActionCount = specialActionCount;
}

Creature::Creature(string name, int life, int strength, int perception, int AC, int experience, string weaponName, int weaponStat, string type = "Creature")
    : Being(name, life, strength, perception, AC, type) {
    this->experience = experience;
    this->weaponName = weaponName;
    this->weaponStat = weaponStat;
    this->type = type;
}

Boss::Boss(string name, int life, int strength, int perception, int AC, int experience, string weponName, int weaponStat, string specialAction, string type = "Boss")
    : Creature(name, life, strength, perception, AC, experience, weaponName, weaponStat, type) {
    this->type = type;
    this->specialAction = specialAction;

}









