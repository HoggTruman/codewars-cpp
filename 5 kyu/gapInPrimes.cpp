// https://www.codewars.com/kata/561e9c843a2ef5a40c0000a4/cpp

#include <utility>
#include <cmath>

class GapInPrimes
{
    public:
        static std::pair<long long, long long> gap(int g, long long m, long long n) {
            // Initialised to n so that the calculated gap is always
            // non-positive and does not match g for the first prime
            long long current{ n };

            for (long long k{ m }; k <= n; ++k)
            {
                if (isPrime(k))
                {
                    if (k - current == g)
                    {
                        return std::pair{ current, k };
                    }

                    current = k;
                }
            }

            return std::pair{ 0, 0 };
        }


    private:
        static bool isPrime(long long k)
        {
            long long squareRoot = sqrt(k);

            for (long long divisor{ 2 }; divisor <= squareRoot; ++divisor)
            {
                if (k % divisor == 0)
                {
                    return false;
                }
            }

            return true;
        }
};
