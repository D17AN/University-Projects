#include "CustomException.h"

MyException::MyException(const std::string& _msg) : msg{_msg}{
}

const char* MyException::what() const
{
	return this->msg.c_str();
}
