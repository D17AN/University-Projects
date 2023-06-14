#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include<climits>
#include <exception>
using namespace std;

int SortedMultiMap::hash_function(int key) const
{
	if(key < 0)
		key = this->capacity + key % this->capacity;
	return key % this->capacity;
}

void SortedMultiMap::resize()
{
	this->capacity *= 2;
	Node** aux = new Node * [this->capacity];
	for(int i = 0; i < this->capacity; ++i)
		aux[i] = nullptr;
	for(int i = 0; i < this->capacity / 2; ++i){
		Node* curr_node = this->dict[i];
		while(curr_node != nullptr){
			int place = this->hash_function(curr_node->key);
			Node* next = curr_node->next;
			curr_node->next = aux[place];
			aux[place] = curr_node;
			curr_node = next;
		}
	}
	delete[] this->dict;
	this->dict = aux;
}

void SortedMultiMap::resize(Node* node)
{
	node->capacity *= 2;
	auto* aux = new TValue[node->capacity];
	for(int i = 0; i < node->size; ++i)
		aux[i] = node->values[i];
	delete[] node->values;
	node->values = aux;
}

SortedMultiMap::SortedMultiMap(Relation r) {
	this->dict_size = 0;
	this->load_factor = 0.5;
	this->capacity = 1;
	this->dict = new Node * [this->capacity];
	for(int i = 0; i < this->capacity; i++)
		this->dict[i] = nullptr;
	this->comp = r;
}

void SortedMultiMap::add(TKey c, TValue v) {
	int place = this->hash_function(c);
	Node* curr_node = this->dict[place];
	Node* prev = nullptr;
	while(curr_node != nullptr){
		if(curr_node->key == c){
			if(curr_node->size == curr_node->capacity)
				this->resize(curr_node);
			curr_node->values[curr_node->size] = v;
			curr_node->size += 1;
			this->dict_size++;
			break;
		}
		if(comp(curr_node->key, c) && curr_node->key != c)
			prev = curr_node;
		curr_node = curr_node->next;
	}
	if(curr_node == nullptr){
		if(double(this->dict_size + 1) / this->capacity >= this->load_factor){
			this->resize();
			place = this->hash_function(c); // recalculate the hash for key
			curr_node = this->dict[place];
			prev = nullptr;
			while(curr_node != nullptr){
				if(comp(curr_node->key, c) && curr_node->key != c){
					prev = curr_node;
					curr_node = curr_node->next;
				}
				else
					break;
			}
		}
		Node* new_node = new Node;
		new_node->values[0] = v;
		new_node->size = 1;
		new_node->key = c;
		if(prev == nullptr){
			new_node->next = this->dict[place];
			this->dict[place] = new_node;
		}
		else{
			new_node->next = prev->next;
			prev->next = new_node;
		}
		this->dict_size++;
	}
}


vector<TValue> SortedMultiMap::search(TKey c) const {
	int place = this->hash_function(c);
	Node* curr_node = this->dict[place];
	vector<TValue> values;
	while(curr_node != nullptr){
		if(curr_node->key == c){
			for(int i = 0; i < curr_node->size; i++)
				values.push_back(curr_node->values[i]);
			break;
		}
		curr_node = curr_node->next;
	}
	return values;
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	int place = this->hash_function(c);
	Node* prev = nullptr;
	Node* curr_node = this->dict[place];
	while(curr_node != nullptr){
		if(curr_node->key == c){
			bool deleted = false;
			for(int i = 0; i < curr_node->size; ++i)
				if(curr_node->values[i] == v){
					for(int j = i; j + 1 < curr_node->size; ++j)
						curr_node->values[j] = curr_node->values[j + 1];
					curr_node->size -= 1;
					this->dict_size--;
					deleted = true;
					break;
				}
			if(curr_node->size == 0){
				delete[] curr_node->values;
				if(prev == nullptr){
					this->dict[place] = curr_node->next;
					delete curr_node;
				}
				else{
					Node* next = curr_node->next;
					prev->next = next;
					delete curr_node;
				}
			}
			return deleted;
		}
		prev = curr_node;
		curr_node = curr_node->next;
	}
	return false;
}


int SortedMultiMap::size() const {
	return this->dict_size;
}

bool SortedMultiMap::isEmpty() const {
	return this->dict_size == 0;
}
 
int SortedMultiMap::getKeyRange() const
{
	int minimum = INT_MAX;
	int maximum = INT_MIN;
	if(this->dict_size == 0)
		return -1;
	for(int i = 0; i < this->dict_size; ++i){
		Node* curr_node = this->dict[i];
		while(curr_node != nullptr){
			int place = this->hash_function(curr_node->key);
			if(this->dict[place]->key < minimum)
				minimum = this->dict[place]->key;
			if(this->dict[place]->key > maximum)
				maximum = this->dict[place]->key;
			Node* next = curr_node->next;
			curr_node = next;
		}
	}
	return maximum - minimum + 1;

}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	for(int i = 0; i < this->capacity; ++i){
		Node* curr_node = this->dict[i];
		while(curr_node != nullptr){
			delete[] curr_node->values;
			Node* next = curr_node->next;
			delete curr_node;
			curr_node = next;
		}
	}
	delete[] this->dict;
}

SortedMultiMap::Node::Node()
{
	this->next = nullptr;
	this->key = 0;
	this->size = 0;
	this->capacity = 1;
	this->values = new TValue[this->capacity];
}
