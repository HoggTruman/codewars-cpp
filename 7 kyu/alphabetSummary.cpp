// https://www.codewars.com/kata/59d9ff9f7905dfeed50000b0

#include <vector>
#include <string>

int lettersInPosition(std::string_view s)
{
    const int ASCII_A{ 65 };
    const int ASCII_a{ 97 };
    int count{ 0 };

    for (int i{ 0 }; i < s.length(); i++)
    {
        if (std::isupper(s[i]) &&
            s[i] == ASCII_A + i)
        {
            count++;
        }
        else if (s[i] == ASCII_a + i)
        {
            count++;
        }
    }

    return count;
}


std::vector<int> solve(const std::vector<std::string>& arr) {
    std::vector<int> result(arr.size());
    for (int i{ 0 }; i < arr.size(); i++)
    {
        result[i] = lettersInPosition(arr[i]);
    }

    return result;
};

