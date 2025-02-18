// https://www.codewars.com/kata/5fc7caa854783c002196f2cb

#include <string>

static std::string speedify(const std::string& input)
{
    std::string result{};

    for (unsigned int i{ 0 }; i < input.size(); ++i)
    {
        unsigned int pos{ i + (input[i] - 'A') };
        if (pos >= result.size())
        {
            result += std::string(pos - result.size() + 1, ' ');
        }
        result[pos] = input[i];
    }

    return result;
}