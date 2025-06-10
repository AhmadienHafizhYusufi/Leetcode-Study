#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenating in different orders gives different results,
        // there is no common divisor string
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Find the greatest common divisor of the lengths
        int gcdLength = gcd(str1.size(), str2.size());

        // The GCD string is the prefix of str1 with length gcdLength
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution sol;

    // Dummy test case 1
    string str1 = "ABCABC";
    string str2 = "ABC";
    // Expected output: "ABC"
    cout << "GCD of \"" << str1 << "\" and \"" << str2 << "\": "
         << sol.gcdOfStrings(str1, str2) << endl;

    // Dummy test case 2
    str1 = "ABABAB";
    str2 = "ABAB";
    // Expected output: "AB"
    cout << "GCD of \"" << str1 << "\" and \"" << str2 << "\": "
         << sol.gcdOfStrings(str1, str2) << endl;

    // Dummy test case 3
    str1 = "LEET";
    str2 = "CODE";
    // Expected output: ""
    cout << "GCD of \"" << str1 << "\" and \"" << str2 << "\": "
         << sol.gcdOfStrings(str1, str2) << endl;

    return 0;
}