#include <vector>
#include <string>
#include <fstream>

using namespace std;

void showCharacters(vector <Person*> &characters);
void readBeingsFromFile(vector <Person*> &characters, string filename);
void writeCharactersToFile(vector <Person*> &characters, std::ofstream &characterFile);
void createCharacter(vector <Person*> &characters, ofstream &characterFile);
