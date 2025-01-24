// https://www.codewars.com/kata/52e88b39ffb6ac53a400022e/cpp

#include <string>

std::string uint32_to_ip(uint32_t ip)
{
	return std::to_string(ip >> 24) + "."
		+ std::to_string((ip >> 16) & 255) + "."
		+ std::to_string((ip >> 8) & 255) + "."
		+ std::to_string(ip & 255);
}
