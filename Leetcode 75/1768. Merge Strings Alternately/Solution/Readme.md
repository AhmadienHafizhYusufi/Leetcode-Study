# Approach 1: Two Pointers

## Intuition

We use two pointers: `i` for `word1` and `j` for `word2`, both starting at the
first letter of each word. We also create an empty string called `results` to
build our answer.

We take turns adding letters from each word. First, we add `word1[i]` to
`results` and move `i` to the next letter. Then, we add `word2[j]` to `results`
and move `j` forward.

We keep repeating this process, alternating between the two words, until we
reach the end of both. If one word runs out of letters before the other, we just
keep adding letters from the remaining word until both are finished.

## Algorithm

1. Find the lengths of `word1` and `word2` and store them in `m` and `n`.
2. Make an empty string called `result` to build the merged word.
3. Set two pointers, `i` and `j`, both starting at `0`, to keep track of where
   we are in each word.
4. While either pointer hasn't reached the end of its word:
   - If `i` is still less than `m`, add the next letter from `word1` to `result`
     and move `i` forward.
   - If `j` is still less than `n`, add the next letter from `word2` to `result`
     and move `j` forward.
5. When both words are finished, return `result`.

## Implementation

### C++

```cpp
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
```
