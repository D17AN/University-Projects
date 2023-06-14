#pragma once
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Utils{
public:
	static vector<string> tokenize(const string& str, char delimeter);
	static void formatSentence(string& str);
};