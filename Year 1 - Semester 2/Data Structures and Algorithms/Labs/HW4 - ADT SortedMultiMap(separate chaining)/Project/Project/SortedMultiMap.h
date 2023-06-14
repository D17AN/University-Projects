#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);


class SortedMultiMap {
	friend class SMMIterator;
    private:
        struct Node{
            int key;
            int size, capacity;
            TValue* values;
            Node* next;
            Node();
        };
        int dict_size, capacity;
        double load_factor;
        Node** dict;
        Relation comp;
 

        //hash function for the hash table
        [[nodiscard]] int hash_function(int key)const;//Theta(1)

        //resize the hash table by doubling its capacity
        void resize(); //Theta(n)

        //resize the dynamic array in Node 
        static void resize(Node* node); //Theta(n), n is the number of links in the list
		//TODO - Representation

    public:

    // constructor //Theta(1)
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    //O(n), average Theta(1)
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    //Theta(n), n is the number of values with key = c
    [[nodiscard]] vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
     //O(n), average Theta(1)
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multima
    //Theta(1)
    [[nodiscard]] int size() const; 

    //verifies if the sorted multi map is empty
    //Theta(1)
    [[nodiscard]] bool isEmpty() const;

    [[nodiscard]] int getKeyRange()const;
    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    [[nodiscard]] SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
};
