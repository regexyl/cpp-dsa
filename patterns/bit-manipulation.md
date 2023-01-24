# Bit Manipulation

####

#### [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum)

Instead of using the 0/1 knapsack solution (by iterating through the array and selectively choosing the elements that make up half of the total sum of the array), we simply find out if the combination of bits within the half value exists within the combination of bits derived from iterating throughout `nums` and obtaining the `OR` value against the previous `possibleSums` value.

```python
def canPartition(self, nums: List[int]) -> bool:
    total = sum(nums)
    if total % 2 != 0: return False

    possibleSums = 1
    for n in nums:
        possibleSums |= possibleSums << n
    
    halfSum = total // 2
    return 1 << halfSum & possibleSums != 0
```

You need to somehow trust that the bit combination of `1 << halfSum` exists within the total bit combination within `possibleSums`.

```python
# base case
bits = 1
# 000000 0000000001 reading from right, 0 is reachable, space is just for readability

# step 1a, find newly reachable sums; this left shifts each turned on bit by n (effectively adding n to every previous sum)
possibleSums = bits << 1
# 000000 0000000010
# step 1b, takes the OR of previous sums and new sums, because at each step we can add n OR skip it
bits |= possibleSums
# 000000 0000000011 — reachable sums are now 0 and 1

# step 2
possibleSums = bits << 3
# 000000 0000011000
bits |= possibleSums
# 000000 0000011011 — reachable sums are 0, 1, 3, and 4

# step 3
possibleSums = bits << 7
# 000011 0110000000
bits |= possibleSums
# 000011 0110011011 — 0, 1, 3, 4, 7, 8, 10, and 11

# step 4
possibleSums = bits << 3
# 011011 0011011000
bits |= possibleSums
# 011011 0111011011 — 0, 1, 3, 4, 6–8, 10, 11, 13, and 14
```

