#include "Task.h"

Task::Task() : description{""}, status{"closed"}, programmerId{0} {}

Task::Task(const std::string& _description, const std::string& _status, const int& _programmerId) : 
	description{_description}, status{_status}, programmerId{_programmerId} {}

std::string Task::getDescription() const{
	return this->description;
}

std::string Task::getStatus() const{
	return this->status;
}

int Task::getProgrammerId() const{
	return this->programmerId;
}

void Task::setDescription(const std::string& _description){
	this->description.assign(_description);
}

void Task::setStatus(const std::string& _status){
	this->status.assign(_status);
}

void Task::setProgrammerId(const int& _programmerId){
	this->programmerId = _programmerId;
}

std::string Task::toString() const
{
	return this->description + "|" + this->status + "|" + std::to_string(this->programmerId);
}

Task::~Task(){
}

std::istream& operator>>(std::istream& is, Task& t)
{
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = Utils::tokenize(line, '|');
	if (tokens.size() != 3){
		return is;
	}

	try{
		t.description.assign(tokens[0]);
		t.status.assign(tokens[1]);
		t.programmerId = std::stoi(tokens[2]);
	}
	catch (...){
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Task& t){
	os << t.description << "|" << t.status << "|" << t.programmerId;
	return os;
}
