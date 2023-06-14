#include "ui.h"

void UI::printMenu()
{
	std::cout << "1. Update client.\n";
	std::cout << "2. Show all.\n";
	std::cout << "3. Add dwelling.\n";
	std::cout << "4. Save clients to file.\n";
	std::cout << "0. Exit.\n";
}

void UI::updateClient()
{
	try{
		std::string name;
		double newIncome;
		std::cout << "Name: "; std::cin >> name; std::cout << "\n";
		std::cout << "newIncome: "; std::cin >> newIncome; std::cout << "\n";
		this->c.updateClient(name, newIncome);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::showAll()
{
	std::vector<Client*> clients = this->c.getClients();
	std::vector<Dwelling> dwellings = this->c.getDwellings();
	std::cout << "Clients:\n";
	std::for_each(clients.begin(), clients.end(), [&](Client* c){
		std::cout << c->toString() << "\n";
		});
	std::cout << "\nDwellings:\n";
	std::for_each(dwellings.begin(), dwellings.end(), [&](Dwelling& d){
		std::cout << d.getPrice() << "|" << d.getIsProfitable() << "\n";
		});
}

void UI::addDwelling()
{
	try{
		double price;
		bool isProfitable;
		std::cout << "Price: "; std::cin >> price; std::cout << "\n";
		std::cout << "Is profitable?(1 or 0): "; std::cin >> isProfitable; std::cout << "\n";
		Dwelling d = this->c.addDwelling(price, isProfitable);
		std::cout << "Interested client:\n"; 
		std::vector<Client*> clients = this->c.getInterestedClients(d);
		std::for_each(clients.begin(), clients.end(), [&](Client* c){
			std::cout << c->toString() << "\n";
			});
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::run()
{
	while (true){
		try{
			this->printMenu();
			int option;
			std::cout << "Option: "; std::cin >> option; std::cout << "\n";
			if (option == 1){
				this->updateClient();
			}
			else if (option == 2){
				this->showAll();
			}
			else if (option == 3){
				this->addDwelling();
			}
			else if (option == 4){
				this->c.writeToFile("clients.txt");
			}
			else if (option == 0){
				break;
			}
			else{
				std::cout << "Bad option!\n";
			}
		}
		catch (std::exception& e){
			std::cout << e.what() << "\n";
		}
	}
}

UI::~UI()
{
}
