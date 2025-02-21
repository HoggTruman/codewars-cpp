// https://www.codewars.com/kata/5f9f43328a6bff002fa29eb8

#include <cmath>

static bool approx_equals(double a, double b) {
	return std::abs(a - b) < 0.001;
}