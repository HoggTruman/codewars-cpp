// https://www.codewars.com/kata/557b5e0bddf29d861400005d

#include <cmath>

double converter(int mpg)
{
    const double l_per_g{ 4.54609188 };
    const double km_per_m{ 1.609344 };
    double kpl{ mpg * km_per_m / l_per_g };

    return std::round(kpl * 100) / 100;
}