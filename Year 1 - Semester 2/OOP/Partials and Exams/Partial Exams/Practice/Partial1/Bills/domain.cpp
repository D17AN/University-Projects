#include "domain.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

Date::Date() : day(0), month(0), year(0)
{
}

Date::Date(const Date& date)
{
    this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

int Date::getDay()const
{
    return this->day;
}

int Date::getMonth()const
{
    return this->month;
}

int Date::getYear()const
{
    return this->year;
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setYear(int year)
{
    this->year = year;
}

Date& Date::operator=(const Date& date)
{
    if(*this == date)
		return *this;

    this->day = date.day;
	this->month = date.month;
	this->year = date.year;
	return *this;
}

bool Date::operator==(Date date)const
{
    return this->day == date.day && this->month == date.month && this->year == date.year;
}

bool Date::operator!=(Date date)const
{
    return !(*this == date);
}

bool Date::operator<(Date date)const
{
    return this->year < date.year || (this->year == date.year && this->month < date.month) || (this->year == date.year && this->month == date.month && this->day < date.day);
}

bool Date::operator>(Date date)const
{
    return this->year > date.year || (this->year == date.year && this->month > date.month) || (this->year == date.year && this->month == date.month && this->day > date.day);
}

bool Date::operator<=(Date date)const
{
    return this->year <= date.year || (this->year == date.year && this->month <= date.month) || (this->year == date.year && this->month == date.month && this->day <= date.day);
}

bool Date::operator>=(Date date)const
{
    return this->year >= date.year || (this->year == date.year && this->month >= date.month) || (this->year == date.year && this->month == date.month && this->day >= date.day);
}

Bill::Bill(const std::string& id, const std::string& company, const Date& date, const double& sum, const bool& paid) : id(id), company(company), date(date), sum(sum), paid(paid) {}

Bill::Bill(const Bill& bill) : id(bill.id), company(bill.company), date(bill.date), sum(bill.sum), paid(bill.paid) {}

Bill::Bill() : id(0), company(""), date(Date()), sum(0.0), paid(false) {}

std::string Bill::getId() const
{
    return this->id;
}

std::string Bill::getCompany() const
{
    return this->company;
}

Date Bill::getDate() const
{
   return this->date;
}

double Bill::getSum() const
{
    return this->sum;
}

bool Bill::getPaid() const
{
    return this->paid;
}

void Bill::setId(const std::string& id)
{
    this->id = id;
}

void Bill::setCompany(const std::string& company)
{
    this->company = company;
}

void Bill::setDate(const Date& date)
{
    this->date = date;
}

void Bill::setSum(const double& sum)
{
    this->sum = sum;
}

void Bill::setPaid(const bool& paid)
{
    this->paid = paid;
}

bool Bill::operator==(const Bill& bill) const
{
    return this->id == bill.id;
}

bool Bill::operator!=(const Bill& bill) const
{
    return this->id != bill.id;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "." << date.month << "." << date.year;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Bill& bill)
{
    os << bill.id << ";" << bill.company << ";" << bill.date << ";" << bill.sum << ";" << bill.paid;
    return os;
}
