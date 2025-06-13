#include <iostream>
#include <vector>
using namespace std;

// Define the Solution class
class Solution {
public:
    // Function to move all zeroes to the end of the vector
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0; // Tracks the position to place the next non-zero element

        // First pass: move all non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) { // If the current element is non-zero
                nums[lastNonZeroFoundAt++] = nums[i]; // Place it at the next available position
            }
        }

        // Second pass: fill the rest of the vector with zeroes
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0; // Set remaining elements to zero
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