#include "basket.h"

Basket::Basket(const std::string& fileName) : fileName{fileName}{
	this->basket = new std::vector<TrenchCoat>;
}

std::string Basket::getFileName(){
	return this->fileName;
}

Basket::~Basket(){
	delete this->basket;
	this->basket = nullptr;
}

void Basket::add(TrenchCoat& c){
	std::vector<TrenchCoat>& v = *this->basket;
	auto it = std::find_if(v.begin(), v.end(), [&c](TrenchCoat& tc){
		return c == tc;
		});
	
	if (it == v.end()){
		TrenchCoat newTC{c};
		newTC.setQuantity(1);
		this->basket->push_back(newTC);
	}
	else{
		it->setQuantity(it->getQuantity() + 1);
	}
}

std::vector<TrenchCoat>& Basket::get(){
	return *this->basket;
}

int Basket::getTotal(){
	int basketTotal = 0;
	std::vector<TrenchCoat>& v = *this->basket;
	std::for_each(v.begin(), v.end(), [&basketTotal](TrenchCoat& tc){
		basketTotal += tc.getPrice() * tc.getQuantity();
		});

	return basketTotal;
}

void Basket::saveToFile(){
	if (this->fileName == ""){
		throw RepositoryException{"The basket hasn't been initialized with a file!"};
	}
	std::fstream file{this->fileName, std::ios::out | std::ios::trunc};

	if (!file.is_open()){
		throw RepositoryException{"The file couldn't been opened!"};
	}

	std::for_each(this->basket->begin(), this->basket->end(), [&](TrenchCoat& tc){
		if (&this->basket->back() != &tc){
			file << tc << "\n";
		}
		else{
			file << tc;
		}
		});
}

BasketHTML::BasketHTML(const std::string& fileName) : Basket{fileName}{}


void BasketHTML::saveToFile()
{
	std::fstream file{this->fileName, std::ios::out | std::ios::trunc};
	if (!file.is_open()){
		throw RepositoryException{"The file couldn't be opened!"};
	}

	file << "<!DOCTYPE html>" << "\n";
	file << "<html>" << "\n";
	file << "<head>" << "\n";
	file << "<title>Basket List</title>" << "\n";
	file << "</head>" << "\n";
	file << "<body>" << "\n";
	file << "<table style=\"border: 1px solid black;\">" << "\n";
	file << "<tr>" << "\n";
	file << "<td style=\"border: 1px solid black;\">Size</td>" << "\n";
	file << "<td style=\"border: 1px solid black;\">Colour</td>" << "\n";
	file << "<td style=\"border: 1px solid black;\">Price</td>" << "\n";
	file << "<td style=\"border: 1px solid black;\">Quantity</td>" << "\n";
	file << "<td style=\"border: 1px solid black;\">Link</td>" << "\n";
	file << "</tr>" << "\n";
	std::for_each(this->basket->begin(), this->basket->end(), [&file](TrenchCoat& tc){
		file << "<tr>" << "\n";
		file << "<td style=\"border: 1px solid black;\">" << tc.getSize() << "</td>" << "\n";
		file << "<td style=\"border: 1px solid black;\">" << tc.getColor() <<"</td>" << "\n";
		file << "<td style=\"border: 1px solid black;\">" << tc.getPrice() << "</td>" << "\n";
		file << "<td style=\"border: 1px solid black;\">" << tc.getQuantity() << "</td>" << "\n";
		file << "<td style=\"border: 1px solid black;\">" << "<a href=\"" << tc.getPhotographLink()  << "\">" << tc.getPhotographLink() << "</td>" << "\n";
		file << "</tr>" << "\n";
		});
	file << "</table></body></html>";
	file.close();
}


BasketCSV::BasketCSV(const std::string& name) : Basket(name) {}


void BasketCSV::saveToFile(){
	std::fstream file{this->fileName, std::ios::out | std::ios::trunc};
	if (!file.is_open()){
		throw RepositoryException{"The file couldn't be opened!"};
	}
	std::for_each(this->basket->begin(), this->basket->end(), [&file](TrenchCoat& tc){
		file << tc << "\n";
		});
	file.close();
}
