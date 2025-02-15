// https://www.codewars.com/kata/5506b230a11c0aeab3000c1f

#include <cmath>

class Evaporator
{
public:
	static int evaporator(double _, double evap_per_day, double threshold)
	{
		double decimalThreshold{ threshold / 100 };
		double dailyMultiplier{ 1.0 - evap_per_day / 100.0 };
		return static_cast<int>(std::ceil(std::log(decimalThreshold) / std::log(dailyMultiplier)));
	}
};
