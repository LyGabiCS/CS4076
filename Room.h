#ifndef ROOM_H_
#define ROOM_H_
#include "item.h"

#include <string>
#include <map>
#include <vector>

using namespace std;
using std::vector;
using std::string;

class Room
{
private:
    string description;
    map <string, Room*> exits;
    vector <Item> itemsInRoom;




public:
    //DEFAULT CONSTRUCTOR
    Room(string = "Castle");

    string getDescription();
    vector <Item> getItemsInRoom();
    void setItemsInRoom(vector <Item>);
    int numOfItems();
    void setExits(Room*, Room*, Room*, Room*);
    Room* nextRoom(string);
    void addItem(Item*);
    string displayItem();
    int isItemInRoom(string);
    void takeItem(string);
    void removeItemFromRoom(int location);
    void operator+(Item* item);






};


#endif // !ROOM_H_

