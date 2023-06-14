#include "SourceFilesRepository.h"

SourceFilesRepository::SourceFilesRepository(const std::string& _fileName) : fileName{_fileName}{
	this->readFromFile();
}

void SourceFilesRepository::addSourceFile(const SourceFile& sf)
{
	this->sourceFiles.push_back(sf);
}

std::vector<SourceFile>& SourceFilesRepository::getAll(){
	return this->sourceFiles;
}

void SourceFilesRepository::readFromFile(){
	std::fstream fin{this->fileName, std::ios::in};
	SourceFile sf;
	while (fin >> sf){
		this->sourceFiles.push_back(sf);
	}
	fin.close();
}

void SourceFilesRepository::saveToFile()
{
	std::fstream fout{this->fileName, std::ios::out | std::ios::trunc};
	int n = this->sourceFiles.size();
	int i = 1;
	for (const SourceFile& sf : this->sourceFiles){
		i < n ? fout << sf << "\n" : fout << sf;
		i++;
	}
	fout.close();
}

SourceFilesRepository::~SourceFilesRepository(){
	this->saveToFile();
}
