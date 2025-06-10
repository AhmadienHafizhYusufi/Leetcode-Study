# Approach 1: Brute Force

## Intuition

To find the greatest common divisor (GCD) string of two strings, we look for the
longest string that can be repeated to make both str1 and str2.

Instead of checking every possible string, we only need to check each prefix
(awal substring) of the shorter string. If a prefix can be repeated to form both
strings, then it is a candidate for the GCD string.

We start with the longest possible prefix (the whole shorter string) and keep
trying shorter prefixes until we find one that works.

## Algorithm (Step-by-step)

1. **Find the shorter string** between `str1` and `str2`. Let’s call it `str1`
   for simplicity.
2. **Try every prefix** of `str1`, starting from the longest to the shortest.
3. For each prefix:
   - Check if both `str1` and `str2` can be made by repeating this prefix.
   - If yes, return this prefix as the answer.
   - If not, try the next shorter prefix.
4. If no prefix works, return an empty string `""`.

## Implementation

```cpp
class Solution {
public:
    // Helper function to repeat a string k times
    string repeat(string str, int k) {
        string ans = "";
        for (int i = 0; i < k; ++i) ans += str;
        return ans;
    }

    // Check if both strings can be made by repeating the same substring of length k
    bool isValid(string str1, string str2, int k) {
        if (str1.size() % k != 0 || str2.size() % k != 0) return false;
        string base = str1.substr(0, k);
        return str1 == repeat(base, str1.size() / k) && str2 == repeat(base, str2.size() / k);
    }

    // Main function to find the GCD string
    string gcdOfStrings(string str1, string str2) {
        int minLen = min(str1.size(), str2.size());
        for (int len = minLen; len >= 1; --len) {
            if (isValid(str1, str2, len)) {
                return str1.substr(0, len);
            }
        }
        return "";
    }
};
```

## Complexity

- **Time Complexity:**  
  $O(min(m, n) \times (m + n))$  
  We check each prefix of the shorter string (up to `min(m, n)` prefixes), and
  for each, we may need to build both strings (which takes $O(m + n)$ time).

- **Space Complexity:**  
  $O(min(m, n))$  
  We store a prefix substring and repeated strings.

---

**Tips for Beginners:**

- A **prefix** is just the beginning part of a string. For example, `"ab"` is a
  prefix of `"abcabc"`.
- We only need to check prefixes because only a prefix can be repeated to form
  the whole string.
- Always start checking from the longest possible prefix to find the answer
  faster.

# Approach 2: Greatest Common Divisor

## Intuition

Instead of checking every possible prefix, we can use a mathematical trick:

- If two strings can be formed by repeating the same substring, then joining
  them in any order (`str1 + str2` or `str2 + str1`) will give the same result.
- If joining them in different orders gives different results, it means there is
  **no common substring** that can be repeated to form both strings.

So, if `str1 + str2` is equal to `str2 + str1`, we know there is a common
pattern. The length of the largest possible repeating substring is the _greatest
common divisor (GCD)_ of the lengths of `str1` and `str2`.

We can take the first `gcdLength` characters from either string as the answer.

## Algorithm

1. Check if the concatentaions of `str1` and `str2` in different orders are the
   same.
   - if not, return `""`.
2. Get the GCD `gcdLength` of the two lengths of `str1` and `str2`.
3. Return the prefix string with a length of `gcdLength` of either `str1` or
   `str2` as the answer.

## Implementation

```cpp
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
```

## Complexity Analysis

Let `m`, `n` be the lenghtes of the two input strings `str1` and `str2`.

- Time complexity: $O(m+n)$
  - We need to compare the two concatenations of lenth $O(m+n)$, it takes
    $O(m+n)$ time.
  - We calculate the GCD using binary Euclidean algorithm, it takes
    $log(m \times n) time$
  - To sum up, the overall time complexity is $O(m+n)$.
- Space complexity: $O(m+n)$, we need to compare the two concatenations of
  length $O(m+n)$
