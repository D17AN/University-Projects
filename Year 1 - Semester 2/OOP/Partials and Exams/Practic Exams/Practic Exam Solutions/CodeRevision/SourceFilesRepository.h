#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "SourceFile.h"

class SourceFilesRepository{
private:
	std::string fileName;
	std::vector<SourceFile> sourceFiles;

public:
	SourceFilesRepository(const std::string& _fileName);
	
	void addSourceFile(const SourceFile& sf);
	std::vector<SourceFile>& getAll();
	void readFromFile();
	void saveToFile();

	~SourceFilesRepository();
};