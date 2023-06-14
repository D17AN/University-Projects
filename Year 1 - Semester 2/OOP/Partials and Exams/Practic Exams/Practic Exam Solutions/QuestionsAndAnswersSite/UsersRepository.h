#pragma once
#include "User.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

class UsersRepository{
private:
	std::vector<User> users;
	std::string fileName;

public:
	UsersRepository();
	UsersRepository(const std::string& _fileName);
	~UsersRepository();

	std::vector<User>& getAll();

	void loadFromFile();
	void saveToFile();
};