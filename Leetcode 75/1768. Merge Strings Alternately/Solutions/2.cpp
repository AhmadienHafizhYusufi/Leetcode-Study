// Includes the input/output stream library for using cout and cin.
#include <iostream>         
// Includes the string library to use the std::string class.
#include <string>           
// Allows you to use standard library names without the 'std::' prefix.
using namespace std;        

// Defines a class named Solution.
class Solution {            
    // Public access specifier so members can be accessed outside the class.
    public:                 
        // Declares a function that takes two strings and returns a string.
        string mergeAlternately(string word1, string word2) { 
            // Stores the length of word1 in variable m.
            int m = word1.size();     
            // Stores the length of word2 in variable n.
            int n = word2.size();     
            // Initializes an empty string to store the merged result.
            string result = "";       

            // Loops from 0 to the length of the longer word.
            for (int i = 0; i < max(m, n); i++) { 
                // If i is within the bounds of word1,
                if (i < m) {                      
                    // append the i-th character of word1 to result.
                    result.push_back(word1[i]);   
                }
                // If i is within the bounds of word2,
                if (i < n) {                      
                    // append the i-th character of word2 to result.
                    result.push_back(word2[i]);   
                }
            }

            // Returns the merged string.
            return result;                        
        }
};

// Entry point of the program.
int main() {                      
    // Declares and initializes string a with "abc".
    string a = "abc";             
    // Declares and initializes string b with "pqrs".
    string b = "pqrs";            
    // Creates an instance of the Solution class.
    Solution sol;                 
    // Calls mergeAlternately with a and b, prints the result.
    cout << sol.mergeAlternately(a,b); 
    // Returns 0 to indicate successful execution.
    return 0;                     
}