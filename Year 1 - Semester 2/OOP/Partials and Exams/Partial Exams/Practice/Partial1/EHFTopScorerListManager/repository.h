#pragma once
#include "domain.h"
#include <algorithm>
#include <vector>
#include <exception>

class Repository{
private:
	std::vector<Player> v;

public:
	const std::vector<Player>& get()const;
	int search(const Player& p)const;

	/*
	* Add player to repository
	* Input:
	*	p: Player, the new player that must be added
	* Output:
	*	the list contains all the elements from before and the new player, if it already exists an exception is thrown
	*/
	void add(const Player& p);
};