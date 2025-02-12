// https://www.codewars.com/kata/54d512e62a5e54c96200019e

#include <string>
#include <map>
#include <cmath>
#include <sstream>

class PrimeDecomp
{
public:
    static std::string factors(int lst)
    {
        const int maxFactor{ static_cast<int>(lst / 2) };
        std::map<int, int> factorCounts{};
        int remaining{ lst };
        int factor{ 2 };

        while (!isPrime(remaining))
        {
            if (remaining % factor == 0) {
                remaining /= factor;
                ++factorCounts[factor];
            }
            else {
                factor = getNextPrime(factor, maxFactor);
            }
        }

        ++factorCounts[remaining];

        return constructDecmopositionString(factorCounts);
    }

private:
    static int getNextPrime(int prev, int max)
    {
        for (int k{ prev + 1 }; k <= max; ++k) {
            if (isPrime(k)) {
                return k;
            }
        }

        return -1;
    }

    static bool isPrime(int k)
    {
        int squareRoot = sqrt(k);

        for (int divisor{ 2 }; divisor <= squareRoot; ++divisor)
        {
            if (k % divisor == 0)
            {
                return false;
            }
        }

        return true;
    }

    static std::string constructDecmopositionString(std::map<int, int>& factorCounts)
    {
        std::stringstream result{};

        for (auto& [factor, count] : factorCounts) {
            result << '(' << factor;
            if (count > 1) result << "**" << count;
            result << ')';
        }

        return result.str();
    }
};
