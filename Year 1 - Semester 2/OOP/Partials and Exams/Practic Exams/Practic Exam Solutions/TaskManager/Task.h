#pragma once

#include <string>
#include <istream>
#include <ostream>
#include <vector>
#include "Utils.h"

class Task{
private:
	std::string description;
	std::string status; // open, in_progress, closed
	int programmerId;

public:
	Task();
	Task(const std::string& _description, const std::string& _status, const int& _programmerId);
	
	std::string getDescription()const;
	std::string getStatus()const;
	int getProgrammerId()const;
	void setDescription(const std::string& _description);
	void setStatus(const std::string& _status);
	void setProgrammerId(const int& _programmerId);

	std::string toString()const;

	friend std::istream& operator>>(std::istream& is, Task& t);
	friend std::ostream& operator<<(std::ostream& os, const Task& t);
	~Task();
};