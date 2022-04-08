#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Room.h"
#include "item.h"

using std::vector;

class ZorkUL
{
private:
    Room* currentRoom;
    vector <Room*> availableRooms;
    void createRooms();


public:

    ZorkUL();
    ~ZorkUL();

    string printWelcome();
    string printHelp();
    string goRoom(string);
    string currentItems();
    string addToInventory(string);
    string lowerCase(string);
    Room* getCurrentRoom();
    int collectedMoney();
    






};


#endif // !ZORKUL_H_

