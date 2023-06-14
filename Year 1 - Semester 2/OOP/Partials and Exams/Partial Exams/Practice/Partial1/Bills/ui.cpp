#include "ui.h"

void UI::printMenu()
{
	std::cout << "1. Add bill" << std::endl;
	std::cout << "2. Delete bill" << std::endl;
	std::cout << "3. Display all" << std::endl;
	std::cout << "4. Display unpaid bills" << std::endl;
	std::cout << "5. Total amount of unpaid bills" << std::endl;
	std::cout << "0. Exit" << std::endl;
}

void UI::addBillUI()
{
	try{
		std::string id, company;
		int day, month, year;
		double sum;
		bool paid;
		std::cout << "Id: "; std::cin >> id;
		std::cout << "Company: "; std::cin >> company;
		std::cout << "Day: "; std::cin >> day;
		std::cout << "Month: "; std::cin >> month;
		std::cout << "Year: "; std::cin >> year;
		std::cout << "Sum: "; std::cin >> sum;
		std::cout << "Paid: "; std::cin >> paid;
		Bill c(id, company, Date(day, month, year), sum, paid);
		ctrl.addBill(c);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void UI::deleteBillUI()
{
	try{
		std::string id, company;
		int day, month, year;
		double sum;
		bool paid;
		std::cout << "Id: "; std::cin >> id;
		std::cout << "Company: "; std::cin >> company;
		std::cout << "Day: "; std::cin >> day;
		std::cout << "Month: "; std::cin >> month;
		std::cout << "Year: "; std::cin >> year;
		std::cout << "Sum: "; std::cin >> sum;
		std::cout << "Paid: "; std::cin >> paid;
		Bill c(id, company, Date(day, month, year), sum, paid);
		ctrl.deleteBill(c);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

void UI::displayAllUI(const std::vector<Bill>& v)
{
	std::for_each(v.begin(), v.end(), [](const Bill& b){
		std::cout << b << std::endl; 
		});
}

UI::UI(Controller& c) : ctrl{c}{
	Bill b1{"0A33455X", "Digi", Date(15, 04, 2016), 75.00, false};
	Bill b2{"EED36677", "E-On", Date(16, 03, 2016), 122.00, true};
	Bill b3{"X990TTRR", "Orange", Date(18, 04, 2016), 46.00, false};
	Bill b4{"1234RR55", "Vodafone", Date(20, 04, 2016), 75.00, false};
	Bill b5{"TRE3EERR", "Tcomm", Date(21, 04, 2016), 10.00, true};
	this->ctrl.addBill(b1);
	this->ctrl.addBill(b2);
	this->ctrl.addBill(b3);
	this->ctrl.addBill(b4);
	this->ctrl.addBill(b5);
}

void UI::run()
{
	while (true){
		int option;
		printMenu();
		std::cout << "Option: "; std::cin >> option;

		if (option == 0){
			break;
		}
		else if (option == 1){
			addBillUI();
		}
		else if (option == 2){
			deleteBillUI();
		}
		else if (option == 3){
			displayAllUI(ctrl.getAll());
		}
		else if (option == 4){
			displayAllUI(ctrl.getAllUnpaidSortedByDate());
		}
		else if (option == 5){
			std::cout << ctrl.getTotalUnpaidBills() << std::endl;
		}
		else{
			std::cout << "Invalid option!" << std::endl;
		}
	}
}
