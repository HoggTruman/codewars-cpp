// https://www.codewars.com/kata/550554fd08b86f84fe000a58

#include <vector>
#include <string>
#include <algorithm>
#include <set>

class WhichAreIn
{
	public:
		static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2)
		{
			std::set<std::string> substrings;

			for (auto& s1 : array1)
			{
				for (auto& s2 : array2)
				{
					if (s2.find(s1) != std::string::npos)
					{
						substrings.insert(s1);
						continue;
					}
				}
			}

			return std::vector<std::string>(substrings.begin(), substrings.end());
		}
};
