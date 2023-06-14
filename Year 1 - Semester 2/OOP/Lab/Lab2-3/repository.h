#pragma once
#include "vector.h"
typedef struct{
	Vector* data;
}Repository;

/*
* Creates a structure of type repository
* Output:
*	return: a pointer to a structure of type Repository
*/
Repository* repositoryConstructor();


/*
* Destroy a structure of type Repository
* Input:
*	- repo: a pointer to a structure of type Repository
*
* Ouput:
*	the memory occupied by the structure is freed
*/
void repositoryDestructor(Repository* repo);

/*
* Get the size of the repository
* Input:
*	- repo: pointer to a structure of type repository
* Output:
*	return: positive integer, indicating the number of elements from the repository
*/
int repositoryGetSize(Repository* repo);


/*
* Adds an element to the repository
* Input:
*	- repo: pointer to a structure of type Repository
*	- e: pointer to a structure of type Medicine
* Output:
*	return: 1 if it was successful and the repository contains one more element, Medicine. If already exists, then its quantity will be updated, -1 otherwise
*/
int repositoryAdd(Repository* repo, Medicine* e);


/*
* Removes element e from the repository
* Input:
*	- repo: pointer to a structure of type Repository
*	- e: pointer to a structure of type Medicine
* Output:
*	return: 1 if the element is removed, -1 othewise. If quantity is over 1, quantity will be decremeted
*/
int repositoryRemove(Repository* repo, Medicine* e);

/*
* Updates a product
* Input:
*	- repo: pointer to a structure of type Repository
*	- e: pointer to a structure of type Medicine
*	- newQuantity: int, the new quantity of the medicine
*	- newPrice: float, the new price of the medicine
* 
* Output:
*	return: 1, the element is found and updated, -1 otherwise
*/
int repositoryUpdate(Repository* repo, Medicine* e, int newQuantity, float newPrice);


/*
* Search for a medicine in the repository 
* Input:
*	- repo: pointer to a structure of type Repository
*	- e: pointer to a structure of type Medicine
* 
* Output:
*	return: positive integer, the position of the Medicine in the repository, -1 if it doesn't exist
*/
int repositorySearchMedicine(Repository* repo, Medicine* e);


