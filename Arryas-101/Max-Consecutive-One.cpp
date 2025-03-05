#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
	int maxConsecutive = 0;
    int countConsecutive = 0;
    for (int num : nums) {
        if (num == 1) {
            countConsecutive++;
            maxConsecutive = max(maxConsecutive, countConsecutive);
        } else {
            countConsecutive = 0;
        }
    }
    return maxConsecutive;
}

int main() {
	vector<int> nums = { 1, 1, 0, 1, 1, 1, 1, 1 };
	cout << "Maximum consecutive ones: " << findMaxConsecutiveOnes(nums) << endl;
	return 0;
}