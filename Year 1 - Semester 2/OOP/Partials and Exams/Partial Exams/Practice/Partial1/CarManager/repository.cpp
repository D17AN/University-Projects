#include "repository.h"

const std::vector<Car>& Repository::get() const{
	return this->v;
}

int Repository::search(const Car& c){
	auto it = std::find_if(this->v.begin(), this->v.end(), [&c](const Car& other){
		return c == other;
		});
	if(it == this->v.end())
		return -1;
	return it - v.begin();
}


void Repository::add(const Car& c){
	int i = this->search(c);
	if (i == -1){
		return this->v.push_back(c);
	}
	else{
		throw std::exception("The element already exists!");
	}
}

void Repository::remove(const Car& c){
	int i = this->search(c);
	if (i == -1){
		throw std::exception("The element doesn't exists!");
	}
	else{
		auto it = std::remove_if(this->v.begin(), this->v.end(), [&c](const Car& other){
			return c == other;
			});
		
		v.erase(it, v.end());
	}
}
