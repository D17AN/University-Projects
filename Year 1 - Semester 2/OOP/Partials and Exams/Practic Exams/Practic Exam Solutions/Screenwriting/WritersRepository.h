#pragma once
#include "Writer.h"
#include <fstream>

class WritersRepository{
private:
	std::vector<Writer> writers;
	std::string fileName;

public:
	WritersRepository(const std::string& _fileName);
	~WritersRepository();

	std::vector<Writer>& getAll();

private:
	void loadFromFile();
	void saveToFile();
};