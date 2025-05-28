#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] != nums[i]) {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    vector<int> expectedNums = {0,1,2,3,4};

    int k = sol.removeDuplicates(nums);

    // Assert k == expectedNums.size()
    if (k != expectedNums.size()) {
        cout << "Test failed: length mismatch" << endl;
        return 1;
    }

    // Assert nums[i] == expectedNums[i] for i < k
    for (int i = 0; i < k; i++) {
        if (nums[i] != expectedNums[i]) {
            cout << "Test failed at index " << i << endl;
            return 1;
        }
    }

    cout << "Test passed!" << endl;
    return 0;
}