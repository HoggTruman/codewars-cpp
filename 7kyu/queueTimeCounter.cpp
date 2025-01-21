// https://www.codewars.com/kata/5b538734beb8654d6b00016d

#include<vector>

long long queue(const std::vector<int>& queuers, int pos) {
	long long timeTaken{ 0 };

	for (int i{ 0 }; i < (int)queuers.size(); i++)
	{
		if (i <= pos)
		{
			timeTaken += std::min(queuers[i], queuers[pos]);
		}
		else
		{
			timeTaken += std::min(queuers[i], queuers[pos] - 1);
		}
	}

	return timeTaken;
}