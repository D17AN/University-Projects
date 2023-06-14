#include "Utils.h"
#include <sstream>
vector<string> tokenize(string line, char delimiter)
{
	vector<string> result;
	string token;
	stringstream s{ line };
	while (getline(s, token, delimiter))
	{
		result.push_back(token);
	}
	return result;
}