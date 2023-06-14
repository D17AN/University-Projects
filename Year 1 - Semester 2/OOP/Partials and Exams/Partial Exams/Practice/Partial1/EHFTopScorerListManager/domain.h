#pragma once
#include<string>
#include<ostream>

class Player{
private:
	std::string name, nationality, team;
	int goals;
public:
	Player();
	Player(const std::string& name, const std::string& nationality, const std::string& team, int goals);
	Player(const Player& other);
	bool operator==(const Player& other)const;
	friend std::ostream& operator<<(std::ostream& os, const Player& p);
	std::string getName()const{ return this->name; }
	std::string getNationality()const{ return this->nationality; }
	std::string getTeam()const{ return this->team; }
	int getGoals()const{ return this->goals; }
};