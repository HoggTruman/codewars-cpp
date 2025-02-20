// https://www.codewars.com/kata/57ecf6efc7fe13eb070000e1

#include <string>
#include <map>
static std::string outed(const std::map<std::string, int>& meet, const std::string& boss) {
	unsigned int totalHappiness{};
	for (auto& [name, happiness] : meet) {
		name == boss ?
			totalHappiness += happiness * 2u :
			totalHappiness += happiness;
	}

	return totalHappiness > meet.size() * 5u ?
		"Nice Work Champ!" :
		"Get Out Now!";
}