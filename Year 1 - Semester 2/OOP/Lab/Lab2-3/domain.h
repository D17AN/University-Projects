#pragma once

typedef struct{
	char* name;
	float concentration;
	int quantity;
	float price;
} Medicine;


/*
* Constructs a structure of type Medicine
* Input:
*	- new_name: array of characters, the name of the Medicine
*	- new_concentration: float, the concentration of the Medicine
*	- new_quantity: int, the quantity of the Medicine
*	- new_price: float, the price of the Medicine
*/
Medicine* medicineConstructor(char* new_name, float new_concentration, int new_quantity, float new_price);


/*
* Deconstructs a structure of type Medicine
* Input:
*	- m: pointer to a structure of type Medicine
* 
* Output:
*	frees the memory occupied by the Medicine
*/
void medicineDeconstructor(Medicine* m);


/*
* Creates a deepcopy of a structure of type Medicine
* Input:
*	- m: pointer to a structure of type Medicine
* 
* Output:
*	return: pointer to a new allocated structure of type Medicine, containing the same data
*/
Medicine* medicineDeepcopy(Medicine* m);


/*
* Gets the name of a Medicine
*/
char* medicineGetName(Medicine* m);


/*
* Gets the concentration of a Medicine
*/
float medicineGetConcentration(Medicine* m);


/*
* Gets the quantity of a medicine
*/
int medicineGetQuantity(Medicine* m);


/*
* Gets the price of a medicine
*/
float medicineGetPrice(Medicine* m);


/*
* Sets the name of a medicine
*/
void medicineSetName(Medicine* m, char* new_name);


/*
* Sets the concentration of a medicine
*/
void medicineSetConcentration(Medicine* m, float new_concentration);


/*
* Sets the quantity of a medicine
*/
void medicineSetQuantity(Medicine* m, int new_quantity);


/*
* Set the price of a medicine 
*/
void medicineSetPrice(Medicine* m, float new_price);


/*
*  Checks if they are the same medicine. They are equal if the name, concentration and price are the same.
* Input:
*	- m1: pointer to a structure of type Medicine
*	- m2: pointer to a structure of type Medicine
*	
* Output:
*	return: 1 if the medicines are equal, 0 otherwise
*	
*/
int medicineEqual(Medicine* m1, Medicine* m2);


/*
* Checks if m1 name is lexicographical smaller than m2 name
* Input:
*	- m1: pointer to a structure of type Medicine
*	- m2: pointer to a structure of type Medicine
* Output:
*	return: 1 if m1 name is lexicographical smaller than m2 name, 0 otherwise
*/
int medicineAscendingOrderByName(Medicine* m1, Medicine* m2);


/*
* Checks if the name of a given medicine contains a given substring
* Input:
*	- m: pointer to structure of type Medicine
*	- atr: pointer to a char, the string we want to match with a substring of the name of the medicine
* Output:
*	return: 1 if the provided string is empty or is a match, 0 otherwise
*/
int medicineNameContainSubstring(Medicine* m, char* atr);


/*
* Prints a medicine
*/
void medicinePrint(Medicine* m);