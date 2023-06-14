#pragma once
#include "domain.h"
#include "customexcpetion.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>


class Basket{
protected:
	std::vector<TrenchCoat>* basket;
	std::string fileName;

public:
	/*
	* Constructor which initialize the basket with the content of a file
	* @param - fileName: string, the input/output of the basket
	*/
	Basket(const std::string& fileName);

	std::string getFileName();

	/*
	* Gets the basket data
	* Output:
	*	return: type std::vector<TrenchCoat>, a list of coats representing the
	*/
	std::vector<TrenchCoat>& get();

	/*
	* Adds a TrenchCoat in the basket
	* Input:
	*	tc: the TrenchCoat to be added
	* 
	* Ouput:
	*	The TrenchCoat was added in the basket. If the TrenchCoat exists in the basket, 
	*	its quantity is going to be incremented by 1, otherwise 1 TrenchCoat(copy of its) is going to be added 
	*	to the basket.
	*/
	void add(TrenchCoat& tc);

	/*
	* Gets the sum of the products from the basket
	* Output:
	*	return: int, the total sum of TrenchCoats from the basket
	*/
	int getTotal(); 


	/*
	* Overwrites the content of the file with the TrenchCoats from the basket
	*/
	virtual void saveToFile();

	virtual ~Basket();
};


class BasketHTML : public Basket{

public:
	BasketHTML(const std::string& name);

	void saveToFile() override;
};


class BasketCSV : public Basket{
public:
	BasketCSV(const std::string& name);

	void saveToFile() override;
};