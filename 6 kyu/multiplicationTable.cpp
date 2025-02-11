// https://www.codewars.com/kata/534d2f5b5371ecf8d2000a08/cpp

#include <vector>

static std::vector<std::vector<int>> multiplication_table(int n) 
{
	std::vector<std::vector<int>> result{};

	for (int i{ 1 }; i <= n; ++i)
	{
		std::vector<int> row{};

		for (int j{ 1 }; j <= n; ++j)
		{
			row.push_back(i * j);
		}

		result.push_back(row);
	}

	return result;
}