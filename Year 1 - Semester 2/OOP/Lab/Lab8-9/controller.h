#pragma once

#include "repository.h"
#include "basket.h"

class ControllerAdministrator{
private:
	Repository& repo;

public:
	/*
	* ControllerAdministrator Constructor. Links to a controller an existing repository
	* Input:
	*	- repo: type Repository, the repository to be linked with
	* Output:
	*	An object of type ControllerAdministrator has been instantied
	*/
	ControllerAdministrator(Repository& repo);


	/*
	* Deconstructor ControllerAdministrator
	* Output:
	*	the memory occupied by the instance has been deallocated
	*/
	~ControllerAdministrator();

	
	/*
	* Add a TrenchCoat in the repository of the current controller
	* Input:
	*	- tc: type TrenchCoat, the object to be added
	*
	* Output:
	*	if the instance already exists, then its quantity will be updated by adding the provided quantity to the current quantity, otherwise the TrenchCoat will be added
	*/
	void add(TrenchCoat& tc);


	/*
	* Remove a TrenchCoat from repository of the current controller
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
	*/
	void remove(TrenchCoat& tc, int quantity);

	
	/*
	* Update a given TrenchCoat from the repository of the current controller
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
	*	return: the Vector of TrenchCoats from repository of the current controller
	*/
	std::vector <TrenchCoat>& get();
	
};


class ControllerUser{
private:
	Repository& repo;
	Basket* basket;

public:
	ControllerUser(Repository& repo, Basket* basket);
	
	void setBasket(Basket* b);

	std::string getFileName();

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
	void addToBasket(TrenchCoat& tc);

	/*
	* Get all the TrenchCoats from the repository
	* Input:
	*	size: type string, the size of the TrenchCoats to get, if empty all will be considered
	* 
	* Output:
	*	return: type Vector<TrenchCoat> the list of TrenchCoats with the given size from the Repository
	*/
	std::vector<TrenchCoat> getRepo(const std::string& size);


	/*
	* Get the TrenchCoats from the basket
	* Output:
	*	return: type Vector<TrenchCoat>, a list with all TrenchCoats from the basket
	*/
	std::vector<TrenchCoat>& getBasket();


	/*
	* Gets the the total sum of the products from the basket
	* Ouput:
	*	return: int, the total value of the basket
	*/
	int getBasketTotal();


	~ControllerUser();
	
};