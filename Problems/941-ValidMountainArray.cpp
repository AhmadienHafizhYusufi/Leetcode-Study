#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false; // A mountain array must have at least 3 elements

        int i = 0;

        // Ascending part
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // Peak cannot be the first or last element
        if (i == 0 || i == n - 1) return false;

        // Descending part
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1; // Check if we reached the end of the array
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {2, 1};
    vector<int> arr2 = {3, 5, 5};
    vector<int> arr3 = {0, 3, 2, 1};
    vector<int> arr4 = {0, 1, 2, 3, 4, 5};

    cout << sol.validMountainArray(arr1) << endl; // Expected: false
    cout << sol.validMountainArray(arr2) << endl; // Expected: false
    cout << sol.validMountainArray(arr3) << endl; // Expected: true
    cout << sol.validMountainArray(arr4) << endl; // Expected: false

    return 0;
}