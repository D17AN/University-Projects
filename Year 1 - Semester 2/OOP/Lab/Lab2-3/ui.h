#pragma once
#include "controller.h"

typedef struct{
	Controller* controller;
}UI;


UI* uiConstructor(Controller* controller);


void uiDeconstructor(UI* ui);


void uiInit(UI* ui);


void uiRunProgram(UI* ui, History* h);


void uiPrintData(Vector* v);