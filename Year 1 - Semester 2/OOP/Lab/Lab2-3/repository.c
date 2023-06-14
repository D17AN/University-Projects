#include "repository.h"
#include<stdlib.h>
Repository* repositoryConstructor(){
	Repository* repo = (Repository*)malloc(sizeof(Repository));
	if(repo == NULL)
		return NULL;
	repo->data = vectorConstructor(10);
	return repo;
}


void repositoryDestructor(Repository* repo){
	vectorDestructor(repo->data);
	free(repo);
}


int repositoryGetSize(Repository* repo){
	return vectorGetSize(repo->data);
}


int repositoryUpdate(Repository* repo, Medicine* e, int newQuantity, float newPrice){
	int pos = vectorSearchElem(repo->data, e, medicineEqual);
	if(pos != -1){
		medicineSetQuantity(repo->data->elems[pos], newQuantity);
		medicineSetPrice(repo->data->elems[pos], newPrice);
		return 1;
	}
	return -1;
}


int repositoryAdd(Repository* repo, Medicine* e){
	int pos = vectorSearchElem(repo->data, e, medicineEqual);
	if(pos == -1){
		//the element doesn't exist
		return vectorAddElem(repo->data, e);
	}
	else{
		//the element already exists
		medicineSetQuantity(repo->data->elems[pos], medicineGetQuantity(repo->data->elems[pos]) + 1);
		medicineDeconstructor(e);
		return 1;
	}
}


int repositoryRemove(Repository* repo, Medicine* e){
	int pos = vectorSearchElem(repo->data, e, medicineEqual);
	if(pos != -1){
		//the element is in list
		int medicineQuantity = medicineGetQuantity(repo->data->elems[pos]);
		if(medicineQuantity > 1){
			//quantity is over 1
			medicineSetQuantity(repo->data->elems[pos], medicineQuantity - 1);
		}
		else{
			//quantity is 1, then we need to delete the elem
			vectorDeletePosition(repo->data, pos);
		}
		return 1;
	}
	else{
		return -1;
	}
}


int repositorySearchMedicine(Repository* repo, Medicine* e){
	return vectorSearchElem(repo->data, e, medicineEqual);
}
