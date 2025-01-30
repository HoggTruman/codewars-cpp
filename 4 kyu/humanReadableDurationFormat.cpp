// https://www.codewars.com/kata/52742f58faf5485cae000b9a/cpp

#include <string>
#include <vector>


std::string toTimeString(const std::string& unit, const int& n)
{
	if (n == 0) {
		return "";
	}

	return std::to_string(n) + " " + unit + (n > 1 ? "s" : "");
}


std::string format_duration(int s) {
	if (s == 0) {
		return "now";
	}

	const int S_PER_Y{ 31'536'000 };
	const int S_PER_D{ 86'400 };
	const int S_PER_H{ 3600 };
	const int S_PER_M{ 60 };

	std::vector<std::pair<std::string, int>> times = {
		{ "year", s / S_PER_Y },
		{ "day", (s % S_PER_Y) / S_PER_D },
		{ "hour", (s % S_PER_D) / S_PER_H },
		{ "minute", (s % S_PER_H) / S_PER_M },
		{ "second", s % S_PER_M}
	};

	std::vector<std::string> timeStrings{};

	for (const auto& [unit, value] : times)
	{
		if (value != 0) {
			timeStrings.push_back(toTimeString(unit, value));
		}
	}

	std::string result{};

	for (size_t i{ 0 }; i < timeStrings.size(); ++i)
	{
		if (i != 0 && i == timeStrings.size() - 1)
		{
			result += " and " ;
		}
		else if (i > 0)
		{
			result += ", ";
		}

		result += timeStrings[i];
	}

	return result;
}
