#pragma once
#include <vector>
#include <string>
#include <sstream>

class Utils{
public:
	static std::vector<std::string> tokenizeString(const std::string& str, char delimeter);
	static void formatSentence(std::string& str);
};