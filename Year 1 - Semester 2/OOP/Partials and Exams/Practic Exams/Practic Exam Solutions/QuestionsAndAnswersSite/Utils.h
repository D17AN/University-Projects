#pragma once
#include <string>
#include <vector>
#include <sstream>


class Utils{
public:
	static std::vector<std::string> tokenize(const std::string& str, char delimeter);
	static void formatSentence(std::string& str);
};