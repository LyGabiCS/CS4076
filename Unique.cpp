#include "item.h"

using std::string;


Unique::Unique(string name, int value, string rarity) : Item( description, value, rarity )
{

}


void Item::setValue(int inValue)
{
    if (inValue < 400)
       cout << "value invalid, must be > 400 gulden" ;
    else
        value = inValue;
}
