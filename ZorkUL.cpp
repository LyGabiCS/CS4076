#include <iostream>
#include "mainwindow.h"
#include <QApplication>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.resize(1500, 800);
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
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p;

    a = new Room("Pond");
        a->addItem(new Item("Swiss Knife", 20, "Common"));
        a->addItem(new Item("Axe", 10, "Common"));

    b = new Room("Hall");
        b->addItem(new Item("Mona Lisa", 750, "Unique"));
        b->addItem(new Item("Candlestick", 15, "Common"));

    c = new Room("Dining");
        c->addItem(new Item("Weinglut Schloss", 340, "Rare"));
        c->addItem(new Item("Silver Cutlery", 60, "Common"));

    d = new Room("Kitchen");
        d->addItem(new Item("Chef's Knife", 80, "Common"));

    e = new Room("Salon");
        e->addItem(new Item("Violin 'Ex-Carrodus'", 800, "Unique"));
        e->addItem(new Item("Porcelain Tea-Set", 240, "Rare"));
        e->addItem(new Item("Ceramic Vase", 90, "Common"));

    f = new Room("Library");
        f->addItem(new Item("10 Gulden Coins", 10, "Common"));
        f->addItem(new Item("Frauenbildnis", 820, "Unique"));
        f->addItem(new Item("Bronze Atlas", 290, "Rare"));

    g = new Room("Terrace");

    h = new Room("Study");
        h->addItem(new Item("Map of Mattersburg", 190, "Rare"));
        h->addItem(new Item("Lord's Wax Seal Stamp", 380, "Rare"));
        h->addItem(new Item("Coin Purse", 55, "Common"));

    i = new Room("Stables");
        i->addItem(new Item("Horseshoe", 10, "Common"));
        i->addItem(new Item("Horseshoe", 10, "Common"));

    j = new Room("Garden");

    k = new Room("Armory");
        k->addItem(new Item("Kasket", 240, "Rare"));
        k->addItem(new Item("Lord's boots", 630, "Unique"));
        k->addItem(new Item("Bayonet", 420, "Rare"));
        k->addItem(new Item("Cavalry Sabre", 890, "Unique"));

    l = new Room("Staff");
        l->addItem(new Item("5 Gulden Coins", 5, "Common"));
        l->addItem(new Item("Spoon", 1, "Common"));
        l->addItem(new Item("Brooch", 750, "Unique"));

    m = new Room("Guards");
        m->addItem(new Item("Almdudler", 45, "Common"));

    n = new Room("Red Tower");
        n->addItem(new Item("Bayonet", 360, "Rare"));
        n->addItem(new Item("Broken Sabre", 220, "Rare"));
        n->addItem(new Item("Leather Gloves", 60, "Common"));

    o = new Room("Gallery");
        o->addItem(new Item("The Young Hare", 690, "Unique"));
        o->addItem(new Item("Gemstone Bouquet", 990, "Unique"));
        o->addItem(new Item("The Last Judgement", 870, "Unique"));

    p = new Room("Black Tower");
        p->addItem(new Item("120 Gulden Coins", 120, "Rare"));
        p->addItem(new Item("Wine", 20, "Common"));
        p->addItem(new Item("Bayonet", 260, "Rare"));

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
    l->setExits(NULL, NULL, c, m);
    m->setExits(NULL,l, NULL, NULL);
    n->setExits(o, a, NULL, NULL);
    o->setExits(p, NULL, o, NULL);
    p->setExits(NULL,NULL, o, NULL);

        currentRoom = a;
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

void ZorkUL::printWelcome() {
    cout << "Welcome to Zork!"<< endl;
    cout << "You are at the entrance of Forchtenstein Castle, a looming shadow on the beautiful town of "<< endl;
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
        cout << " [Black Tower]  [Guards] --- [Staff]                          " << endl;
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

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
    if (commandWord.compare("scout") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
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




