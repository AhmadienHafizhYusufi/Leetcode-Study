# 32. Longest Valid Parentheses

Given a string containing just the characters `'('` and `')'`, return _the
length of the longest valid (well-formed) parentheses **substring**_.

A **substring** is a contiguous **non-empty** sequence of characters within a
string.

#### Example 1:

**Input:** s = "(()"

**Output:** 2

**Explanation:** The longest valid parentheses substring is "()".

#### Example 2:

**Input:** s = ")()())"

**Output:** 4

**Explanation:** The longest valid parentheses substring is "()()".

#### Example 3:

**Input:** s = ""

**Output:** 0

### Constraints:

- `0 <= s.length <= 3 \* 104`
- `s[i]` is `'(', or ')'`.
