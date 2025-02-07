// https://www.codewars.com/kata/51f2b4448cadf20ed0000386/cpp

#include <string>

static std::string replaceAll(std::string str) {	
	return str.substr(0, str.find('#'));
}