#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Each Item will have a name, value and rarity.
// Value of each item will be added up to the grand total
// Rarity of each item will determine which wordle the player will do!
// Total will be updated every time the player picks up and successfully finishes a wordle.

class Item {

protected:

    string description;
    string fullDescription;
    int value = 0;
    string rarity;
    int total = 0;

public:

    Item (string description, int value, string rarity);
//DESTRUCTOR
    virtual ~Item();
    string getShortDescription();
    string getFullDescription();
    int getValue();
    int getTotal();
    string getRarity();

//VIRTUAL FUNCTION
    virtual void setValue(int newValue);
    void setTotal(int newTotal);
    void sumTotal(int value);
};

//INHERITANCE
class Common : public Item {

public:
    Common(string description, int value, string rarity);
    void setValue(int newValue);


};


class Rare : public Item {

public:
    Rare(string description, int value, string rarity);
    void setValue(int newValue);

};


class Unique : public Item {

public:
    Unique(string description, int value, string rarity);
    void setValue(int newValue);


};
#endif /*ITEM_H_*/
