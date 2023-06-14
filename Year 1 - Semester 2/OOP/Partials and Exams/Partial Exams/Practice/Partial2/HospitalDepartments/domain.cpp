#include "domain.h"

HospitalDepartment::~HospitalDepartment()
{
}

bool NeonatalUnit::isEfficient() const
{
    return this->averageGrade >= 8.5 && this->nrNewBorns >= this->nrMothers;
}

std::string NeonatalUnit::toString() const
{
    return this->name + "|" + std::to_string(this->nrDoctors) + "|" 
        + std::to_string(this->nrMothers) + "|" + std::to_string(this->nrNewBorns) 
        + "|" + std::to_string(this->averageGrade);
}

NeonatalUnit::~NeonatalUnit()
{
}

bool Surgery::isEfficient() const
{
    return (this->nrPatients / this->nrDoctors) >= 2;
}

std::string Surgery::toString() const
{
    return this->name + "|" + std::to_string(this->nrDoctors) + "|" + std::to_string(this->nrPatients);
}

Surgery::~Surgery()
{
}
