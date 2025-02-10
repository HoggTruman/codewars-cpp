// https://www.codewars.com/kata/59811fd8a070625d4c000013

#include <string>

static std::string integrate(const int& coefficient, const int& exponent) {
	return std::to_string((coefficient / (exponent + 1))) + "x^" + std::to_string(exponent + 1);
}