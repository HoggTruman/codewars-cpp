// https://www.codewars.com/kata/5ac6932b2f317b96980000ca/cpp

#include <vector>
#include <set>
#include<cmath>

typedef unsigned long long ull;

static ull minValue(std::vector<int> values)
{
    std::set<int> uniqueValues(values.begin(), values.end());
    ull result{ 0 };
    ull power{ uniqueValues.size() - 1 };

    for (const int& value : uniqueValues)
    {
        result += static_cast<ull>(std::pow(10, power--) * value);
    }

    return result;
}
