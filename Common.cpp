#include "item.h"


Common::Common(string name, int value, string rarity) : Item( description, value, rarity )
{

}

void Item::setValue(int inValue)
{
    if (inValue > 100 || inValue < 0)
       cout << "value invalid, must be 0 gulden < value < 100 gulden" ;
    else
        value = inValue;
}
