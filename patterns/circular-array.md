---
description: >-
  A very specific page dedicated to finding the min/max values of a wrap-around
  array.
---

# Circular Array

If an array is said to be wrapped around (i.e. circular) and that you need to find the maximum or minimum value of a contiguous subarray, think of the array as two separate cases:

1. Within normal range
2. Wrap around
   1. For this case, invert that thought process and find the opposite of the contiguous wrap-around subarray. What's left in the array is the part you're not finding - so take that and subtract it from the total of the array.

<figure><img src="../.gitbook/assets/circular-array.png" alt=""><figcaption></figcaption></figure>

**Questions**

* [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray) 🟠
