#include "repo.h"
#include <fstream>

void Repository::loadData()
{
	ifstream driversFile;
	driversFile.open("drivers.txt");
	if (driversFile.is_open())
	{
		Driver d;
		while (driversFile >> d)
		{
			this->drivers.push_back(d);
		}

		driversFile.close();
	}
	ifstream reportsFile;
	reportsFile.open("reports.txt");
	if (reportsFile.is_open())
	{
		Report r;
		while (reportsFile >> r)
		{
			this->reports.push_back(r);
		}

		reportsFile.close();
	}
}

void Repository::saveReports()
{
	ofstream reportsFile;
	reportsFile.open("reports.txt");
	if (reportsFile.is_open())
	{
		for (Report r : this->reports)
		{
			reportsFile << r;
		}
		reportsFile.close();
	}
}

void Repository::saveDrivers()
{
	ofstream driversFile;
	driversFile.open("drivers.txt");
	if (driversFile.is_open())
	{
		for (Driver d : this->drivers)
		{
			driversFile << d;
		}
		driversFile.close();
	}
}

bool Repository::isInRadius(float driverLatitude, float driverLongitude, Report r, int threshold)
{
	double distance = sqrt((driverLatitude - r.getLatitude()) * (driverLatitude - r.getLatitude()) + (driverLongitude - r.getLongitude()) * (driverLongitude - r.getLongitude()));
	if (distance > threshold)
	{
		return false;
	}
	return true;
}


Repository::Repository()
{
	this->loadData();
}

vector<Driver>& Repository::getDrivers()
{
	return this->drivers;
}

vector<Report> Repository::getReportsInRadius(float latitude, float longitude, int threshold)
{
	vector<Report> result;
	for (Report r : this->reports)
	{
		if (this->isInRadius(latitude, longitude, r, threshold))
		{
			result.push_back(r);
		}
	}
	return result;
}

void Repository::addReport(Report r, Driver d)
{
	if (this->isInRadius(d.getLatitude(), d.getLongitude(), r, 20))
	{
		this->reports.push_back(r);
		this->notify();
		this->saveReports();
		
	}
	else
	{
		throw exception("Not in radius!");
	}
}

void Repository::increaseDriverScore(string d)
{
	for (int i = 0; i < this->drivers.size(); i++)
	{
		if (this->drivers[i].getName() == d)
		{
			this->drivers[i].setScore(this->drivers[i].getScore() + 1);
			break;
		}
	}
	this->notify();
	this->saveDrivers();
}

void Repository::validateReport(Report r)
{
	for (int i = 0; i < this->reports.size(); i++)
	{
		if (this->reports[i] == r)
		{
			this->reports[i].setValidate(1);
			break;
		}
	}
	this->notify();
	this->saveReports();

}

void Repository::increaseReportVotes(Report r)
{
	for (int i = 0; i < this->reports.size(); i++)
	{
		if (this->reports[i] == r)
		{
			this->reports[i].setVotes(this->reports[i].getVotes() + 1);
			break;
		}
	}
	this->notify();
	this->saveReports();
}

void Repository::moveDriverNorth(Driver d)
{
	for (int i = 0; i < this->drivers.size(); i++)
	{
		if (this->drivers[i] == d)
		{
			this->drivers[i].setLongitude(this->drivers[i].getLongitude() + 1);
			break;
		}
	}
	this->notify();
	this->saveDrivers();
}

void Repository::moveDriverSouth(Driver d)
{
	for (int i = 0; i < this->drivers.size(); i++)
	{
		if (this->drivers[i] == d)
		{
			this->drivers[i].setLongitude(this->drivers[i].getLongitude() - 1);
			break;
		}
	}
	this->notify();
	this->saveDrivers();
}

void Repository::moveDriverEast(Driver d)
{
	for (int i = 0; i < this->drivers.size(); i++)
	{
		if (this->drivers[i] == d)
		{
			this->drivers[i].setLatitude(this->drivers[i].getLatitude() + 1);
			break;
		}
	}
	this->notify();
	this->saveDrivers();
}

void Repository::moveDriverWest(Driver d)
{
	for (int i = 0; i < this->drivers.size(); i++)
	{
		if (this->drivers[i] == d)
		{
			this->drivers[i].setLatitude(this->drivers[i].getLatitude() - 1);
			break;
		}
	}
	this->notify();
	this->saveDrivers();
}
