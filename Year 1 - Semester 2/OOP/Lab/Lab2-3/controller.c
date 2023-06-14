#include "controller.h"
#include<stdlib.h>

Controller* controllerConstructor(Repository* repo){
	Controller* controller = (Controller*)malloc(sizeof(Controller));
	if(controller == NULL)
		return NULL;
	controller->repo = repo;
	return controller;
}


void controllerDestructor(Controller* controller){
	repositoryDestructor(controller->repo);
	free(controller);
}


int controllerAdd(Controller* controller, Medicine* e){
	return repositoryAdd(controller->repo, e);
}


int controllerRemove(Controller* controller, Medicine* e){
	return repositoryRemove(controller->repo, e);
}


int controllerUpdate(Controller* controller, Medicine* e, int newQuantity, float newPrice){
	return repositoryUpdate(controller->repo, e, newQuantity, newPrice);
}


int controllerSearch(Controller* controller, Medicine* e){
	return repositorySearchMedicine(controller->repo, e);
}


Vector* controllerFilterNameContainingSubstring(Controller* controller, char* substr){
	Vector* resultSet = vectorConstructor(repositoryGetSize(controller->repo));
	int n = repositoryGetSize(controller->repo);
	for(int i = 0; i < n; i++){
		if(medicineNameContainSubstring(controller->repo->data->elems[i], substr)){
			vectorAddElem(resultSet, medicineDeepcopy(controller->repo->data->elems[i]));
		}
	}
	int resultSetSize = vectorGetSize(resultSet);
	for(int i = 0; i < resultSetSize - 1; i++){
		for(int j = i + 1; j < resultSetSize; j++){
			if(medicineAscendingOrderByName(resultSet->elems[i], resultSet->elems[j]) == 0){
				TElem* tmp = resultSet->elems[i];
				resultSet->elems[i] = resultSet->elems[j];
				resultSet->elems[j] = tmp;
			}
		}
	}
	return resultSet;
}


Vector* controllerFilterQuantityLessThanX(Controller* controller, int x){
	Vector* resultSet = vectorConstructor(repositoryGetSize(controller->repo));
	int n = repositoryGetSize(controller->repo);
	for(int i = 0; i < n; i++){
		if(medicineGetQuantity(controller->repo->data->elems[i]) < x){
			vectorAddElem(resultSet, medicineDeepcopy(controller->repo->data->elems[i]));
		}
	}

	return resultSet;
}