#include "utils.h"

std::vector<std::string> Utils::tokenizeString(const std::string& str, char delimeter){
	std::istringstream stream{str};
	std::string line = "";
	std::vector<std::string> tokens;
	while (getline(stream, line, delimeter)){
		Utils::formatSentence(line);
		tokens.push_back(line);
	}
	return tokens;
}

void Utils::formatSentence(std::string& str){
	std::istringstream stream{str};
	std::string line = "";
	std::string newStr = "";
	while (getline(stream, line, ' ')){
		for (char& ch : line){
			if (ch >= 'A' && ch <= 'Z'){
				ch = tolower(ch);
			}
		}
		newStr = newStr + line + " ";
	}
	//remove the last space
	if (newStr != ""){
		newStr.pop_back();
	}

}
