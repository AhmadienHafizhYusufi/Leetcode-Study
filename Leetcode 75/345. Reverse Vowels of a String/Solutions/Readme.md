# Approach 1: Two Pointers

## Intuition

1. **What are vowels?**  
   Vowels are the letters: a, e, i, o, u (both lowercase and uppercase).

2. **How do we reverse only the vowels?**
   - We look for vowels from the start and end of the string at the same time.
   - When we find a vowel at the start and a vowel at the end, we swap them.
   - We keep moving towards the center, swapping vowels as we go.

## Algorithm

1. Initialize the left pointer `start` to `0`, and the right pointer `end` to
   `s.size() - 1`.
2. Keep iterating until the left pointer catches up with the right pointer. a.
   Keep incrementing the left pointer `start` until it's pointing to a vowel
   character. b. Keep decrementing the right pointer `end` until it's pointing
   to a vowel character. c. Swap the characters at the `start` and `end`. d.
   Increment the `start` and `end`.
3. Return the string `s`.

## Implementation

```cpp
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
```

## Example

Let’s see how `"hello"` changes:

| Step | String    | left | right | Action                  |
| ---- | --------- | ---- | ----- | ----------------------- |
| 1    | h e l l o | 0    | 4     | e and o found, swap     |
| 2    | h o l l e | 1    | 3     | done (pointers crossed) |

So, `"hello"` becomes `"holle"`.

## Complexity Analysis

- Time complexity: $O(N)$. It might be tempting to say that there are two nested
  loops and hence the complexity would be $O(N<sup>2</sup>)$. However, if we
  observe closely the pointers `start` and `end` will only traverse the index
  once. Each element of trhe string `s` will be iterated only once either by the
  left or right poiinter and not both. We swap characters when bothg pointers
  point to vowels which are $O(1)$ operation. Hence the total time complexity
  will be $O(N)$.
- Space Complexity: $O(N)$. In C++ we only need an extra temporary variable to
  perform the swap and hence the space complexity is $O(1)$.
