// https://www.codewars.com/kata/5772da22b89313a4d50012f7/cpp

#include <string>

static std::string greet(const std::string& name, const std::string& owner) {
	return name == owner ? "Hello boss" : "Hello guest";
}