### Approach: One-time Traversal

#### Intuition

If a character in $word$ appearch consecutively $k$ times (where $k>1$), and
Alice makes a mistake in this part, then in the actual original string, this
character could have appeared $1,2,...,k-1$ times. That is, there are $k-1$
possible variations.

For the case $k=1$, Alice will not make a mistake, so there are $0$
possibilities, which is consistent with the formula $k-1$.

Therefore, we can traverse the string once: let the current traversal position
be $l$, and suppose the characters in $word$ from positions $[l,r]$ are the
same, while the character at position $r+l$ is different (or does not exist). In
this case, we increase the answer by $r-l$, and continue traversing from
position $r+l$.

This further implies that the total contribution of the interval $[l,r]$ to the
answer is $r-l$. We can interpret this as position $l$ not contributing to the
answer, while each of the positions $[l+1,r]$ contributes 1. Therefore, for any
position $i$ in the string $word$ (where $i>0$), if $word[i-1]$, we can increase
the answer by 1.
