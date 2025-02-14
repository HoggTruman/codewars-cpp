// https://www.codewars.com/kata/57f759bb664021a30300007d/cpp

#include <string>

static std::string switcheroo(const std::string& s) {
	std::string result{ s };

	for (char& letter : result) {
		if (letter == 'c') continue;
		letter = (letter == 'a') ? 'b' : 'a';
	}

	return result;
}