#pragma once

#include "Participant.h"
#include <vector>
#include <string>
#include <fstream>


class ParticipantsRepository{
private:
	std::vector<Participant> participants;
	std::string fileName;

public:
	ParticipantsRepository();
	ParticipantsRepository(const std::string& _fileName);
	~ParticipantsRepository();

	std::vector<Participant>& getAll();

private:
	void loadFromFile();
	void saveToFile();
};
