// https://www.codewars.com/kata/51ba717bb08c1cd60f00002f/cpp

#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
	if (args.empty()) {
		return "";
	}

	std::string result = std::to_string(args.at(0));
	int rangeStartIndex{ 0 };
	int rangeLength{ 1 };
	
	for (size_t i{ 1 }; i <= args.size(); ++i)
	{
		if (args[i] != args[i - 1] + 1)
		{
			if (rangeLength >= 3)
			{
				result += "-" + std::to_string(args[i - 1]);
			}
			else if (rangeLength == 2)
			{
				result += "," + std::to_string(args[i - 1]);
			}

			if (i != args.size())
			{
				result += "," + std::to_string(args[i]);
			}
			
			rangeLength = 1;
			rangeStartIndex = i;
		}
		else
		{
			++rangeLength;
		}
	}

	return result;
}