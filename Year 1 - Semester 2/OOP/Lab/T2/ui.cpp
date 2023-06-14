#include "ui.h"

void UI::printMenu()
{
	std::cout << "1. Add car.\n";
	std::cout << "2. Show all.\n";
	std::cout << "3. Save to file.\n";
	std::cout << "0. Exit.\n";
}

void UI::addCarUI()
{
	try{
		int nrDoors;
		std::string engineType;
		int autonomy;
		std::cout << "Number doors(2 or 4): "; std::cin >> nrDoors; std::cout << "\n";
		std::cout << "Engine type(electric or turbo): "; std::cin >> engineType; std::cout << "\n";
		std::cout << "Autonomy: "; std::cin >> autonomy; std::cout << "\n";
		this->s.addCar(nrDoors, engineType, autonomy);
		std::cout << engineType << "|" << this->s.getCars().back().toString() << "\n";
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::displayCars(const std::vector<Car>& v)
{
	std::for_each(v.begin(), v.end(), [&](Car c){
		std::cout << c.toString() << "\n";
		});
}

void UI::run()
{
	while (true){
		try{
			this->printMenu();
			int option;
			std::cout << "Option: "; std::cin >> option; std::cout << "\n";
			if(option == 1){
				this->addCarUI();
			}
			else if (option == 2){
				this->displayCars(this->s.getCars());
			}
			else if (option == 3){
				
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
