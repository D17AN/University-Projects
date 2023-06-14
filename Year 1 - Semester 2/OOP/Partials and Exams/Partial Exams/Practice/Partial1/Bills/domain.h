#pragma once
#include <string>
#include <ostream>

class Date{
private:
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);
	Date();
	Date(const Date& date);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	Date& operator=(const Date& date);
	bool operator==(Date date)const;
	bool operator!=(Date date)const;
	bool operator<(Date date)const;
	bool operator>(Date date)const;
	bool operator<=(Date date)const;
	bool operator>=(Date date)const;
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};


class Bill{
private:
	std::string id;
	std::string company;
	Date date;
	double sum;
	bool paid;

public:
	Bill(const std::string& id, const std::string& company, const Date& date, const double& sum, const bool& paid);
	Bill(const Bill& bill);
	Bill();
	std::string getId()const;
	std::string getCompany()const;
	Date getDate()const;
	double getSum()const;
	bool getPaid()const;
	void setId(const std::string& id);
	void setCompany(const std::string& company);
	void setDate(const Date& date);
	void setSum(const double& sum);
	void setPaid(const bool& paid);
	bool operator==(const Bill& bill)const;
	bool operator!=(const Bill& bill)const;
	friend std::ostream& operator<<(std::ostream& os, const Bill& bill);
};