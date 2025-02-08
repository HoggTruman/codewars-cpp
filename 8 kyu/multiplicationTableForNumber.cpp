// https://www.codewars.com/kata/5a2fd38b55519ed98f0000ce/cpp

#include <string>
#include <sstream>

static std::string multi_table(int number)
{
    std::stringstream result{};

    for (int k{ 1 }; k <= 10; ++k)
    {
        result << k << " * " << number << " = " << k * number;
        if (k != 10) {
            result << '\n';
        }
    }

    return result.str();
}