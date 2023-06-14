#include "Urepo.h"

Urepo::Urepo() {
    read_from_file();
}

Urepo::~Urepo() {
    save_to_file();
}

#include <fstream>

void Urepo::read_from_file() {
    std::ifstream f(file_name);
    while(!f.eof()){
        Users user;
        f>> user;
        if(user.getName() == "")
            return;
        this->arr.push_back(user);
    }
    f.close();

}

void Urepo::save_to_file() {
    std::ofstream f(file_name);
    f.clear();
    for(const auto& user:arr){
        f<<user<<"\n";
    }
    f.close();
}

vector<Users> &Urepo::get_all() {
    return arr;
}
