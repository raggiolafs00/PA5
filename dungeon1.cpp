#include "beings.h"
#include "dungeon1.h"
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

void entrance(Person &character){
    int choice;
    while (choice != 1)
    {
        cout << "You are in the entrance of the dungeon. What do you want to do?" << endl;
        cout << "1. Go to the next room" << endl;
        cout << "2. Go back to the previous room" << endl;
        cin >> choice;
        system("clear");
        switch (choice)
        {
        case 1:
            //Room1();
            break;
        case 2:
            cout << "You can't go back to the previous room" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
        }
    }
    

}