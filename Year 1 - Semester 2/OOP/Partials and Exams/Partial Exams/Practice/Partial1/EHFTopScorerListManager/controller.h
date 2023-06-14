#pragma once
#include "repository.h"

class Controller{
private:
	Repository& repo;

public:
	Controller(Repository& repo);
	const std::vector<Player>& get();
	
	/*
	* Gets an vector of players from a specific team
	* Input:
	*	- team: string, the team in which the Players must be
	* Ouput:
	*	return: a vector of Players, each of them being from a given team, sorted descending by the nr of goals
	*/
	const std::vector<Player> getPlayersHavingTeam(const std::string& team);
	void add(const Player& p);

};