#include "ProgrammersRepository.h"


ProgrammersRepository::ProgrammersRepository(const std::string& _fileName) : fileName{_fileName}{
	this->readFromFile();
}

std::vector<Programmer>& ProgrammersRepository::getAll()
{
	return this->programmers;
}

void ProgrammersRepository::readFromFile()
{
	std::fstream fin{this->fileName, std::ios::in};
	Programmer p;
	while (fin >> p){
		this->programmers.push_back(p);
	}
	fin.close();
}

void ProgrammersRepository::saveToFile()
{
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	int n = this->programmers.size();
	int i = 1;
	for (const Programmer& p : this->programmers){
		i < n ? fout << p << "\n" : fout << p;
		i++;
	}
	fout.close();
}

ProgrammersRepository::~ProgrammersRepository(){
	this->saveToFile();
}
