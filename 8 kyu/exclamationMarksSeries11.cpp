// https://www.codewars.com/kata/57fb09ef2b5314a8a90001ed

#include <string>
#include <unordered_set>

static std::string replace(const std::string& s)
{
    std::unordered_set<char> vowels{ {'a','e','i','o','u','A','E','I','O','U'} };
    std::string result{};
    for (const char& c : s) {
        result += vowels.count(c) ? '!' : c;
    }

    return result;
}