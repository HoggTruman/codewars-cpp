// https://www.codewars.com/kata/585894545a8a07255e0002f1

#include <map>
#include <string>
#include <unordered_set>


class PatternCounter
{
	public:
		static unsigned int countPatterns(char firstDot, unsigned short numDots)
		{
			std::unordered_set<char> visited{};
			return countPatternsFrom(firstDot, numDots, visited);
		}

	private:
		// dots reachable in a single move without jumping over other dots.
		// dots in value string are reachable from dot specified by key.
		static const std::map<char, std::string> reachable;

		// dots reachable in a single move by jumping over an occupied dot.
		// the inner map contains dots such that when key is taken, value is reachable.
		static const std::map<char, std::map<char, char>> reachableByJump;


		static unsigned int countPatternsFrom(const char& currentDot, const unsigned short& numDots, std::unordered_set<char>& visited)
		{
			if (numDots == 1 || numDots == 0) {
				return numDots;
			}

			unsigned int totalPatterns{ 0 };
			visited.insert(currentDot);

			for (const char& nextDot : PatternCounter::reachable.at(currentDot))
			{
				if (visited.count(nextDot) == 0)
				{
					totalPatterns += countPatternsFrom(nextDot, numDots - 1, visited);
				}				
			}

			for (const auto& [occupiedDot, nextDot] : PatternCounter::reachableByJump.at(currentDot))
			{
				if (visited.count(occupiedDot) == 1 &&
					visited.count(nextDot) == 0)
				{
					totalPatterns += countPatternsFrom(nextDot, numDots - 1, visited);
				}
			}

			visited.erase(currentDot);
			return totalPatterns;
		}		
};

const std::map<char, std::string> PatternCounter::reachable = {
			{ 'A', "BDEFH" },
			{ 'B', "ACDEFGI" },
			{ 'C', "BDEFH" },
			{ 'D', "ABCEGHI" },
			{ 'E', "ABCDFGHI" },
			{ 'F', "ABCEGHI" },
			{ 'G', "BDEFH" },
			{ 'H', "ACDEFGI" },
			{ 'I', "BDEFH" },
};

const std::map<char, std::map<char, char>> PatternCounter::reachableByJump = {
			{ 'A', { { 'B', 'C' }, { 'E', 'I' }, { 'D', 'G' } } },
			{ 'B', { { 'E', 'H' } } },
			{ 'C', { { 'B', 'A' }, { 'E', 'G' }, { 'F', 'I' } } },
			{ 'D', { { 'E', 'F' } } },
			{ 'E', {} },
			{ 'F', { { 'E', 'D' } } },
			{ 'G', { { 'D', 'A' }, { 'E', 'C' }, { 'H', 'I' } } },
			{ 'H', { { 'E', 'B' } } },
			{ 'I', { { 'H', 'G' }, { 'E', 'A' }, { 'F', 'C' } } }
};


static unsigned int countPatternsFrom(char firstDot, unsigned short length) {
	return PatternCounter::countPatterns(firstDot, length);
}
