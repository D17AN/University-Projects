#include "ui.h"

UI::UI(Controller& cntr) : cntr{cntr}{
	Car c1{"Fiat", "Bravo", 2007, "red"};
	Car c2{"Fiat", "Idea", 2003, "black"};
	Car c3{"Audi", "A5", 2007, "blue"};
	Car c4{"BMW", "Coupe", 2013, "pink"};
	Car c5{"Ford", "Fiesta", 1976, "yellow"};
	this->cntr.add(c1);
	this->cntr.add(c2);
	this->cntr.add(c3);
	this->cntr.add(c4);
	this->cntr.add(c5);
}

void UI::display(const std::vector<Car>& v){
	std::for_each(v.begin(), v.end(), [](const Car& c){
		std::cout << c << "\n";
		});
}

void UI::add(){
	try{
		std::string name, model, colour;
		int year;
		std::cout << "\nname="; std::cin >> name;
		std::cout << "\nmodel="; std::cin >> model;
		std::cout << "\nyear="; std::cin >> year;
		std::cout << "\ncolour="; std::cin >> colour;
		Car c{name, model, year, colour};
		this->cntr.add(c);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::remove()
{
	try{
		std::string name, model, colour;
		int year;
		std::cout << "\nname="; std::cin >> name;
		std::cout << "\nmodel="; std::cin >> model;
		std::cout << "\nyear="; std::cin >> year;
		std::cout << "\ncolour="; std::cin >> colour;
		Car c{name, model, year, colour};
		this->cntr.remove(c);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::menu(){
	std::cout << "\n1.Show all.\n2.Add.\n3.Remove.\n4.Show vintage.\n5.Exit.\n";
}

void UI::run(){
	while (true){
		try{
			int option;
			this->menu();
			std::cout << "\noption="; std::cin >> option; std::cout << "\n";
			if (option == 1){
				this->display(this->cntr.getSortedByManufacturerAndModel());
			}
			else if (option == 2){
				this->add();
			}
			else if (option == 3){
				this->remove();
			}
			else if (option == 4){
				this->display(this->cntr.getVintageCars());
			}
			else if (option == 5){
				break;
			}
			else{
				std::cout << "\nBad option!\n";
			}
		}
		catch (std::exception& e){
			std::cout << e.what() << "\n";
		}
	}
}
