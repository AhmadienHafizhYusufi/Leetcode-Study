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

## Complexity Analysis

Here, `m` is the length of `word1` and `n` is the length of `word2`.

- Time complexity: $O(m+n)$
  - We iterate over `word1` and `word2` once and push their letters into
    `result`. It would take $O(m+n)$ time.
- Space complexity: $O(1)$
  - Without considering the space consumed by the input strings ( `word1` and
    `word2` ) and the output string ( `result` ), we do not use more than
    constant space.

# Approach 2: One Pointer

## Intuition

We use one index (let's call it `i`) to combine the two words. We start with
`i = 0` and keep going until we reach the end of the longer word. This means we
go up to `i = max(word1.length(), word2.length())`.

At each step, we check if `i` is still within the length of each word. If `i` is
less than the length of `word1`, we add the letter at position `i` from `word1`
to our result.

If `i` is less than the length of `word2`, we add the letter at position `i`
from `word2` to our result.

If `i` is bigger than the length of a word, we just skip adding a letter from
that word and continue with the other word.

## Algorithm

1. Create two variables, `m` and `n`, to store the length of `word1` and
   `word2`.
2. Create an empty string variable `result` to store the result of merged words.
3. Iterate over `word1` and `word2` using a loop running from `i = 0` to
   `i < max(m, n)` and keep incrementing `i` by `1` after each iteration:
   - If `i < m`, it means that we have not completely traversed `word1`. As a
     result, we append `word1[i]` to `result`.
   - If `i < n`, it means that we have not completely traversed `word2`. As a
     result, we append `word2[i]` to `result`.
4. Return `result`.

## Implementation

```cpp
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
```

## Complexity Analysis

Here, `m` is the length of `word1` and `n` is the length of `word2`.

- Time complexity: $O(m+n)$
  - We iterate over `word1` and `word2` once pushing their letters into
    `result`. It would take $O(m+n)$ time.
- Space complexity: $O(1)$
  - Without considering the space consumend by the input strings ( `word1` and
    `word2` ) and the output string ( `result` ), we do not use more than
    constant space.
