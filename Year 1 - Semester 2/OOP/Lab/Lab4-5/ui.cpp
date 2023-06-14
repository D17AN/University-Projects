#include "ui.h"

UI::UI(ControllerAdministrator& a, ControllerUser& u) : controllerAdministrator{a}, controllerUser{u}, mainIsRunning{ false }, administratorModeIsRunning{false}, userModeIsRunning{false}{
}

UI::~UI(){}

void UI::displayStartingTextMenu(){
	std::string displayText = "\nChoose option:\n1. Run Administrator Mode.\n2. Run User Mode.\n3. Exit program\n";
	std::cout << displayText;
}

void UI::displayAdministratorTextMenu(){
	std::string displayText = "\nImportant! A Trench Coat is unique by its size, color, and photographLink.";
	displayText += "\nChoose Option : \n1. Show all the Trench Coats.";
	displayText += "\n2. Add a TrenchCoat.";
	displayText += "\n3. Remove an existing Trench Coat.";
	displayText += "\n4. Update the information of an existing Trench Coat.";
	displayText += "\n5. Exit administrator mode.";
	displayText += "\n";
	std::cout << displayText;
}

void UI::displayUserTextMenu(){
	std::string displayText = "\n1. Show basket.";
	displayText += "\n2. Navigate Trench Coat catalog.";
	displayText += "\n3. Exit user mode.";
	displayText += "\n";
	std::cout << displayText;
}


void UI::displayUserNavigationCatalogMenu(){
	std::string displayText = "\n1. Next Trench Coat.";
	displayText += "\n2. Add Trench Coat to basket.";
	displayText += "\n3. Display Trench Coat.";
	displayText += "\n4. Exit nagivation mode.";
	displayText += "\n";
	std::cout << displayText;
}


void UI::displayTrenchCoats(Vector<TrenchCoat>& v){
	int size = v.getSize();
	std::cout << "\n";
	for (int i = 0; i < size; i++){
		std::cout << v[i] << "\n";
	}
}


void UI::runProgram(){
	this->mainIsRunning = true;
	std::string option;
	while (this->mainIsRunning){
		UI::displayStartingTextMenu();
		std::cout << "\nEnter option: "; getline(std::cin, option);
		Utils::formatSentence(option);
		if (option == "1"){
			this->runAdministratorMode();
		}
		else if(option == "2"){
			this->runUserMode();
		}
		else if (option == "3"){
			this->mainIsRunning = false;
		}
		else{
			std::cout << "\nWrong option, try again!\n";
		}
		option.clear();
	}
}

void UI::runAdministratorMode(){
	std::cout << "\nAdministrator mode.\n";
	this->administratorModeIsRunning = true;
	std::string option;
	while (this->administratorModeIsRunning){
		UI::displayAdministratorTextMenu();
		std::cout << "\nEnter option: "; getline(std::cin, option);
		Utils::formatSentence(option);
		if (option == "1"){
			UI::displayTrenchCoats(this->controllerAdministrator.get());
		}
		else if (option == "2"){
			this->addAdministrator();
		}
		else if (option == "3"){
			this->removeAdministrator();
		}
		else if (option == "4"){
			this->updateAdministrator();
		}
		else if (option == "5"){
			this->administratorModeIsRunning = false;
		}
		else{
			std::cout << "\nWrong option, try again!\n";
		}

		option.clear();
	}
}


void UI::addAdministrator(){
	TrenchCoat tc;
	std::cout << "\nInput format TrenchCoat: size | color | price | quantity | photograph link\n";
	try{
		std::cout << "Enter input: ";  std::cin >> tc;
		this->controllerAdministrator.add(tc);
	}
	catch (TrenchCoatException& e){
		std::cout << "\n" << e.what() << "\n";
	}
}


void UI::removeAdministrator(){
	TrenchCoat tc;
	std::cout << "\nInput format TrenchCoat: size | color | price | quantity | photograph link\n";
	try{
		std::cout << "Enter input: ";  std::cin >> tc;

		std::string quantityS;
		std::cout << "\nHow many TrenchCoats to delete?"; getline(std::cin, quantityS);
		Utils::formatSentence(quantityS);
		int quantity = std::stoi(quantityS);

		if (TrenchCoatValidator::isQuantityValid(quantity) == false){
			throw TrenchCoatException("The number of TrenchCoats which can be deleted must be a positive integer!");
		}

		this->controllerAdministrator.remove(tc, quantity);

	}
	catch (TrenchCoatException& e){
		std::cout << "\n" << e.what() << "\n";
	}
	catch (std::invalid_argument& e){
		std::cout << "\nThe given amount of TrenchCoats conversion fail! It must be an integer!\n";
	}
	catch (std::out_of_range& e){
		std::cout << "\nThe given amount of TrenchCoats exceeds the range of the data type!\n";
	}
	catch (RepositoryException& e){
		std::cout << "\n" << e.what() << "\n";
	}

}


void UI::updateAdministrator(){
	TrenchCoat tc;
	std::cout << "\nInput format TrenchCoat: size | color | price | quantity | photograph link\n";
	try{
		std::cout << "Enter input: ";  std::cin >> tc;

		std::string newPriceS, newQuantityS;
		std::cout << "\nThe new price: "; getline(std::cin, newPriceS);
		std::cout << "\nThe new quantity: "; getline(std::cin, newQuantityS);

		int newPrice, newQuantity;
		try{
			Utils::formatSentence(newPriceS);
			newPrice = std::stoi(newPriceS);
		}
		catch (std::invalid_argument& e){
			throw std::invalid_argument("The new price couldn't be converted! It must be an integer!");
		}
		catch (std::out_of_range& e){
			throw std::out_of_range("The new price is out of the data type range!");
		}

		try{
			Utils::formatSentence(newQuantityS);
			newQuantity = std::stoi(newQuantityS);
		}
		catch (std::invalid_argument& e){
			throw std::invalid_argument("The new quantity couldn't be converted! It must be an integer!");
		}
		catch (std::out_of_range& e){
			throw std::out_of_range("The new quantity is out of the data type range!");
		}

		if (TrenchCoatValidator::isPriceValid(newPrice) == false){
			throw TrenchCoatException("The new price of the TrenchCoat must be a positive integer!");
		}


		if (TrenchCoatValidator::isQuantityValid(newQuantity) == false){
			throw TrenchCoatException("The new quantity of the TrenchCoat must be a positive integer!");
		}

		this->controllerAdministrator.update(tc, newPrice, newQuantity);

	}
	catch (TrenchCoatException& e){
		std::cout << "\n" << e.what() << "\n";
	}
	catch (std::invalid_argument& e){
		std::cout << "\n" << e.what() << "\n";
	}
	catch (std::out_of_range& e){
		std::cout << "\n" << e.what() << "\n";
	}
	catch (RepositoryException& e){
		std::cout << "\n" << e.what() << "\n";
	}
}


void UI::runUserMode(){
	std::cout << "\nUser mode.\n";
	this->userModeIsRunning = true;
	std::string option = "";
	while (this->userModeIsRunning){
		UI::displayUserTextMenu();
		std::cout << "Enter option: ";  getline(std::cin, option);
		Utils::formatSentence(option);
		if (option == "1"){
			//See basket
			this->displayTrenchCoats(this->controllerUser.getBasket());
			std::cout << "Total amount of the basket: " << this->controllerUser.getBasketTotal() << "\n";
		}
		else if (option == "2"){
			//Navigation
			this->runUserNavigationMode();
		}
		else if (option == "3"){
			//exit User mode
			this->userModeIsRunning = false;
		}
		else{
			std::cout << "\nWrong option, try again!\n";
		}
		option.clear();
	}
}

void UI::runUserNavigationMode(){
	try{
		bool runUserNavigationMode = true;
		std::string option = "";
		std::string size = "";
		std::cout << "\nEnter size: "; getline(std::cin, size);
		Utils::formatSentence(size);

		if (!TrenchCoatValidator::isSizeValid(size) && size != ""){
			throw TrenchCoatException("The entered size is not valid!");
		}

		Vector<TrenchCoat> v = this->controllerUser.getRepo(size);
		int currentPos = 0;
		int len = v.getSize();
		if(len > 0){
			while (runUserNavigationMode){
				this->displayUserNavigationCatalogMenu();
				std::cout << "\n" << v[currentPos] << "\n\n";
				std::cout << "Enter option: ";  getline(std::cin, option);
				Utils::formatSentence(option);
				if (option == "1"){
					currentPos = (currentPos + 1) % len;
				}
				else if (option == "2"){
					this->controllerUser.addToBasket(v[currentPos]);
					std::cout << "Total price of the basket: " << this->controllerUser.getBasketTotal() << "\n";
				}
				else if (option == "3"){
					std::string command = "start " + v[currentPos].getPhotographLink();
					std::system(command.c_str());
				}
				else if (option == "4"){
					runUserNavigationMode = false;
				}
				else{
					std::cout << "\nWrong option, try again!\n";
				}
			}
		}
		else{
			std::cout << "\nSeems there are no " + size + " Trench Coats\n";
		}
	}
	catch (TrenchCoatException& e){
		std::cout << e.what() << "\n";
	}
}

