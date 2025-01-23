// https://www.codewars.com/kata/539a0e4d85e3425cb0000a88/cpp

struct addFunctor {
	int sum{ 0 };

	auto& operator()(int n)
	{
		sum += n;
		return *this;
	}

	operator int()
	{
		return sum;
	}
};

