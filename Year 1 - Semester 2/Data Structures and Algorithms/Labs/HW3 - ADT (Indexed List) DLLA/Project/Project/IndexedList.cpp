#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"
IndexedList::IndexedList() {
	//TODO - Implementation
    this->dlla.cap = default_capacity;
    this->dlla.elems = new DLLANode[default_capacity];
    this->dlla.firstEmpty = 0;
    this->dlla.head = -1;

    for(int i = 0; i < default_capacity; i++){
        this->dlla.elems[i].info = NULL_TELEM;
        this->dlla.elems[i].next = -1;
        this->dlla.elems[i].prev = -1;
    }
    this->dlla.size = 0;
    this->dlla.tail = -1;
    //BC:theta(1), WC: theta(1), AC: theta(1)
}


void IndexedList::change_capacity(int new_capacity){
    DLLANode* new_elems = new DLLANode[new_capacity];
    for(int i = 0; i < this->dlla.cap && i < new_capacity; i++){
        new_elems[i].info = this->dlla.elems[i].info;
        new_elems[i].next = this->dlla.elems[i].next;
        new_elems[i].prev = this->dlla.elems[i].prev;
    }
    for(int i = this->dlla.cap; i < new_capacity; i++){
        new_elems[i].info = NULL_TELEM;
        new_elems[i].next = -1;
        new_elems[i].prev = -1;
    }
  
    this->dlla.firstEmpty = this->dlla.cap;
    delete[] this->dlla.elems;
    this->dlla.elems = new_elems;
    this->dlla.cap = new_capacity;
    //BC:theta(new_capacity), WC: theta(new_capacity), AC: theta(new_capacity)
}


int IndexedList::allocate(){
    int newElem = this->dlla.firstEmpty;
    if(newElem == -1){
        this->change_capacity(2 * this->dlla.cap);
        newElem = this->dlla.firstEmpty;
    }
    int index = 0;
    while(index < this->dlla.cap){
        if(index != newElem && this->dlla.elems[index].info == NULL_TELEM)
            break;
        index++;
    }


    if(index == this->dlla.cap)
        this->dlla.firstEmpty = -1;
    else
        this->dlla.firstEmpty = index;
    this->dlla.elems[newElem].next = -1;
    this->dlla.elems[newElem].prev = -1;
    this->dlla.size++;
    return newElem;
    //O(n)
}


void IndexedList::deallocate(int poz){
    if(this->dlla.elems[poz].info != NULL_TELEM){
        this->dlla.elems[poz].next = -1;
        this->dlla.elems[poz].prev = -1;
        this->dlla.elems[poz].info = NULL_TELEM;

        if(this->dlla.firstEmpty == -1)
            this->dlla.firstEmpty = poz;
        this->dlla.size--;
    }
    //theta(1)
}


int IndexedList::size() const {
    //TODO - Implementation
    int node = this->dlla.head;
    int steps = 0;
    while(node != -1){
        steps++;
        node = this->dlla.elems[node].next;
    }
    return steps;
    //theta(capaciy)
}


bool IndexedList::isEmpty() const {
    //TODO - Implementation
    if(this->size() == 0)
        return true;
	return false;
    //theta(1)
}

TElem IndexedList::getElement(int pos) const {
    //TODO - Implementation
    if(pos < 0 || pos > this->dlla.size)
        throw std::exception();
    int node = this->dlla.head;
    int index = 0;
    while(node != -1){
        if(index == pos)
            return this->dlla.elems[node].info;
        node = this->dlla.elems[node].next;
        index++;
    }
	return NULL_TELEM;
}

TElem IndexedList::setElement(int pos, TElem e) {
    //TODO - Implementation
    if(pos < 0 || pos > this->dlla.size)
        throw std::exception();
    int node = this->dlla.head;
    int index = 0;
    while(node != -1){
        if(index == pos){
            TElem old_val = this->dlla.elems[node].info;
            this->dlla.elems[node].info = e;
            return old_val;
        }
        node = this->dlla.elems[node].next;
        index++;
    }
	return NULL_TELEM;
}

void IndexedList::addToEnd(TElem e) {
    //TODO - Implementation
    int pos = this->allocate();
    if(this->dlla.head == -1){
        this->dlla.elems[pos].info = e;
        this->dlla.head = pos;
        this->dlla.tail = pos;
    }
    else{
        int old_end = this->dlla.tail;
        this->dlla.elems[old_end].next = pos;
        this->dlla.elems[pos].prev = old_end;
        this->dlla.elems[pos].info = e;
        this->dlla.tail = pos;
    }
}

void IndexedList::addToPosition(int pos, TElem e) {
    //TODO - Implementation
    if(pos < 0 || pos > this->dlla.size)
        throw std::exception();
    int newElem = this->allocate();
    this->dlla.elems[newElem].info = e;
    if(pos == 0)
        if(this->dlla.head == -1){
            this->dlla.head = newElem;
            this->dlla.tail = newElem;
        }

        else{
            this->dlla.elems[newElem].next = this->dlla.head;
            this->dlla.elems[this->dlla.head].prev = newElem;
            this->dlla.head = newElem;
        }
    else{
        int nodC = this->dlla.head;
        int pozC = 0;
        while(nodC != -1 && pozC < pos - 1){
            nodC = this->dlla.elems[nodC].next;
            pozC = pozC + 1;
        }
        if(nodC != -1){
            int nodNext = this->dlla.elems[nodC].next;
            this->dlla.elems[newElem].next = nodNext;
            this->dlla.elems[newElem].prev = nodC;
            this->dlla.elems[nodC].next = newElem;
            if(nodNext == -1)
                this->dlla.tail = newElem;
            else
                this->dlla.elems[nodNext].prev = newElem;
        }
    }
    // O(n)
}

TElem IndexedList::remove(int pos) {
    //TODO - Implementation
    if(0 > pos || pos >= this->dlla.size)
        throw std::exception();
    int node = this->dlla.head;
    int index = 0;
    while(index < pos && node != -1){
        node = this->dlla.elems[node].next;
        index++;
    }

    if(node == this->dlla.head){
        int tmp = this->dlla.head;
        TElem tmp_elem = this->dlla.elems[tmp].info;
        this->dlla.head = this->dlla.elems[this->dlla.head].next;
        this->deallocate(node);
        return tmp_elem;
    }
    else{
        TElem tmp_elem = this->dlla.elems[node].info;
        int deleted_node = node;
        node = this->dlla.elems[node].prev;
        this->dlla.elems[node].next = this->dlla.elems[deleted_node].next;
        this->dlla.elems[this->dlla.elems[deleted_node].next].prev = node;
        this->deallocate(deleted_node);
        return tmp_elem;   
    }
	return NULL_TELEM;
}

int IndexedList::search(TElem e) const{
    //TODO - Implementation
    int current = this->dlla.head;
    int index = 0;
    while(current != -1){
        if(this->dlla.elems[current].info == e){
            return index;
        }
        current = this->dlla.elems[current].next;
        index++;
    }
	return -1;
}

int IndexedList::removeAll(){
    int current = this->dlla.head;
    int index = 0;
    int old_size = this->size();
    while(index < old_size){
        this->remove(0);
        index++;
    }
    return old_size;
}


ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	//TODO - Implementation
    //delete[] this->dlla.elems;
}