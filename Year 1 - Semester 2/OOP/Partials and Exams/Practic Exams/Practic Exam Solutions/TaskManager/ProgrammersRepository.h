#pragma once
#include <vector>
#include <fstream>
#include "Programmer.h"

class ProgrammersRepository{
private:
	std::vector<Programmer> programmers;
	std::string fileName;

public:
	ProgrammersRepository(const std::string& _fileName);

	std::vector<Programmer>& getAll();
	void readFromFile();
	void saveToFile();

	~ProgrammersRepository();
};