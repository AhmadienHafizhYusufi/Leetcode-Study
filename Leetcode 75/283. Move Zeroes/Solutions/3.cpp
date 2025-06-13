#include <iostream>
#include <vector>
using namespace std;

// Define the Solution class
class Solution {
    public:
        // Function to move all zeroes in the vector to the end while maintaining the order of non-zero elements
        void moveZeroes(vector<int>& nums) {
            // Initialize two pointers:
            // lastNonZeroFoundAt: position to place the next non-zero element
            // cur: current index in the array
            for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
                // If the current element is not zero
                if (nums[cur] != 0) {
                    // Swap the current element with the element at lastNonZeroFoundAt
                    swap(nums[lastNonZeroFoundAt++], nums[cur]);
                }
            }
        }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}