#pragma once
#include "domain.h"
typedef Medicine TElem;

/*
* Compare function for 2 elements
*/
typedef int(*compareFunction)(TElem*, TElem*);

typedef struct {
	TElem** elems;
	int size;
	int capacity;
} Vector;

/*
* Creates a structure of type Vector
* Input:
*	- capacity: int, the current capacity of the Vector
* 
* Output:
*	return: a pointer to a structure of type Vector
*/
Vector* vectorConstructor(int capacity);


/*
* Destroy a structure of type Vector
* Input:
*	- v: pointer of type Vector
* 
* Output:
*	frees the memory occupied by the Vector
*/
void vectorDestructor(Vector* v);

/*
* Resizes a structure of type Vector
* Input:
*	- v: pointer of type Vector
* 
* Output:
*	a vector which has doubled its capacity
*/
void vectorResize(Vector* v);

/*
* Creates a copy of a structure of type Vector, providing the same data as it
* Input:
*	- v: pointer of type Vector
* 
*Output:
*	return: a deepcopy of the given structure Vector
*/
Vector* vectorDeepcopy(Vector* v);


/*
* Get the size of a vector
* Input:
*	- v: pointer to a structure of type Vector
* Ouput:
*	return: the number of elements which is contained by the Vector
*/
int vectorGetSize(Vector* v);


/*
* Adds an element in the Vector
* Input:
*	- v: pointer of type Vector
*	- elem: pointer of type TElem, the element to be added
* 
* Output:
*	return: 1 if the add was successful and the Vector structure contains the elem of type TElem, -1 otherwise
*/
int vectorAddElem(Vector* v, TElem* elem);


/*
* Deletes the element from a give position
* Input:
*	- v: pointer of type Vector
*   - elem: a pointer of type TElem, the element to be deleted
* 
* Output:
*	return: 1 if the deletion is successful, -1 otherwise
*/
int vectorDeletePosition(Vector* v, int pos);


/*
* Search an element in the vector
* Input:
*	- v: a pointer of type Vector
*	- elem: a pointer of type TElem, the element to be searched
*	- compare: pointer to a function which handles the comparing of 2 TElems
* Output:
*	return: a positive integer, which indicates the position of the elemenent in the Vector,
*			-1 otherwise
*/
int vectorSearchElem(Vector* v, TElem* elem, compareFunction compare);



/*
* Structure of type History:
*	- operationIndex: intger, indicates the current position from the list of states
*	- size: integer, indicates the total number of elements of the states
*	- capacity: integer, indicates the current capacity of the states
*	- states: list of pointers of type Vector
*/
typedef struct{
	int operationIndex, size, capacity;
	Vector** states;
}History;


/*
* Constructs a structure of type history
* Input:
*	- capacity: int, the current capacity of the structure
* Output:
*	return: pointer to a structure of type History
*/
History* historyConstructor(int capacity);


/*
* Deconstructs a structure of type history
* Input:
*	- h: pointer to a structure of type history
* Output:
*	the memory occupied by the structure has been freed
* 
*/
void historyDeconstructor(History* h);


/*
* Resize the capacity of a structure of type History
Input:
*	- h: pointer to a structure of type History
* Output:
*	the structure h of type History has been resized, its capacity doubled
*/
void historyResize(History* h);


/*
* Add to a structure of type History a given structure of type Vector
* Input:
*	- h: pointer to a structure of type History
* 
* Output:
*	return: if v has been succesfully added to h, then 1 is being returned, otherwise -1
*/
int historyAdd(History* h, Vector* v);


/*
* Remove the elements between 2 indexes
* Input:
*	- h: pointer to a structure of type History
*	- startIndex: positive integer, the start position from where the elements must be deleted
*	- endIndex: positive integer, the end position from where the elemenets must be deleted
*
* Ouput:
*	all the elements of h between [startIndex, endIndex) have been deleted
*/
void historyRemove(History* h, int startIndex, int endIndex);


/*
* Undo. Assign to v its previous state
* Input:
*	- h: pointer to a structure of type History
*	- v: the address of pointer of type Vector
*
* Output:
*	v has been restored to its previous state
*	return: if an undo can be performed 1 is returned, otherwise -1
*/
int undo(History* h, Vector** v);


/*
*Redo.Assign to v the state before performing an undo
* Input:
*	-h : pointer to a structure of type History
*	-v : the address of pointer of type Vector
*
*Output :
*	v has been restored to the state before perfoming an undo
*   return : if an redo can be performed 1 is being returned, otherwise - 1
*/
int redo(History* h, Vector** v);



