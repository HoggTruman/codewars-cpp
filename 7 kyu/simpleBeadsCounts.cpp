// https://www.codewars.com/kata/58712dfa5c538b6fc7000569/cpp

static unsigned int countRedBeads(unsigned int n) {
	return n < 2 ? 0 : 2 * n - 2;
}