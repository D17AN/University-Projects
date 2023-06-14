#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

ListIterator::ListIterator(const IndexedList& list) : list(list){
   //TODO - Implementation
    this->index = this->list.dlla.head;

}

void ListIterator::first(){
    //TODO - Implementation
    this->index = this->list.dlla.head;
}

void ListIterator::next(){
    //TODO - Implementation
    if(this->index == -1)
        throw std::exception();
    this->index = this->list.dlla.elems[this->index].next;
}

bool ListIterator::valid() const{
    //TODO - Implementation
    return this->index != -1;
}

TElem ListIterator::getCurrent() const{
   //TODO - Implementation
    if(this->index == -1)
        throw std::exception();

    return this->list.dlla.elems[this->index].info;
}