// https://www.codewars.com/kata/5a092d9e46d843b9db000064

#include <vector>
#include <map>

static int solve(std::vector<int> v) {
	std::map<int, bool> pairs{};

	for (int& k : v)
	{
		if (pairs.count(-k)) {
			pairs[-k] = true;
		}
		else {
			pairs[k] = false;
		}
	}

	for (auto [key, isPair] : pairs)
	{
		if (!isPair) {
			return key;
		}
	}

	return 0;
}