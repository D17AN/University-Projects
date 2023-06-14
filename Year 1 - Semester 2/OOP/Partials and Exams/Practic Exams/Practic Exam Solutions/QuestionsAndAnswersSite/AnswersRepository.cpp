#include "AnswersRepository.h"

AnswersRepository::AnswersRepository() : fileName{""}{
}

AnswersRepository::AnswersRepository(const std::string& _fileName) : fileName{_fileName}{
	this->loadFromFile();
}

AnswersRepository::~AnswersRepository(){
	if (this->fileName != ""){
		this->saveToFile();
	}
}

std::vector<Answer>& AnswersRepository::getAll(){
	return this->answers;
}

void AnswersRepository::addAnswer(const Answer& a){
	this->answers.push_back(a);
}

void AnswersRepository::loadFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	Answer answer;
	while (fin >> answer){
		if (answer.getCreator() == ""){
			continue;
		}
		this->answers.push_back(answer);
	}
	fin.close();
}

void AnswersRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	for (const Answer& answer : this->answers){
		fout << answer << "\n";
	}
	fout.close();
}
