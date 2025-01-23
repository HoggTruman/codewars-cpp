// https://www.codewars.com/kata/5a1c28f9c9fc0ef2e900013b


#include <string>

std::string pyramid(int n) {
	if (n == 0)
	{
		return "\n";
	}

	if (n == 1)
	{
		return "/\\\n";
	}

	std::string result{ "" };

	for (int k{ 1 }; k <= n; k++)
	{
		result += std::string(n - k, ' ');

		result += '/';

		if (k == n)
		{
			result += std::string(2 * k - 2, '_');
		}
		else
		{
			result += std::string(2 * k - 2, ' ');
		}
		
		result += "\\\n";
	}

	return result;
}