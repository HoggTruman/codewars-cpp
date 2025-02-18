// https://www.codewars.com/kata/5a4d303f880385399b000001

#include <string>

static int factorial(int n) {
    int factorial{ 1 };
    for (int k{ 2 }; k <= n; ++k) {
        factorial *= k;
    }
    return factorial;
}


static std::string strong_num(int number)
{
    int sum{ 0 };
    int remainingDigits{ number };

    while (remainingDigits > 0)
    {
        sum += factorial(remainingDigits % 10);
        remainingDigits /= 10;
    }

    return sum == number ? "STRONG!!!!" : "Not Strong !!";
}