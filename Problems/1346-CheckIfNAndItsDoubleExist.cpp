#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    bool checkIfExist(vector<int>& arr) {
        // 1. Iterate through all pairs of indices
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                // 2. Check if the current element is double the other
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true; // Found a pair where one is double the other
                }
            }
        }
        return false; // No such pair found
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 2, 5, 3};
    
    // Test case 1
    if (sol.checkIfExist(arr)) {
        cout << "Test case 1 passed!" << endl;
    } else {
        cout << "Test case 1 failed!" << endl;
    }

    // Test case 2
    arr = {7, 1, 14, 11};
    if (sol.checkIfExist(arr)) {
        cout << "Test case 2 passed!" << endl;
    } else {
        cout << "Test case 2 failed!" << endl;
    }

    // Test case 3
    arr = {3, 1, 7, 11};
    if (!sol.checkIfExist(arr)) {
        cout << "Test case 3 passed!" << endl;
    } else {
        cout << "Test case 3 failed!" << endl;
    }

    return 0;
}