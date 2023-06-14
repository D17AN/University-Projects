#include "QuestionsRepository.h"

QuestionsRepository::QuestionsRepository() : fileName{""}{
}

QuestionsRepository::QuestionsRepository(const std::string& _fileName) : fileName{_fileName}{
	this->loadFromFile();
}

QuestionsRepository::~QuestionsRepository(){
	if (this->fileName != ""){
		this->saveToFile();
	}
}

std::vector<Question>& QuestionsRepository::getAll(){
	return this->questions;
}

void QuestionsRepository::addQuestion(const Question& q){
	this->questions.push_back(q);
}

void QuestionsRepository::loadFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	Question question;
	while (fin >> question){
		if (question.getCreator() == ""){
			continue;
		}
		this->questions.push_back(question);
	}
	fin.close();
}

void QuestionsRepository::saveToFile(){
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	for (const Question& question : this->questions){
		fout << question << "\n";
	}
	fout.close();
}
