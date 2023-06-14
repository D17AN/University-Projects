#pragma once
#include <string>
#include <iostream>
#include <sstream>
class Student
{
private:
	std::string id;
	std::string name;
	std::string email;
	int year;
	std::string title;
	std::string coordinator;
public:
	Student(std::string i = "", std::string n = "", std::string em = "", int y = 0, std::string t = "No title", std::string coord = "")
	{
		id = i;
		name = n;
		email = em;
		year = y;
		title = t;
		coordinator = coord;
	}
	std::string getId() { return id; }
	std::string getName() { return name; }
	std::string getEmail() { return email; }
	int getYear() { return year; }
	std::string getTitle() { return title; }
	std::string getCoordinator() { return coordinator; }

	void setCoordinator(std::string coord) { coordinator = coord; }

	void setEmail(std::string em) { email = em; }

	void setTitle(std::string t) { title = t; }

	std::string toString()
	{
		return id + ',' + name + ',' + email + ',' + std::to_string(year) + ',' + title + ',' + coordinator;
	}

};

