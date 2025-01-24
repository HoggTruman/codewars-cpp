// https://www.codewars.com/kata/5418a1dd6d8216e18a0012b2/cpp

#include <cmath>

class Kata {
    public:
        static bool validate(long long int n) {
            if (n <= 0)
            {
                return false;
            }

            const int numDigits = std::floor(std::log10(n) + 1);

            if (numDigits > 16)
            {
                return false;
            }

            int sum{};

            for (int digitFromRight{ 1 }; digitFromRight <= numDigits; ++digitFromRight)
            {
                int digit{ static_cast<int>(n % 10) };

                if (digitFromRight % 2 == 0)
                {
                    digit *= 2;

                    if (digit > 9)
                    {
                        digit -= 9;
                    }
                }

                sum += digit;
                n /= 10;
            }

            return sum % 10 == 0;
        }
};