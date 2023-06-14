#include "Controller.h"

Controller::Controller(SourceFilesRepository& _sourceFilesRepo) : sourceFilesRepo{_sourceFilesRepo} {}

std::vector<SourceFile> Controller::sortedByName(){
	std::vector<SourceFile>& sourceFiles = this->sourceFilesRepo.getAll();
	std::vector<SourceFile> res;
	std::copy(sourceFiles.begin(), sourceFiles.end(), std::back_inserter(res));
	std::sort(res.begin(), res.end(), [](const SourceFile& sf1, const SourceFile& sf2){
		return sf1.getName() < sf2.getName();
		});
	return res;
}

bool Controller::searchSourceFile(const std::string& name){
	std::vector<SourceFile>& sourceFiles = this->sourceFilesRepo.getAll();
	auto pos = std::find_if(sourceFiles.begin(), sourceFiles.end(), [&name](const SourceFile& sf){
		return name == sf.getName();
		});
	
	return pos != sourceFiles.end();
}

void Controller::addSourceFile(const std::string& name, const std::string& creator)
{
	if (this->searchSourceFile(name)){
		throw std::exception("The file already exists.");
	}

	SourceFile sf{name, "not_revised", creator, "none"};
	this->sourceFilesRepo.addSourceFile(sf);
	this->notify();
}

void Controller::revise(const std::string& name, const std::string& reviewer)
{
	std::vector<SourceFile>& sourceFiles = this->sourceFilesRepo.getAll();
	auto pos = std::find_if(sourceFiles.begin(), sourceFiles.end(), [&name](const SourceFile& sf){
		return name == sf.getName();
		});
	
	if (pos != sourceFiles.end()){
		int i = pos - sourceFiles.begin();
		sourceFiles[i].setReviewer(reviewer);
		sourceFiles[i].setStatus("revised");
	}
	else{
		throw std::exception("The file to be revised doesn't exists.");
	}

	this->notify();
}

Controller::~Controller(){
}

