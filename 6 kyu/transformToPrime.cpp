// https://www.codewars.com/kata/5a946d9fba1bb5135100007c

#include <vector>
#include <numeric>
#include <cmath>

static bool isPrime(int k)
{
    int squareRoot = sqrt(k);

    for (int divisor{ 2 }; divisor <= squareRoot; ++divisor)
    {
        if (k % divisor == 0)
        {
            return false;
        }
    }

    return true;
}


static int minimumNumber(std::vector <int> numbers)
{
	const int sum = std::reduce(numbers.begin(), numbers.end());

    int k{ sum };

    while (!isPrime(k))
    {
        ++k;
    }

	return k - sum;
}
