#include "domain.h"

Car::Car(const std::string& name, const std::string& model, int year, const std::string& colour) : name{name}, model{model}, year{year}, colour{colour} {}

Car::Car(const Car& other){
	this->name.assign(other.name);
	this->model.assign(other.model);
	this->colour.assign(other.colour);
	this->year = other.year;
}

bool Car::operator==(const Car& other)const{
	return this->model == other.model && this->year == other.year;
}

std::ostream& operator<<(std::ostream& os, const Car& c){
	os << c.name << "|" << c.model << "|" << c.year << "|" << c.colour;
	return os;
}
