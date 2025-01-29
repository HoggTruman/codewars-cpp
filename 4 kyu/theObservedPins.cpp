// https://www.codewars.com/kata/5263c6999e0f40dee200059d/cpp

#include <string>
#include <vector>
#include <map>

void findVariations(const std::string& baseVariation, const std::string& observed, std::vector<std::string>& variations)
{
	const std::map<char, std::vector<char>> keyOptions = {
		{ '0', { '0', '8' } },
		{ '1', { '1', '2', '4' }},
		{ '2', { '1', '2', '3', '5' }},
		{ '3', { '2', '3', '6' }},
		{ '4', { '1', '4', '5', '7' }},
		{ '5', { '2', '4', '5', '6', '8' }},
		{ '6', { '3', '5', '6', '9' } },
		{ '7', { '4', '7', '8' }},
		{ '8', { '0', '5', '7', '8', '9' }},
		{ '9', { '6', '8', '9' }}
	};

	const char observedKey{ observed[baseVariation.size()] };

	for (const char& key : keyOptions.at(observedKey))
	{
		std::string variation{ baseVariation + key };
		if (variation.size() == observed.size())
		{
			variations.push_back(variation);
		}
		else
		{
			findVariations(variation, observed, variations);
		}
	}
}

std::vector<std::string> get_pins(std::string observed) {
	std::vector<std::string> variations{};
	std::string baseVariation{ "" };
	findVariations(baseVariation, observed, variations);

	return variations;
}
