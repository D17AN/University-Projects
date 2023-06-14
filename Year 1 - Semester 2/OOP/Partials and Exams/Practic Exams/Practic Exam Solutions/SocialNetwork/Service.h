#pragma once
#include "TRepo.h"
#include "PRepo.h"
#include "Observer.h"
#include <algorithm>

class Service : public Observable {
private:
    TRepo& trepo;
    PRepo& prepo;
public:
    Service(TRepo &trepo, PRepo &prepo);

    vector<Posts> getAllPosts(string& user);
    vector<Topics> getForUser(string& user);
    void add(int id, string& t, int d, int m, int y,string user);
    int getpostsize();

    virtual ~Service();
};