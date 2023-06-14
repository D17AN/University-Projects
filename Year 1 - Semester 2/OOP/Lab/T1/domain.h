#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>

class Protein{
private:
	std::string organism, name, sequence;

public:
	Protein(std::string organism, std::string name, std::string sequence);
	Protein();
	Protein(const Protein& p);
	std::string getOrganism()const;
	std::string getName()const;
	std::string getSequence()const;
	void setOrganism(std::string organism);
	void setName(std::string name);
	void setSequence(std::string sequence);
	bool operator==(const Protein& p)const;
	friend std::ostream& operator<<(std::ostream& os, const Protein& p);
};