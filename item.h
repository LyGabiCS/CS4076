#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

// Each Item will have a name, value and rarity.
// Name of each item will be used in the inventory section
// Value of each item will be added up to the grand total
// Rarity of each item will determine which wordle the player will do!

class Item {
private:
    string description;
    int value;
    string rarity;

public:
    Item (string description, int value, string rarity);
    string getShortDescription();
    string getRarity();
    int getWeight();
    void setWeight(int weightGrams);
    float getValue();
    void setValue(int value);
};

#endif /*ITEM_H_*/
