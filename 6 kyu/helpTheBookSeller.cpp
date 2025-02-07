// https://www.codewars.com/kata/54dc6f5a224c26032800005c/

#include <string>
#include <vector>
#include <map>
#include <sstream>

class StockList
{
	public:
		static std::string stockSummary(std::vector<std::string>& lstOfArt, std::vector<std::string>& categories)
		{
			if (lstOfArt.empty() || categories.empty())
			{
				return "";
			}

			std::map<char, int> counts{};

			for (std::string& category : categories)
			{
				counts[category[0]] = 0;
			}

			for (std::string& book : lstOfArt)
			{
				if (counts.count(book[0]))
				{
					std::string count{ book.substr(book.find(' ') + 1) };
					counts[book[0]] += std::stoi(count);
				}
			}

			std::stringstream result{};

			for (std::string& category : categories)
			{
				result << '(' << category << " : " << counts[category[0]] << ')';

				if (category != categories.back())
				{
					result << " - ";
				}
			}

			return result.str();
		}
};
