#include "item.h"
#include <iostream>
using namespace std;

//INITIALIZER LIST
Item::Item(string name, int value, string rarity)
    : name{ name }, value{ value }, rarity{rarity}
{

}
//DESTRUCTOR
Item::~Item()
{
    delete this;
}

string Item::getName()
{
    return this->name;
}

int Item::getValue()
{
    return this->value;
}

string Item::getRarity()
{
    return this->rarity;
}

void Item::setName(string newName)
{
    name = newName;
}
void Item::setValue(int newValue)
{
    value = newValue;
}
void Item::setRarity(string newRarity)
{
    rarity = newRarity;
}

bool Item::operator==(Item i)
{
    if (this->getName() == i.getName())
    {
        return true;
    }
    else
    {
        return false;
    }
}



Common::Common(string name, int value, string rarity) : Item(name, value, rarity)
{
}

void Common::setValue(int inValue)
{

    if (inValue > 100 || inValue < 1)
       cout << "Common Items are worth between 1 and 100 guldens";
    else
       value = inValue;
}




Rare::Rare(string name, int value, string rarity) : Item(name, value, rarity)
{

}

void Rare::setValue(int inValue)
{

    if (inValue > 400 || inValue < 100)
       cout << "Rare Items are worth between 100 and 400 guldens";
    else
       value = inValue;
}




Unique::Unique(string name, int value, string rarity) : Item(name, value, rarity)
{

}
void Unique::setValue(int inValue)
{

    if (inValue > 1000 || inValue < 400)
       cout << "Rare Items are worth between 100 and 400 guldens";
    else
       value = inValue;
}


