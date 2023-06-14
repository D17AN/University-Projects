#include "Utils.h"

std::vector<std::string> Utils::tokenize(const std::string& str, char delimeter){
	std::istringstream stream{str};
	std::string line;
	std::vector<std::string> res;
	while (getline(stream, line, delimeter)){
		Utils::formatSentence(line);
		res.push_back(line);
	}
	return res;
}

void Utils::formatSentence(std::string& str){
	std::istringstream stream{str};
	std::string res = "", line;
	while (getline(stream, line, ' ')){
		for (char& ch : line){
			if (ch >= 'A' && ch <= 'Z'){
				ch = tolower(ch);
			}
		}
		res = res + line + " ";
	}

	if (res.size() > 0){
		res.pop_back();
	}
	
	str.assign(res);
}
