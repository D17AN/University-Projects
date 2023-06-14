#include "repository.h"


Repository::Repository(){
	this->vector = new Vector<TrenchCoat>;
}


Repository::Repository(const std::string& sourceFile){
	this->vector = new Vector<TrenchCoat>;
	std::ifstream file{sourceFile};
	try{
		if (!file.is_open()){
			throw RepositoryException("File could not be opened!");
		}

		TrenchCoat tc;
		while (!file.eof()){
			file >> tc;
			this->vector->add(tc);
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
	this->vector = new Vector<TrenchCoat>;
	*this->vector = *other.vector;
}


void Repository::add(TrenchCoat& tc){
	bool found = false;
	int size = this->vector->getSize();
	Vector<TrenchCoat>& v = this->vector->get();
	for (int i = 0; i < size; i++){
		if (v[i] == tc){
			found = true;
			v[i].setQuantity(v[i].getQuantity() + tc.getQuantity());
			break;
		}
	}
	if (!found){
		this->vector->add(tc);
	}
}


void Repository::remove(TrenchCoat& tc, int quantity){
	bool found = false;
	int size = this->vector->getSize();
	Vector<TrenchCoat>& v = this->vector->get();
	for (int i = 0; i < size; i++){
		if (v[i] == tc){
			found = true;
			if (v[i].getQuantity() > quantity){
				v[i].setQuantity(v[i].getQuantity()  - quantity);
			}
			else{
				this->vector->removePosition(i);
			}
			break;
		}
	}

	if (!found){
		throw RepositoryException("The TrenchCoat to be deleted doesn't exists!");
	}
}


void Repository::update(TrenchCoat& tc, int newPrice, int newQuantity){
	bool found = false;
	int size = this->vector->getSize();
	Vector<TrenchCoat>& v = this->vector->get();
	for (int i = 0; i < size; i++){
		if (v[i] == tc){
			found = true;
			v[i].setPrice(newPrice);
			v[i].setQuantity(newQuantity);
			break;
		}
	}

	if (!found){
		throw RepositoryException("The TrenchCoat to be updated doesn't exists!");
	}

		
}


Vector<TrenchCoat>& Repository::get(){
	return this->vector->get();
}