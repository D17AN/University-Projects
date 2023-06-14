#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "Programmer.h"

class ProgrammersRepository{
private:
	std::string fileName;
	std::vector<Programmer> programmers;

public:
	ProgrammersRepository(const std::string& _fileName);

	std::vector<Programmer>& getAll();

	void readFromFile();
	void saveToFile();
	
	~ProgrammersRepository();
};