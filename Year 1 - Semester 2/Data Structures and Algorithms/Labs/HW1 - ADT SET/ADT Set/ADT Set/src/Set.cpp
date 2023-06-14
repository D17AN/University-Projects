#include "Set.h"
#include "SetITerator.h"

Set::Set() {
	//TODO - Implementation
	//thetha(1)
	this->current_capacity = 0;
	this->total_capacity = 0;
	this->max_value = -1;
	this->min_value = 1;
	this->elements = new bool[current_capacity];
}


bool Set::add(TElem elem) {
	//TODO - Implementation
	if(this->current_capacity == 0){
		//thetha(1)
		this->max_value = this->min_value = elem;
		this->total_capacity = 1;
		delete this->elements;
		this->elements = new bool[this->total_capacity];
		this->elements[this->total_capacity - 1] = true;
		this->current_capacity++;
		return true;
	}
	else if(this->max_value < elem){
		//thetha(new_size)
		int new_size = elem - this->min_value + 1;
		bool* aux_set = new bool[new_size];
		for(int i = 0; i < this->current_capacity; i++)
			aux_set[i] = this->elements[i];
		for(int i = this->current_capacity; i < new_size - 1; i++)
			aux_set[i] = false;
		aux_set[new_size - 1] = true;
		delete this->elements;
		this->elements = aux_set;
		this->current_capacity = new_size;
		this->total_capacity = new_size;
		this->max_value = elem;
		return true;
	}
	else if(this->min_value > elem){
		//thetha(new_size)
		int new_size = this->max_value - elem + 1;
		bool* aux_set = new bool[new_size];
		for(int i = 0; i < new_size - this->current_capacity; i++)
			aux_set[i] = false;
		for(int i = new_size - this->current_capacity, j = 0; i < new_size; i++, j++)
			aux_set[i] = this->elements[j];
		aux_set[0] = true;
		delete this->elements;
		this->elements = aux_set;
		this->current_capacity = this->total_capacity = new_size;
		this->min_value = elem;
		return true;
	}
	else if(search(elem) == false){
		//thetha(1)
		this->elements[elem - this->min_value] = true;
		return true;
	}
	return false;
}


bool Set::remove(TElem elem) {
	//TODO - Implementation
	if(search(elem) == true){
		if(this->current_capacity == 1){
			//thetha(1)
			delete this->elements;
			this->elements = new bool[0];
			this->max_value = -1;
			this->min_value = 1;
			this->current_capacity = this->total_capacity = 0;
			return true;
		}
		else if(elem == this->max_value){
			//thetha(current_capacity)
			int count = 0, index = -1;
			for(int i = this->current_capacity - 1; i >= 0 && count < 2; i--)
				if(this->elements[i] == true){
					count++;
					index = i;
				}
			int new_size = index + 1;
			bool* aux_set = new bool[new_size];
			for(int i = index; i >= 0; i--)
				aux_set[i] = this->elements[i];
			delete this->elements;
			this->elements = aux_set;
			this->current_capacity = this->total_capacity = index + 1;
			this->max_value = this->min_value + index;
			return true;
		}
		else if(elem == this->min_value){
			//thetha(current_capacity)
			int count = 0, index = -1;
			for(int i = 0; i < this->current_capacity && count < 2; i++)
				if(this->elements[i] == true){
					count++;
					index = i;
				}
			int new_size = this->max_value - (this->min_value + index) + 1;
			bool* aux_set = new bool[new_size];
			for(int i = 0; i < new_size; i++)
				aux_set[i] = this->elements[i + index];
			delete this->elements;
			this->elements = aux_set;
			this->current_capacity = this->total_capacity = new_size;
			this->min_value = this->min_value + index;
			return true;
		}
		else if(this->min_value < elem && elem < this->max_value){
			//thetha(1)
			this->elements[elem - this->min_value] = false;
			return true;
		}
	}
	return false;
}

bool Set::search(TElem elem) const {
	//TODO - Implementation
	//thetha(1)
	if(this->current_capacity > 0 && this->min_value <= elem && elem <= this->max_value)
		if(this->elements[elem - this->min_value] == true)
			return true;
		else return false;
	return false;
}


int Set::size() const {
	//TODO - Implementation
	//thetha(current_capacity)
	int nr = 0;
	for(int i = 0; i < this->current_capacity; i++)
		if(this->elements[i] == true)
			nr++;
	return nr;
}


bool Set::isEmpty() const {
	//thetha(1)
	//TODO - Implementation
	return size() == 0;
}


Set::~Set() {
	//TODO - Implementation
	delete this->elements;
}


SetIterator Set::iterator() {
	return SetIterator(*this);
}


