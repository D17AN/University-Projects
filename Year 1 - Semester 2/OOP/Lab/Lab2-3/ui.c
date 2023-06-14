#include "ui.h"
#include "util.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
UI* uiConstructor(Controller* controller){
	UI* ui = (UI*)malloc(sizeof(UI));
	if(ui == NULL)
		return NULL;
	ui->controller = controller;
	return ui;
}


void uiDeconstructor(UI* ui){
	controllerDestructor(ui->controller);
	free(ui);
}


void uiAddMedicine(UI* ui){
	char name[256];
	float concentration, price;
	int quantity;
	printf("Add medicine\n");
	printf("Enter name: "); fgetc(stdin); fgets(name, 254, stdin); printf("\n"); 
	printf("Enter concentration: "); scanf_s("%f", &concentration); printf("\n");
	printf("Enter price: "); scanf_s("%f", &price); printf("\n");
	printf("Enter quantity: "); scanf_s("%d", &quantity); printf("\n");
	formatText(name);
	concentration = floorf(concentration * 100) / 100;
	price = floorf(price * 100) / 100;
	Medicine* m = medicineConstructor(name, concentration, quantity, price);
	
	int res = controllerAdd(ui->controller, m);
	if(res == -1)
		printf("Something bad happend when adding the element\n");
	else
		printf("The medicine was added successfully\n");
}


void uiRemoveMedicine(UI* ui){
	char name[256];
	float concentration, price;
	int quantity;
	printf("Remove medicine\n");
	printf("Enter name: "); fgetc(stdin); fgets(name, 254, stdin); printf("\n");
	printf("Enter concentration: "); scanf_s("%f", &concentration); printf("\n");
	printf("Enter price: "); scanf_s("%f", &price); printf("\n");
	printf("Enter quantity: "); scanf_s("%d", &quantity); printf("\n");
	formatText(name);
	concentration = floorf(concentration * 100) / 100;
	price = floorf(price * 100) / 100;

	Medicine* m = medicineConstructor(name, concentration, quantity, price);

	int res = controllerRemove(ui->controller, m);

	if(res == -1){
		printf("The medicine doesn't exist, it can't be deleted\n");
	}
	else{
		printf("The medicine was successfully deleted\n");
	}
	medicineDeconstructor(m);
}


void uiUpdateMedicine(UI* ui){
	char name[256];
	float concentration, price;
	int quantity;
	printf("Update medicine\n");
	printf("Enter name: "); fgetc(stdin); fgets(name, 254, stdin); printf("\n");
	printf("Enter concentration: "); scanf_s("%f", &concentration); printf("\n");
	printf("Enter price: "); scanf_s("%f", &price); printf("\n");
	printf("Enter quantity: "); scanf_s("%d", &quantity); printf("\n");
	formatText(name);
	concentration = floorf(concentration * 100) / 100;
	price = floorf(price * 100) / 100;

	Medicine* m = medicineConstructor(name, concentration, quantity, price);
	
	float newPrice;
	int newQuantity;
	printf("Enter new price: "); scanf_s("%f", &newPrice); printf("\n");
	printf("Enter new quantity: "); scanf_s("%d", &newQuantity); printf("\n");
	newPrice = floorf(newPrice * 100) / 100;

	int res = controllerUpdate(ui->controller, m, newQuantity, newPrice);

	if(res == -1){
		printf("The medicine doesn't exist, it can't be updated\n");
	}
	else{
		printf("The medicine was successfully updated\n");
	}

	medicineDeconstructor(m);
}


void uiFilterNameContainingSubstring(UI* ui){
	char substr[256];
	printf("Filter medicines\n");
	printf("Enter substring to match the medicines(use "" for display all the medicines): "); 
	fgetc(stdin); fgets(substr, 254, stdin); printf("\n");
	formatText(substr);
	
	Vector* v = controllerFilterNameContainingSubstring(ui->controller, substr);
	
	uiPrintData(v);

	vectorDestructor(v);
}


void uiFilterQuantityLessThanX(UI* ui){
	int x;
	printf("Filter the medicines having quantity less than x\n");
	printf("Enter x: ");
	scanf_s("%d", &x);
	printf("\n");
	
	Vector* v = controllerFilterQuantityLessThanX(ui->controller, x);
	uiPrintData(v);

	vectorDestructor(v);
}


void uiPrintData(Vector* v){
	int n = v->size;
	printf("\n");
	for(int i = 0; i < n; i++){
		medicinePrint(v->elems[i]);
	}
	printf("\n");
}


void uiPrintMenu(){
	char* menu = "\n1. Show all the medicines.\n2. Add medicine.\n3. Remove medicine.\n4. Update medicine.\n5. Show all the medicines which contain a string in their name.\n6. Show all the medicines having their quantity less than x\n7. Undo\n8. Redo\n9. Exit\n";
	printf("%s", menu);
}

void uiRunProgram(UI* ui, History* h){
	historyAdd(h, ui->controller->repo->data);
	while(1){
		uiPrintMenu();
		int option; printf("Enter option: "); scanf_s("%d", &option); printf("\n");
		if(option == 1){
			uiPrintData(ui->controller->repo->data);
		}
		else if(option == 2){
			uiAddMedicine(ui);
			historyAdd(h, ui->controller->repo->data);
		}
		else if(option == 3){
			uiRemoveMedicine(ui);
			historyAdd(h, ui->controller->repo->data);
		}
		else if(option == 4){
			uiUpdateMedicine(ui);
			historyAdd(h, ui->controller->repo->data);
		}
		else if(option == 5){
			uiFilterNameContainingSubstring(ui);
		}
		else if(option == 6){
			uiFilterQuantityLessThanX(ui);
		}
		else if(option == 7){
			int res = undo(h, &ui->controller->repo->data);
			if(res == -1)
				printf("\nNo available undo!\n");
		}
		else if(option == 8){
			int res = redo(h, &ui->controller->repo->data);
			if(res == -1)
				printf("\nNo available redo!\n");
		}
		else if(option == 9){
			break;
		}
		else{
			printf("Wrong option, try again\n");
		}
	}
}


void uiInit(UI* ui){
	Medicine* m1 = medicineConstructor("paracetamol", (float)80, 2, (float)10.99);
	Medicine* m2 = medicineConstructor("nurofen", (float)70, 11, (float)15.35);
	Medicine* m3 = medicineConstructor("coldrex", (float)65, 10, (float)21.99);
	Medicine* m4 = medicineConstructor("teraflu", (float)73.25, 18, (float)13.25);
	Medicine* m5 = medicineConstructor("faringosept", (float)91, 20, (float)5.99);
	Medicine* m6 = medicineConstructor("acc", (float)80.30, 3, (float)16.99);
	Medicine* m7 = medicineConstructor("aspirina", (float)87.45, 2, (float)20.09);
	Medicine* m8 = medicineConstructor("colebil", (float)92.5, 19, (float)50.99);
	Medicine* m9 = medicineConstructor("dicarbocalm", (float)59.99, 1, (float)41.29);
	Medicine* m10 = medicineConstructor("faringocalm", (float)73.4, 7, (float)32.99);
	controllerAdd(ui->controller, m1);
	controllerAdd(ui->controller, m2);
	controllerAdd(ui->controller, m3);
	controllerAdd(ui->controller, m4);
	controllerAdd(ui->controller, m5);
	controllerAdd(ui->controller, m6);
	controllerAdd(ui->controller, m7);
	controllerAdd(ui->controller, m8);
	controllerAdd(ui->controller, m9);
	controllerAdd(ui->controller, m10);
}