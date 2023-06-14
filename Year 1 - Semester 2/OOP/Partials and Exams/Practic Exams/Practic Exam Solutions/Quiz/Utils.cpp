#include "Utils.h"


std::vector<std::string> Utils::tokenize(const std::string& str, const char& delimeter){
	std::istringstream stream{str};
	std::string line;
	std::vector<std::string> tokens;
	while (getline(stream, line, delimeter)){
		Utils::formatSentence(line);
		tokens.push_back(line);
	}
	return tokens;
}

void Utils::formatSentence(std::string& str){
	std::istringstream stream{str};
	std::string line;
	std::string res = "";
	while (getline(stream, line, ' ')){
		for (char& ch : line){
			if (ch >= 'A' && ch <= 'Z')
				ch = tolower(ch);
		}
		res += line + " ";
	}
	
	if (res.size() > 0){
		res.pop_back();
	}
}