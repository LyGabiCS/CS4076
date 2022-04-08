#include "Room.h"


Room::Room(string name)
{
    this->description = name;

}

string Room::getDescription()
{
    return this->description;
}

vector <Item> Room::getItemsInRoom()
{
    return this->itemsInRoom;
}

void Room::setItemsInRoom(vector<Item> newVector)
{
    this->itemsInRoom = newVector;
}

void Room::setExits(Room* north, Room* east, Room* south, Room* west)
{
    if (north != NULL)
    {
        exits["north"] = north;
    }
    if (east != NULL)
    {
        exits["east"] = east;
    }
    if (south != NULL)
    {
        exits["south"] = south;
    }
    if (west != NULL)
    {
        exits["west"] = west;
    }
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction);
    if (next == exits.end())
        return NULL;
    return next->second;

}


void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x].getName() + "  ";
            x++;
        }
    }
    return tempString;
}

int Room::numOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
    }
    else if (itemsInRoom.size() > 0) {
        int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            int tempFlag = inString.compare(itemsInRoom[x].getName());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin() + x);
                return x;
            }
            x++;
        }
    }
    return -1;
}

void Room::takeItem(string name)
{
    vector <Item> items = getItemsInRoom();

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].getName() == name)
        {
            items.erase(items.begin() +i);
            this->setItemsInRoom(items);
        }
    }
}

void Room::removeItemFromRoom(int location)
{
    itemsInRoom.erase(itemsInRoom.begin() + location);
}

void Room::operator+(Item *item)
{
    addItem(item);
}



