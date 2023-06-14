#include "Controller.h"

Controller::~Controller(){
}

vector<Item> Controller::getItems()
{
	vector<Item> items = repo.getItems();
	sort (items.begin(), items.end(), [](Item& i1, Item& i2) {return i1.getPrice() < i2.getPrice(); });
	return items;
}

vector<string> Controller::getItemsCatogories(){
	vector<string> categories;
	categories.push_back("all");
	for (auto item : repo.getItems()){
		if (find(categories.begin(), categories.end(), item.getCategory()) == categories.end()){
			categories.push_back(item.getCategory());
		}
	}
	return categories;
}

void Controller::addItem(Item item)
{
	repo.addItem(item);
	notify();
}

Controller::Controller(ItemsRepository& repo) : repo(repo) {
}
