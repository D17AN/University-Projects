#include "domain.h"

Building::Building() : address{""}, constructionYear{0} {}

Building::Building(const std::string& _address, const int& _constructionYear) : address{_address}, constructionYear{_constructionYear} {}

Building::Building(const Building& other) : address{other.address}, constructionYear{other.constructionYear} {}

Building::~Building()
{
}

Block::Block() : Building(), totalApartments{0}, occupiedAppartments{0} {}

Block::Block(const std::string& _address, const int& _constructionYear, const int& _totalApartments, const int& _occupiedApartments) : Building(_address, _constructionYear), totalApartments{_totalApartments}, occupiedAppartments{_occupiedApartments} {}

Block::Block(const Block& other) : Building()
{
	this->address.assign(other.address);
	this->constructionYear = other.constructionYear;
	this->totalApartments = other.totalApartments;
	this->occupiedAppartments = other.occupiedAppartments;
}

bool Block::mustBeRestored() const
{
	return 2023 - this->constructionYear >= 40 && float(this->totalApartments * 0.8) <= float(this->occupiedAppartments);
}

bool Block::canBeDemolished() const
{
	return float(this->totalApartments * 0.05) >= this->occupiedAppartments;
}

std::string Block::toString() const
{
	return this->address + "|" + std::to_string(this->constructionYear) + "|" + std::to_string(this->totalApartments) + "|" +
		std::to_string(this->occupiedAppartments);
}

Block::~Block()
{
}

House::House() : Building(), isHistorical{false} {}

House::House(const std::string& _address, const int& _constructionYear, const bool& _isHistorical) : Building(_address, _constructionYear), isHistorical{_isHistorical}{}

House::House(const House& other) : Building()
{
	this->address.assign(other.address);
	this->constructionYear = other.constructionYear;
	this->isHistorical = other.isHistorical;
}

bool House::mustBeRestored() const
{
	return 2023 - this->constructionYear >= 100;
}

bool House::canBeDemolished() const
{
	return !isHistorical;
}

std::string House::toString() const
{
	return this->address + "|" + std::to_string(this->constructionYear) + "|" + std::to_string(this->isHistorical);
}

House::~House()
{
}
