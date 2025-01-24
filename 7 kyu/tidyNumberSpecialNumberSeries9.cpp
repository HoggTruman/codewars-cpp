// https://www.codewars.com/kata/5a87449ab1710171300000fd/cpp

#include <limits>

bool tidyNumber(int number)
{
	// initialised to max so that the first digit is always less than or equal
	int rightDigit{ std::numeric_limits<int>::max() };

	while (number != 0)
	{		
		int leftDigit{ number % 10 };
		
		if (leftDigit > rightDigit)
		{
			return false;
		}

		rightDigit = leftDigit;
		number /= 10;
	}

	return true;
}
