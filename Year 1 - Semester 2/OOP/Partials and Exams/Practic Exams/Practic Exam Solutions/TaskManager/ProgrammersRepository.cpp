#include "ProgrammersRepository.h"

ProgrammersRepository::ProgrammersRepository(const std::string& _fileName) : fileName{_fileName}{
	this->readFromFile();
}

std::vector<Programmer>& ProgrammersRepository::getAll(){
	return this->programmers;
}

void ProgrammersRepository::readFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	Programmer p;
	while (fin >> p){
		if (p.getName() == "")//if the data of the programmer wasn't read, it's not added
			continue;
		this->programmers.push_back(p);
	}
	fin.close();
}

void ProgrammersRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	for (const Programmer& p : this->programmers){
		fout << p << "\n";
	}
	fout.close();
}

ProgrammersRepository::~ProgrammersRepository(){
	this->saveToFile();
}
