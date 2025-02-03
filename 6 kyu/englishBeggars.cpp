// https://www.codewars.com/kata/59590976838112bfea0000fa

#include <vector>

static std::vector<int> beggars(const std::vector<int>& values, unsigned int n) {
	if (n == 0) {
		return {};
	}

	std::vector<int> beggarEarnings(n, 0);

	for (size_t i{ 0 }; i < values.size(); ++i)
	{
		beggarEarnings[i % n] += values[i];
	}

	return beggarEarnings;
}