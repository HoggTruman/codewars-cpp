// https://www.codewars.com/kata/5a54e796b3bfa8932c0000ed

#include <string>


static std::string jumpingNumber(int number)
{
	int prev{ number % 10 };

	while ((number /= 10) > 0)
	{
		int current = number % 10;
		if (abs(current - prev) != 1) {
			return "Not!!";
		}

		prev = current;
	}

	return "Jumping!!";
}