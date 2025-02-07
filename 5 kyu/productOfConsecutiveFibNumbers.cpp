// https://www.codewars.com/kata/5541f58a944b85ce6d00006a

#include <vector>
typedef unsigned long long ull;

static class ProdFib
{
	public:
		static std::vector<ull> productFib(ull prod)
		{
			ull fib_n_minus_2{ 1 };
			ull fib_n_minus_1{ 1 };
			ull product{ fib_n_minus_2 * fib_n_minus_1 };

			while (product < prod)
			{
				ull fib_n{ fib_n_minus_2 + fib_n_minus_1 };
				fib_n_minus_2 = fib_n_minus_1;
				fib_n_minus_1 = fib_n;
				product = fib_n_minus_2 * fib_n_minus_1;
			}

			return { fib_n_minus_2, fib_n_minus_1, product == prod};
		}
};