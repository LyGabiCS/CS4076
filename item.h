#ifndef ITEM_H_
#define ITEM_H_

#include <string>


using std::string;

class Item {

protected:
    string name;
    int value;
    string rarity;

public:
    Item(string, int, string);
    ~Item();

    string getName();
    int getValue();
    string getRarity();

    void setName(string);
    virtual void setValue(int);
    void setRarity(string);

    bool operator==(Item);
};



// COMMON ITEMS
class Common : public Item
{

public:
    Common(string, int,  string);
    void setValue(int);

};

// RARE ITEMS
class Rare : public Item
{

public:
    Rare(string, int,  string);
    void setValue(int);
};

// UNIQUE ITEMS
class Unique : public Item
{

public:
    Unique(string, int,  string);
    void setValue(int);
};

#endif /*ITEM_H_*/
