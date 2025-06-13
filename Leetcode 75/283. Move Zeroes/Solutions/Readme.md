# Approach 1: Space Sub-Optimal

## Intuition

- The goal is to move all the zeros in the array to the end, while keeping the
  order of the other numbers the same.
- In this approach, we use extra space (a new array) to help us.
- First, we count how many zeros are in the original array.
- Then, we make a new array and put all the non-zero numbers into it, keeping
  their order.
- After that, we add the zeros to the end of the new array.
- Finally, we copy everything from the new array back to the original array.

This way, all the non-zero numbers stay in their original order, and all the
zeros end up at the back, but we use extra space.

## Algorithm

1. Count how many zeros are in the original array.
2. Make a new array and add all the non-zero numbers from the original array to
   it, in order.
3. Add the counted number of zeros to the end of the new array.
4. Copy all the elements from the new array back to the original array.
5. Now, the original array has all non-zero numbers at the front and all zeros
   at the end.

## Implementation

```cpp
class Solution {
public:
    // Function to move all zeroes to the end of the vector
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // Count the number of zeroes in the vector
        int numZeroes = 0;
        for (int i = 0; i < n; i++) {
            // Increment numZeroes if the current element is zero
            numZeroes += (nums[i] == 0);
        }

        // Create a new vector to store non-zero elements
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // Add non-zero elements to the new vector
            if (nums[i] != 0) {
                ans.push_back(nums[i]);
            }
        }

        // Append zeroes to the end of the new vector
        while (numZeroes--) {
            ans.push_back(0);
        }

        // Copy the elements from the new vector back to the original vector
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};
```

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the number of elements in the array.
  We go through the array a few times, but each time is $O(n)$.
- **Space Complexity:** $O(n)$, because we use a new array to store the result.

# Approach 2: Space Optimal, Operation Sub-Optimal

## Intuition

- The goal is to move all the zeros in the array to the end, but keep the order
  of the other numbers the same.
- We use two pointers (think of them as two fingers pointing at places in the
  array).
  - One pointer (`cur`) goes through every number in the array.
  - The other pointer (`lastNonZeroFoundAt`) keeps track of where the next
    non-zero number should go.
- As we look at each number:
  - If it’s not zero, we put it at the front (where `lastNonZeroFoundAt` is
    pointing), and move `lastNonZeroFoundAt` forward.
  - If it’s zero, we just skip it for now.
- After we’ve moved all the non-zero numbers to the front, we fill the rest of
  the array with zeros.

This way, all the non-zero numbers stay in their original order, and all the
zeros end up at the back.

## Algorithm

1. Start with a pointer `lastNonZeroFoundAt` at the beginning of the array
   (index 0).
2. Go through each number in the array from start to end:
   - If the number is not zero:
     - Put this number at the position `lastNonZeroFoundAt`.
     - Move `lastNonZeroFoundAt` one step forward.
3. After you finish the loop, all the non-zero numbers are at the front of the
   array.
4. Now, fill the rest of the array (from `lastNonZeroFoundAt` to the end) with
   zeros.
5. Done! All zeros are at the end, and the order of the other numbers is the
   same as before.

## Implementation

```cpp
// Define the Solution class
class Solution {
public:
    // Function to move all zeroes to the end of the vector
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0; // Tracks the position to place the next non-zero element

        // First pass: move all non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) { // If the current element is non-zero
                nums[lastNonZeroFoundAt++] = nums[i]; // Place it at the next available position
            }
        }

        // Second pass: fill the rest of the vector with zeroes
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0; // Set remaining elements to zero
        }
    }
};

```

## Complexity Analysis:

- Time Complexity: $O(n)$. However, the total number of operations are still
  sub-optimal. The total operations (array writest) that code does it `n` (total
  number of elements).
- Space Complexity: $O(1)$. Only constant space is used.

# Approach 3: Optimal

## Intuition

- The goal is to move all the zeros in the array to the end, while keeping the
  order of the other numbers the same.
- In this approach, we use two pointers:
  - One pointer (`cur`) goes through every number in the array.
  - The other pointer (`lastNonZeroFoundAt`) keeps track of where the next
    non-zero number should go.
- As we look at each number:
  - If it’s not zero, we swap it with the number at the `lastNonZeroFoundAt`
    position. This puts the non-zero number at the front and moves any zero
    behind it.
  - After swapping, we move `lastNonZeroFoundAt` forward.
- This way, every time we find a non-zero, it gets moved to the correct spot,
  and zeros are pushed to the end as a result of the swaps.
- This approach does everything in one pass and with the minimum number of
  operations.

## Algorithm

1. Start with two pointers: `lastNonZeroFoundAt` at the beginning (index 0) and
   `cur` also at the beginning.
2. Go through each number in the array with `cur`:
   - If the number at `cur` is not zero:
     - Swap it with the number at `lastNonZeroFoundAt`.
     - Move `lastNonZeroFoundAt` one step forward.
3. Continue until you reach the end of the array.
4. Now, all non-zero numbers are at the front in their original order, and all
   zeros are at the end.

## Implementation

```cpp
// Define the Solution class
class Solution {
public:
    // Function to move all zeroes in the vector to the end while maintaining the order of non-zero elements
    void moveZeroes(vector<int>& nums) {
        // Initialize two pointers:
        // lastNonZeroFoundAt: position to place the next non-zero element
        // cur: current index in the array
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            // If the current element is not zero
            if (nums[cur] != 0) {
                // Swap the current element with the element at lastNonZeroFoundAt
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};
```

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the number of elements in the array.
  We go through the array only once.
- **Space Complexity:** $O(1)$, because we do not use any extra space.
