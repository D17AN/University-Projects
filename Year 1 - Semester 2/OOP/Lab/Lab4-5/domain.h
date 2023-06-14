#pragma once
#include <string>
#include <istream>
#include <ostream>
#include "customexcpetion.h"
#include "utils.h"
#include <stdexcept>
#include <vector>
#include <math.h>

/*
* Object of type TrenchCoat
* A TrenchCoat is unique by its size, color and photographLink.
*/
class TrenchCoat{
private:
	std::string size;
	std::string color;
	int price;
	int quantity;
	std::string photographLink;

	/*
	* size | color | price | quantity | photograph link => how a TrenchCoat is read
	* Reads from an input stream a string/line and assigns it accordingly to the called instance
	* Each attribute it's separeted through a '|'.
	* Input:
	*	is: type istream, the input stream from where we extract data
	*
	* Output:
	*	return: the given input stream
	*
	* Exceptions:
	*	- a line must have exactly 5 fields, otherwise an error is thrown
	*	- a field can't be an empty otherwise an error is thrown
	*	- if the price cannot be converted to a number, or the value is out of the data type range, an error is thrown
	*	- if the quantity cannot be converted to a number, or the value is out of the data type range, an error is thrown
	*	- if the size is not s, m, l, or xl an error is thrown
	*	- if the price is not a positive number an error is thrown
	*	- if the quantity is not a positive number an error is thrown
	*/
	std::istream& read(std::istream& is);


public:
	/*
	* Default constructor
	*/
	TrenchCoat();


	/*
	* Constructor for a Trench Coat
	* Input:
	*	- size: type string, the size of the coat
	*	- color: type string, the color of the coat
	*	- price: type int, the price of the coat
	*	- quantity: type int, the quantity of coats of same type
	*	- photographLink: type string, the link to the photograph of the trench coat
	* 
	* Output:
	*	An instance of type TrenchCoat has been created
	*/
	TrenchCoat(const std::string& size, const std::string& color, const int& price, const int& quantity, const std::string& photographLink);
	
	
	/*Copy constructor for a Trench Coat
	* Input:
	*	- TrenchCoat: type TrenchCoat, the instance to be copied
	* Output:
	*	A new instance of type TrenchCoat has been created, having the same data as the given TrenchCoat
	*/
	TrenchCoat(const TrenchCoat& tc);


	/*
	* Getter for the size of a TrenchCoat
	* Output:
	*	return: a string, representing the size of the TrenchCoat
	*/
	std::string getSize();
	


	/*
	* Getter for the color of a TrenchCoat
	* Output:
	*	return: a string, representing the color of the TrenchCoat
	*/
	std::string getColor();

	
	/*
	* Getter for the price of a TrenchCoat
	* Output:
	*	return: a int, representing the price of the TrenchCoat
	*/
	int getPrice();


	/*
	* Getter for the quantity of a TrenchCoat
	* Output:
	*	return: an int, representing the quantity of the TrenchCoat
	*/
	int getQuantity();


	/*
	* Getter for the photograph link of a TrenchCoat
	* Output:
	*	return: a string, representing the photograph link of the Trench Coat
	*/
	std::string getPhotographLink();


	/*
	* Setter for the price of a TrenchCoat
	* Input:
	*	- newPrice: type int, the new price of the TrenchCoat
	* 
	* Output:
	*	The price of the instance of type TrenchCoat will be set to newPrice
	*/
	void setPrice(const int& newPrice);

	
	/*
	* Setter for the quantity of a TrenchCoat
	* Input:
	*	- newQuantity: type int, the new quantity of the TrenchCoat
	* 
	* Output:
	*	The quantity of the instance of type TrenchCoat will be set to newQuantity
	*/
	void setQuantity(const int& newQuantity);


	/*
	* Overloading the equality operator
	* 2 instances are equal if the size, color and the photographLink are the same
	* Input:
	*	other: type TrenchCoat, the TrenchCoat to be compared with the current instance
	*
	* Output:
	*	return: true, if other is equal with current instance, false otherwise
	*/
	bool operator==(const TrenchCoat& other);


	/*
	* Overloading the inequality operator
	* 2 instances are inequal if the size, color and/or the photographLink are not the same
	* Input:
	*	other: type TrenchCoat, the TrenchCoat to be compared with the current instance
	*
	* Output:
	*	return: true, if other is inequal with current instance, false otherwise
	*/
	bool operator!=(const TrenchCoat& other);


	/*
	* Copy assignment
	* The attributes of other are going to be copied to the current instance
	* Input:
	*	- other: type TrenchCoat, the TrenchCoat to have its attributes copied to the current instance
	*
	* Output:
	*	The current instance has its attributes set to the attributes of other
	*/
	TrenchCoat& operator=(const TrenchCoat& other);

	
	/*
	* Overloading the insertion operator for inserting data to an output stream from a Trench Coat
	* Input:
	*	- os: type ostream, output stream
	*	- tc: type TrenchCoat, the TrenchCoat from which we extract data
	* Ouput:
	*	return: the stream to which we inserted data
	*/
	friend std::ostream& operator<<(std::ostream& os, const TrenchCoat& tc);

	
	/*
	* Overloading extraction operator for the extracting data from an input stream and storing them in a Trench Coat
	* Input:
	*	- is: type istream, input stream
	*	- tc: type TrenchCoat, the TrenchCoat in which we insert data
	* Output:
	*	return: the stream from which we extracted data
	*/
	friend std::istream& operator>>(std::istream& is, TrenchCoat& tc);


	/*
	* Destructor for a TrenchCoat
	* Output:
	*	The memory occupied by the instance of class has been freed
	*/
	~TrenchCoat();
	
};


class TrenchCoatValidator{
public:
	/*
	* Checks if the size of a TrenchCoat is valid
	* Input:
	*	size: type string, the size of a TrenchCoat
	*
	* Output:
	*	return: true, the size is valid, false otherwise
	*/
	static bool isSizeValid(const std::string& size);

	/*
	* Checks if the color of a TrenchCoat is valid
	* Input:
	*	size: type string, the color of a TrenchCoat
	*
	* Ouput:
	*	return: true, the color is valid, false otherwise
	*/
	static bool isColorValid(const std::string& color);

	/*
	* Checks if the price of a TrenchCoat is valid
	* Input:
	*	price: type int, the price of a TrenchCoat
	*
	* Output:
	*	return: true, the price is valid, false otherwise
	*/
	static bool isPriceValid(const int& price);

	/*
	* Checks if the quantity of a TrenchCoat is valid
	* Input:
	*	quantity: type int, the price of a TrenchCoat
	*
	* Output:
	*	return: true, the quantity is valid, false otherwise
	*/
	static bool isQuantityValid(const int& quantity);

	/*
	* Checks if the photographLink of a TrenchCoat is valid
	* Input:
	*	photographLink: type string, the photograph link of a TrenchCoat
	*
	* Output:
	*	return: true, the photograph link is valid, false otherwise
	*/
	static bool isPhotographLinkValid(const std::string& photographLink);
};