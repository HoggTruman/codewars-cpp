// https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c

#include <vector>

static int maxSequence(const std::vector<int>& arr) 
{
	int subSumMax{ 0 };
	int currentSubSum{ 0 };

	for (const int& k : arr)
	{
		currentSubSum = currentSubSum < 0 ? k : currentSubSum + k;
		if (currentSubSum > subSumMax) {
			subSumMax = currentSubSum;
		}				
	}

	return subSumMax;
}