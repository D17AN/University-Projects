#include "WritersRepository.h"

WritersRepository::WritersRepository(const std::string& _fileName) : fileName{_fileName}{
	this->loadFromFile();
}

WritersRepository::~WritersRepository(){
	this->saveToFile();
}

std::vector<Writer>& WritersRepository::getAll(){
	return this->writers;
}

void WritersRepository::loadFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	Writer w;
	while (fin >> w){
		if (w.getName() == "")
			continue;
		this->writers.push_back(w);
	}
	fin.close();
}

void WritersRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	for (const Writer& w : this->writers){
		fout << w << "\n";
	}
	fout.close();
}
