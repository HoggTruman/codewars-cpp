// https://www.codewars.com/kata/52223df9e8f98c7aa7000062

#include <string>

char rotateUpper(const char& c)
{
	return 'A' + (c - 'A' + 13) % 26;
}


char rotateLower(const char& c)
{
	return 'a' + (c - 'a' + 13) % 26;
}


std::string rot13(const std::string& str) {
	std::string result{ "" };

	for (auto c : str)
	{
		if (std::isupper(c))
		{
			result += rotateUpper(c);
		}
		else if (std::islower(c))
		{
			result += rotateLower(c);
		}
		else
		{
			result += c;
		}
	}

	return result;
}