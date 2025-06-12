# Approach 1: Single Scan

## Intuition

The solution is very simple. We can find out the extra maximum number of
flowers, `count`, that can be planted for the given `flowerbed` arrangement. To
do som we can traverse over all the elements of the `flowerbed` and find out
thos elements which are 0 (implying an empty position). For every such element,
we check if its both adjacent positions are also empty. If so, we can plant a
flower at the current position without violating the no-adjacent-flowers-rule.
For the first and last elements, we need to check the previous and the next
adjacent psotions respectively.

If the `count` obtained is greater than or equal to `n`, the required number of
flowers to be planted, we can plant `n` flowers in the empty spaces, otherwise
not.

## Algorithm

## Algorithm

1. Initialize a variable `count` to 0. This will keep track of how many flowers
   we can plant.
2. Loop through each position `i` in the `flowerbed` array:
   - If the current plot (`flowerbed[i]`) is empty (equals 0):
     - Check if the left plot is empty or if `i` is the first plot.
     - Check if the right plot is empty or if `i` is the last plot.
     - If both left and right plots are empty (or out of bounds), plant a flower
       at position `i` by setting `flowerbed[i]` to 1, and increase `count`
       by 1.
3. After the loop, check if `count` is greater than or equal to `n` (the
   required number of flowers to plant).
   - If yes, return `true`.
   - If not, return `false`.

## Implementation

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            // Check if the current plot is empty
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty
                bool emptyLeftPlot = (i == 0 || (flowerbed[i - 1]) == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1 || (flowerbed[i + 1] == 0));

                // If both plots empty, we can plant a flower here
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count >= n;
    }
};
```

## Complexity Analysis

- Time complexity: $O(n)$. A singler scan of the `flowerbed` array of size `n`
  is done.
- Space complexity: $O(1)$. Constant extra space is used.

# Approach 2: Optimized

## Intuition

Instead of always checking every spot in the flowerbed, we can stop early if we
have already planted enough flowers.  
As soon as we reach the required number of flowers (`n`), we return `true`.  
If we finish checking all spots and still haven't planted enough, we return
`false`.

## Algorithm (Step by Step)

1. Start with a counter `count` set to 0. This will track how many flowers we
   have planted.
2. Go through each spot in the `flowerbed`:
   - If the current spot is empty (`0`):
     - Check if the spot to the left is also empty, or if this is the first
       spot.
     - Check if the spot to the right is also empty, or if this is the last
       spot.
     - If both sides are empty (or out of bounds), plant a flower here:
       - Set this spot to `1` (to show a flower is planted).
       - Increase `count` by 1.
       - If `count` is now equal to or greater than `n`, return `true` right
         away.
3. If you finish checking all spots and haven't planted enough flowers, return
   `false`.

## Implementation

```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            // Check if the current spot is empty
            if (flowerbed[i] == 0) {
                // Check if the left and right spots are empty or out of bounds
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);

                // If both sides are empty, plant a flower here
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;
                    count++;
                    // If we've planted enough flowers, return true
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        // If not enough flowers were planted, return false
        return count >= n;
    }
};
```

## Complexity

- **Time:** O(n), where n is the number of spots in the flowerbed. We check each
  spot once.
- **Space:** O(1), we only use a few extra variables.
