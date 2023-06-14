#include "utils.h"

std::vector<std::string> Utils::tokenize(const std::string& s, const char& delim){
	std::istringstream stream{s};
	std::string line = "";
	std::vector<std::string> tokens;
	while (getline(stream, line, delim)){
		if (line.length() == 0){
			continue;
		}

		Utils::formatSentence(line);
		tokens.push_back(line);
	}
	//in the case we reached the end of the stream but we have data in the line which we didn't put in the vector
	
	return tokens;
}


void Utils::formatSentence(std::string& s){
	std::istringstream stream{s};
	std::string newS = "";
	std::string line = "";
	while (getline(stream, line, ' ')){
		//if the line is empty means that we got a delimeter so we skip
		if (line.length() == 0){
			continue;
		}
		for (char& c : line){
			if (c >= 'A' && c <= 'Z'){
				c = tolower(c);
			}
		}
		newS += line;
		newS += " ";//adding a space after each line
	}
	
	//in the case we have only spaces
	s.clear();
	s = "";
	if (newS.length() != 0){
		if (newS[newS.length() - 1] == ' '){
			newS.pop_back();
			s = newS;
		}
	}
}