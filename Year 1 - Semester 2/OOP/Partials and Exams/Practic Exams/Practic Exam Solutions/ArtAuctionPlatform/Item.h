#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include "Offer.h"
using namespace std;

class Item{
private:
	string name, category;
	int price;
	vector<Offer> offers;

public:
	Item() : name{""}, category{""}, price{0}{}
	Item(string name, string category, int price) : name{name}, category{category}, price{price}{}
	Item(const Item& other) : name{other.name}, category{other.category}, price{other.price}{}

	void setName(string name){this->name = name;}
	void setCategory(string category){this->category = category;}
	void setPrice(int price){this->price = price;}
	void setOffers(vector<Offer> offers){this->offers = offers;}

	string getName() const{return this->name;}
	string getCategory() const{return this->category;}
	int getPrice() const{return this->price;}
	vector<Offer> getOffers()const {return this->offers;}

	string toString() const;

	friend ostream& operator<<(ostream& os, const Item& i);
	friend istream& operator>>(istream& is, Item& i);
};