#include "Report.h"
#include "Utils.h"
#include <sstream>

Report::Report(const string& description, const string& reporter, const float& latitude, 
	const float& longitude, const int& validated, const int& votes)
	: description(description), reporter(reporter), 
	latitude(latitude), longitude(longitude), 
	validated(validated), votes(votes)
{
}

string Report::getDescription()const
{
	return this->description;
}

string Report::getReporter()const
{
	return this->reporter;
}

float Report::getLatitude()const
{
	return this->latitude;
}

float Report::getLongitude()const
{
	return this->longitude;
}

int Report::checkValidated()const
{
	return this->validated;
}

int Report::getValidated()const
{
	return this->validated;
}

void Report::setDescription(const string& newDesc)
{
	this->description = newDesc;
}

void Report::setReporter(const string& newReporter)
{
	this->reporter = newReporter;
}

void Report::setLatitude(const float& newLat)
{
	this->latitude = newLat;
}

void Report::setLongitude(const float& newLong)
{
	this->longitude = newLong;
}

void Report::setValidate(const int& newValidated)
{
	this->validated = newValidated;
}

string Report::toString()const
{
	stringstream out;
	out << this->description << ";" << this->reporter << ";" << 
		this->latitude << ";" << this->longitude << ";" 
		<< this->validated << ";" << this->votes << "\n";
	return out.str();
}

int Report::getVotes()const
{
	return this->votes;
}

void Report::setVotes(int newVotes)
{
	this->votes = newVotes;
}

bool Report::operator==(Report r)
{
	return (this->latitude == r.latitude) && (this->longitude == r.longitude) && (this->reporter == r.reporter);
}

ostream& operator<<(ostream& out, Report& r)
{
	out << r.toString();
	return out;
}

istream& operator>>(istream& in, Report& r)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 6)
	{
		return in;
	}
	r.description = tokens[0];
	r.reporter = tokens[1];
	r.latitude = stof(tokens[2]);
	r.longitude = stof(tokens[3]);
	r.validated = stoi(tokens[4]);
	r.votes = stoi(tokens[5]);

	return in;
}
