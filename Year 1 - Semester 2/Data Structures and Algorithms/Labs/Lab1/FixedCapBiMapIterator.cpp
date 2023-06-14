#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>
using namespace std;


FixedCapBiMapIterator::FixedCapBiMapIterator(const FixedCapBiMap& d) : map(d)
{
	this->currentIndex = 0;
}


void FixedCapBiMapIterator::first() {
	this->currentIndex = 0;
}


void FixedCapBiMapIterator::next() {
	if (this->currentIndex >= this->map.currentCapacity)
        throw exception();
    this->currentIndex++;
}


TElem FixedCapBiMapIterator::getCurrent(){
    if (this->currentIndex >= this->map.currentCapacity)
        throw exception();
	return this->map.elements[this->currentIndex];
}


bool FixedCapBiMapIterator::valid() const {
    if (this->currentIndex < this->map.currentCapacity)
        return true;
    return false;
}



