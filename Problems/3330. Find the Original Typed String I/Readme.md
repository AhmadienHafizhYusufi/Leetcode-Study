### 3330. Find the Original Typed String I

Alice is attempting to type a sepcific string on her computer. However, she
tends to be clumsy an **may** press a key for too long, resulting in a character
being typed **multiple** times.

Although Alice tried to focus on her typing, she is aware that she may still
have dsone this **at most** _once_.

You are given a string `word`, which represents the **final** output displayed
on Alice's screen. Return the total number of _possible_ original string that
Alice _might_ have intended to type.

#### Example 1:

**Input:** word = "abbcccc"

**Output:** 5

**Explanation:** The possible string are : `"abbcccc"`, `"abbccc"`, `"abbcc"`,
`"abcccc"`.

#### Example 2:

**Input:** word = "abcd"

**Output:** 1

**Explanation:** The only possible string is `"abcd"`

#### Example 3:

**Input:** word = "aaaa"

**Output:** 4

#### Constraints:

- `1 <= word.length <= 100`
- `word` consist only of lowercase English letters.
