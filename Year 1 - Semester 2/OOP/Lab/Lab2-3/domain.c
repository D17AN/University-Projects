#include "domain.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
Medicine* medicineConstructor(char* new_name, float new_concentration, int new_quantity, float new_price){
	Medicine* m = (Medicine*)malloc(sizeof(Medicine));
	if(m == NULL)
		return NULL;
	m->name = (char*)malloc(sizeof(char) * (strlen(new_name) + 1));
	if(m->name == NULL)
		return NULL;
	strcpy(m->name, new_name);
	m->concentration = new_concentration;
	m->quantity = new_quantity;
	m->price = new_price;
	return m;
}


void medicineDeconstructor(Medicine* m){
	free(m->name);
	free(m);
	m = NULL;
}


Medicine* medicineDeepcopy(Medicine* m){
	Medicine* new_m = (Medicine*)malloc(sizeof(Medicine));
	if(new_m == NULL)
		return NULL;
	new_m->name = (char*)malloc(sizeof(char) * (strlen(m->name) + 1));
	if(new_m->name == NULL)
		return NULL;
	strcpy(new_m->name, m->name);
	new_m->concentration = m->concentration;
	new_m->quantity = m->quantity;
	new_m->price = m->concentration;
	return new_m;
}


char* medicineGetName(Medicine* m){
	return m->name;
}


float medicineGetConcentration(Medicine* m){
	return m->concentration;
}


int medicineGetQuantity(Medicine* m){
	return m->quantity;
}


float medicineGetPrice(Medicine* m){
	return m->price;
}


void medicineSetName(Medicine* m, char* new_name){
	
	if(strlen(m->name) < strlen(new_name)){
		char* tmp = (char*)realloc(m->name, sizeof(char) * strlen(new_name));
		if(tmp != NULL){
			m->name = tmp;
		}
	}
	strcpy(m->name, new_name);
}


void medicineSetConcentration(Medicine* m, float new_concentration){
	m->concentration = new_concentration;
}


void medicineSetQuantity(Medicine* m, int new_quantity){
	m->quantity = new_quantity;
}


void medicineSetPrice(Medicine* m, float new_price){
	m->price = new_price;
}


int medicineEqual(Medicine* m1, Medicine* m2){
	return strcmp(m1->name, m2->name) == 0 &&
		m1->concentration == m2->concentration;
}


int medicineAscendingOrderByName(Medicine* m1, Medicine* m2){
	return strcmp(m1, m2) <= 0;
}


int medicineNameContainSubstring(Medicine* m, char* atr){
	if(strcmp(atr, "") == 0){
		return 1;
	}
	return strstr(m->name, atr) != NULL;
}


void medicinePrint(Medicine* m){
	printf("Name: %s | Concentration: %.2f | Quantity: %d | Price: %.2f\n", m->name, m->concentration, m->quantity, m->price);
}
















