// https://www.codewars.com/kata/55f2b110f61eb01779000053/cpp

#include <cmath>

static int get_sum(int a, int b)
{
	int n{ std::abs(a - b) + 1 };
	return (a + b) * n / 2;
}