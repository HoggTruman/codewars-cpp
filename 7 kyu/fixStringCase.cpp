// https://www.codewars.com/kata/5b180e9fedaa564a7000009a/cpp

#include <string>
#include <cctype>

static std::string solve(const std::string& str) {
	std::string result{ str };
	int upperCount{};
	int lowerCount{};

	for (const char& c : str)
	{
		std::isupper(c) ? ++upperCount : ++lowerCount;
	}	

	if (upperCount > lowerCount) 
	{
		for (auto& c : result) c = toupper(c);
	} 
	else 
	{
		for (auto& c : result) c = tolower(c);
	}

	return result;
}