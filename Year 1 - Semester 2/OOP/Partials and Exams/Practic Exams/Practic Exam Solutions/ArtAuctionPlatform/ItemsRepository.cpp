#include "ItemsRepository.h"

ItemsRepository::ItemsRepository()
{
	loadFromFile();
}

ItemsRepository::~ItemsRepository()
{
	saveToFile();
}

void ItemsRepository::addItem(const Item& item)
{
	this->items.push_back(item);
}

vector<Item>& ItemsRepository::getItems()
{
	return this->items;
}

void ItemsRepository::loadFromFile()
{
	fstream fin("items.txt", std::ios::in);
	Item item;
	while (fin >> item) {
		if (item.getName() != "") {
			this->items.push_back(item);
		}
	}
	fin.close();
}

void ItemsRepository::saveToFile()
{
	fstream fout("items.txt", std::ios::out | std::ios::out);
	for (auto& item : this->items) {
		fout << item << endl;
	}
	fout.close();
}
