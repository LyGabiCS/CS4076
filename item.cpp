#include "item.h"

Item::Item (string inDescription, int value, string rarity) {
    description = inDescription;
    setValue(value);
    getRarity() = rarity;
}

void Item::setValue(int inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
       value = inValue;
}


string Item::getShortDescription()
{
    return description;
}

string Item::getRarity()
{
    return rarity;
}

