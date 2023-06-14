#pragma once

#include "utils.h"
#include <string>
#include <ostream>
#include <istream>
#include <vector>
#include <exception>

class SourceFile{
private:
	std::string name, status, creator, reviewer;

public:
	SourceFile();
	SourceFile(const std::string& _name, const std::string& _status, const std::string& _creator, const std::string& _reviewer);
	
	std::string getName()const;
	std::string getStatus()const;
	std::string getCreator()const;
	std::string getReviewer()const;
	
	void setName(const std::string& _name);
	void setStatus(const std::string& _status);
	void setCreator(const std::string& _creator);
	void setReviewer(const std::string& _reviewer);

	std::string toString()const;
	friend std::ostream& operator<<(std::ostream& os, const SourceFile& sf);
	friend std::istream& operator>>(std::istream& is, SourceFile& sf);

	~SourceFile();
};