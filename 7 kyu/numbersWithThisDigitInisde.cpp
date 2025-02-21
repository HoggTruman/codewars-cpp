// https://www.codewars.com/kata/57ad85bb7cb1f3ae7c000039

#include <vector>

static bool containsDigit(long k, long d) {
    while (k > 0) {
        if (k % 10 == d) return true;
        k /= 10;
    }
    return false;
}

static std::vector<long> numbersWithDigitInside(long x, long d)
{
    long count{ 0 };
    long sum{ 0 };
    long product{ 1 };

    for (long k{ 1 }; k <= x; ++k)
    {
        if (containsDigit(k, d)) {
            ++count;
            sum += k;
            product *= k;
        }
    }

    return { count, sum, count == 0 ? 0 : product };
}