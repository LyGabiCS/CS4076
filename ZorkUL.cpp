#include <iostream>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char *argv[]) {
    ZorkUL temp;
    temp.play();
    return 0;
}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q;

    a = new Room("Pond");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
    b = new Room("Hall");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("Dining");
    d = new Room("Kitchen");
    e = new Room("Salon");
    f = new Room("Library");
    g = new Room("Terrace");
    h = new Room("Study");
    i = new Room("Stables");
    j = new Room("Garden");
    k = new Room("Caretaker");
    l = new Room("Staff");
    m = new Room("Garage");
    n = new Room("Port");
    o = new Room("GuardRoom");
    p = new Room("Gallery");
    q = new Room("Clocktower");

//             (N, E, S, W)
    a->setExits(b, NULL, NULL, o);
    b->setExits(NULL, c, a, NULL);
    c->setExits(l, NULL, d, b);
    d->setExits(c, NULL, e, NULL);
    e->setExits(d, f, NULL, NULL);
    f->setExits(NULL, h, g, e);
    g->setExits(f, NULL, NULL, NULL);
    h->setExits(i, NULL, NULL, f);
    i->setExits(NULL, NULL, h, j);
    j->setExits(k, i, NULL, NULL);
    k->setExits(NULL,NULL, j, NULL);
    l->setExits(n, NULL, c, m);
    m->setExits(NULL,l, NULL, NULL);
    n->setExits(NULL,NULL, l, NULL);
    o->setExits(p, a, NULL, NULL);
    p->setExits(q, NULL, p, NULL);
    q->setExits(NULL,NULL, p, NULL);

        currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
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

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "                             [Port]                           " << endl;
        cout << "                               ¦                              " << endl;
        cout << "                               ¦                              " << endl;
        cout << " [Clocktower]  [Garage] --- [Staff]                           " << endl;
        cout << "     |                         ¦                              " << endl;
        cout << "     |                         ¦                              " << endl;
        cout << "[Gallery]       [Hall] --- [Dining]    [Caretaker]            " << endl;
        cout << "     |             ¦           ¦            ¦                 " << endl;
        cout << "     |             ¦           ¦            ¦                 " << endl;
        cout << "[GuardRoom] --- [Pond]     [Kitchen]    [Garden] --- [Stables]" << endl;
        cout << "                               ¦                         ¦    " << endl;
        cout << "                               ¦                         ¦    " << endl;
        cout << "                            [Salon] --- [Library] --- [Study] " << endl;
        cout << "                                            ¦                 " << endl;
        cout << "                                            ¦                 " << endl;
        cout << "                                        [Terrace]             " << endl;
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
  //Week 2 Update - teleport command word that takes the player back to the center "a"
    if (commandWord.compare("teleport") == 0) {
        if (!command.hasSecondWord()) {
        cout << "Unauthorised!"<< endl;
        }
        else{
        teleport();
        cout << currentRoom->longDescription() << endl;
      }
    }
}
/** COMMANDS **/
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
        cout << "underdefined input"<< endl;
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

  string ZorkUL::teleport() {
  return currentRoom->shortDescription();
    }



