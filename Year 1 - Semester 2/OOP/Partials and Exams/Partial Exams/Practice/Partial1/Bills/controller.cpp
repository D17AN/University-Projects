#include "controller.h"

void Controller::addBill(const Bill& bill)
{
    repo.addBill(bill);
}

void Controller::deleteBill(const Bill& bill)
{
    repo.deleteBill(bill);
}

double Controller::getTotalUnpaidBills()
{
    const std::vector<Bill>& v = repo.getAll();
    double sum = 0;
    std::for_each(v.begin(), v.end(), [&sum](const Bill& b) {
        if (b.getPaid() == false) 
            sum += b.getSum(); 
        });
    return sum;
}


std::vector<Bill> Controller::getAllUnpaidSortedByDate()
{
    std::vector<Bill> v = repo.getAll();
    std::vector<Bill> unpaid;
    std::copy_if(v.begin(), v.end(), std::back_inserter(unpaid), [](const Bill& b){
        return b.getPaid() == false; 
        });
    std::sort(unpaid.begin(), unpaid.end(), [](const Bill& b1, const Bill& b2){
        return b1.getDate() < b2.getDate(); 
        });
    return unpaid;
}

const std::vector<Bill>& Controller::getAll()const
{
    return repo.getAll();
}
