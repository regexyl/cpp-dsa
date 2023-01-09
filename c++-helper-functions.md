# C++ Helper Functions

```cpp
// Included in LeetCode, no need for #include header
#include <limits> // std::numeric_limits<int>::max(), but INT_MAX can be used instead
#include <cstdlib> // abs()
#include <algorithm> // min()
```

- Insert an element at the ith position in a vector
- Sort a vector backwards: `std::sort(v.rbegin(), v.rend());`
- Sort a vector with a lambda function
```cpp
sort(mMyClassVector.begin(), mMyClassVector.end(), 
    [](const T& a, const T& b) -> bool { 
        return a.mProperty > b.mProperty; 
    });
```
- Declare a vector with fixed capacity: `vector<int> dp(size)`
- Declare a vector with fixed capacity with a set value: `vector<int> dp(size, 1e9);`
- Build a min-heap / max-heap
    - `priority_queue`: a max-heap by default
```cpp
priority_queue<int> pq;
pq.top();
pq.empty();
pq.size();
pq.push();
pq.pop();
pq.swap();

// An easy way to declare a min-heap
// ! use `std::greater<int>`
priority_queue<int, vector<int> greater<int>> pqMin;
```
- Convert int to string: `to_string(num)`
- Convert string to int: `stoi(str)`
- Convert a container to a string: `string s(v.begin(), v.end());`
- Convert a vector into a set: `set<string> s(v.begin(), v.end());`
- Convert a set into a vector: `vector<string> v(s.begin(), s.end())`
- Filter out elements with lambda function
```cpp
std::vector<int> foo = {25,15,5,-5,-15};
std::vector<int> bar;

// copy only positive numbers:
std::copy_if (foo.begin(), foo.end(), std::back_inserter(bar), [](int i){return i>=0;} );
```
- Map function
- Is uppercase: `int isupper(int ch);`
- Is lowercase: `int islower(int ch);`
- Transform a char to uppercase: `char toupper(int ch);`
- Transform a char to lowercase: `char tolower(int ch);`
- Transform a string to uppercase: `transform(input.begin(), input.end(), input.begin(), ::toupper);`
    - There are two different toupper functions - [ref](https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase):
        - `toupper` in the global namespace (accessed with `::toupper`), which comes from C. We want this.
        - `toupper` in the std namespace (accessed with `std::toupper`) which has multiple overloads and thus cannot be simply referenced with a name only. You have to explicitly cast it to a specific function signature in order to be referenced, but the code for getting a function pointer looks ugly: `static_cast<int (*)(int)>(&std::toupper)`
        - Since you're using namespace std, when writing toupper, 2. hides 1. and is thus chosen, according to name resolution rules.
- Transform a string to lowercase: `transform(input.begin(), input.end(), input.begin(), ::islower);`
    - I'm inferring from the above.

## C++ Specific
- Include all standard libraries: `#include <bits/stdc++.h>`
    - A downside is that this slows down the compile speed since a lot of unnecessary code is included.
- `stack`
    - Compared to `vector`, it is a LIFO-only container.
    - Its methods are also shortened in terms of string length:
        - `vector` -> `v.push_back()`, `stack` -> `s.push()`
        - `vector` -> `v.back()`, `stack` -> `s.top()`
        - `vector` -> `v.pop_back()`, `stack` -> `s.pop()`