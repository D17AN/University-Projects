#include "customexcpetion.h"

MyException::MyException(const std::string& msg){
	this->msg = msg;
}


const char* MyException::what(){
	return this->msg.c_str();
}


VectorException::VectorException(const std::string& msg) : MyException(msg){}


const char* VectorException::what(){
	this->msg.assign("Vector Exception:\n" + this->msg + "\n");
	return this->msg.c_str();
}


TrenchCoatException::TrenchCoatException(const std::string& msg) : MyException{msg} {}


const char* TrenchCoatException::what(){
	this->msg.assign("Trench Coat Exception:\n" + this->msg + "\n");
	return this->msg.c_str();
}


RepositoryException::RepositoryException(const std::string& msg) : MyException(msg) {}


const char* RepositoryException::what(){
	this->msg.assign("Repository exception:\n" + this->msg + "\n");
	return this->msg.c_str();
}

