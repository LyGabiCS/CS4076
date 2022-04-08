#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "Item.h"
#include "Room.h"

#include <vector>

using std::vector;

class Inventory : public Item, public Room
{
private:
	vector <Item> playerInventory;
	int total;


public:
	vector <Item> getPlayerInventory();
	void setPlayerInventory(vector <Item>);

	int getTotal();
	void setTotal(int);

	int collectedMoney(vector <Item>);



};
#endif // !INVENTORY_H_
