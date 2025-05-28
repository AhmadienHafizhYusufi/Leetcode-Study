#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // Sort with custom comparator: even numbers first, then odd
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return (a % 2) < (b % 2);
        });
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 1, 2, 4};
    
    vector<int> sortedArray = solution.sortArrayByParity(nums);
    
    cout << "Sorted Array by Parity: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}