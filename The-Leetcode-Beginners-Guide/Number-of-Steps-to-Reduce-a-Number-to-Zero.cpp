#include <iostream>

using namespace std;

int numberOfSteps(int num) {
	int steps = 0;
	while (num > 0) {
		if (num % 2 == 0) {
			num /= 2;
			steps++;
		}
		else if (num % 2 != 0) {
			num--;
			steps++;
		}
	}
	return steps;
}

int main() {
	int num = 14;
	cout << "Number of steps to reduce " << num << " to zero: " << numberOfSteps(num) << endl;

	num = 8;
	cout << "Number of steps to reduce " << num << " to zero: " << numberOfSteps(num) << endl;

	num = 123;
	cout << "Number of steps to reduce " << num << " to zero: " << numberOfSteps(num) << endl;

	return 0;
}