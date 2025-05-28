#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            for (int i = digits.size() - 1; i >= 0; i--) {
                if (digits[i] < 9) {
                    digits[i]++;
                    return digits;
                }
                digits[i] = 0;
                if (i == 0) {
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
            }
            return digits;
        }
};

int main() {
    Solution solution;
    vector<int> digits = {9, 9, 9};
    vector<int> result = solution.plusOne(digits);
    
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}