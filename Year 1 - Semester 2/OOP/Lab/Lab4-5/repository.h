#pragma once
#include "domain.h"
#include "vector.h"
#include "customexcpetion.h"
#include <fstream>

class Repository{
private:
	 Vector<TrenchCoat>* vector;

public:

	/*
	* Default constructor
	* Output:
	*	creates an instance of type Repository
	*/
	Repository();


	/*
	* Constructor
	* Load a repository with TrenchCoats
	* Input:
	*	source: type string, represents a file from where to load data
	* Output:
	*	The data of the current instance is going to be initialized with the data of the file version
	*/
	Repository(const std::string& sourceFile);


	/*
	* Copy constructor
	* Input:
	*	- other: type Repository, the instance from where is going to be copied
	* Ouptut
	*	the current instance is going to have its attributes set to other
	*/
	Repository(const Repository& other);


	/*
	* Destructor
	* Output:
	*	the memory occupied by the instance has been deallocated
	*/
	~Repository();

	/*
	* Add a TrenchCoat in the repository
	* Input:
	*	- tc: type TrenchCoat, the object to be added
	* 
	* Output:
	*	if the instance already exists, then its quantity will be updated by adding the provided quantity to the current quantity, otherwise the TrenchCoat will be added
	*/
	void add(TrenchCoat& tc);


	/*
	* Remove a TrenchCoat from repository
	* Input:
	*	- tc: type TrenchCoat, the TrenchCoat to be removed
	*	- quantity: type int, how many items to be removed
	* 
	* Output:
	*	if the given quantity is bigger or equal than the quantity of TrenchCoats, than the 
	*	TrenchCoat is going to be deleted from memory, otherwise the given quantity is going to 
	*	be substracted from the total quantity of TrenchCoats. If the TrenchCoat doesn't exist 
	*	an error is thrown.
	* 
	* Exceptions: RepositoryException
	*	
	*/
	void remove(TrenchCoat& tc, int quantity);


	/*
	* Update a given TrenchCoat from the repository
	* Input:
	*	- tc: type TrenchCoat, the entity to be updated
	*	- newPrice: type int, the new price of the TrenchCoat
	*	- newQuantity: type int, the new quantity of TrenchCoat
	* 
	* Ouput:
	*	the given TrenchCoat from the repository is going to have its price and quantity 
	*	updated to the provided ones. If the TrenchCoat doesn't exist an error is thrown.
	* 
	* Exceptions: RepositoryException
	*/
	void update(TrenchCoat& tc, int newPrice, int newQuantity);


	/*
	* Gets a vector of TrenchCoats
	* Output:
	*	return: the Vector of TrenchCoats from the repository
	*/
	Vector<TrenchCoat>& get();
};