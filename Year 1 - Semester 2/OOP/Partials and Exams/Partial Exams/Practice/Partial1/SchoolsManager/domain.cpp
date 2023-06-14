#include "domain.h"

School::School() : name{""}, address{""}, date{0,0,0}, visited{false} {}

School::School(std::string name, std::string address, Date date, bool visited) : name{name}, address{address}, date{date}, visited{visited}{}

std::string School::getName()const
{
	return this->name;
}

std::string School::getAddress()const
{
	return this->address;
}

Date School::getDate()const
{
	return this->date;
}

bool School::getVisited()const
{
	return this->visited;
}

void School::setName(std::string name)
{	
	this->name = name;
}

void School::setAddress(std::string address)
{
	this->address = address;
}

void School::setDate(Date date)
{
	this->date = date;
}

void School::setVisited(bool visited)
{
	this->visited = visited;
}

bool School::operator==(const School& school)const
{
	return this->name == school.name && this->address == school.address;
}

std::ostream& operator<<(std::ostream& os, const School& school)
{
	os << school.name << "|" << school.address << "|" << school.date.day << "." << school.date.month << "." << school.date.year << "|" << school.visited;
	return os;
}

bool Date::operator==(const Date& date) const
{
	return this->day == date.day && this->month == date.month && this->year == date.year;
}

bool Date::operator<(const Date& date) const
{
	if (this->year < date.year)
		return true;
	if (this->year == date.year && this->month < date.month)
		return true;
	if (this->year == date.year && this->month == date.month && this->day < date.day)
		return true;
	return false;
}

bool Date::operator>(const Date& date) const
{
	if (this->year > date.year)
		return true;
	if (this->year == date.year && this->month > date.month)
		return true;
	if (this->year == date.year && this->month == date.month && this->day > date.day)
		return true;
	return false;
}
