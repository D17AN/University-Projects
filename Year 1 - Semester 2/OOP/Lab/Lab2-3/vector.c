#include "vector.h"
#include<stdlib.h>

Vector* vectorConstructor(int capacity){
	if(capacity < 0){
		return NULL;
	}
	Vector* v = (Vector*)malloc(sizeof(Vector));
	if(v == NULL)
		return NULL;
	v->elems = (TElem**)malloc(sizeof(TElem*) * capacity);
	v->size = 0;
	v->capacity = capacity;
	return v;
}


void vectorDestructor(Vector* v){
	for(int i = 0; i < v->size; i++){
		medicineDeconstructor(v->elems[i]);
		v->elems[i] = NULL;
	}
	free(v->elems);
	v->elems = NULL;
	free(v);
	v = NULL;
}


void vectorResize(Vector* v){
	TElem** tmp = (TElem**)realloc(v->elems, sizeof(TElem*) * v->capacity * 2);
	if(tmp != NULL){
		v->elems = tmp;
		v->capacity *= 2;
	}
}


int vectorGetSize(Vector* v){
	return v->size;
}


int vectorSearchElem(Vector* v, TElem* elem, compareFunction compare){
	for(int i = 0; i < v->size; i++){
		if(compare(elem, v->elems[i]) == 1){//if the elems are equal 
			return i;
		}
	}
	return -1;
}


int vectorAddElem(Vector* v, TElem* elem){
	int initialCapacity = v->capacity;
	if(v->size == v->capacity){
		vectorResize(v);
		if(v->capacity == initialCapacity)//the resize was unsuccessful
			return -1;
	}
	v->elems[v->size++] = elem;
	return 1;
}


int vectorDeletePosition(Vector* v, int pos){

	if(pos < 0 || pos >= v->size)//if the index is out of bounds
		return -1;

	for(int i = pos + 1; i < v->size; i++){
		TElem* m = medicineConstructor(medicineGetName(v->elems[i]), 
			medicineGetConcentration(v->elems[i]), medicineGetQuantity(v->elems[i]),
			medicineGetPrice(v->elems[i]));
		medicineDeconstructor(v->elems[i-1]);
		v->elems[i - 1] = m;
	}
	medicineDeconstructor(v->elems[v->size-1]);
	v->size--;
	return 1;
}


Vector* vectorDeepcopy(Vector* v){
	Vector* newV = vectorConstructor(v->capacity);
	newV->size = v->size;
	for(int i = 0; i < v->size; i++){
		newV->elems[i] = medicineConstructor(v->elems[i]->name, v->elems[i]->concentration, v->elems[i]->quantity, v->elems[i]->price);
	}
	return newV;
}


History* historyConstructor(int capacity){
	History* h = (History*)malloc(sizeof(History));
	if(h == NULL)
		return NULL;
	h->states = (Vector**)malloc(capacity * sizeof(Vector*));
	h->operationIndex = -1;
	h->capacity = capacity;
	h->size = 0;
	return h;
}


void historyDeconstructor(History* h){
	for(int i = 0; i < h->size; i++){
		vectorDestructor(h->states[i]);
		h->states[i] = NULL;
	}
	free(h->states);
	h->states = NULL;
	free(h);
	h = NULL;
}


void historyResize(History* h){
	Vector** tmp = (Vector**)realloc(h->states, sizeof(Vector*) * h->capacity * 2);
	if(tmp == NULL)
		return NULL;
	h->states = tmp;
	h->capacity *= 2;
}


int historyAdd(History* h, Vector* v){
	int start = h->operationIndex + 1;
	int end = h->size;
	historyRemove(h, start, end);
	if(h->size == h->capacity){
		int oldCapacity = h->capacity;
		historyResize(h);
		if(oldCapacity == h->capacity)
			return -1;
	}
	h->states[h->size++] = vectorDeepcopy(v);
	h->operationIndex = h->size - 1;
	return 1;
}


void historyRemove(History* h, int startIndex, int endIndex){
	for(int i = startIndex; i < endIndex; i++){
		for(int j = i + 1; j < h->size; j++){
			Vector* v = vectorDeepcopy(h->states[j]);
			vectorDestructor(h->states[j - 1]);
			h->states[j - 1] = v;
		}
		vectorDestructor(h->states[h->size - 1]);
		h->size--;
		endIndex--;
	}
}


int undo(History* h, Vector** v){
	int undoIndex = h->operationIndex - 1;
	if(undoIndex < 0)
		return -1;
	vectorDestructor(*v);
	*v = vectorDeepcopy(h->states[undoIndex]);
	h->operationIndex--;
	return 1;
}


int redo(History* h, Vector** v){
	int redoIndex = h->operationIndex + 1;
	if(redoIndex >= h->size)
		return -1;
	vectorDestructor(*v);
	*v = vectorDeepcopy(h->states[redoIndex]);
	h->operationIndex++;
	return 1;
}