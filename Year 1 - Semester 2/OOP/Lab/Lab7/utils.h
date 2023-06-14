#pragma once
#include <string>
#include<vector>
#include<sstream>

class Utils{
public:
	/*
	* Tokenize a string by separating each line based on the given delimeter
	* Input:
	*	- s: type string, the string to be tokenized
	*	- delim: type string, the delimeter
	* 
	* Output:
	*	return: a vector of strings, each string representing a line from the string
	*/
	static std::vector<std::string> tokenize(const std::string& s, const char& delim);
	

	/*
	* Formats a sentence by removing all the spaces before the first character occurence and after last character occurence, replace all multiple spaces between words with 1 space, all uppercases will become small letters
	* Input:
	*	- s: type string, the string to be formated
	* 
	* Output:
	*	the given string will be formated corresponding with the description
	*	
	*/
	static void formatSentence(std::string& s);
};