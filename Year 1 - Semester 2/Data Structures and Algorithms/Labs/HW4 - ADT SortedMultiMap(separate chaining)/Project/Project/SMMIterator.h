#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	//DO NOT CHANGE THIS PART
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map); //O(n*N), n = nr. of different keys, N = capacity of hashtable
	SortedMultiMap::Node* current, * head;
	int pos;


public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

