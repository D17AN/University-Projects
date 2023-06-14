#pragma once

#include <string>
#include <ostream>
#include <istream>
#include <vector>
#include <exception>
#include "utils.h"

class Programmer{
private:
	std::string name;
	int nrRevised, nrMustRevise;

public:
	Programmer();
	Programmer(const std::string& _name, const int& _nrRevised, const int& _nrMustRevise);
	std::string getName()const;
	int getNrRevisedFiles()const;
	int getNrMustReviseFiles()const;
	void setName(const std::string& _name);
	void setNrRevisedFiles(const int& _nrRevised);
	void setNrMustReviseFiles(const int& _nrMustRevise);
	bool operator==(const Programmer& other);

	std::string toString()const;
	friend std::ostream& operator<<(std::ostream& os, const Programmer& p);
	friend std::istream& operator>>(std::istream& is, Programmer& p);

	~Programmer();
};
