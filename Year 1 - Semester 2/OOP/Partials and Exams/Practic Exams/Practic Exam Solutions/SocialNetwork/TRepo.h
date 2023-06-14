#pragma once
#include "Topics.h"
#include <algorithm>

class TRepo {
private:
    string file_name = "Topics.txt";
    vector<Topics> arr;
public:
    TRepo();

    virtual ~TRepo();

    void read_from_file();
    void save_to_file();
    vector<Topics>& getAll();
    vector<Topics> getAllForUser(string& user);
    void add_subscriber(string& topic_name, string& name);
};
