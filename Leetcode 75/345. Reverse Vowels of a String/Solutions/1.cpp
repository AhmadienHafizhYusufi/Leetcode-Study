#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to reverse only the vowels in the input string
    string reverseVowels(string s) {
        // Set of vowels for quick lookup (both lowercase and uppercase)
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0, right = s.size() - 1; // Two pointers: start and end

        // Loop until the two pointers meet
        while (left < right) {
            // Move left pointer forward until it points to a vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) left++;
            // Move right pointer backward until it points to a vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) right--;
            // If both pointers are at vowels, swap them
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        // Return the modified string with vowels reversed
        return s;
    }
};

int main() {
    Solution sol;
    string input = "hello";
    // Call the function to reverse vowels in "hello"
    string output = sol.reverseVowels(input);
    cout << "Original string: " << input << endl;
    cout << "After reversing vowels: " << output << endl;

    // Another example with "leetcode"
    input = "leetcode";
    output = sol.reverseVowels(input);
    cout << "Original string: " << input << endl;
    cout << "After reversing vowels: " << output << endl;

    return 0;
}