#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>

//make a template for thid vector TEMPLATE FUNCTION DONE!
using namespace std;
using std::string;


//REQUIREMENT ABSTRACT CLASS DONE

class Item {

private:
    //name of item
    string description;
    //outputs a formatted string with all the details
    string longDescription;
    //monetary value
    int value;
    //displays its rarity
    string rarity;
    // the total money collected for every item picked
    int total;

public:
     static vector <Item> pickedUp;
    Item (string , int , string );
    string getShortDescription();
    string getLongDescription();
    int getValue();
    void setValue(int);
    string getRarity();
    void setRarity(string);
    // THESE 2 WILL BE IN ZORKUL
    //void addToTotal(int);
    //void findTotal();
    //  REQUIREMENT VIRTUAL FUNCTION = DONE
    virtual string printOutVector();
};

// I will make ZorkUL friend to each subclass so it can access protected and private members
// REQUIREMENT FRIENDSHIP = DONE

// COMMON ITEMS
class Common : public Item
{
    friend class ZorkUl;
public:
    Common(string, int, string);
    string printOutVector();

};

// RARE ITEMS
class Rare : public Item
{
    friend class ZorkUL;
public:
    Rare(string, int, string);
    string printOutVector();
};

// UNIQUE ITEMS
class Unique : public Item
{
    friend class ZorkUL;
public:
    Unique(string, int, string);
    string printOutVector();
};

#endif /*ITEM_H_*/
