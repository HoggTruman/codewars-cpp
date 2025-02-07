// https://www.codewars.com/kata/5648b12ce68d9daa6b000099/cpp

#include <utility>
#include <vector>

static unsigned int number(const std::vector<std::pair<int, int>>& busStops) {
	int peopleOnBus{ 0 };
	for (auto& [on, off] : busStops)
	{
		peopleOnBus += on - off;
	}

	return static_cast<unsigned int>(peopleOnBus);
}