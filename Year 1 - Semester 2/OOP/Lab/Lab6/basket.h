#pragma once
#include "domain.h"
#include <vector>
#include <algorithm>

class Basket{
private:
	std::vector<TrenchCoat>* basket;

public:
	/*
	* Default constructor for basket
	* Output:
	*	Creates an instance of type basket
	*/
	Basket();

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


	~Basket();
};

