#include "UserRepo.h"

UserRepo::UserRepo(){
	loadUsers();
}

UserRepo::~UserRepo(){
	saveUsers();
}

void UserRepo::addUser(User& user){
	this->users.push_back(user);
}

vector<User>& UserRepo::getUsers(){
	return this->users;
}

void UserRepo::loadUsers(){
	fstream fin{"users.txt", std::ios::in};
	while (!fin.eof()){
		User u;
		fin >> u;
		if (u.getName() != ""){
			this->users.push_back(u);
		}
	}
	fin.close();
}

void UserRepo::saveUsers(){
	fstream fout{"users.txt", std::ios::out | std::ios::trunc};
	for (auto u : this->users){
		fout << u << "\n";
	}
}
