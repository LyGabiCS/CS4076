#include "item.h"


// Constructor, can specify name, monetary value and its rarity
Item::Item (string inDescription, int value, string inRarity) {
    description = inDescription;
    setValue(value);
    rarity = inRarity;
}

//setter for value
void Item::setValue(int inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
        value = inValue;
}

//The grand total after the player picks up their items. Will be used for the progress bar
void Item::sumTotal(int value)
{
    int total = getTotal();
    total += value;

}
//getter for the item name
string Item::getShortDescription()
{
    return description;
}
//getter for a string consisting of the item's attricbutes
string Item::getFullDescription()
{
    return description + ", " + to_string(value) +" gulden, " + rarity;
}

//getter for the total
int Item::getTotal()
{
    return total;
}

//getter for the item rarity
string Item::getRarity()
{
    return rarity;
}

