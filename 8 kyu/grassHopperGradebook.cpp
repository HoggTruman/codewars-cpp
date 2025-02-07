// https://www.codewars.com/kata/55cbd4ba903825f7970000f5/cpp

static char getGrade(int a, int b, int c) {
	int average{ (a + b + c) / 3 };

	if (average >= 90) {
		return 'A';
	} 
	else if (average >= 80) {
		return 'B';
	}
	else if (average >= 70) {
		return 'C';
	}
	else if (average >= 60) {
		return 'D';
	} 
	else {
		return 'F';
	}
}