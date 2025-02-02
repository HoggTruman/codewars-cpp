// https://www.codewars.com/kata/5700c9acc1555755be00027e


#include <string>
#include <vector>
#include <unordered_set>

class Rotations
{
public:
    static bool containAllRots(const std::string& str, std::vector<std::string>& arr)
    {
        std::unordered_set<std::string> rots{};
        for (size_t i{ 0 }; i < str.size(); ++i)
        {
            rots.insert(str.substr(i, str.length() - i) + str.substr(0, i));
        }

        for (std::string& rot : arr)
        {
            rots.erase(rot);
        }

        return rots.empty();
    }
};
