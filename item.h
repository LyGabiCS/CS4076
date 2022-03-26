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
private:

    string description;
    string fullDescription;
    int value = 0;
    string rarity;
    int total = 0;

public:

    Item (string description, int value, string rarity);
    string getShortDescription();
    string getFullDescription();
    int getValue();
    int getTotal();
    string getRarity();
    void setValue(int newValue);
    void setTotal(int newTotal);
    void sumTotal(int value);
};

#endif /*ITEM_H_*/
