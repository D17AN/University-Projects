#pragma once
#include <exception>
#include <string>

class MyException : public std::exception{
private:
	std::string msg;

public:
	MyException(const std::string& _msg);
	const char* what()const;
};