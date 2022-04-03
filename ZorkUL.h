#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"

#include <iostream>
#include <string>
using namespace std;



//CREATE A POINTER FUNCTION THAT IGNORES CASES FOR THE OTHER FUNCTIONS

class ZorkUL {
private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
    string lowerCase(string);
    vector <Item> inventory;
    int collectedMoney();
    void printTotal();
    //typedef bool (ZorkUL::* lowercase_ptr)(string one, string two);
    //bool equals(const string&, const string&);
    //string (ZorkUL::* lowercase_ptr)(string);

public:
    ZorkUL();
    void play();
    string go(string direction);
};

#endif /*ZORKUL_H_*/
