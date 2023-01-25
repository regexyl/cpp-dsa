---
description: Identify the type of DP question you see.
---

# DP

### Methodology for Solving DPs

#### 1. Identify the category

1. [0/1 Knapsack](dp.md#1.-0-1-knapsack)
2. [Unbounded Knapsack](dp.md#unbounded-knapsack)
3. Shortest Path (eg: Unique Paths I/II) - or is it Palindromic Sequence as seen on educative.io?
4. Fibonacci Sequence (eg: House Thief, Jump Game)
5. Longest Common Substring/Subsequeunce

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

#### 5. \[After coding] Optimize

### Patterns

#### 1. 0/1 Knapsack

Given an array of items which each have a _weight (w)_ and _value (v)_ assigned, and a _capacity (c)_ that specifies the total value of items you can put within a knapsack, find the **maximum value** you can store within it.



<figure><img src="../.gitbook/assets/01-knapsack.png" alt=""><figcaption></figcaption></figure>

#### Unbounded Knapsack

### Problems

#### Decode Ways

{% hint style="info" %}
recursion
{% endhint %}

Using a recursive function (let's call it _**r**_), imagine trying to maximize the number of times _**r**_ is called as long as it's valid. This enables all pathways of these calls to hit the base case of `return 1`, so they eventually all add up to the total number of ways this number pattern can be decoded.

(Imagine scattering out all your Pokeballs in the hopes of each Pokeball thrown out captures 1 Pokemon each.)&#x20;

<figure><img src="../.gitbook/assets/decode-ways-dp.png" alt=""><figcaption></figcaption></figure>

### References

* [educative.io - Grokking Dynamic Programming Patterns for Coding Interviews](https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews)
* [LeetCode Forum - Target Sum Discussion Post](https://leetcode.com/problems/target-sum/solutions/455024/dp-is-easy-5-steps-to-think-through-dp-questions/)
