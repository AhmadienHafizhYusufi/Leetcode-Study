#include <iostream>
#include <vector>

using namespace std;

// Solution class definition
class Solution {
public:
    // Function to move all zeroes to the end of the vector
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // Count the number of zeroes in the vector
        int numZeroes = 0;
        for (int i = 0; i < n; i++) {
            // Increment numZeroes if the current element is zero
            numZeroes += (nums[i] == 0);
        }

        // Create a new vector to store non-zero elements
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // Add non-zero elements to the new vector
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
            }
        }

        // Append zeroes to the end of the new vector
        while (numZeroes--) {
            ans.push_back(0);
        }

        // Copy the elements from the new vector back to the original vector
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
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