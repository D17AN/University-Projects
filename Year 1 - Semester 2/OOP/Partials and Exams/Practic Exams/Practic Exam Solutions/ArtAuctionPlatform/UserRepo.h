#pragma once
#include "User.h"
#include <fstream>


class UserRepo
{
private:
	vector<User> users;

public:
	UserRepo();
	~UserRepo();
	void addUser(User& user);
	vector<User>& getUsers();

private:
	void loadUsers();
	void saveUsers();
};