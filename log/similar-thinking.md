---
description: >-
  Solved a question, then checked the answers and realized there's a faster way
  to type it all out - but they have a similar concept.
---

# Similar Thinking

## Arrays

### Number of laser beams in a bank

Find the number of beams in total, with the condition that beams can only pass through rows which do not have an existing beam inside.

![](<../.gitbook/assets/image (1).png>)

```
Input: bank = ["011001","000000","010100","001000"]
Output: 8
```

#### Original

Declares a vector to store the number of beams per row, with values of 0 filtered out.

```cpp
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int total {0}; // I *have* to declare this, or some weird insanely large (or small) digit would be assigned to total
        vector<int> beams_per_row; // per non-empty row

        for (int i = 0; i < bank.size(); ++i) {
            int count {0};
            for (auto c : bank[i]) {
                if (c == '1') ++count;
            }
            if (count != 0) beams_per_row.push_back(count);
        }

        for (int i = 1; i < beams_per_row.size(); ++i) {
            total += beams_per_row[i - 1] * beams_per_row[i];
        }

        return total;
    }
};
```

#### Improved

Uses `count()` and a single pointer `pre` to keep track of the last row with >= 1 laser beams.

```cpp
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, pre = 0;
        for (int i = 0; i < bank.size(); i ++) {
            int n = count(bank[i].begin(), bank[i].end(), '1');
            if (n == 0) continue;
            ans += pre * n;;
            pre = n;
        }
        return ans;
    }
};
```
