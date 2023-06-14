#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<exception>
#include<iostream>


class HospitalDepartment{
protected:
	std::string name;
	int nrDoctors;

public:
	HospitalDepartment(const std::string _name, const int& _nrDoctors) : name{_name}, nrDoctors{_nrDoctors} {}
	HospitalDepartment(const HospitalDepartment& other) : name{other.name}, nrDoctors{other.nrDoctors} {}
	virtual bool isEfficient()const = 0;
	virtual std::string toString()const = 0;
	virtual ~HospitalDepartment();
};


class NeonatalUnit : public HospitalDepartment{
private:
	int nrMothers;
	int nrNewBorns;
	double averageGrade;

public:
	NeonatalUnit(const std::string& _name, const int& _nrDoctors, const int& _nrMothers, const int& _nrNewBorns, const double& _averageGrade) :
		HospitalDepartment(_name, _nrDoctors), nrMothers{_nrMothers}, nrNewBorns{_nrNewBorns}, averageGrade{_averageGrade} {}
	NeonatalUnit(const NeonatalUnit& other) : HospitalDepartment(other.name, other.nrDoctors), nrMothers{other.nrMothers},
		nrNewBorns{other.nrNewBorns}, averageGrade{other.averageGrade} {}
	bool isEfficient()const override;
	std::string toString()const override;
	~NeonatalUnit()override;
};


class Surgery : public HospitalDepartment{
private:
	int nrPatients;

public:
	Surgery(const std::string& _name, const int& _nrDoctors, const int& _nrPatients) : 
		HospitalDepartment(_name, _nrDoctors), nrPatients{_nrPatients} {}
	Surgery(const Surgery& other) : HospitalDepartment(other.name, other.nrDoctors), nrPatients{other.nrPatients} {}
	bool isEfficient()const override;
	std::string toString()const override;
	~Surgery();
};