// https://www.codewars.com/kata/555624b601231dc7a400017a/cpp

int josephusSurvivor(int n, int k) {
	if (n == 1)
	{
		return 1;
	}

	return (josephusSurvivor(n - 1, k) + k - 1) % n + 1;
}