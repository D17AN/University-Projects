#pragma once
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <exception>
#include "Idea.h"

class IdeasRepository{
private:
	std::vector<Idea> ideas;
	std::string fileName;

public:
	IdeasRepository();
	IdeasRepository(const std::string& _fileName);
	~IdeasRepository();

	std::vector<Idea>& getAll();
	void addIdea(const Idea& i);
	void updateIdeaStatus(int idx, const std::string& newStatus);

private:
	void loadFromFile();
	void saveToFile();
};