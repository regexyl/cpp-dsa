---
description: Identify the type of DP question you see.
---

# DP

1. Pattern 1: 0/1 Knapsack
2. Unbounded Knapsack
3. Fibonacci Numbers
4. Palindromic Sequence
5. Longest Common Substring

### Patterns

#### 0/1 Knapsack

Recursion -> Memoized (Top-Down) / Bottom-Up

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
