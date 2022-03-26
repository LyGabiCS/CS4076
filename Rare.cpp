#include "item.h"


Rare::Rare(string name, int value, string rarity) : Item( description, value, rarity )
{

}


void Item::setValue(int inValue)
{
    if (inValue > 400 || inValue < 100)
       cout << "value invalid, must be 100 gulden < value < 400 gulden" ;
    else
        value = inValue;
}

