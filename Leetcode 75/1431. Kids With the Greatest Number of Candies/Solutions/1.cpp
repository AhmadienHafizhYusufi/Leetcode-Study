#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        // Find the maximum number of candies any kid currently has
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }

        vector<bool> result;
        // For each kid, check if giving them extraCandies makes their total
        // at least as much as the current maximum
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        // Return the result vector containing true/false for each kid
        return result;
    }
};

int main() {
    // Example input: candies = [2,3,5,1,3], extraCandies = 3
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    Solution sol;
    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);

    // Output the result
    cout << "Result: ";
    for (bool canHaveMax : result) {
        cout << (canHaveMax ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}