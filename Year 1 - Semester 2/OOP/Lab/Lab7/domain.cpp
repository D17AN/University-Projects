#include "domain.h"


TrenchCoat::TrenchCoat() : size{""}, color{""}, price{0}, quantity{0}, photographLink{""}{}


TrenchCoat::TrenchCoat(const std::string& size, const std::string& color, const int& price, const int& quantity, const std::string& photographLink){
	this->size = size;
	this->color = color;
	this->price = price; // keeping only 2 decimals
	this->quantity = quantity;
	this->photographLink = photographLink;
}


TrenchCoat::TrenchCoat(const TrenchCoat& tc){
	this->size.assign(tc.size);
	this->color.assign(tc.color);
	this->price = tc.price;
	this->quantity = tc.quantity;
	this->photographLink.assign(tc.photographLink);
}


std::string TrenchCoat::getSize(){
	return this->size;
}


std::string TrenchCoat::getColor(){
	return this->color;
}


int TrenchCoat::getPrice(){
	return this->price;
}


int TrenchCoat::getQuantity(){
	return this->quantity;
}


std::string TrenchCoat::getPhotographLink(){
	return this->photographLink;
}


void TrenchCoat::setPrice(const int& newPrice){
	this->price = newPrice;
}


void TrenchCoat::setQuantity(const int& newQuantity){
	this->quantity = newQuantity;
}


bool TrenchCoat::operator==(const TrenchCoat& tc){
	return this->size == tc.size && this->color == tc.color && this->photographLink == tc.photographLink;
}


bool TrenchCoat::operator!=(const TrenchCoat& tc){
	return this->size != tc.size || this->color != tc.color || this->photographLink != tc.photographLink;
}


TrenchCoat& TrenchCoat::operator=(const TrenchCoat& tc){
	if (this == &tc){
		return *this;
	}
	this->size.assign(tc.size);
	this->color.assign(tc.color);
	this->price = tc.price;
	this->quantity = tc.quantity;
	this->photographLink = tc.photographLink;
	return *this;
}


std::ostream& operator<<(std::ostream& os, const TrenchCoat& tc){
	os << tc.size << "|" << tc.color << "|" << tc.price << "|" << tc.quantity << "|" << tc.photographLink;
	return os;
}


std::istream& operator>>(std::istream& is, TrenchCoat& tc){
	return tc.read(is);
}


std::istream& TrenchCoat::read(std::istream& is){
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	if (tokens.size() != 5){
		throw TrenchCoatException("Not enough fields, 5 fields are requiered!");
	}

	std::string size, color, photographLink;
	int price;
	int quantity;
	
	size = tokens[0];
	color = tokens[1];
	photographLink = tokens[4];

	//price conversion
	try{
		price = std::stoi(tokens[2]);
	}
	catch (std::invalid_argument& e){
		throw TrenchCoatException("Illegal conversion! The price must be an int number!");
	}
	catch (std::out_of_range& e){
		throw TrenchCoatException("Value of price out of the data type range!");
	}

	//quantity conversion
	try{
		quantity = std::stoi(tokens[3]);
	}
	catch (std::invalid_argument& e){
		throw TrenchCoatException("Illegal conversion! The quantity must be an int number!");
	}
	catch (std::out_of_range& e){
		throw TrenchCoatException("Value of quantity out of the data type range!");
	}
	
	//validation stuff
	bool errorOccured = false;
	std::string validationErrors = "\n";
	if (TrenchCoatValidator::isSizeValid(size) == false){
		validationErrors += "Invalid size! The size must be s, m, l, or xl.\n";
		errorOccured = true;
	}
	if (TrenchCoatValidator::isColorValid(color) == false){
		validationErrors += "Invalid color!\n";
		errorOccured = true;
	}
	if (TrenchCoatValidator::isPriceValid(price) == false){
		validationErrors += "Invalid price! The price must be a positive number.\n";
		errorOccured = true;
	}
	if (TrenchCoatValidator::isQuantityValid(quantity) == false){
		validationErrors += "Invalid quantity! The quantity must be a positive integer.\n";
		errorOccured = true;
	}
	if (TrenchCoatValidator::isPhotographLinkValid(photographLink) == false){
		validationErrors += "Invalid photograph link\n";
		errorOccured = true;
	}

	if (errorOccured){
		throw TrenchCoatException(validationErrors);
	}

	this->size = size;
	this->color = color;
	this->price = price;
	this->quantity = quantity;
	this->photographLink = photographLink;

	return is;
}


TrenchCoat::~TrenchCoat(){
}


bool TrenchCoatValidator::isSizeValid(const std::string& size){
	if (size == "s"){
		return true;
	} else if (size == "m"){
		return true;
	} else if (size == "l"){
		return true;
	} else if (size == "xl"){
		return true;
	}
	return false;
}


bool TrenchCoatValidator::isColorValid(const std::string& color){
	if (color == "")
		return false;
	return true;
}


bool TrenchCoatValidator::isPriceValid(const int& price){
	if (price >= 0)
		return true;
	return false;
}


bool TrenchCoatValidator::isQuantityValid(const int& quantity){
	if (quantity >= 0)
		return true;
	return false;
}


bool TrenchCoatValidator::isPhotographLinkValid(const std::string& photographLink){
	if (photographLink == "")
		return false;
	return true;
}