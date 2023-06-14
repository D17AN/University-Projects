#include "Utils.h"

vector<string> Utils::tokenize(const string& str, char delimeter)
{
	vector<string> tokens;
	istringstream stream{str};
	string line;
	while (getline(stream, line, delimeter)){
		Utils::formatSentence(line);
		tokens.push_back(line);
	}
	return tokens;
}

void Utils::formatSentence(string& str)
{
	istringstream stream{str};
	string res = "";
	string line;
	while (getline(stream, line, ' ')){
		for (char& ch : line){
			if (ch >= 'A' && ch <= 'Z'){
				ch = tolower(ch);
			}
		}
		res += line + " ";
	}
	if (res.size() > 0){
		res.pop_back();
	}
	str = res;
}
