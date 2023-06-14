#pragma once

#include "ItemsRepository.h"
#include "Subject.h"
#include <algorithm>
#include <iterator>


class Controller : public Subject
{
	ItemsRepository& repo;

	public:
		Controller(ItemsRepository& repo);
		~Controller();

		vector<Item> getItems();
		vector<string> getItemsCatogories();
		void addItem(Item item);
		
};
