// https://www.codewars.com/kata/57ed30dde7728215300005fa/cpp

#include <string>

std::string bumps(std::string road) 
{
	return std::count(road.begin(), road.end(), 'n') <= 15 ? "Woohoo!" : "Car Dead";
}