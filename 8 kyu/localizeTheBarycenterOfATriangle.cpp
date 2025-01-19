// https://www.codewars.com/kata/5601c5f6ba804403c7000004

#include <utility>
#include <cmath>

using point = const std::pair<double, double>;

double roundToDP(double value, int decimalPlaces)
{
	const double multiplier = std::pow(10.0, decimalPlaces);
	return std::round(value * multiplier) / multiplier;
}


std::pair<double, double> barTriang(point p1, point p2, point p3) {
	auto x = (p1.first + p2.first + p3.first) / 3;
	auto y = (p1.second + p2.second + p3.second) / 3;
	return {roundToDP(x, 4), roundToDP(y, 4)};
}