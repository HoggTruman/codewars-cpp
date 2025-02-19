// https://www.codewars.com/kata/5786f8404c4709148f0006bf

#include <cmath>

static double startingMark(double bodyHeight)
{
    double m{ (10.67 - 9.45) / (1.83 - 1.52) };
    double c{ 9.45 - m * 1.52 };
    double startMark{ m * bodyHeight + c };
    return std::round(startMark * 100) / 100;
}