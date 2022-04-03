#include <iostream>

#include "mainwindow.h"
#include "ZorkUL.h"

#include <QApplication>
#include <QTimer>

//NAMESPACE
using namespace std;


int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;

    w.resize(1400, 700);
    //w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
    ZorkUL temp;
    temp.play();
    return 0;
}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *pond, *hall, *dining, *kitchen, *salon, *library, *terrace, *study, *stables, *garden, *armory, *staff, *guards, *redTower, *gallery, *blackTower;

    pond = new Room("Pond");
            pond->addCommon(new Common("Swiss Knife", 20, "Common"));
            pond->addCommon(new Common("Axe", 10, "Common"));

        hall = new Room("Hall");
            hall->addUnique(new Unique("Mona Lisa", 750,  "Unique"));
            hall->addCommon(new Common("Candlestick", 15, "Common"));

        dining = new Room("Dining");
            dining->addRare(new Rare("Weinglut Schloss", 340,  "Rare"));
            dining->addCommon(new Common("Silver Cutlery", 60, "Common"));

        kitchen = new Room("Kitchen");
            kitchen->addCommon(new Common("Chef's Knife", 80,  "Common"));

        salon = new Room("Salon");
            salon->addUnique(new Unique("Violin 'Ex-Carrodus'", 800,  "Unique"));
            salon->addRare(new Rare("Porcelain Tea-Set", 240,  "Rare"));
            salon->addCommon(new Common("Ceramic Vase", 90, "Common"));

        library = new Room("Library");
            library->addCommon(new Common("10 Gulden Coins", 10, "Common"));
            library->addUnique(new Unique("Frauenbildnis", 820, "Unique"));
            library->addRare(new Rare("Bronze Atlas", 290, "Rare"));

        terrace = new Room("Terrace");

        study= new Room("Study");
            study->addRare(new Rare("Map of Mattersburg", 190, "Rare"));
            study->addRare(new Rare("Lord's Wax Seal Stamp", 380,  "Rare"));
            study->addCommon(new Common("Coin Purse", 55, "Common"));

        stables = new Room("Stables");
            stables->addCommon(new Common("Horseshoe", 10,  "Common"));
            stables->addCommon(new Common("Horseshoe", 10, "Common"));

        garden = new Room("Garden");

        armory = new Room("Armory");
            armory->addRare(new Rare("Kasket", 240, "Rare"));
            armory->addUnique(new Unique("Lord's boots", 630, "Unique"));
            armory->addRare(new Rare("Bayonet", 420, "Rare"));
            armory->addUnique(new Unique("Cavalry Sabre", 890, "Unique"));

        staff = new Room("Staff");
            staff->addCommon(new Common("5 Gulden Coins", 5, "Common"));
            staff->addCommon(new Common("Spoon", 1, "Common"));
            staff->addUnique(new Unique("Brooch", 750, "Unique"));

        guards = new Room("Guards");
            guards->addCommon(new Common("Almdudler", 45, "Common"));

        redTower = new Room("Red Tower");
            redTower->addRare(new Rare("Bayonet", 360, "Rare"));
            redTower->addRare(new Rare("Broken Sabre", 220, "Rare"));
            redTower->addCommon(new Common("Leather Gloves", 60, "Common"));

        gallery = new Room("Gallery");
            gallery->addUnique(new Unique("The Young Hare", 690, "Unique"));
            gallery->addUnique(new Unique("Gemstone Bouquet", 990, "Unique"));
            gallery->addUnique(new Unique("The Last Judgement", 870, "Unique"));

        blackTower = new Room("Black Tower");
            blackTower->addRare(new Rare("120 Gulden Coins", 120, "Rare"));
            blackTower->addCommon(new Common("Wine", 20, "Common"));
            blackTower->addRare(new Rare("Bayonet", 260, "Rare"));


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

            currentRoom = pond;
    }

//  Main play routine.  Loops until end of play.

void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

string ZorkUL::printWelcome() {
    string welcome = "Servus! It's an absolutely dreadful day in Burgenland, Austria\n"
                     "Yet, its good as any other day for thieving! Today you've found\n"
                     "yourself at the entrance to Forchtenstein Castle, a looming shadow\n"
                     "over the poor folk of Forchenstein. Take everything you possibly can\n"
                     "and remember: be quick about it, you can't steal time!\n "
                     "You begin your journey at the " +currentRoom->longDescription() + "\n"
                     "Good Luck!";
    return welcome;


   // cout << "Servus! It's an absolutely dreadful day in Burgenland, Austria"<< endl;
   // cout << "Yet, its good as any other day for thieving! Today you've found"<< endl;
    //cout << "yourself at the entrance to Forchtenstein Castle, a looming shadow"<< endl;
    //cout << "over the poor folk of Forchenstein. Take everything you possibly can "<< endl;
    //cout << "and remember: be quick about it, you can't steal time! " << endl;
    //cout << "You begin your journey at the ";
    //cout << currentRoom->longDescription() << endl;
    //cout << "Good Luck";
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "Come on now, no one's got time for that!"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "[Black Tower]  [Guards] --- [Staff]                           " << endl;
        cout << "     |                         ¦                              " << endl;
        cout << "     |                         ¦                              " << endl;
        cout << "[Gallery]       [Hall] --- [Dining]     [Armory]              " << endl;
        cout << "     |             ¦           ¦            ¦                 " << endl;
        cout << "     |             ¦           ¦            ¦                 " << endl;
        cout << "[Red Tower] --- [Pond]     [Kitchen]    [Garden] --- [Stables]" << endl;
        cout << "                               ¦                         ¦    " << endl;
        cout << "                               ¦                         ¦    " << endl;
        cout << "                            [Salon] --- [Library] --- [Study] " << endl;
        cout << "                                            ¦                 " << endl;
        cout << "                                            ¦                 " << endl;
        cout << "                                        [Terrace]             " << endl;
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    //need a function to ignore cases, will be very helpful for the take commend REMEMBER!!!!!!!
    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "you need to pick something pal"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "what sort of thief are you, it's not in this room!" << endl;
        else
            cout << "found it!" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    if (commandWord.compare("progress") == 0) {
        if (command.hasSecondWord())
            cout << "give me a second will ya"<< endl;
        else
            return true; // write a function that specifies the room details
    }
}
// COMMANDS
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "incomplete input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
      }
  }




