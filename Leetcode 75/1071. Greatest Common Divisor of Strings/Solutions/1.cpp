#include <iostream> // Include the input/output stream library
using namespace std; // Use the standard namespace

// Define the Solution class
class Solution {
    public:
        // Checks if both strings can be constructed by repeating the same substring of length k
        bool valid(string str1, string str2, int k) {
            int len1 = str1.size(), len2 = str2.size(); // Get lengths of both strings
            if (len1 % k > 0 || len2 % k > 0) { // If either string's length is not divisible by k
                return false; // Not possible to construct by repeating a substring of length k
            } else {
                string base = str1.substr(0, k); // Take the first k characters as the base substring
                int n1 = len1 / k, n2 = len2 / k; // Calculate how many times base should repeat for each string
                // Check if repeating base n1 times gives str1 and repeating base n2 times gives str2
                return str1 == joinWords(base, n1) && str2 == joinWords(base, n2);
            }
        }

        // Helper function to repeat a string k times
        string joinWords(string str, int k) {
            string ans = ""; // Initialize an empty result string
            for (int i = 0; i < k; ++i) { // Repeat k times
                ans += str; // Append str to ans
            }
            return ans; // Return the repeated string
        }

        // Finds the greatest common divisor string of str1 and str2
        string gcdOfStrings(string str1, string str2) {
            int len1 = str1.length(), len2 = str2.length(); // Get lengths of both strings
            // Try all possible substring lengths from min(len1, len2) down to 1
            for (int i = min(len1, len2); i >= 1; --i) {
                if (valid(str1, str2, i)) { // If both strings can be constructed by repeating the same substring of length i
                    return str1.substr(0, i); // Return that substring
                }
            }
            return ""; // If no such substring exists, return empty string
        }
};

int main() {
    string a = "ABCABC", b = "ABC"; // Example input strings
    Solution sol; // Create an instance of Solution
    string gcd = sol.gcdOfStrings(a, b); // Find the GCD string
    cout << gcd; // Output the result
}