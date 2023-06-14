#include "cont.h"

Controller::Controller(Repository& repo)
	: repo(repo)
{
}

void Controller::addObserver(Observer* o)
{
	this->repo.addObserver(o);
}

vector<Report> Controller::getReportsInRadius(float latitude, float longitude, int threshold)
{
	return this->repo.getReportsInRadius(latitude, longitude, threshold);
}

void Controller::addReport(Report r, Driver d)
{
	this->repo.addReport(r, d);
}

void Controller::increaseDriverScore(string d)
{
	this->repo.increaseDriverScore(d);
}

void Controller::validateReport(Report r)
{
	this->repo.validateReport(r);
}

void Controller::increaseReportVotes(Report r)
{
	this->repo.increaseReportVotes(r);
}

void Controller::moveDriverNorth(Driver d)
{
	this->repo.moveDriverNorth(d);
}

void Controller::moveDriverSouth(Driver d)
{
	this->repo.moveDriverSouth(d);
}

void Controller::moveDriverEast(Driver d)
{
	this->repo.moveDriverEast(d);
}

void Controller::moveDriverWest(Driver d)
{
	this->repo.moveDriverWest(d);
}
