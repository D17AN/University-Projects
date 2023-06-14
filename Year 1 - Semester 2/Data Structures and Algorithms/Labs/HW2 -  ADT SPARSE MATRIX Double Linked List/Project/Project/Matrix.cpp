#include "Matrix.h"
#include <exception>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	   
	//TODO - Implementation
	this->rows = nrLines;
	this->cols = nrCols;
	this->head = NULL;
}


int Matrix::nrLines() const {
	//theta(1)
	//TODO - Implementation
	return this->rows;
}


int Matrix::nrColumns() const {
	//theta(1)
	//TODO - Implementation
	return this->cols;
}


TElem Matrix::element(int i, int j) const {
	//TODO - Implementation
	//theta(n)
	if(!(0 <= i && i < this->nrLines() && 0 <= j && j < this->nrColumns()))
		throw std::exception();
	node* tmp = this->head;
	while(tmp != NULL){
		if(tmp->row == i && tmp->col == j)
			return tmp->value;
		else if(tmp->row >= i && tmp->col > j)
			break;
		tmp = tmp->next;
	}
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
	//TODO - Implementation
	//theta(n)
	if(!(0 <= i && i < this->nrLines() && 0 <= j && j < this->nrColumns()))
		throw std::exception();

	node* tmp;
	//If any node is not in the list
	if(this->head == NULL){
		tmp = new node;
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->value = e;
		tmp->col = j;
		tmp->row = i;
		this->head = tmp;
		return NULL_TELEM;
	}
	tmp = this->head;
	while(tmp != NULL){
		//if the elem exists we return it
		if(tmp->row == i && tmp->col == j){
			TElem old_value = tmp->value;
			tmp->value = e;
			return old_value;
		}
		// if the the elem doesn't exist we insert it // when we need to insert it inside the list
		else if(tmp->row >= i && tmp->col > j){
			node* new_cell = new node;
			new_cell->row = i;
			new_cell->col = j;
			new_cell->value = e;

			//If the cell needs to be inserted at the beginning of the list
			if(tmp->prev != NULL)
				tmp->prev->next = new_cell;
			new_cell->prev = tmp->prev;
			new_cell->next = tmp;
			tmp->prev = new_cell;
			
			return NULL_TELEM;
		}
		//if the element doesn't exist, but needs to be added at the end
		else if(tmp->next == NULL){
			node* new_cell = new node;
			new_cell->row = i;
			new_cell->col = j;
			new_cell->value = e;
			tmp->next = new_cell;
			new_cell->prev = tmp;
			new_cell->next = NULL;
			return NULL_TELEM;
		}
		tmp = tmp->next;
	}
	return NULL_TELEM;
}


int Matrix::numberOfNonZeroElems()const{
	//theta(n)
	node* tmp = this->head;
	int i = 0;
	while(tmp != NULL){
		tmp = tmp->next;
		i++;
	}
	return i;
}

