#include <iostream>
#include <string>
using namespace std;

// Define the Solution class
class Solution {
    public:
        // Function to merge two strings alternately
        string mergeAlternately(string word1, string word2) {
            int m = word1.size(); // Get the length of the first string
            int n = word2.size(); // Get the length of the second string

            string result = ""; // Initialize the result string

            int i = 0, j = 0; // Initialize indices for both strings

            // Loop until both strings are fully traversed
            while(i < m || j < n) {
                if (i < m) { // If there are characters left in word1
                    result.push_back(word1[i++]); // Add next char from word1 and increment i
                } 
                if (j < n) { // If there are characters left in word2
                    result.push_back(word2[j++]); // Add next char from word2 and increment j
                }
            }

            return result; // Return the merged string
        }
};

int main() {
    // Example input strings to merge alternately
    string a = "abc";   // First string
    string b = "pqrs"; // Second string (longer to show uneven merge)

    // Create an instance of the Solution class
    Solution sol;

    // Call the mergeAlternately function and print the result
    // Expected output: "adbecfgh"
    cout << sol.mergeAlternately(a, b);

    return 0; // Indicate successful program termination
}