#include "Driver.h"
#include "Utils.h"
#include <sstream>
Driver::Driver(const string& name, const string& status, const float& latitude, 
	const float& longitude, const int& score)
	: name(name), status(status), latitude(latitude), 
	longitude(longitude), score(score)
{
}

string Driver::getName()
{
	return this->name;
}

string Driver::getStatus()
{
	return this->status;
}

float Driver::getLatitude()
{
	return this->latitude;
}

float Driver::getLongitude()
{
	return this->longitude;
}

int Driver::getScore()
{
	return this->score;
}

void Driver::setStatus(string newStatus)
{
	this->status = newStatus;
}

void Driver::setScore(int newScore)
{
	this->score = newScore;
}

string Driver::toString()
{
	stringstream out;
	out << this->name << ";" << this->status << ";" << this->latitude << ";" 
		<< this->longitude << ";" << this->score << "\n";
	return out.str();
}

void Driver::setLatitude(int newLat)
{
	this->latitude = newLat;
}

void Driver::setLongitude(int newLong)
{
	this->longitude = newLong;
}

bool Driver::operator==(Driver d)
{
	return (this->latitude == d.latitude) && 
		(this->longitude == d.longitude) && 
		(this->name == d.name);
}

ostream& operator<<(ostream& out, Driver& d)
{
	out << d.toString();
	return out;
}

istream& operator>>(istream& in, Driver& d)
{
	string line;
	getline(in, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 5)
	{
		return in;
	}

	d.name = tokens[0];
	d.status = tokens[1];
	d.latitude = stof(tokens[2]);
	d.longitude = stof(tokens[3]);
	d.score = stoi(tokens[4]);
	
	return in;
}
