---
description: Greedy involves a bit of math and proofing.
---

# Greedy

### [Gas Station](https://leetcode.com/problems/gas-station)
This works based on the proof that the starting index should be `i + 1`, where the array of contiguous elements below should be result in the lowest possible value:
```
gas[0] - cost[0] + gas[1] - cost[1] + ... + gas[i] - cost[i]
```

This makes the index `i + 1` the most optimal place to start the circular looping from.

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, start = 0;
        int minNett = INT_MAX;
        int n = gas.size();

        for (int i = 0; i < n; ++i) {
            total += gas[i] - cost[i];
            if (total < minNett) {
                minNett = total;
                start = i + 1;
            }
        }

        return total < 0 ? -1 : start % n;
    }
};
```
