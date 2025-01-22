// https://www.codewars.com/kata/56606694ec01347ce800001b/cpp

namespace Triangle
{
    bool isTriangle(int a, int b, int c)
    {
        return a - b < c && b - a < c && c - a < b;
    }
};