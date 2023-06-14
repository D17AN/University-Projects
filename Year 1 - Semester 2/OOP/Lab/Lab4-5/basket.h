#pragma once
#include "vector.h"
#include "domain.h"

class Basket{
private:
	Vector<TrenchCoat> basket;

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
	*	return: type Vector<TrenchCoat>, a list of coats representing the
	*/
	Vector<TrenchCoat>& get();

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
	void add(const TrenchCoat& tc);

	/*
	* Gets the sum of the products from the basket
	* Output:
	*	return: int, the total sum of TrenchCoats from the basket
	*/
	int getTotal(); 


	~Basket();
};

