# Dynamic Programming

### Todo

* [ ] [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick)

### Methodology for Solving DPs

#### 1. Identify the category

1. [0/1 Knapsack](dp.md#1.-0-1-knapsack)
2. [Unbounded Knapsack](dp.md#unbounded-knapsack)
3. Shortest Path (eg: Unique Paths I/II) - or is it Palindromic Sequence as seen on educative.io?
4. [Fibonacci Numbers](dp.md#fibonacci-numbers) (eg: House Thief, Jump Game)
5. [Longest Common Substring](dp.md#longest-common-substring)

#### 2. States

The variables you need to keep track of in order to reach the optimal result.

{% hint style="info" %}
If recursion within a separate function is used, these state variables are the ones typically passed into the function as parameters.
{% endhint %}

* 0/1 Knapsack: In general, you'll require two states - _index_ (usually indicating your current position within the given array) and _current value_.
* Unbounded knapsack:
* Palindromic sequence:
* Fibonacci sequence:
* Longest common substring/sequence:

#### 3. Decisions

The step that brings you closer to the base case. In a 0/1 Knapsack problem, it is deciding whether or not to include the current item in the knapsack.

```python
def dp(i, val, items):
    # ...
    
    noIncl = dp(i + 1, val, items)
    incl = dp(i + 1, val + items[i], items)
    
    return max(incl, noIncl)
```

#### 4. Base case

The base case relates directly to the conditions required by the answer. Identify the valid and invalid base cases.

It can be, e.g.:

* Index being out of bounds
* Capacity limit reached

An example of a valid base case can be: index is out of bounds, but current value is still within the capacity limit.

An example of an invalid base case can be: current value is outside of the capacity limit.

#### 5. \[After coding] Optimize

If you've used a top-down recursive method, you could use an array for memoization:

```python
class Solution:
    def findTargetSumWays(self, nums, S):
        index = len(nums) - 1
        curr_sum = 0
        self.memo = {} # array to memoize
        return self.dp(nums, S, index, curr_sum)
        
    def dp(self, nums, target, index, curr_sum):
        if (index, curr_sum) in self.memo:
            return self.memo[(index, curr_sum)]
        
        if index < 0 and curr_sum == target:
            return 1
        if index < 0:
            return 0 
        
        positive = self.dp(nums, target, index-1, curr_sum + nums[index])
        negative = self.dp(nums, target, index-1, curr_sum + -nums[index])
        
        self.memo[(index, curr_sum)] = positive + negative
        return self.memo[(index, curr_sum)]
```

### Patterns

#### 1. 0/1 Knapsack

Given an array of items which each have a _weight (w)_ and _value (v)_ assigned, and a _capacity (c)_ that specifies the total value of items you can put within a knapsack, find the **maximum value** you can store within it.



<figure><img src="../.gitbook/assets/01-knapsack.png" alt=""><figcaption></figcaption></figure>

Examples

* Equal Subset Sum Partition
* Subset Sum
* Minimum Subset Sum Difference
* Count of Subset Sum
* Target Sum

#### Unbounded Knapsack

Examples

* Rod Cutting
* [Coin Change](https://leetcode.com/problems/coin-change/)
* [Coin Change II](https://leetcode.com/problems/coin-change-ii/)
* Minimum Coin Change
* Maximum Ribbon Cut
* [Minimum Cost for Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/)

#### Fibonacci Numbers

Examples

* Staircase
* Number factors
* Minimum jumps to reach the end
* Minimum jumps with fee
* House thief
* [Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum/) (also falls under the [Longest Common Substring](dp.md#longest-common-substring) category)

#### Palindromic Sequence

Examples

* Longest Palindromic Subsequence (also falls in the [Longest Common Substring](dp.md#longest-common-substring) category)
* Longest Palindromic Substring
* Count of Palindromic Substrings
* Minimum Deletions in a String to make it a Palindrome
* Palindromic Partitioning

#### Longest Common Substring

Examples

* Longest Common Substring
* Longest Common Subsequence
* Minimum Deletions and Insertions to Transform a String into Another
* Longest Increasing Subsequence
* Maximum Sum Increasing Subsequence
* Shortest Common Super-Sequence
* Minimum Deletions to Make a Sequence Sorted
* Longest Repeating Subsequence
* Subsequence Pattern Matching
* Longest Bitonic Subsequence
* Longest Alternating Subsequence
* [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)
* [Edit Distance](https://leetcode.com/problems/edit-distance/)
* Strings Interleaving

### Problems

#### Decode Ways

{% hint style="info" %}
recursion
{% endhint %}

Using a recursive function (let's call it _**r**_), imagine trying to maximize the number of times _**r**_ is called as long as it's valid. This enables all pathways of these calls to hit the base case of `return 1`, so they eventually all add up to the total number of ways this number pattern can be decoded.

(Imagine scattering out all your Pokeballs in the hopes of each Pokeball thrown out captures 1 Pokemon each.)&#x20;

<figure><img src="../.gitbook/assets/decode-ways-dp.png" alt=""><figcaption></figcaption></figure>

```python
from functools import lru_cache

class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)

        @lru_cache(None)
        def dp(i: int) -> int:
            if i == n: return 1
            
            num = 0
            if s[i] != "0":
                num += dp(i + 1)
            if i + 1 < n and 10 <= int(s[i:i + 2]) <= 26:
                num += dp(i + 2)

            return num

        return dp(0)
```

### References

* [educative.io - Grokking Dynamic Programming Patterns for Coding Interviews](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews)
* [LeetCode Forum - Target Sum Discussion Post](https://leetcode.com/problems/target-sum/solutions/455024/dp-is-easy-5-steps-to-think-through-dp-questions/)
