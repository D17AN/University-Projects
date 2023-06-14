#include "domain.h"

double ElectricEngine::getPrice() const
{
	return this->basePrice + double(this->autonomy) * 0.01;
}

std::string ElectricEngine::toString() const
{
	return std::to_string(this->basePrice) + "|" + std::to_string(this->autonomy);
}

ElectricEngine::~ElectricEngine()
{
}

double TurboEngine::getPrice() const
{
	return this->basePrice + 100;
}

std::string TurboEngine::toString() const
{
	return std::to_string(this->basePrice);
}

TurboEngine::~TurboEngine()
{
}

Engine::~Engine()
{
}
