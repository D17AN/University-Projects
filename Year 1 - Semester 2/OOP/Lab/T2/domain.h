#pragma once
#include<string>
#include<iostream>
#include<exception>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>


class Engine{
protected:
	double basePrice;

public:
	Engine(double basePrice) : basePrice{ basePrice } {};
	Engine(const Engine& other) : basePrice{ other.basePrice } {};
	virtual double getPrice() const = 0;
	virtual std::string toString() const = 0;
	virtual ~Engine();
};


class ElectricEngine : public Engine {
private:
	int autonomy;
public:
	ElectricEngine(double basePrice, int autonomy) : Engine{ basePrice }, autonomy{ autonomy } {};
	ElectricEngine(const ElectricEngine& other) : Engine{ other.basePrice }, autonomy{ other.autonomy } {};
	double getPrice() const override;
	std::string toString() const override;
	~ElectricEngine();
};

class TurboEngine : public Engine {
public:
	TurboEngine(double basePrice) : Engine{basePrice} {};
	TurboEngine(const TurboEngine& other) : Engine{other.basePrice} {};
	double getPrice() const override;
	std::string toString() const override;
	~TurboEngine();
};