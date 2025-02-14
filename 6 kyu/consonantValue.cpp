// https://www.codewars.com/kata/59c633e7dcc4053512000073/cpp

#include <string>
#include <unordered_set>

static int solve(const std::string& s)
{
    const std::unordered_set<char> vowels({ 'a', 'e', 'i', 'o', 'u' });
    int highScore{ 0 };
    int currentScore{ 0 };

    for (const char& c : s)
    {
        if (vowels.count(c) == 0)
        {
            currentScore += c - 'a' + 1;
        }
        else
        {
            highScore = std::max(highScore, currentScore);
            currentScore = 0;
        }
    }

    return std::max(highScore, currentScore);
}