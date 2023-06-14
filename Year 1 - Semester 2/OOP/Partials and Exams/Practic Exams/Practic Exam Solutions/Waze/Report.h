#pragma once
#include <string>
#include <iostream>
using namespace std;

class Report {
private:
	string description;
	string reporter;
	float latitude, longitude;
	int validated;
	int votes;

public:
	Report(const string& description = "", const string& reporter = "", 
		const float& latitude = 0, const float& longitude = 0, 
		const int& validated = 0, const int& votes = 0);
	string getDescription()const;
	string getReporter()const;
	float getLatitude()const;
	float getLongitude()const;
	int checkValidated()const;
	int getValidated()const;
	
	void setDescription(const string& newDesc);
	void setReporter(const string& newReporter);
	void setLatitude(const float& newLat);
	void setLongitude(const float& newLong);
	void setValidate(const int& newValidated);
	
	string toString()const;
	
	int getVotes()const;
	void setVotes(int newVotes);
	
	friend ostream& operator<<(ostream& out, Report& r);
	friend istream& operator>>(istream& in, Report& r);
	
	bool operator==(Report r);
};