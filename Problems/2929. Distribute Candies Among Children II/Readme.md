### 2929. Distribute Candies Among Children II

You are given two positive integers `n` and `limit`.

Return the **_total number_** _of ways to distribute_ `n` _candies among_ `3`
_children such that no child gets more than_ `limit` _candies_.

#### Example 1:

**Input:** n = 5, limit = 2

**Output:** 3

**Explanation:** There are 3 ways to distribute 5 candies such that no child
gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).

#### Example 2:

**Input:** n = 3, limit = 3

**Output:** 10

**Explanation:** There are 10 ways to distribute 3 candies such taht no child
gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2),
(1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).

#### Constraints:

- $1 \leq n \leq 10^6$
- $1 \leq limit \leq 10^6$
