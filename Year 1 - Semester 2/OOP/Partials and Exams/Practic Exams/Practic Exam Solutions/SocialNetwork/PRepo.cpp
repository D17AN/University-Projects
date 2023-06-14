#include "PRepo.h"

PRepo::PRepo() {
    read_from_file();
}

PRepo::~PRepo() {
    save_to_file();
}

vector<Posts> &PRepo::getAll() {
    return arr;
}

#include <fstream>

void PRepo::read_from_file() {
    std::ifstream f(file_name);
    while(!f.eof()){
        Posts user;
        f>> user;
        if(user.getText() == "")
            return;
        this->arr.push_back(user);
    }
    f.close();

}

void PRepo::save_to_file() {
    std::ofstream f(file_name);
    f.clear();
    for(const auto& user:arr){
        f<<user<<"\n";
    }
    f.close();
}

void PRepo::modify(int id, string& text) {
    for(auto p:arr){
        if(p.getId() == id)
            p.setText(text);
    }
}

void PRepo::add(Posts &p) {
    arr.push_back(p);
}

