#include "controller.h"


Controller::Controller(Repository& repo) : repo{repo}{}

const std::vector<Player>& Controller::get()
{
	return this->repo.get();
}

const std::vector<Player> Controller::getPlayersHavingTeam(const std::string& team)
{
	std::vector<Player> res;
	const std::vector<Player>& v = this->repo.get();
	std::copy_if(v.begin(), v.end(), std::back_inserter(res), [&team](const Player& p){
		return team == p.getTeam();
		});
	std::sort(res.begin(), res.end(), [](const Player& p1, const Player& p2){
		return p1.getGoals() > p2.getGoals();
		});
	return res;
}

void Controller::add(const Player& p)
{
	this->repo.add(p);
}
