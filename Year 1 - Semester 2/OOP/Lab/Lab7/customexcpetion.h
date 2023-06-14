#pragma once
#include <exception>
#include<string>

/*
* Abstract class for custom exceptions
*/
class MyException : public std::exception{
protected:
	std::string msg;
public:
	MyException(const std::string& msg);
	virtual const char* what();
};


class TrenchCoatException : public MyException{
public:
	TrenchCoatException(const std::string& msg);
	const char* what() override;
};


class RepositoryException : public MyException{
public:
	RepositoryException(const std::string& msg);
	const char* what();
};