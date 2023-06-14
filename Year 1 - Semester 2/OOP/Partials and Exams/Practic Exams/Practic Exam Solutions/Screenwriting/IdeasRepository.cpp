#include "IdeasRepository.h"

IdeasRepository::IdeasRepository() : fileName{""}{
}

IdeasRepository::IdeasRepository(const std::string& _fileName) : fileName{_fileName}{
	this->loadFromFile();
}

IdeasRepository::~IdeasRepository(){
	if(this->fileName != "")
		this->saveToFile();
}

std::vector<Idea>& IdeasRepository::getAll(){
	return this->ideas;
}

void IdeasRepository::addIdea(const Idea& i){
	this->ideas.push_back(i);
}

void IdeasRepository::updateIdeaStatus(int idx, const std::string& newStatus){
	this->ideas[idx].setStatus(newStatus);
}

void IdeasRepository::loadFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	Idea i;
	while (fin >> i){
		if (i.getDescription() == "")
			continue;
		this->ideas.push_back(i);
	}
	fin.close();
}

void IdeasRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	for (const Idea& i : this->ideas){
		fout << i << "\n";
	}
	fout.close();
}
