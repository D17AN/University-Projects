#pragma once
#include "Item.h"
#include <string>
#include <fstream>

class ItemsRepository
{
	vector<Item> items;
public:
	ItemsRepository();
	~ItemsRepository();
	void addItem(const Item& item);
	vector<Item>& getItems();

private:
	void loadFromFile();
	void saveToFile();
};