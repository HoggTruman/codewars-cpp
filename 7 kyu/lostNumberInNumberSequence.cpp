// https://www.codewars.com/kata/595aa94353e43a8746000120

#include <list>
#include <unordered_set>

static int findDeletedNumber(std::list<int> startingList, std::list<int> mixedList)
{
    if (startingList.size() == mixedList.size()) {
        return 0;
    }

    std::unordered_set<int> included{};
    included.insert(mixedList.begin(), mixedList.end());

    for (int& k : startingList) {
        if (included.count(k) == 0) {
            return k;
        }
    }
    
    return 0;
}