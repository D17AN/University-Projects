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


std::vector<TrenchCoat>& ControllerAdministrator::get(){
	return this->repo.get();
}


ControllerUser::ControllerUser(Repository& repo, Basket& basket) : repo{repo}, basket{basket} {}


ControllerUser::~ControllerUser() {}


void ControllerUser::addToBasket(TrenchCoat& tc){
	this->basket.add(tc);
}


std::vector<TrenchCoat> ControllerUser::getRepo(const std::string& size){
	std::vector<TrenchCoat>& v = this->repo.get();
	if (size == ""){
		return v;
	}

	std::vector<TrenchCoat> res;

	std::for_each(v.begin(), v.end(), [&size, &res](TrenchCoat& tc){
			if (tc.getSize() == size){
				TrenchCoat newTC = tc;
				res.push_back(newTC);
			}
		});

	return res;
}


std::vector<TrenchCoat>& ControllerUser::getBasket(){
	return this->basket.get();
}


int ControllerUser::getBasketTotal(){
	return this->basket.getTotal();
}




