// https://www.codewars.com/kata/580a4734d6df748060000045/cpp

#include <vector>
#include <string>

std::string is_sorted_and_how(std::vector<int> array)
{
    if (array[0] == array[1])
    {
        return "no";
    }

    const bool isAscending{ array[1] > array[0] };

    for (size_t i{ 1 }; i < array.size() - 1; i++)
    {
        if (isAscending)
        {
            if (array[i + 1] <= array[i]) 
            {
                return "no";
            }            
        }
        else 
        {
            if (array[i + 1] >= array[i])
            {
                return "no";
            }            
        }
    }

    return isAscending ?
        "yes, ascending" :
        "yes, descending";
}