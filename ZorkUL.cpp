#include <iostream>
#include <algorithm>
#include <vector>

#include "mainwindow.h"
#include "ZorkUL.h"
#include "Wordle.h"
#include "exception.h"

#include <QApplication>
#include <QTimer>

//USER DEFINED NAMESPACE
using namespace exception;
using namespace std;
using std::vector;


vector <Item> playerInventory;
int total = 0;


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;

    w.resize(1400, 700);
    w.show();
    QTimer::singleShot(420000, &a, SLOT(quit()));
    return a.exec();

}

ZorkUL::ZorkUL()
{
    createRooms();
}

ZorkUL::~ZorkUL()
{
    for (int i = 0; i < availableRooms.size(); i++) {
        delete availableRooms[i];
    }
}


void ZorkUL::createRooms()
{
    Room *pond, * hall, * dining, * kitchen, * salon, * library, * terrace, * study, *stables, * garden, * armory, * staff, * guards, * redTower, * gallery, * blackTower;

    pond = new Room("Pond");
    pond->addItem(new Item("Knife", 20, "Common"));
    pond->addItem(new Item("Axe", 10, "Common"));
    availableRooms.push_back(pond);


    hall = new Room("Hall");
    hall->addItem(new Item("Painting", 750, "Unique"));
    hall->addItem(new Item("Candlestick", 15, "Common"));
    availableRooms.push_back(hall);

    dining = new Room("Dining");
    dining->addItem(new Item("Vase", 340, "Rare"));
    dining->addItem(new Item("Cutlery", 60, "Common"));
    availableRooms.push_back(dining);

    kitchen = new Room("Kitchen");
    kitchen->addItem(new Item("Knife", 80, "Common"));
    availableRooms.push_back(kitchen);

    salon = new Room("Salon");
    salon->addItem(new Item("Violin", 800, "Unique"));
    salon->addItem(new Item("Porcelain", 240, "Rare"));
    salon->addItem(new Item("Flute", 90, "Common"));
    availableRooms.push_back(salon);

    library = new Room("Library");
    library->addItem(new Item("Coins", 10, "Common"));
    library->addItem(new Item("Statue", 820, "Unique"));
    library->addItem(new Item("Atlas", 290, "Rare"));
    availableRooms.push_back(library);

    terrace = new Room("Terrace");
    availableRooms.push_back(terrace);

    study = new Room("Study");
    study->addItem(new Item("Map", 190, "Rare"));
    study->addItem(new Item("Seal", 380, "Rare"));
    study->addItem(new Item("Purse", 55, "Common"));
    availableRooms.push_back(study);

    stables = new Room("Stables");
    stables->addItem(new Item("Horseshoe", 10, "Common"));
    stables->addItem(new Item("Horseshoe", 10, "Common"));
    availableRooms.push_back(stables);

    garden = new Room("Garden");
    availableRooms.push_back(garden);

    armory = new Room("Armory");
    armory->addItem(new Item("Kasket", 240, "Rare"));
    armory->addItem(new Item("Boots", 630, "Unique"));
    armory->addItem(new Item("Bayonet", 420, "Rare"));
    armory->addItem(new Item("Sabre", 890, "Unique"));
    availableRooms.push_back(armory);

    staff = new Room("Staff");
    staff->addItem(new Item("5 Gulden Coins", 5, "Common"));
    staff->addItem(new Item("Spoon", 1, "Common"));
    staff->addItem(new Item("Brooch", 750, "Unique"));
    availableRooms.push_back(staff);

    guards = new Room("Guards");
    guards->addItem(new Item("Wine", 45, "Common"));
    availableRooms.push_back(guards);

    redTower = new Room("Red Tower");
    redTower->addItem(new Item("Bayonet", 360, "Rare"));
    redTower->addItem(new Item("Sabre", 220, "Rare"));
    redTower->addItem(new Item("Gloves", 60, "Common"));
    availableRooms.push_back(redTower);

    gallery = new Room("Gallery");
    gallery->addItem(new Item("Bowl", 690, "Unique"));
    gallery->addItem(new Item("Painting", 990, "Unique"));
    gallery->addItem(new Item("Mosaic", 870, "Unique"));
    availableRooms.push_back(gallery);

    blackTower = new Room("Black Tower");
    blackTower->addItem(new Item("Coins", 120, "Rare"));
    blackTower->addItem(new Item("Wine", 20, "Common"));
    blackTower->addItem(new Item("Bayonet", 260, "Rare"));
    availableRooms.push_back(blackTower);



    //             (N, E, S, W)
    pond->setExits(hall, NULL, NULL, redTower);

    hall->setExits(NULL, dining, pond, NULL);

    dining->setExits(staff, NULL, kitchen, hall);

    kitchen->setExits(dining, NULL, salon, NULL);

    salon->setExits(kitchen, library, NULL, NULL);

    library->setExits(NULL, study, terrace, salon);

    terrace->setExits(library, NULL, NULL, NULL);

    study->setExits(stables, NULL, NULL, library);

    stables->setExits(NULL, NULL, study, garden);

    garden->setExits(armory, stables, NULL, NULL);

    armory->setExits(NULL, NULL, garden, NULL);

    staff->setExits(NULL, NULL, dining, guards);

    guards->setExits(NULL, staff, NULL, NULL);

    redTower->setExits(gallery, pond, NULL, NULL);

    gallery->setExits(blackTower, NULL, redTower, NULL);

    blackTower->setExits(NULL, NULL, gallery, NULL);


    this->currentRoom = pond;
}

string ZorkUL::printWelcome()
{
    return "Welcome to Zork! Your goal is to loot as many rooms in the given time! "
        "Beware of the time limit and tough Wordle puzzles on your journey through "
        "Forchenstein Castle! GOOD LUCK!";
}

string ZorkUL::printHelp()
{
    return "Buttons:\n"
        "Use Arrowpad to move rooms\n"
        "Use Map button to show Map\n"
        "Timer will countdown your game time\n";
}

string ZorkUL::goRoom(string direction)
{
      currentRoom = getCurrentRoom();
      Room* nextRoom;
      currentRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
        return "There is no room this way!";
    }
    else
    {
        currentRoom = nextRoom;
        return currentRoom->getDescription();
    }
}

string ZorkUL::currentItems()
{
    return currentRoom->displayItem();
}

string ZorkUL::addToInventory(string itemName)
{
    int index = currentRoom->isItemInRoom(itemName);
    Item item = currentRoom->getItemsInRoom().at(index);
    int money = item.getValue();
    total += money;
    playerInventory.push_back(item);
    currentRoom->takeItem(itemName);
    return "You took " + itemName;
}


string ZorkUL::lowerCase(string word)
{
    string uppercase = word;
    std::transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::tolower);
    return uppercase;
}

Room* ZorkUL::getCurrentRoom()
{
    return currentRoom;
}

int ZorkUL::collectedMoney()
{
    int endTotal = 0;
    for(int i = 0; i < playerInventory.size(); i++)
    {
        endTotal += playerInventory[i].getValue();
        return endTotal;
    }
}





