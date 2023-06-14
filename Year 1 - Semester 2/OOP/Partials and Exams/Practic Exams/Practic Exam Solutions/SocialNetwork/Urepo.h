#pragma once
#include "Users.h"

class Urepo {
private:
    string file_name = "Users.txt";
    vector<Users> arr;
public:
    Urepo();

    virtual ~Urepo();

    void read_from_file();
    void save_to_file();

    vector<Users>& get_all();
};
