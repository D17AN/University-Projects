#include "ui.h"

int main(){
	Client* c1 = new Person{"Dan", 5000};
	Client* c2 = new Person{"Constantin", 4000};
	Client* c3 = new Company{"Amazon", 10000000000, 10000};
	Client* c4 = new Company{"Google", 100, 10};
	Dwelling d1{1000, true};
	Dwelling d2{500, false};
	std::vector<Client*> clients{c1, c2, c3, c4};
	std::vector<Dwelling> dwellings{d1, d2};
	RealEstateAgency c{clients, dwellings};
	UI ui{c};
	ui.run();

	for (Client* c : clients){
		delete c;
	}
	return 0;
}