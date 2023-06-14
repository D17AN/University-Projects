#include "controller.h"

ControllerAdministrator::ControllerAdministrator(Repository& repo) : repo{repo} {}


ControllerAdministrator::~ControllerAdministrator(){}


void ControllerAdministrator::add(TrenchCoat& tc){
	this->repo.add(tc);
}


void ControllerAdministrator::remove(TrenchCoat& tc, int quantity){
	this->repo.remove(tc, quantity);
}


void ControllerAdministrator::update(TrenchCoat& tc, int newPrice, int newQuantity){
	this->repo.update(tc, newPrice, newQuantity);
}


Vector<TrenchCoat>& ControllerAdministrator::get(){
	return this->repo.get();
}


ControllerUser::ControllerUser(Repository& repo, Basket& basket) : repo{repo}, basket{basket} {}


ControllerUser::~ControllerUser() {}


void ControllerUser::addToBasket(const TrenchCoat& tc){
	this->basket.add(tc);
}


Vector<TrenchCoat> ControllerUser::getRepo(const std::string& size){
	Vector<TrenchCoat> v = this->repo.get();
	if (size == ""){
		return v;
	}

	Vector<TrenchCoat> res;
	int len = v.getSize();
	for (int i = 0; i < len; i++){
		if (v[i].getSize() == size){
			TrenchCoat tc = v[i];
			res.add(tc);
		}
	}

	return res;
}


Vector<TrenchCoat>& ControllerUser::getBasket(){
	return this->basket.get();
}


int ControllerUser::getBasketTotal(){
	return this->basket.getTotal();
}




