---
description: >-
  Basically attempting Leetcode questions with a singular way of solving them,
  then realizing afterwards that there's a better way to go about it.
---

# Alternative Thinking

## Strings

### Detect Capital (Easy)

We define the usage of capitals in a word to be right when one of the following cases holds:

* All letters in this word are capitals, like `"USA"`.
* All letters in this word are not capitals, like `"leetcode"`.
* Only the first letter in this word is capital, like `"Google"`.

Given a string `word`, return `true` if the usage of capitals in it is right.

#### Original

Convoluted, does not take advantage of counting number of uppercase and lowercase letters respectively.

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;

        bool allLower {false};
        bool ifFirstUpperRestUpper = {false};

        if (!isupper(word[0])) {
            allLower = true;
        } else if (isupper(word[1])) {
            ifFirstUpperRestUpper = true;
        }
        
        for (int i = 1; i < word.size(); ++i) {
            char c = word[i];

            if (allLower) {
                if (isupper(c)) return false;
            } else {
                if (ifFirstUpperRestUpper && !isupper(c)) return false;
                if (!ifFirstUpperRestUpper && isupper(c)) return false;
            }
        }

        return true;
    }
};
```

#### Improved

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstUpper {false};
        int totalUpper {0};

        if (word[0] >= 65 && word[0] <= 90) firstUpper = true;
        for (char c : word) {
            if (c >= 65 && c <= 90) ++totalUpper;
        }

        if (totalUpper == word.size()) {
            return true;
        } else if (totalUpper == 0) {
            return true;
        } else if (firstUpper && totalUpper == 1) {
            return true;
        } else {
            return false;
        }
    }
};
```

## Arrays

### [Shortest Word Distance II](https://leetcode.com/problems/shortest-word-distance-ii)

#### Original

```cpp
class WordDistance {
public:
    unordered_map<string, vector<int>> dict;

    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            dict[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int distance = std::numeric_limits<int>::max(); // infinity

        // Inefficient nested for loop
        for (int i : dict[word1]) {
            for (int j : dict[word2]) {
                distance = min(abs(i - j), distance);
            }
        }

        return distance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
```

#### Improved

```cpp
class WordDistance {
public:
    unordered_map<string, vector<int>> dict;

    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            dict[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int distance = INT_MAX;

        // Instead of constructing two for loops, only increment either
        // i or j if the corresponding position int is lower than the other
        for (int i = 0, j = 0; i < dict[word1].size() && j < dict[word2].size();) {
            int one = dict[word1][i];
            int two = dict[word2][j];

            distance = min(abs(one - two), distance);
            
            if (one < two) {
                ++i;
            } else {
                ++j;
            }
        }

        return distance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
```
