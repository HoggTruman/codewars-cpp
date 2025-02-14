// https://www.codewars.com/kata/5b73fe9fb3d9776fbf00009e/cpp

#include <vector>
#include <algorithm>
static int sumOfDifferences(const std::vector<int>& arr) {
	std::vector<int> arrDesc{ arr };
	std::sort(arrDesc.begin(), arrDesc.end(), std::greater<int>());
	int sum{ 0 };
	for (int i{ 0 }; i < static_cast<int>(arrDesc.size()) - 1; ++i)
	{
		sum += arrDesc[i] - arrDesc[i + 1];
	}
	return sum;
}