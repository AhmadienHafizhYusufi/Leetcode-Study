#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
	int maxWealth = 0;

	for (const auto& customer : accounts) {
		int currentWealth = 0;
		for (int money : customer) {
			currentWealth += money;
		}
		maxWealth = max(maxWealth, currentWealth);
	}

	return maxWealth;
}

int main() {
	vector<vector<int>> accounts = { {1, 2, 3}, {3, 2, 1}, {4, 5, 6} };
	cout << "Kekayaan maksimum pelanggan terkaya: " << maximumWealth(accounts) << endl;

	return 0;
}