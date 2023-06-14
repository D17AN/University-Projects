#include "ui.h"

UI::UI(ControllerAdministrator& a, ControllerUser& u) : controllerAdministrator{a}, controllerUser{u}, mainIsRunning{ false }, administratorModeIsRunning{false}, userModeIsRunning{false}{
}

UI::~UI(){}

void UI::displayStartingTextMenu(){
	std::string displayText = "Choose option:\n1. Run Administrator Mode.\n2. Run User Mode.\n0. Exit program\n";
	std::cout << displayText;
}

void UI::displayAdministratorTextMenu(){
	std::string displayText = "Important! A Trench Coat is unique by its size, color, and photographLink.\n";
	displayText += "Choose Option : \n1. Show all the Trench Coats.\n";
	displayText += "2. Add a TrenchCoat.\n";
	displayText += "3. Remove an existing Trench Coat.\n";
	displayText += "4. Update the information of an existing Trench Coat.\n";
	displayText += "0. Exit administrator mode.\n";
	std::cout << displayText;
}

void UI::displayUserTextMenu(){
	std::string displayText = "1. Show basket.\n";
	displayText += "2. Navigate Trench Coat catalog.\n";
	displayText += "3. Basket List (CSV or HTML).\n";
	displayText += "0. Exit user mode.\n";
	std::cout << displayText;
}


void UI::displayUserNavigationCatalogMenu(){
	std::string displayText = "\n1. Next Trench Coat.";
	displayText += "\n2. Add Trench Coat to basket.";
	displayText += "\n3. Display Trench Coat.";
	displayText += "\n0. Exit nagivation mode.";
	displayText += "\n";
	std::cout << displayText;
}


void UI::displayTrenchCoats(std::vector<TrenchCoat>& v){
	std::cout << "\n";
	std::for_each(v.begin(), v.end(), [](TrenchCoat& tc){
		std::cout << tc << '\n';
		});
	std::cout << "\n";
}


void UI::runProgram(){
	std::string option;
	Basket* b = nullptr;

	while (true){
		std::cout << "Type of Basket(CSV or HTML): "; getline(std::cin, option);
		Utils::formatSentence(option);
		if (option == "csv"){
			b = new BasketCSV(DEFAULT_BASKET_CSV);
			this->controllerUser.setBasket(b);
			break;
		}
		else if (option == "html"){
			b = new BasketHTML(DEFAULT_BASKET_HTML);
			this->controllerUser.setBasket(b);
			break;
		}
		else{
			std::cout << "Bad option. Try again!\n";
		}
		option.clear();
	}

	this->mainIsRunning = true;
	while (this->mainIsRunning){
		option.clear();
		UI::displayStartingTextMenu();
		std::cout << "\nEnter option: "; getline(std::cin, option);
		Utils::formatSentence(option);
		if (option == "1"){
			this->runAdministratorMode();
		}
		else if(option == "2"){
			this->runUserMode();
		}
		else if (option == "0"){
			this->mainIsRunning = false;
			delete b;
			b = nullptr;
		}
		else{
			std::cout << "Wrong option, try again!\n";
		}
	}
}


void UI::run(){
	Repository repo("repositoryInit.txt");

	Basket* basket = nullptr;
	
	ControllerAdministrator controllerAdministrator{repo};
	ControllerUser controllerUser{repo, basket};
	UI ui{controllerAdministrator, controllerUser};

	ui.runProgram();

	delete basket;
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
		else if (option == "0"){
			this->administratorModeIsRunning = false;
		}
		else{
			std::cout << "Wrong option, try again!\n";
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
		std::cout << e.what() << "\n";
	}
}


void UI::removeAdministrator(){
	TrenchCoat tc;
	std::cout << "Input format TrenchCoat: size | color | price | quantity | photograph link\n";
	try{
		std::cout << "Enter input: ";  std::cin >> tc; std::cout << "\n";

		std::string quantityS;
		std::cout << "How many TrenchCoats to delete?"; getline(std::cin, quantityS); std::cout << "\n";
		Utils::formatSentence(quantityS);
		int quantity = std::stoi(quantityS);

		if (TrenchCoatValidator::isQuantityValid(quantity) == false){
			throw TrenchCoatException("The number of TrenchCoats which can be deleted must be a positive integer!");
		}

		this->controllerAdministrator.remove(tc, quantity);

	}
	catch (TrenchCoatException& e){
		std::cout << e.what() << "\n";
	}
	catch (std::invalid_argument& e){
		std::cout << "The given amount of TrenchCoats conversion fail! It must be an integer!\n";
	}
	catch (std::out_of_range& e){
		std::cout << "The given amount of TrenchCoats exceeds the range of the data type!\n";
	}
	catch (RepositoryException& e){
		std::cout << e.what() << "\n";
	}

}


void UI::updateAdministrator(){
	TrenchCoat tc;
	std::cout << "Input format TrenchCoat: size | color | price | quantity | photograph link\n";
	try{
		std::cout << "Enter input: ";  std::cin >> tc; std::cout << "\n";

		std::string newPriceS, newQuantityS;
		std::cout << "The new price: "; getline(std::cin, newPriceS); std::cout << "\n";
		std::cout << "The new quantity: "; getline(std::cin, newQuantityS); std::cout << "\n";

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
		std::cout << e.what() << "\n";
	}
	catch (std::invalid_argument& e){
		std::cout << e.what() << "\n";
	}
	catch (std::out_of_range& e){
		std::cout << e.what() << "\n";
	}
	catch (RepositoryException& e){
		std::cout << e.what() << "\n";
	}
}


void UI::runUserMode(){
	std::cout << "User mode.\n";
	this->userModeIsRunning = true;
	std::string option = "";
	while (this->userModeIsRunning){
		UI::displayUserTextMenu();
		std::cout << "Enter option: ";  getline(std::cin, option); std::cout << "\n";
		Utils::formatSentence(option);
		if (option == "1"){
			//See basket
			try{
				this->displayTrenchCoats(this->controllerUser.getBasket());
				std::cout << "Total amount of the basket: " << this->controllerUser.getBasketTotal() << "\n";
			}
			catch (RepositoryException& e){
				std::cout << e.what() << "\n";
			}
		}
		else if (option == "2"){
			//Navigation
			this->runUserNavigationMode();
		}
		else if (option == "3"){
			std::string cmd = "start " + this->controllerUser.getFileName();
			system(cmd.c_str());
		}
		else if (option == "0"){
			//exit User mode
			this->userModeIsRunning = false;
		}
		else{
			std::cout << "Wrong option, try again!\n";
		}
		option.clear();
	}
}

void UI::runUserNavigationMode(){
	try{
		bool runUserNavigationMode = true;
		std::string option = "";
		std::string size = "";
		std::cout << "Enter size: "; getline(std::cin, size); std::cout << "\n";
		Utils::formatSentence(size);

		if (!TrenchCoatValidator::isSizeValid(size) && size != ""){
			throw TrenchCoatException("The entered size is not valid!");
		}

		std::vector<TrenchCoat> v = this->controllerUser.getRepo(size);
		int currentPos = 0;
		int len = v.size();
		if(len > 0){
			while (runUserNavigationMode){
				try{
					this->displayUserNavigationCatalogMenu();
					std::cout << v[currentPos] << "\n";
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
					else if (option == "0"){
						runUserNavigationMode = false;
					}
					else{
						std::cout << "Wrong option, try again!\n";
					}
				}
				catch (RepositoryException& e){
					std::cout << e.what() << "\n";
				}
			}
		}
		else{
			std::cout << "Seems there are no " + size + " Trench Coats\n";
		}
	}
	catch (TrenchCoatException& e){
		std::cout << e.what() << "\n";
	}
}

