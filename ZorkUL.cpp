#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include <QTimer>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
   // w.resize(1500, 800);
    w.setWindowState(Qt::WindowMaximized);
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
        a->addItem(new Common("Swiss Knife", 20, "Common"));
        a->addItem(new Common("Axe", 10, "Common"));

    b = new Room("Hall");
        b->addItem(new Unique("Mona Lisa", 750, "Unique"));
        b->addItem(new Common("Candlestick", 15, "Common"));

    c = new Room("Dining");
        c->addItem(new Rare("Weinglut Schloss", 340, "Rare"));
        c->addItem(new Common("Silver Cutlery", 60, "Common"));

    d = new Room("Kitchen");
        d->addItem(new Common("Chef's Knife", 80, "Common"));

    e = new Room("Salon");
        e->addItem(new Unique("Violin 'Ex-Carrodus'", 800, "Unique"));
        e->addItem(new Rare("Porcelain Tea-Set", 240, "Rare"));
        e->addItem(new Common("Ceramic Vase", 90, "Common"));

    f = new Room("Library");
        f->addItem(new Common("10 Gulden Coins", 10, "Common"));
        f->addItem(new Unique("Frauenbildnis", 820, "Unique"));
        f->addItem(new Rare("Bronze Atlas", 290, "Rare"));

    g = new Room("Terrace");

    h = new Room("Study");
        h->addItem(new Rare("Map of Mattersburg", 190, "Rare"));
        h->addItem(new Rare("Lord's Wax Seal Stamp", 380, "Rare"));
        h->addItem(new Common("Coin Purse", 55, "Common"));

    i = new Room("Stables");
        i->addItem(new Common("Horseshoe", 10, "Common"));
        i->addItem(new Common("Horseshoe", 10, "Common"));

    j = new Room("Garden");

    k = new Room("Armory");
        k->addItem(new Rare("Kasket", 240, "Rare"));
        k->addItem(new Unique("Lord's boots", 630, "Unique"));
        k->addItem(new Rare("Bayonet", 420, "Rare"));
        k->addItem(new Unique("Cavalry Sabre", 890, "Unique"));

    l = new Room("Staff");
        l->addItem(new Common("5 Gulden Coins", 5, "Common"));
        l->addItem(new Common("Spoon", 1, "Common"));
        l->addItem(new Unique("Brooch", 750, "Unique"));

    m = new Room("Guards");
        m->addItem(new Common("Almdudler", 45, "Common"));

    n = new Room("Red Tower");
        n->addItem(new Rare("Bayonet", 360, "Rare"));
        n->addItem(new Rare("Broken Sabre", 220, "Rare"));
        n->addItem(new Common("Leather Gloves", 60, "Common"));

    o = new Room("Gallery");
        o->addItem(new Unique("The Young Hare", 690, "Unique"));
        o->addItem(new Unique("Gemstone Bouquet", 990, "Unique"));
        o->addItem(new Unique("The Last Judgement", 870, "Unique"));

    p = new Room("Black Tower");
        p->addItem(new Rare("120 Gulden Coins", 120, "Rare"));
        p->addItem(new Common("Wine", 20, "Common"));
        p->addItem(new Rare("Bayonet", 260, "Rare"));

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
    cout << "Servus! It's an absolutely dreadful day in Burgenland, Austria"<< endl;
    cout << "Yet, its good as any other day for thieving! Today you've found"<< endl;
    cout << "yourself at the entrance to Forchtenstein Castle, a looming shadow"<< endl;
    cout << "over the poor folk of Forchenstein. Take everything you possibly can "<< endl;
    cout << "and remember: be quick about it, you can't steal time! " << endl;
    cout << endl;
    cout << "You being you're journey at the ";
    cout << currentRoom->longDescription() << endl;
    cout << "Good Luck";
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




