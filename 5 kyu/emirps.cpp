// https://www.codewars.com/kata/55de8eabd9bef5205e0000ba

#include <array>
#include <vector>
#include <numeric>
#include <cmath>


bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	int root_n{ static_cast<int>(std::sqrt(n)) };

	for (int k{ 2 }; k <= root_n; ++k)
	{
		if (n % k == 0)
		{
			return false;
		}
	}

	return true;
}


int reverse(int n)
{
	int reverse{ 0 };

	while (n > 0)
	{
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}

	return reverse;
}


std::array<int, 3> findEmirp(const int n) {
	const int first_emirp{ 13 };

	if (n < first_emirp) {
		return { 0, 0, 0 };
	}

	std::vector<int> emirps{};

	for (int k{ first_emirp }; k <= n; ++k)
	{
		if (isPrime(k))
		{
			int rev_k{ reverse(k) };
			if (rev_k != k &&
				isPrime(rev_k))
			{
				emirps.push_back(k);
			}			
		}
	}

	return { 
		static_cast<int>(emirps.size()),
		emirps.back(),
		std::reduce(emirps.begin(), emirps.end())
	};
}
