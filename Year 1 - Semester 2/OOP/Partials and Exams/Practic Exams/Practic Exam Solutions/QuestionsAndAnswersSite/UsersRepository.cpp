#include "UsersRepository.h"

UsersRepository::UsersRepository() : fileName{""}{
}

UsersRepository::UsersRepository(const std::string& _fileName) : fileName{_fileName}{
	this->loadFromFile();
}

UsersRepository::~UsersRepository(){
	if (this->fileName != ""){
		this->saveToFile();
	}
}

std::vector<User>& UsersRepository::getAll(){
	return this->users;
}

void UsersRepository::loadFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	User user;
	while (fin >> user){
		if (user.getName() == ""){
			continue;
		}
		this->users.push_back(user);
	}
	fin.close();
}

void UsersRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	for (const User& user : this->users){
		fout << user << "\n";
	}
	fout.close();
}
