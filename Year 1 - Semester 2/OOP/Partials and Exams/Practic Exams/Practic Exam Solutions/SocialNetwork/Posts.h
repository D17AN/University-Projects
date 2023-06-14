#pragma once
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Posts {
private:
    int id;
    string text;
    int day, month, year;
    string user;
public:
    Posts(int id, const string &text, int day, int month, int year, const string &user);
    Posts();
    virtual ~Posts();

    friend ostream &operator<<(ostream &os, const Posts &posts);
    friend istream &operator>>(istream &is, Posts &posts);

    int getId() const;

    void setId(int id);

    const string &getText() const;

    void setText(const string &text);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);

    const string &getUser() const;

    void setUser(const string &user);
};
