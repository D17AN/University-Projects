#include "controller.h"

ControllerAdministrator::ControllerAdministrator(Repository& repo) : repo{repo} {}


ControllerAdministrator::~ControllerAdministrator(){}


void ControllerAdministrator::add(TrenchCoat& tc){
	this->repo.add(tc);
	this->repo.saveToFile();
}


void ControllerAdministrator::remove(TrenchCoat& tc, int quantity){
	this->repo.remove(tc, quantity);
	this->repo.saveToFile();
}


void ControllerAdministrator::update(TrenchCoat& tc, int newPrice, int newQuantity){
	this->repo.update(tc, newPrice, newQuantity);
	this->repo.saveToFile();
}


std::vector<TrenchCoat>& ControllerAdministrator::get(){
	return this->repo.get();
}


ControllerUser::ControllerUser(Repository& repo, Basket* basket) : repo{repo}, basket{basket} {}


void ControllerUser::setBasket(Basket* b){
	this->basket = b;
}

std::string ControllerUser::getFileName()
{
	return this->basket->getFileName();
}


ControllerUser::~ControllerUser() {}


void ControllerUser::addToBasket(TrenchCoat& tc){
	if (this->basket == nullptr){
		throw RepositoryException{"The basket pointer must point to a valid basket!"};
	}
	this->basket->add(tc);
	this->basket->saveToFile();
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
	if (this->basket == nullptr){
		throw RepositoryException{"The basket pointer must point to a valid basket!"};
	}
	return this->basket->get();
}


int ControllerUser::getBasketTotal(){
	if (this->basket == nullptr){
		throw RepositoryException{"The basket pointer must point to a valid basket!"};
	}
	return this->basket->getTotal();
}




