#include "ui.h"

void UI::printMenu()
{
	std::cout << "1. Add hospital department.\n";
	std::cout << "2. Show all.\n";
	std::cout << "3. Show all efficient.\n";
	std::cout << "4. Save to file.\n";
	std::cout << "0. Exit.\n";
}

void UI::printMenuHospitalDepartment()
{
	std::cout << "1. Add Surgery Department.\n";
	std::cout << "2. Add NeonatalUnit Department.\n";
	std::cout << "0. Go back.\n";
}

void UI::addHospitalDepartment()
{
	while (true){
		try{
			this->printMenuHospitalDepartment();
			int option;
			std::cout << "Option: "; std::cin >> option; std::cout << "\n";
			if (option == 1){
				this->addSurgery();
			}
			else if (option == 2){
				this->addNeonatalUnit();
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

void UI::addNeonatalUnit()
{
	try{
		std::string name;
		int nrDoctors, nrMothers, nrNewBorns;
		double averageGrade;
		std::cout << "Name: "; std::cin >> name; std::cout << "\n";
		std::cout << "Number doctors: "; std::cin >> nrDoctors; std::cout << "\n";
		std::cout << "Number mothers: "; std::cin >> nrMothers; std::cout << "\n";
		std::cout << "Number new borns: "; std::cin >> nrNewBorns; std::cout << "\n";
		std::cout << "Average grade: "; std::cin >> averageGrade; std::cout << "\n";
		
		HospitalDepartment* h = new NeonatalUnit(name, nrDoctors, nrMothers, nrNewBorns, averageGrade);

		this->c.addDepartment(h);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::addSurgery(){
	try{
		std::string name;
		int nrDoctors, nrPatients;
		std::cout << "Name: "; std::cin >> name; std::cout << "\n";
		std::cout << "Number doctors: "; std::cin >> nrDoctors; std::cout << "\n";
		std::cout << "Number patients: "; std::cin >> nrPatients; std::cout << "\n";

		HospitalDepartment* h = new Surgery(name, nrDoctors, nrPatients);

		this->c.addDepartment(h);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::display(const std::vector<HospitalDepartment*>& v)
{
	std::cout << "Hospital Departments:\n";
	std::for_each(v.begin(), v.end(), [&](HospitalDepartment* h){
		std::cout << h->toString() << "\n";
		});
}

void UI::run()
{
	while (true){
		try{
			this->printMenu();
			int option;
			std::cout << "Option: "; std::cin >> option; std::cout << "\n";
			if (option == 1){
				this->addHospitalDepartment();
			}
			else if (option == 2){
				this->display(this->c.getAllDepartments());
			}
			else if (option == 3){
				this->display(this->c.getAllEfficientDepartments());
			}
			else if (option == 4){
				this->c.writeToFile("departments.txt");
			}
			else if (option == 0){
				break;
			}
			else{
				std::cout << "Bad option\n";
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
