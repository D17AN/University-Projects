#include "basket.h"
Basket::Basket() {
	this->basket = new std::vector<TrenchCoat>;
}

Basket::~Basket(){
	delete this->basket;
	this->basket = nullptr;
}

void Basket::add(TrenchCoat& c){
	std::vector<TrenchCoat>& v = *this->basket;
	auto it = std::find_if(v.begin(), v.end(), [&c](TrenchCoat& tc){
		return c == tc;
		});
	
	if (it == v.end()){
		TrenchCoat newTC{c};
		newTC.setQuantity(1);
		this->basket->push_back(newTC);
	}
	else{
		it->setQuantity(it->getQuantity() + 1);
	}
}

std::vector<TrenchCoat>& Basket::get(){
	return *this->basket;
}

int Basket::getTotal(){
	int basketTotal = 0;
	std::vector<TrenchCoat>& v = *this->basket;
	std::for_each(v.begin(), v.end(), [&basketTotal](TrenchCoat& tc){
		basketTotal += tc.getPrice() * tc.getQuantity();
		});

	return basketTotal;
}

