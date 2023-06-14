#pragma once
#include<string>

class Dwelling{
private:
	double price;
	bool isProfitable;
public:
	Dwelling(const double& _price, const bool& _isProfitable) : price{_price}, isProfitable{_isProfitable} {}
	double getPrice()const{ return this->price; }
	bool getIsProfitable()const{ return this->isProfitable; }
	Dwelling& operator=(const Dwelling& other);
	~Dwelling();
};

class Client{
protected:
	std::string name;
	double income;

public:
	Client(const std::string& _name, const double& _income) : name{_name}, income{_income}{}
	Client(const Client& other);
	virtual double totalIncome()const = 0;
	virtual std::string toString()const = 0;
	virtual bool isInterested(const Dwelling& d)const = 0;
	std::string getName()const{ return this->name; }
	double getIncome()const{ return this->income; }
	void setName(const std::string& newName){ this->name = newName; }
	void setIncome(const double& newIncome){ this->income = newIncome; }

	virtual ~Client();
};


class Person : public Client{
public:
	Person(const std::string& _name, const double& _income) : Client(_name, _income){}
	Person(const Person& other) : Client(other.name, other.income) {}
	bool isInterested(const Dwelling& d)const override;
	std::string toString()const override;
	double totalIncome()const override;
	~Person()override;
};


class Company : public Client{
private:
	double moneyFromInvestments;

public:
	Company(const std::string& _name, const double& _income, const double& _moneyFromInvestments) : Client(_name, _income), moneyFromInvestments{_moneyFromInvestments}{}
	Company(const Company& other) : Client(other.name, other.income), moneyFromInvestments{other.moneyFromInvestments} {}
	bool isInterested(const Dwelling& d)const override;
	std::string toString()const override;
	double totalIncome()const override;
	~Company()override;

};