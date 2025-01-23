// https://www.codewars.com/kata/563b662a59afc2b5120000c6/cpp

#include <cmath>

class Arge
{
	public:
		static int nbYear(int p0, double percent, int aug, int p)
		{
			int yearsRequired{ 0 };
			const double percentMultiplier = 1 + percent / 100.0;

			while (p0 < p)
			{
				p0 = pEndOfYear(p0, percentMultiplier, aug);
				yearsRequired++;
			}

			return yearsRequired;
		}

	private:
		static int pEndOfYear(int p, double percentMultiplier, int aug)
		{
			return std::floor(p * percentMultiplier + aug);
		}
};