// https://www.codewars.com/kata/57f22b0f1b5432ff09001cab

#include <string>
#include <vector>
#include <algorithm>

static std::string well(const std::vector<std::vector<std::string>>& arr) {
	int goodCount{};
	for (const auto& row : arr) {
		for (std::string str : row) {
			std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
			if (str == "good") {
				++goodCount;
			}
		}
	}

	return goodCount > 2 ? "I smell a series!" :
		goodCount > 0 ? "Publish!" :
		"Fail!";
}