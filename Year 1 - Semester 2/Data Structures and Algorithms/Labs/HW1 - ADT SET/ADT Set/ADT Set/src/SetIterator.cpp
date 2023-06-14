#include "SetIterator.h"
#include "Set.h"
#include<exception>


SetIterator::SetIterator(Set& m) : set(m)
{
	//TODO - Implementation
	//thetha(1)
	this->current_index = 0;
}


void SetIterator::first() {
	//TODO - Implementation
	//thetha(1)
	this->current_index = 0;
	while(this->current_index < this->set.current_capacity && this->set.elements[this->current_index] == false)
		this->current_index++;
}


void SetIterator::next() {
	//TODO - Implementation
	//thetha(current_capacity)
	if(this->current_index >= this->set.current_capacity)
		throw std::exception();
	this->current_index++;
	while(this->current_index < this->set.current_capacity && this->set.elements[this->current_index] == false)
		this->current_index++;

}


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	//thetha(1)
	if(this->current_index >= this->set.current_capacity)
		throw std::exception();
	return this->set.min_value + this->current_index;
	
}

bool SetIterator::valid() const {
	//TODO - Implementation
	//thetha(1)
	if(this->current_index < this->set.current_capacity)
		return true;
	return false;
}


TElem SetIterator::remove(){
	int val = getCurrent();
	if(this->current_index > 0 || this->current_index < this->set.current_capacity - 1){
		this->set.remove(getCurrent());
		this->next();
	}
	else if(this->current_index == 0)
		this->set.remove(getCurrent());
	else if(this->current_index == this->set.current_capacity - 1)
		this->set.remove(getCurrent());
	return val;
}



