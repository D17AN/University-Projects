#include "basket.h"

Basket::Basket() {}

Basket::~Basket(){}

void Basket::add(const TrenchCoat& c){
	//my responsabilty c is to have its quantity set to 1 when creating it
	bool found = false;
	int size = this->basket.getSize();
	for (int i = 0; i < size; i++){
		if (this->basket[i] == c){
			found = true;
			this->basket[i].setQuantity(this->basket[i].getQuantity() + 1);
			break;
		}
	}

	if (!found){
		TrenchCoat newTC{c}; //creating a copy of the coat
		newTC.setQuantity(1); //setting its quantity to 1
		this->basket.add(newTC);
	}
}

Vector<TrenchCoat>& Basket::get(){
	return this->basket;
}

int Basket::getTotal(){
	int basketTotal = 0;
	int size = this->basket.getSize();
	for (int i = 0; i < size; i++){
		basketTotal += this->basket[i].getQuantity() * this->basket[i].getPrice();
	}
	return basketTotal;
}

