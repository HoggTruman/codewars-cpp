// https://www.codewars.com/kata/57ea5b0b75ae11d1e800006c/cpp

#include <vector>
#include <string>
#include <algorithm>

static std::vector<std::string> sortByLength(std::vector<std::string> array) {
	std::sort(array.begin(), array.end(), [](std::string& a, std::string& b) {
		return a.length() < b.length(); 
	});
	return array;
}