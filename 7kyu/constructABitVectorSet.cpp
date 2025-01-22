// https://www.codewars.com/kata/52f5424d0531259cfc000d04

#include <vector>
#include <cmath>

int sort_by_bit(const std::vector<int>& array) {
	int result{ 0 };

	for (int i : array)
	{
		result += static_cast<int>(std::pow(2, i));
	}

	return result;
}