#include "repository.h"


Repository::Repository(){
	this->vector = new std::vector<TrenchCoat>;
}


Repository::Repository(const std::string& sourceFile){
	this->vector = new std::vector<TrenchCoat>;
	std::ifstream file{sourceFile};
	try{
		if (!file.is_open()){
			throw RepositoryException("File could not be opened!");
		}

		TrenchCoat tc;
		while (!file.eof()){
			file >> tc;
			this->vector->push_back(tc);
		}
		file.close();
	}
	catch (TrenchCoatException& e){
		file.close();
		throw RepositoryException{"Couldn't load from file " + sourceFile + "\n" + std::string{e.what()}};
	}

}


Repository::~Repository(){
	delete this->vector;
	this->vector = nullptr;
}


Repository::Repository(const Repository& other){
	this->vector = new std::vector<TrenchCoat>;
	*this->vector = *other.vector;
}


void Repository::add(TrenchCoat& tc){
	std::vector<TrenchCoat>& v = *this->vector;

	auto it = std::find_if(v.begin(), v.end(), [&tc](const TrenchCoat& c){
		return tc == c;
		});
	//if the element exist
	if (it != v.end()){
		it->setQuantity(it->getQuantity() + tc.getQuantity());
	}
	else{
		v.push_back(tc);
	}
}


void Repository::remove(TrenchCoat& tc, int quantity){
	int size = this->vector->size();
	std::vector<TrenchCoat>& v = *this->vector;
	bool found = false;
	//move at the end the coats which are equal with the given coat 
	auto it = std::remove_if(v.begin(), v.end(), [&tc, &quantity, &found](TrenchCoat& c){
		if (tc == c && tc.getQuantity() > quantity){
			c.setQuantity(c.getQuantity() - quantity);
			found = true;
			return false;//the element won't be deleted, but its quantity is decremented
		}
		else if (tc == c){
			return found = true;
		}
		else{
			return false;
		}

		});
	
	//if the element doesn't exist 
	if (found == false){
		throw RepositoryException("The TrenchCoat to be deleted doesn't exists!");
	}

	//remove all the elements equal with tc
	v.erase(it, v.end());
}


void Repository::update(TrenchCoat& tc, int newPrice, int newQuantity){
	std::vector<TrenchCoat>& v = *this->vector;

	auto it = std::find_if(v.begin(), v.end(), [&tc](TrenchCoat& c){
		return tc == c;
		});

	if (it == v.end()){
		throw RepositoryException("The TrenchCoat to be updated doesn't exists!");
	}

	it->setPrice(newPrice);
	it->setQuantity(newQuantity);
}


std::vector<TrenchCoat>& Repository::get(){
	return *this->vector;
}