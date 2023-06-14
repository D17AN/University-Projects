#include "ParticipantsRepository.h"

ParticipantsRepository::ParticipantsRepository() : fileName{""}{
}

ParticipantsRepository::ParticipantsRepository(const std::string& _fileName) : fileName{_fileName}{
	this->loadFromFile();
}

ParticipantsRepository::~ParticipantsRepository(){
	if (this->fileName != ""){
		this->saveToFile();
	}
}

std::vector<Participant>& ParticipantsRepository::getAll(){
	return this->participants;
}

void ParticipantsRepository::loadFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	Participant p;
	
	while (fin >> p){
		if (p.getName() == ""){
			continue;
		}
		p.setScore(0);
		this->participants.push_back(p);
	}

	fin.close();
}

void ParticipantsRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	
	for (Participant& p : this->participants){
		p.setScore(0);
		fout << p << "\n";
	}

	fout.close();
}
