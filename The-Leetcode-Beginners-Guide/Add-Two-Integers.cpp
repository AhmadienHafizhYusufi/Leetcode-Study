#include <iostream>

using namespace std;

int sum(int num1, int num2) {
	return num1 + num2;
}

int main() {
	int num1, num2;
	
	cout << "num1 = ";
	cin >> num1;
	cout << "num2 = ";
	cin >> num2;
	
	cout << sum(num1, num2);
}