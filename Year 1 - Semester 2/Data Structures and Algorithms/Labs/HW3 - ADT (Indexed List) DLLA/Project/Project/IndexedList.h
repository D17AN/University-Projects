#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -1111111
#define default_capacity 100
class ListIterator;

struct DLLANode{
    TElem info;
    int next;
    int prev;
};

struct DLLA{
    DLLANode* elems;
    int cap;
    int head;
    int tail;
    int firstEmpty;
    int size;
};

class IndexedList {
private:
	//TODO - Representation
    DLLA dlla;
    
    //to change the capacity of the data structure 
    void change_capacity(int new_capacity);

    // gets the index of a free node
    int allocate();

    //frees a node 
    void deallocate(int poz);

	//DO NOT CHANGE THIS PART
    friend class ListIterator;    
public:
    // constructor
    IndexedList ();

    // returns the number of elements from the list
    int size() const;

    // checks if the list is empty
    bool isEmpty() const;

    // returns an element from a position
    //throws exception if the position is not valid
    TElem getElement(int pos) const;

    // modifies an element from a given position
	//returns the old value from the position
    //throws an exception if the position is not valid
    TElem setElement(int pos, TElem e);

    // adds an element to the end of the list
    void addToEnd(TElem e);

    // adds an element to a given position
    //throws an exception if the position is not valid
    void addToPosition(int pos, TElem e);

    // removes an element from a given position
	//returns the removed element
    //throws an exception if the position is not valid
    TElem remove(int pos);

    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    int search(TElem e)  const;

    int removeAll();

    // returns an iterator set to the first element of the list or invalid if the list is empty
    ListIterator iterator() const;

    //destructor
    ~IndexedList();

};
