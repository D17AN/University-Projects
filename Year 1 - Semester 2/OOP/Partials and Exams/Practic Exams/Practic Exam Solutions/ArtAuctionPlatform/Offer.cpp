#include "Offer.h"

string Offer::toString() const
{
	return to_string(this->userId) + "," + to_string(this->day) + "," + to_string(this->month) + "," + to_string(this->year) + "," + to_string(this->offerPrice);
}

ostream& operator<<(ostream& os, const Offer& o)
{
	os << o.toString();
	return os;
}

istream& operator>>(istream& is, Offer& o)
{
	string line;
	getline(is, line);
	vector<string> tokens = Utils::tokenize(line, ',');
	if (tokens.size() != 5){
		return is;
	}
	o.userId = stoi(tokens[0]);
	o.day = stoi(tokens[1]);
	o.month = stoi(tokens[2]);
	o.year = stoi(tokens[3]);
	o.offerPrice = stoi(tokens[4]);
	return is;
}
