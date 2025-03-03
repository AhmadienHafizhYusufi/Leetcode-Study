#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
	int n = nums.size();
	vector<int> hasil(n);
	hasil[0] = nums[0];

	for (int i = 1; i < n; i++) {
		hasil[i] = hasil[i - 1] + nums[i];
	}

	return hasil;
}

int main() {
	vector<int> nums = { 1, 2, 3, 4 };
	vector<int> hasil = runningSum(nums);

	cout << "Running sum: ";
	for (int num : hasil) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}