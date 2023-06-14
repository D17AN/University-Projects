#include "domain.h"

Player::Player() : name{""}, nationality{""}, team{""}, goals{0}
{
}

Player::Player(const std::string& name, const std::string& nationality, const std::string& team, int goals) : name{name}, nationality{nationality}, team{team}, goals{goals}
{
}

Player::Player(const Player& other)
{
	this->name.assign(other.name);
	this->nationality.assign(other.nationality);
	this->team.assign(other.team);
	this->goals = other.goals;
}

bool Player::operator==(const Player& other) const
{
	return  this->name == other.name;
}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << p.name << "|" << p.nationality << "|" << p.team << "|" << p.goals;
	return os;
}
