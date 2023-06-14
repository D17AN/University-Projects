#pragma once

#include "repository.h"


typedef struct{
	Repository* repo;
}Controller;

/*
* Creates a controller
* Input:
*	- repo: a pointer to a structure of type Repository
* Ouput:
*	return: pointer to a structure of type Controller
*/
Controller* controllerConstructor(Repository* repo);


/*
* Destroys a controller
* Input:
*	- controller: a pointer to a structure of type Controller
* 
* Output:
*	the memory occupied by the Controller is freed
*/
void controllerDestructor(Controller* controller);


/*
* Adds an element in the Controller
* Input:
*	- controller: pointer to a structure of type Controller
*	- e: pointer to a structure of type Medicine
* 
* Output
*	return: 1 if it was successful and the new Controller is formed by the old Controller and the given element, -1 othewise
*/
int controllerAdd(Controller* controller, Medicine* e);


/*
* Removes an element from the controller
* Input:
*	- controller: pointer to a structure of type Controller
*	- e: pointer to a structure of type Medicine
* 
* Output:
*	return: 1 if the deletion is successful, -1 otherwise. If quantity is over 1, quantity will be decremented 
*/
int controllerRemove(Controller* controller, Medicine* e);

/*
* Update an element from the controller
* Input:
*	- controller: pointer to a structure of type Controller
*	- e: pointer to a structure of type Medicine
*	- newQuantity: int, the new quantity of the medicine
*	- newPrice: int, the new price of the medicine
* 
* Ouput:
*	return: 1, the element is found and updated, -1 otherwise
*/
int controllerUpdate(Controller* controller, Medicine* e, int newQuantity, float newPrice);


/*
* Search an element in the Controller
* Input:
*	- controller: pointer to a structure of type Controller
*	- e: pointer to a structure of type Medicine
*  Output:
*	return: a positive integer, being the position of the element if is in the Controller, -1 otherwise
*/
int controllerSearch(Controller* controller, Medicine* e);


/*
* Get the medicines which have in their name a certain substring, if the substring is empty get all the medicines
* Input:
*	- controller: pointer to a structure of type Controller
*	- substr: pointer to a string
* Output:
*	return: a pointer to a structure of type Vector, containing all the matched medicines sorted in ascending order by the name
*/
Vector* controllerFilterNameContainingSubstring(Controller* controller, char* substr);


/*
* Get the medicines which have a quantity smaller than a provided value
* Input:
*	- controller: pointer to a structure of type Controller
*	- x: int, value which the medicines must be smaller than
* Output:
*	return: a pointer to a structure of type Vector, containing all the matched medicines
*/
Vector* controllerFilterQuantityLessThanX(Controller* controller, int x);