#include "ui.h"

void UI::printMenu()
{
	std::cout << "1. Add." << "\n";
	std::cout << "2. Remove." << "\n";
	std::cout << "3. Show all." << "\n";
	std::cout << "4. Show proteins having name." << "\n";
	std::cout << "0. Exit." << "\n";
}

void UI::addProtein()
{
	try{
		std::string organism, name, sequence;
		std::cout << "Organism: "; std::cin >> organism;
		std::cout << "Name: "; std::cin >> name;
		std::cout << "Sequence: "; std::cin >> sequence;
		Protein p{ organism, name, sequence };
		this->c.add(p);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::removeProtein()
{
	try{
		std::string organism, name, sequence;
		std::cout << "Organism: "; std::cin >> organism;
		std::cout << "Name: "; std::cin >> name;
		std::cout << "Sequence: "; std::cin >> sequence;
		Protein p{organism, name, sequence};
		this->c.remove(p);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::displayProteins(const std::vector<Protein>& v)
{
	try{
		std::for_each(v.begin(), v.end(), [](const Protein& p){
			std::cout << p << "\n";
		});
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::displayProteinsByName()
{
	try{
		std::string name;
		std::cout << "Name: "; std::cin >> name;
		std::vector<Protein> v = this->c.getByName(name);
		this->displayProteins(v);
		std::cout << "Size: " << v.size() << "\n";
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::run()
{
	while (true){
		try{
			int option;
			this->printMenu();
			std::cout << "Enter option: "; std::cin >> option;
			if (option == 0){
				break;
			}
			else if (option == 1){
				this->addProtein();
			}
			else if (option == 2){
				this->removeProtein();
			}
			else if (option == 3){
				this->displayProteins(this->c.getAll());
			}
			else if (option == 4){
				this->displayProteinsByName();
			}
			else{
				std::cout << "Invalid option!\n";
			}
		}
		catch (std::exception& e){
			std::cout << e.what() << "\n";
		}
	}
}
