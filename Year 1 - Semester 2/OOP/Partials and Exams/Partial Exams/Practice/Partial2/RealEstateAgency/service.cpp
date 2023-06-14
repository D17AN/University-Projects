#include "service.h"

Dwelling RealEstateAgency::addDwelling(const double& price, const bool& isProfitable)
{
    Dwelling d{price, isProfitable};
    this->dwellings.push_back(d);
    return d;
}

void RealEstateAgency::updateClient(std::string& name, double& newIncome)
{
    bool found = false;
    std::find_if(this->clients.begin(), this->clients.end(), [&](Client* c){
            if (c->getName() == name){
                c->setIncome(newIncome);
                found = true;
                return true;
            }
            return false;
        });

    if (found == false){
        throw std::exception("Client doesn't exist");
    }
}

std::vector<Client*> RealEstateAgency::getInterestedClients(const Dwelling& d) const
{
    std::vector<Client*> res;
    std::copy_if(this->clients.begin(), this->clients.end(), std::back_inserter(res), [&](Client* c){
        if (c->isInterested(d)){
            return true;
        }
        return false;
        });
    return res;
}

void RealEstateAgency::writeToFile(const std::string& fileName) const
{
    std::fstream gout{fileName, std::ios::out | std::ios::trunc};
    std::for_each(this->clients.begin(), this->clients.end(), [&](Client* c){
            gout << c->toString() << "\n";
        });
    gout.close();
}

RealEstateAgency::~RealEstateAgency()
{
}
