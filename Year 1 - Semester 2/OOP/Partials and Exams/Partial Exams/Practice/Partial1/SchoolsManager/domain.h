#pragma once
#include<string>
#include<ostream>

struct Date{
	int day;
	int month;
	int year;
	bool operator==(const Date& date)const;
	bool operator<(const Date& date)const;
	bool operator>(const Date& date)const;
};

class School{
private:
	std::string name;
	std::string address;
	Date date;
	bool visited;

public:
	School();
	School(std::string name, std::string address, Date date, bool visited);
	std::string getName()const;
	std::string getAddress()const;
	Date getDate()const;
	bool getVisited()const;
	void setName(std::string name);
	void setAddress(std::string address);
	void setDate(Date date);
	void setVisited(bool visited);
	bool operator==(const School& school)const;
	friend std::ostream& operator<<(std::ostream& os, const School& school);

};