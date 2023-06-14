#pragma once
#include "repo.h"

class Controller {
private:
	Repository& repo;
public:
	Controller(Repository& repo);
	void addObserver(Observer* o);
	vector<Report> getReportsInRadius(float latitude, float longitude, int threshold);
	void addReport(Report r, Driver d);
	void increaseDriverScore(string d);
	void validateReport(Report r);
	void increaseReportVotes(Report r);
	void moveDriverNorth(Driver d);
	void moveDriverSouth(Driver d);
	void moveDriverEast(Driver d);
	void moveDriverWest(Driver d);
};