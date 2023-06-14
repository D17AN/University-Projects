#pragma once
#include "Posts.h"

class PRepo {
private:
    string file_name = "Posts.txt";
    vector<Posts> arr;
public:
    PRepo();

    virtual ~PRepo();

    void read_from_file();
    void save_to_file();
    vector<Posts>& getAll();

    void add(Posts& p);
    void modify(int id, string& text);
};
