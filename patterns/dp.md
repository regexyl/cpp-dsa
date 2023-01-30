# Dynamic Programming

### Todo

* [ ] [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick)
* [ ] [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings)
* [ ] Bottom-up for [Minimum Cost For Tickets](https://leetcode.com/problems/minimum-cost-for-tickets)

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

* [Equal Subset Sum Partition](https://leetcode.com/problems/partition-equal-subset-sum/)
* Subset Sum
* Minimum Subset Sum Difference
* Count of Subset Sum
* Target Sum

#### Unbounded Knapsack

Same as 0/1 knapsack, except that you can put any number of weights into the knapsack (i.e. not just restricted to one).

<figure><img src="../.gitbook/assets/unbounded-knapsack.png" alt=""><figcaption></figcaption></figure>

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

#### [Decode Ways](https://leetcode.com/problems/decode-ways/)

{% hint style="info" %}
recursion, 0/1 knapsack
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

#### [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

{% hint style="info" %}
"Longest Common Substring" pattern
{% endhint %}

Top-Down DP

```python
def longestCommonSubsequence(self, text1: str, text2: str) -> int:
    @cache
    def dp(i, j):
        if i == len(text1) or j == len(text2):
            return 0
        if text1[i] == text2[j]:
            return 1 + dp(i + 1, j + 1)
            
        return max(dp(i + 1, j), dp(i, j + 1))
    
    return dp(0, 0)
```

Bottom-Up DP

```python
def longestCommonSubsequence(self, text1: str, text2: str) -> int:
    # Bottom-up 2D dp
    n1, n2 = len(text1), len(text2)
    dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]

    for i in range(n1 - 1, -1, -1):
        for j in range(n2 - 1, -1, -1):
            if text1[i] == text2[j]:
                dp[i][j] += 1 + dp[i + 1][j + 1] # only take diagonal val
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) # take bottom and right vals

    return dp[0][0]
```

#### [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)

{% hint style="info" %}
0/1 Knapsack, Bitmask
{% endhint %}

This problem can be solved with the regular 0/1 knapsack top-down DP solution w/memoization:

```python
def canPartition(self, nums: List[int]) -> bool:
    n = len(nums)

    total = sum(nums)
    if total % 2 != 0: return False # decimal

    half = total // 2
    memo = [[None] * (half + 1) for _ in range(n)]

    def dp(i, val):
        if val == 0: return True
        if i == n or val < 0: return False

        if memo[i][val] != None: return memo[i][val]
        
        result = dp(i + 1, val) or dp(i + 1, val - nums[i])
        memo[i][val] = result
        return result
    
    return dp(0, half)
```

But there's a more efficient way of solving it via bitmask:

{% embed url="https://docs.google.com/document/d/15fgvC4-rNp2AVDM1b_6kfEDieF9v4a18dE9h_SoIHyg/edit?usp=sharing" %}

### References

* [educative.io - Grokking Dynamic Programming Patterns for Coding Interviews](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews)
* [LeetCode Forum - Target Sum Discussion Post](https://leetcode.com/problems/target-sum/solutions/455024/dp-is-easy-5-steps-to-think-through-dp-questions/)
