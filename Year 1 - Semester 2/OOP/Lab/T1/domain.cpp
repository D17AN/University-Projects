#include "domain.h"

Protein::Protein(std::string organism, std::string name, std::string sequence) : organism{ organism }, name{ name }, sequence{ sequence } {}

Protein::Protein() : organism{""}, name{""}, sequence{""} {}

Protein::Protein(const Protein& p) : organism{ p.organism }, name{ p.name }, sequence{ p.sequence } {}


std::string Protein::getOrganism() const
{
	return this->organism;
}

std::string Protein::getName() const
{
	return this->name;
}

std::string Protein::getSequence() const
{
	return this->sequence;
}

void Protein::setOrganism(std::string organism)
{
	this->organism = organism;
}

void Protein::setName(std::string name)
{
	this->name = name;
}

void Protein::setSequence(std::string sequence)
{
	this->sequence = sequence;
}

bool Protein::operator==(const Protein& p) const
{
	return this->organism == p.organism && this->name == p.name;
}

std::ostream& operator<<(std::ostream& os, const Protein& p)
{
	os << p.organism << "|" << p.name << "|" << p.sequence;
	return os;
}
