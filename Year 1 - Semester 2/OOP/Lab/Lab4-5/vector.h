#pragma once

#include<string>
#include "customexcpetion.h"

template<typename T = int>
class Vector {
	private:
		T* elems;
		int size, capacity;
		
	public:
		/*
		* Constructor
		* Output:
		*  return: an instance of class Vector
		*/
		Vector();


		/*
		* Deconstructor
		* Output:
		*	the memory is freed of the instance of this class
		*/
		~Vector();


		/*
		* Copy constructor
		* Creates a copy of an existing object
		* Input:
		*	- other: type Vector, the object to be initialized with
		* Ouput:
		*	an object which has the same content as the provided class
		*/
		Vector(const Vector<T>& other);
			
		/*
		* Add an element in the Vector
		* Input:
		*	- elem: type T, the element to be added
		* Ouput:
		*	The Vector contains all the previous elements and the new added element. If the element couldn't be added an error is thrown.
		*/
		void add(const T& elem);


		/*
		* Removes the element placed at a certain index from the Vector
		* Input:
		*	- index: type int, the position to be deleted
		* Output:
		*	The vector contains all the previous elements except the element which was placed at the given position. If the index is out of bound an exception is thrown.
		*/
		void removePosition(int index);


		/*
		* Removes an element from the Vector
		* Input:
		*	- elem: type T, the element to be deleted
		* Output:
		*	The vector contains all the previous elements except the first occurence of the given element. If the element doesn't exist an error is thrown.
		*/
		void remove(const T& elem);


		/*
		* Search for a given element in the Vector
		* Input:
		*	- elem: type T, the element to search for
		* Ouput:
		*	return: positive integer, being the position of the element, if the element is found, -1 otherwise.
		*/
		int search(const T& elem);


		/*
		* Get the size of the Vector
		* Ouput:
		*	return: int, the size of the vector
		*/
		int getSize();


		/*
		* Get the Vector
		* Ouput:
		*	return: the list of elements of the Vector
		*/
		Vector<T>& get();

		/*
		* Overload dereferencing operator
		* Input:
		*	- index: type int, the index to be accessed
		* Ouput:
		*	return: a reference to an object of type T, placed on the position index within the Vector. If the index is out of range an error is thrown.
		*/
		T& operator[](int index);
		

		/*
		* Overload the assignment operator
		* Input:
		*	- other: type Vector<T>, the assigned object
		* Ouput:
		*	return: a reference to an object of type Vector<T>. The current instance is going to replace its content with the content of the other object.
		* 
		*/
		Vector<T>& operator=(const Vector<T>& other);


		/*
		* Overload the equality operator
		* Input:
		*	- other: type Vector<T>, the assigned object
		* Output:
		*	return: true, if both objects have the same content(size, capacity, elems), false otherwise.
		*/
		bool operator==(const Vector<T>& other);


	private:
		/*
		* Resize the vector
		* Output:
		*	the vector doubled its capacity, otherwise an error is thrown
		*/
		void vectorResize();

};
	

template<typename T>
Vector<T>::Vector() : size{0}, capacity{10}{
	this->elems = new T[this->capacity];
}
	

template<typename T>
Vector<T>::~Vector(){
	delete[] this->elems;
	this->elems = nullptr;
}


template<typename T>
Vector<T>::Vector(const Vector<T>& other){
	//buffer overrun is not possible, capacity is always going to be >= size
	this->capacity = other.capacity;
	this->size = other.size;
	this->elems = new T[other.capacity];
	for (int i = 0; i < other.size; i++){
		this->elems[i] = other.elems[i];
	}
}


template<typename T>
void Vector<T>::vectorResize(){
	T* newElems = new T[this->capacity * 2];
	if (newElems == nullptr){
		throw VectorException{"An error occured when trying to allocate memory."};
	}

	for (int i = 0; i < this->size; i++){
			newElems[i] = this->elems[i];
	}

	delete[] this->elems;
	this->elems = newElems;
	this->capacity *= 2;
}


template<typename T>
void Vector<T>::add(const T& elem){
	if (this->size == this->capacity){
		this->vectorResize();
	}

	this->elems[this->size++] = elem;
}


template<typename T>
void Vector<T>::removePosition(int index){
	if (index < 0 || index >= this->size){
		throw VectorException{"Index out of bound!"};
	}

	for (int i = index + 1; i < this->size; i++){
		this->elems[i - 1] = this->elems[i];
	}

	this->size--;
}

	
template<typename T>
void Vector<T>::remove(const T& elem){
	int found = -1;
	for (int i = 0; i < this->size && found == -1; i++){
		if (this->elems[i] == elem){
			found = i;
			for (int j = i + 1; j < this->size; j++){
				this->elems[j - 1] = this->elems[j];
			}
			this->size--;
		}
	}

	if (found == -1){
		throw VectorException{"The element doesn't exist!"};
	}
}


template<typename T>
int Vector<T>::search(const T& elem){
	int found = -1;
	for (int i = 0; i < this->size && found == -1; i++){
		if (this->elems[i] == elem){
			found = i;
		}
	}
	return found;
}

template<typename T>
int Vector<T>::getSize(){
	return this->size;
}


template<typename T>
Vector<T>& Vector<T>::get(){
	return *this;
}

template<typename T>
T& Vector<T>::operator[](int index){
	if (index < 0 || index >= this->size){
		throw VectorException{"Index out of bound"};
	}
	return this->elems[index];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
	if (this == &other){
		return *this;
	}

	if (this->capacity != other.capacity){
		T* temp = new T[other.capacity];
		if (temp == nullptr)
			return *this;
		delete[] this->elems;
		this->elems = temp;
		this->capacity = other.capacity;
	}
	this->size = other.size;
	for (int i = 0; i < other.size; i++){
		this->elems[i] = other.elems[i];
	}

	return *this;
	
}


template<typename T>
bool Vector<T>::operator==(const Vector<T>& other){
	if (this->capacity != other.capacity || this->size != other.size){
		return false;
	}

	for (int i = 0; i <= this->size; i++){
		if (this->elems[i] != other.elems[i]){
			return false;
		}
	}
	
	return true;
}

