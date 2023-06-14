#include "domain.h"

Dwelling& Dwelling::operator=(const Dwelling& other)
{
    if (this == &other){
        return *this;
    }
    this->price = other.price;
    this->isProfitable = other.isProfitable;

    return *this;
}

Dwelling::~Dwelling()
{
}

Client::Client(const Client& other) : name{other.name}, income{other.income}{}


Client::~Client()
{
}

bool Person::isInterested(const Dwelling& d) const
{
    return d.getPrice() / 1000 <= this->totalIncome();
}

std::string Person::toString() const
{
    return this->name + "|" + std::to_string(this->income);
}

double Person::totalIncome() const
{
    return this->income;
}

Person::~Person()
{
}

bool Company::isInterested(const Dwelling& d) const
{
    return d.getPrice() / 100 <= this->totalIncome() && d.getIsProfitable();
}

std::string Company::toString() const
{
    return this->name + "|" + std::to_string(this->income) + "|" + std::to_string(this->moneyFromInvestments);
}

double Company::totalIncome() const
{
    return this->income + this->moneyFromInvestments;
}

Company::~Company()
{
}
