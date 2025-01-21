// https://www.codewars.com/kata/57073869924f34185100036d

#include <string>
#include <cstdlib>
#include <cctype>

std::string randomCase(std::string x) {
	for (int i{ 0 }; i < (int)x.length(); i++)
	{
		if (std::rand() % 2 == 0)
		{
			x[i] = std::toupper(x[i]);
		}
		else
		{
			x[i] = std::tolower(x[i]);
		}
	}

	return x;
}