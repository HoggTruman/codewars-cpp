// https://www.codewars.com/kata/586dd26a69b6fd46dd0000c0

#include <string>

static std::string my_first_interpreter(const std::string& code)
{
	std::string result{};
	int memory{ 0 };

	for (const char& c : code)
	{
		if (c == '+')
		{
			memory = (memory + 1) % 256;
		}
		else if (c == '.')
		{
			result += static_cast<char>(memory);
		}
	}

	return result;
}
