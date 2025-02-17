// https://www.codewars.com/kata/5ebd53ea50d0680031190b96

#include <string>
#include <map>

static std::string getTurkishNumber(unsigned int n) {
	const std::map<int, std::string> units{ {
		{ 0, "sıfır" },
		{ 1, "bir" },
		{ 2, "iki" },
		{ 3, "üç" },
		{ 4, "dört" },
		{ 5, "beş" },
		{ 6, "altı" },
		{ 7, "yedi" },
		{ 8, "sekiz" },
		{ 9, "dokuz" },
	} };

	const std::map<int, std::string> tens{ {
		{ 0, "" },
		{ 10, "on" },
		{ 20, "yirmi" },
		{ 30, "otuz" },
		{ 40, "kırk" },
		{ 50, "elli" },
		{ 60, "altmış" },
		{ 70, "yetmiş" },
		{ 80, "seksen" },
		{ 90, "doksan" },
	} };
	
	int numTens{ static_cast<int>((n / 10) * 10) };
	int numUnits{ static_cast<int>(n % 10) };
	
	if (numTens == 0) {
		return units.at(numUnits);
	}

	return tens.at(numTens) + (numUnits > 0 ? " " + units.at(numUnits) : "");
}