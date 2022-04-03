#include "item.h"
#include "Room.h"

//ITEM CLASS DEFINITIONS
Item::Item (string inDescription, int inValue, string inRarity) {
    description = inDescription;
    value = inValue;
    rarity = inRarity;
}

void Item::setValue(int inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
       value = inValue;
}

int Item::getValue() {
    return value;
}


string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}

string Item::getRarity()
{
    return rarity;
}

void Item::setRarity(string itemRarity)
{
    rarity = itemRarity;
}

string Item::printOutVector()
{
    return "base";
}

// REQUIREMENT TEMPLATE FUNCTION = DONE
template <typename T>
T addToVector(vector <T> pickedItems, T item) {
    pickedItems.push_back(item);
}


// COMMON CLASS DEFINITIONS
Common::Common(string name, int value, string rarity) : Item(name, value, rarity)
{

}


string Common::printOutVector()
{
    return "animal";
}



// RARE CLASS DEFINITIONS
Rare::Rare(string name, int value, string rarity) : Item(name, value, rarity)
{

}

string Rare::printOutVector()
{
    return "table";
}


// UNIQUE CLASS DEFINITIONS
Unique::Unique(string name, int value, string rarity) : Item(name, value, rarity)
{

}

string Unique::printOutVector()
{
    return "whatever";
}
