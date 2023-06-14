#include "ui.h"

UI::UI(Controller& controller) : controller{controller}{
	School s1{"Avram_Iancu", "46.77,23.60", Date{ 15, 04, 2022 }, true};
	School s2{"George_Cosbuc", "46.77,23.58", Date{ 18, 04, 2022 }, false};
	School s3{"Alexandru_Vaida_Voievod", "46.77,23.63", Date{ 23, 04, 2022 }, false};
	School s4{"Romulus_Guga", "46.53,24.57", Date{ 04, 05, 2022 }, false};
	School s5{"Colegiul_Transilvania", "46.54,24.57", Date{ 03, 05, 2022 }, false};
	this->controller.addSchool(s1);
	this->controller.addSchool(s2);
	this->controller.addSchool(s3);
	this->controller.addSchool(s4);
	this->controller.addSchool(s5);
}

void UI::run()
{
	while (true){
		try{
			this->printMenu();
			int option;
			std::cout << "Option: "; std::cin >> option;
			if (option == 1)
				this->addSchool();
			else if (option == 2)
				this->deleteSchool();
			else if (option == 3)
				this->getAllUnvisitedAfterDate();
			else if (option == 4){
				this->printAll(this->controller.getAll());
			}
			else if (option == 0)
				break;
		}
		catch (std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
}

void UI::addSchool()
{
	try{
		std::string name, address;
		int day, month, year;
		bool visited;
		std::cout << "Name: "; std::cin >> name;
		std::cout << "Address: "; std::cin >> address;
		std::cout << "Day: "; std::cin >> day;
		std::cout << "Month: "; std::cin >> month;
		std::cout << "Year: "; std::cin >> year;
		std::cout << "Visited: "; std::cin >> visited;
		School school{ name, address, Date{ day, month, year }, visited };
		this->controller.addSchool(school);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void UI::deleteSchool()
{
	try{
		std::string name, address;
		int day, month, year;
		bool visited;
		std::cout << "Name: "; std::cin >> name;
		std::cout << "Address: "; std::cin >> address;
		std::cout << "Day: "; std::cin >> day;
		std::cout << "Month: "; std::cin >> month;
		std::cout << "Year: "; std::cin >> year;
		std::cout << "Visited: "; std::cin >> visited;
		School school{name, address, Date{ day, month, year }, visited};
		this->controller.deleteSchool(school);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void UI::getAllUnvisitedAfterDate()
{
	try{
		int day, month, year;
		std::cout << "Day: "; std::cin >> day;
		std::cout << "Month: "; std::cin >> month;
		std::cout << "Year: "; std::cin >> year;
		Date date{ day, month, year };
		const std::vector<School>& v = this->controller.getAllUnvisitedAfterDate(date);
		this->printAll(v);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void UI::printAll(const std::vector<School>& v)
{
	std::for_each(v.begin(), v.end(), [](const School& s) {
		std::cout << s << std::endl;
		});
}

void UI::printMenu()
{
	std::cout << "1. Add school" << std::endl;
	std::cout << "2. Delete school" << std::endl;
	std::cout << "3. Get all unvisited schools after a given date" << std::endl;
	std::cout << "4. Print all schools" << std::endl;
	std::cout << "0. Exit" << std::endl;
}
