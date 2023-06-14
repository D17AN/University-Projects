#pragma once
#include <string>
#include <ostream>

class Car{
private:
	std::string name, model, colour;
	int year;
public:
	Car() : name{""}, model{""}, colour{""}, year{0} {};
	Car(const std::string& name, const std::string& model, int year, const std::string& colour);
	Car(const Car& other);
	bool operator==(const Car& other)const;
	friend std::ostream& operator<<(std::ostream& os, const Car& c);
	std::string getName()const{ return this->name; }
	std::string getModel()const{ return this->model; }
	std::string getColour()const{ return this->colour; }
	int getYear()const{ return this->year; }

};