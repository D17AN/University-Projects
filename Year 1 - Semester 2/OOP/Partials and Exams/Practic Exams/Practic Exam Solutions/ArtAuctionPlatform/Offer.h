#pragma once
#include <string>
#include <vector>
#include "Utils.h"
#include <istream>
#include <ostream>


using namespace std;

class Offer{
private:
	int userId;
	int day, month, year;
	int offerPrice;

public:
	Offer() : userId{0}, day{0}, month{0}, year{0}, offerPrice{0}{}
	Offer(int userId, int day, int month, int year, int offerPrice) : userId{userId}, day{day}, month{month}, year{year}, offerPrice{offerPrice}{}
	Offer(const Offer & other) : userId{other.userId}, day{other.day}, month{other.month}, year{other.year}, offerPrice{other.offerPrice}{}

	void setUserId(int userId){this->userId = userId;}
	void setDay(int day){ this->day = day; }
	void setMonth(int month){ this->month = month; }
	void setYear(int year){ this->year = year; }
	void setOfferPrice(int offerPrice){ this->offerPrice = offerPrice; }

	int getUserId() const{return this->userId;}
	int getDay() const{return this->day;}
	int getMonth() const{return this->month;}
	int getYear() const{return this->year;}
	int getOfferPrice() const{return this->offerPrice;}

	string toString() const;

	friend ostream& operator<<(ostream& os, const Offer& o);
	friend istream& operator>>(istream& is, Offer& o);
};