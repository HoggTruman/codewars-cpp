// https://www.codewars.com/kata/57eaec5608fed543d6000021/cpp

#include <vector>
#include <variant>

static int divCon(const std::vector<std::variant<int, char>>& x) {
	int total{ 0 };
	for (auto& item : x)
	{
		if (std::holds_alternative<int>(item)) {
			total += std::get<int>(item);
		}
		else {
			total -= std::get<char>(item) - '0';
		}
	}
	return total;
}