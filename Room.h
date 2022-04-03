#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:


    //OR KEEP THE VECTOR ITEM BUT MAKE THE BASE CLASS BACK TO NORMAL WITH JUST A VIRTUAL FUNCTION, NOT PURE VIRTUAL FUNCTION?
    string description;
    map<string, Room*> exits;
    string exitString();
    vector <Item> itemsInRoom;
    //vector <Common> CommonsInRoom;
    //vector <Rare> RaresInRoom;
    //vector <Unique> UniquesInRoom;



public:
    int numberOfItems();
    Room(string description);
    void setExits(Room* north, Room* east, Room* south, Room* west);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    //void addItem(Item* inItem);
    void addCommon(Common* inCommon);
    void addRare(Rare* inRare);
    void addUnique(Unique* inUnique);
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);

};

#endif
