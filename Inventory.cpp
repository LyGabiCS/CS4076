#include "Inventory.h"


vector<Item> Inventory::getPlayerInventory()
{
	return this->playerInventory;
}

void Inventory::setPlayerInventory(vector <Item> v)
{
	playerInventory = v;
}

int Inventory::getTotal()
{
	return this->total;
}

void Inventory::setTotal(int i)
{
	total = i;
}

int Inventory::collectedMoney(vector<Item> v)
{
	int g = 0;
	for (int i = 0; i < v.size(); i++) 
	{
		g += v[i].getValue();
		return g;
	}
}
