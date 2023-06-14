#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	Set& set;
	int current_index;
	SetIterator(Set& s);

	//TODO - Representation

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
	TElem remove();
};


