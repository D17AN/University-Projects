#include "ui.h"

void UI::printMenu()
{
	std::cout <<  "1. Add building.\n";
	std::cout << "2. Show all.\n";
	std::cout << "3. Show buildings to be restored.\n";
	std::cout << "4. Save to file.\n";
	std::cout << "0. Exit.\n";
}

void UI::printAddBuildingMenu()
{
	std::cout << "1. Add block.\n";
	std::cout << "2. Add house.\n";
	std::cout << "0. Go back.\n";
}

void UI::addBuilding()
{
	while (true){
		try{
			this->printAddBuildingMenu();
			int option;
			std::cout << "Option: "; std::cin >> option; std::cout << "\n";
			if (option == 1){
				this->addBlock();
			}
			else if (option == 2){
				this->addHouse();
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

void UI::addBlock()
{
	try{
		std::string address;
		int constructionYear, totalApartments, occupiedApartments;
		std::cout << "Address: "; std::cin >> address; std::cout << "\n";
		std::cout << "Construction year: "; std::cin >> constructionYear; std::cout << "\n";
		std::cout << "Total apartments: "; std::cin >> totalApartments; std::cout << "\n";
		std::cout << "Occupied apartments: "; std::cin >> occupiedApartments; std::cout << "\n";
		Building* b = new Block{address, constructionYear, totalApartments, occupiedApartments};
		this->c.addBuilding(b);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::addHouse()
{
	try{
		std::string address;
		int constructionYear;
		bool isHistorical;
		std::cout << "Address: "; std::cin >> address; std::cout << "\n";
		std::cout << "Construction year: "; std::cin >> constructionYear; std::cout << "\n";
		std::cout << "Is historical(1 or 0): "; std::cin >> isHistorical; std::cout << "\n";
		Building* b = new House{address, constructionYear, isHistorical};
		this->c.addBuilding(b);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::displayBuildings(std::vector<Building*>& v)
{
	std::for_each(v.begin(), v.end(), [&](Building* b){
		std::cout << b->toString() << "\n";
		});
}

void UI::displayRestoredBuildings()
{
	try{
		int year;
		std::cout << "Year: "; std::cin >> year; std::cout << "\n";
		std::vector<Building*> v = this->c.getAllToBeRestored(year);
		this->displayBuildings(v);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::saveToFile()
{
	try{
		this->c.writeToFile("restoration.txt", this->c.getAllToBeRestored(2023));
		this->c.writeToFile("demolition.txt", this->c.getAllToBeDemolished());
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
				this->addBuilding();
			}
			else if (option == 2){
				this->displayBuildings(this->c.getAllBuildings());
			}
			else if (option == 3){
				this->displayRestoredBuildings();
			}
			else if (option == 4){
				this->saveToFile();
			}
			else if (option == 0){
				break;
			}
			else{
				std::cout << "Bad option.\n";
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



