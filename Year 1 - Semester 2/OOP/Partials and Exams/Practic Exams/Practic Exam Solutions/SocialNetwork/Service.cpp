#include "Service.h"

Service::Service(TRepo &trepo, PRepo &prepo) : trepo(trepo), prepo(prepo) {}

Service::~Service() {

}

bool first_dated(Posts& p1, Posts& p2){
    if(p1.getYear() < p2.getYear())
        return true;
    else if(p1.getYear() > p2.getYear())
        return false;
    if(p1.getMonth() < p2.getMonth())
        return true;
    else if(p1.getMonth() > p2.getMonth())
        return false;
    if(p1.getDay() < p2.getDay())
        return true;
    else
        return false;
}


vector<Posts> Service::getAllPosts(string& user) {
    vector<Posts> v;
    for(auto p:prepo.getAll()){
        if(p.getUser() == user)
            v.push_back(p);
    }
    sort(v.begin(), v.end(),[](Posts& p1, Posts& p2){return first_dated(p1,p2);});
    return v;
}

vector<Topics> Service::getForUser(string &user) {
    vector<Topics> v = trepo.getAllForUser(user);
    return v;
}

void Service::add(int id, string& t, int d, int m, int y, string user) {
    Posts p(id, t, d, m, y, user);
    prepo.add(p);
    notify_all_observables();
}

int Service::getpostsize(){
    return prepo.getAll().size();
}