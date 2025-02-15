Given an array `nums` of integers, return how many of them contain an **even number** of digits.

## Example 1:
**Input**: nums = [12,345,2,6,7896]  
**Output**: 2  
**Explanation**:  
- 12 contains 2 digits (even number of digits).  
- 345 contains 3 digits (odd number of digits).  
- 2 contains 1 digit (odd number of digits).  
- 6 contains 1 digit (odd number of digits).  
- 7896 contains 4 digits (even number of digits).  
Therefore, only 12 and 7896 contain an even number of digits.

## Example 2:
**Input**: nums = [555,901,482,1771]  
**Output**: 1  
**Explanation**:  
Only 1771 contains an even number of digits.

## Constraints:
- `1 <= nums.length <= 500`
- `1 <= nums[i] <= 10^5`

## Solution
This problem is about counting the numbers in an array that have an even number of digits. For example, 2 has an odd number of digits, 25 has an even number of digits, 200 has an odd number of digits, and 3000 has an even number of digits.

### Approach:
The number of digits in a number increases every time it is multiplied by 10. To count the digits, we can divide the number by 10 until it becomes a single digit.

### Steps:
1. Create a variable to store the result, named `count`.
2. Iterate through the array using a foreach loop.
3. For each number in the array, create a variable named `digits` to store the digit count, initialized to 0.
4. Use a while loop to count the digits by dividing the number by 10 until it is greater than 0, incrementing the `digits` variable each time.
5. If the digit count is even (`digits % 2 == 0`), increment the `count` variable by 1.
6. After the foreach loop completes, return the `count`.
