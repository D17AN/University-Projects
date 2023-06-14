#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>

using namespace std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
    if (capacity <= 0) {
        throw exception();
    }
	this->currentCapacity=0;
    this->totalCapacity=capacity;
    this->elements=new TElem[capacity];
}

FixedCapBiMap::~FixedCapBiMap() {
	delete this->elements;
}

bool FixedCapBiMap::add(TKey c, TValue v){
	if (this->currentCapacity == this->totalCapacity){
        throw exception();
    }
    int count = 0;

    int index = 0;

    while(index < this->currentCapacity && count <2){
        if (this->elements[index].first == c ){
            count++;
        }
        index++;

    }
    if (count == 2){
        return false;
    }

    this->elements[this->currentCapacity].first = c;
    this->elements[this->currentCapacity].second = v;
    this->currentCapacity++;

    return true;
}

ValuePair FixedCapBiMap::search(TKey c) const{
    ValuePair result(NULL_TVALUE, NULL_TVALUE);

    int index = 0, count = 0;
    while(index < this->currentCapacity && count <2){
        if (this->elements[index].first == c ){
            count++;
            if (count == 1){
                result.first = this->elements[index].second;
            }
            if (count == 2){
                result.second = this->elements[index].second;
            }
        }
        index++;

    }

    return result;
}

bool FixedCapBiMap::remove(TKey c, TValue v){
    for(int i=0; i< this->currentCapacity;i++)
        if (this->elements[i].first==c && this->elements[i].second==v)
        {
            this->elements[i].first= this->elements[this->currentCapacity-1].first;
            this->elements[i].second= this->elements[this->currentCapacity-1].second;
//            this->elements[i] = this->elements[this->currentCapacity - 1]
            this->currentCapacity --;
            return true;
        }
    return false;
}


int FixedCapBiMap::size() const {
    return this->currentCapacity;
}

bool FixedCapBiMap::isEmpty() const{
//    VERSION 1
//    if (this->currentCapacity == 0) {
//        return true;
//    } else {
//        return false;
//    }
//    VERSION 2
	return this->currentCapacity == 0;
}

bool FixedCapBiMap::isFull() const {
//    VERSION 1
//    if (this->currentCapacity == this->totalCapacity) {
//        return true;
//    } else {
//        return false;
//    }
//    VERSION 2
    return this->currentCapacity == this->totalCapacity;
}

FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}



