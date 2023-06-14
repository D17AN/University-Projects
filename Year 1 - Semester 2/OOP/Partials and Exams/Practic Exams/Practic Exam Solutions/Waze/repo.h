#pragma once
#include "Driver.h"
#include "Report.h"
#include <vector>
#include "Observer.h"

class Repository : public Subject {
private:
	vector<Driver> drivers;
	vector<Report> reports;
	void loadData();
	void saveReports();
	void saveDrivers();
	bool isInRadius(float driverLatitude, float driverLongitude, Report r, int threshold);
public:
	Repository();
	vector<Driver>& getDrivers();
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