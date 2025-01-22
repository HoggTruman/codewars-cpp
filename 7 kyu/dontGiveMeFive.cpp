// https://www.codewars.com/kata/5813d19765d81c592200001a

#include <cmath>

bool containsFive(int n)
{
	n = std::abs(n);

	while (n != 0)
	{
		if (n % 10 == 5)
		{
			return true;
		}

		n /= 10;
	}

	return false;
}


int dontGiveMeFive(int start, int end)
{
	int numsWithoutFive{ 0 };

	for (int k{ start }; k <= end; k++)
	{
		if (containsFive(k) == false) 
		{
			numsWithoutFive++;
		}		
	}

	return numsWithoutFive;
}
