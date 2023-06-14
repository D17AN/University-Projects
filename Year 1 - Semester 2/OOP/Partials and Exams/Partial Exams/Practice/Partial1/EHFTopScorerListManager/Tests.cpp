#include "Tests.h"

void Test::testAdd()
{
	Repository repo;
	Controller c{repo};
	Player p1{"a", "a", "a", 10};
	Player p2{"b", "a", "a", 10};
	c.add(p1);
	c.add(p2);
	assert(c.get().size() == 2);
}

void Test::testGetPlayers()
{
	Repository repo;
	Controller c{repo};
	Player p1{"a", "a", "a", 10};
	Player p2{"b", "a", "a", 10};
	c.add(p1);
	c.add(p2);
	assert(c.get().size() == 2);
	assert(c.getPlayersHavingTeam("a").size() == 2);
}

void Test::run()
{
	this->testAdd();
	this->testGetPlayers();
}
