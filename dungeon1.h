#include <vector>
#include <string>
#include <fstream>


using namespace std;

void startDungeon1(Person &character);
void dungeonCreatures(vector <Creature*> &creatures);
bool deathCheck(Person &character);
void room1Empty(Person &character, vector <Creature*> &enemies);
void searchRoom(Person &character);

