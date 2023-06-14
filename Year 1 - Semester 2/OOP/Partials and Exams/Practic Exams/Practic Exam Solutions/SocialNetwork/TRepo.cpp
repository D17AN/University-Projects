#include "TRepo.h"

TRepo::TRepo() {
    read_from_file();
}

TRepo::~TRepo() {
    save_to_file();
}

#include <fstream>

void TRepo::read_from_file() {
    std::ifstream f(file_name);
    while(!f.eof()){
        Topics user;
        f>> user;
        if(user.getText() == "")
            return;
        this->arr.push_back(user);
    }
    f.close();

}

void TRepo::save_to_file() {
    std::ofstream f(file_name);
    f.clear();
    for(const auto& user:arr){
        f<<user<<"\n";
    }
    f.close();
}

vector<Topics> &TRepo::getAll() {
    return arr;
}

void TRepo::add_subscriber(string& topic_name, string &name) {
    int location;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i].getText() == topic_name){
            arr[i].add(name);
        }
    }
}

vector<Topics> TRepo::getAllForUser(string &user) {
    vector<Topics> topics;
    for(auto t:arr){
        for(auto s:t.getUsersInterested()){
            if(s == user){
                topics.push_back(t);
            }
        }
    }
    return topics;
}
