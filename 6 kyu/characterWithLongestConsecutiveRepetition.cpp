// https://www.codewars.com/kata/586d6cefbcc21eed7a001155/cpp

#include <utility>
#include <string>
#include <optional>

std::optional<std::pair<char, unsigned int>> longestRepetition(const std::string& str) {
	if (str.size() == 0)
	{
		return std::nullopt;
	}

	char mostRepeatedChar{};
	unsigned int mostRepeated{};

	char currentChar{};
	unsigned int currentRepeated{};

	for (auto c : str)
	{
		if (c != currentChar)
		{
			if (currentRepeated > mostRepeated)
			{
				mostRepeatedChar = currentChar;
				mostRepeated = currentRepeated;
			}

			currentChar = c;
			currentRepeated = 1;
		}
		else
		{
			currentRepeated++;
		}
	}
	
	if (currentRepeated > mostRepeated)
	{
		return std::pair{ currentChar, currentRepeated };
	}

	return std::pair{ mostRepeatedChar, mostRepeated };
}