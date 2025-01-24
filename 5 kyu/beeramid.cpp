// https://www.codewars.com/kata/51e04f6b544cf3f6550000c1/cpp

int beeramid(int bonus, double price)
{
	int remainingCans{ static_cast<int>(bonus / price) };
	int layers{ 0 };

	while (remainingCans > 0)
	{
		int cansInNextLayer{ (layers + 1) * (layers + 1) };
		if (cansInNextLayer <= remainingCans)
		{
			++layers;
		}
		remainingCans -= cansInNextLayer;
	}

	return layers;
}