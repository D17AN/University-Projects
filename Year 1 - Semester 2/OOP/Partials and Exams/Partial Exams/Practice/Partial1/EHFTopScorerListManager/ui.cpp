#include "ui.h"

void UI::menu(){
	std::cout << "\n1. Show all.\n2. Add player.\n3. Show player by team.\n4. Exit.\n";
}

void UI::display(const std::vector<Player>& v){
	if (v.size() == 0){
		std::cout << "\nNo players!\n";
		return;
	}

	std::for_each(v.begin(), v.end(), [](const Player& p){
		std::cout << p << "\n";
		});
}

void UI::add(){
	try{
		std::string name, nationality, team;
		int goals;
		std::cout << "\nname="; std::cin >> name;
		std::cout << "\nnationality="; std::cin >> nationality;
		std::cout << "\nteam="; std::cin >> team;
		std::cout << "\ngoals="; std::cin >> goals;
		Player p{name, nationality, team, goals};
		this->cntr.add(p);
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

void UI::displayByTeam(){
	try{
		std::string team;
		std::cout << "\nteam="; std::cin >> team;
		this->display(this->cntr.getPlayersHavingTeam(team));
	}
	catch (std::exception& e){
		std::cout << e.what() << "\n";
	}
}

UI::UI(Controller& cntr) : cntr{cntr}{
	Player p1{"Nora_Mork", "NOR", "Larvik", 83};
	Player p2{"Isabelle_Gullden", "SWE", "CSM_Bucharest", 80};
	Player p3{"Cristina_Neagu", "ROU", "Buducnost", 63};
	Player p4{"Allison_Pineau", "FRA", "HCM_Baia_Mare", 82};
	Player p5{"Ilina_Ekaterina", "RUS", "Rostov-Don", 80};
	Player p6{"Nerea_Pena", "ESP", "FTC-Rail_Cargo_Hungaria", 59};
	this->cntr.add(p1);
	this->cntr.add(p2);
	this->cntr.add(p3);
	this->cntr.add(p4);
	this->cntr.add(p5);
	this->cntr.add(p6);
}

void UI::run(){
	while (true){
		try{
			this->menu();
			int option;
			std::cout << "\noption="; std::cin >> option;
			if (option == 1){
				this->display(this->cntr.get());
			}
			else if (option == 2){
				this->add();
			}
			else if (option == 3){
				this->displayByTeam();
			}
			else if (option == 4){
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
