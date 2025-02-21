// https://www.codewars.com/kata/58184387d14fc32f2b0012b2

#include <cmath>


static double f(double x)
{
    return std::expm1(std::log1p(x) / 2);
}
