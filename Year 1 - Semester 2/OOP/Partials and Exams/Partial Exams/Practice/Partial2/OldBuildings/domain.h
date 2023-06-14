#pragma once

#include <string>
#include <ostream>

class Building{
protected:
	std::string address;
	int constructionYear;

public:
	Building();
	Building(const std::string& _address, const int& _constructionYear);
	Building(const Building& other);
	virtual bool mustBeRestored()const = 0;
	virtual bool canBeDemolished()const = 0;
	virtual std::string toString()const = 0;
	int getConstructionYear()const{ return this->constructionYear; };
	virtual ~Building();
};


class Block : public Building{
private:
	int totalApartments;
	int occupiedAppartments;

public:
	Block();
	Block(const std::string& _address, const int& _constructionYear, const int& _totalApartments, const int& _occupiedApartments);
	Block(const Block& other);
	bool mustBeRestored()const override;
	bool canBeDemolished()const override;
	std::string toString()const override;
	~Block();
};


class House : public Building{
private:
	bool isHistorical;

public:
	House();
	House(const std::string& _address, const int& _constructionYear, const bool& _isHistorical);
	House(const House& other);
	bool mustBeRestored()const override;
	bool canBeDemolished()const override;
	std::string toString()const override;
	~House();
};