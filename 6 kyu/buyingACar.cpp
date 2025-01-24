// https://www.codewars.com/kata/554a44516729e4d80b000012/cpp

#include <vector>
#include <cmath>

class BuyCar
{
	public:
		static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingPerMonth, double percentLossByMonth)
		{
			int elapsedMonths{ 0 };
			double priceDiff = startPriceNew - startPriceOld;

			while (priceDiff - elapsedMonths * savingPerMonth > 0)
			{				
				++elapsedMonths;
				if (elapsedMonths % 2 == 0)
				{
					percentLossByMonth += 0.5;
				}
				priceDiff *= 1 - percentLossByMonth / 100.0;
			}

			int remainingCash = std::round(elapsedMonths * savingPerMonth - priceDiff);

			return { elapsedMonths, remainingCash };
		}
};
