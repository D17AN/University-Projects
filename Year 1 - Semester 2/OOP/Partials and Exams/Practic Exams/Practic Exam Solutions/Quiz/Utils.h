#pragma once

#include <vector>
#include <string>
#include <sstream>


class Utils{
public:
	static std::vector<std::string> tokenize(const std::string& str, const char& delimeter);
	static void formatSentence(std::string& str);
};