#include "Item.h"

string Item::toString() const
{
	string str = this->name + "|" + this->category + "|" + to_string(this->price);
	for (const Offer& o : this->offers){
		str += "|" + o.toString();
	}
	return str;
}

ostream& operator<<(ostream& os, const Item& i)
{
	os << i.toString();
	return os;
}

istream& operator>>(istream& is, Item& i)
{
	string line;
	getline(is, line);
	vector<string> tokens = Utils::tokenize(line, '|');

	if (tokens.size() < 3){
		return is;
	}

	i.name.assign(tokens[0]);
	i.category.assign(tokens[1]);
	i.price = stoi(tokens[2]);

	for (int idx = 3; idx < tokens.size(); idx++){
		vector<string> offerTokens = Utils::tokenize(tokens[idx], ',');
		if (offerTokens.size() != 5){
			continue;
		}
		Offer* o = new Offer();
		o->setUserId(stoi(offerTokens[0]));
		o->setDay(stoi(offerTokens[1]));
		o->setMonth(stoi(offerTokens[2]));
		o->setYear(stoi(offerTokens[3]));
		o->setOfferPrice(stoi(offerTokens[4]));
		i.offers.push_back(*o);
	}
	return is;
}
