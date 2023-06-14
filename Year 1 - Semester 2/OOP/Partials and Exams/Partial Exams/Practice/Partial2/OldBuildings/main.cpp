#include "ui.h"

int main(){

	Building* b1 = new House("Address1", 1900, true);
	Building* b2 = new Block("Address2", 1976, 100, 82);
	Building* b3 = new Block("Address3", 2000, 100, 2);
	std::vector<Building*> v{b1, b2, b3};
	Service s{v};
	UI ui{s};
	ui.run();


	for (Building* b : v){
		delete b;
	}

	return 0;
}