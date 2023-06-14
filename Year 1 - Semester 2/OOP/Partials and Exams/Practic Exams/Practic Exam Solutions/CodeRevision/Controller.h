#pragma once
#include <vector>
#include <algorithm>
#include <iterator>

#include "SourceFilesRepository.h"
#include "Subject.h"

class Controller : public Subject{
private:
	SourceFilesRepository& sourceFilesRepo;

public:
	Controller(SourceFilesRepository& _sourceFilesRepo);

	std::vector<SourceFile> sortedByName();
	bool searchSourceFile(const std::string& name);
	void addSourceFile(const std::string& name, const std::string& creator);
	void revise(const std::string& name, const std::string& reviewer);
	
	~Controller();
};