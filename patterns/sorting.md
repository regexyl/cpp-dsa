# Sorting

Different sorting methods in C++: https://leetcode.com/problems/sort-an-array/solutions/1401412/c-clean-code-solution-fastest-all-15-sorting-methods-detailed/

## Types of Sorting

1. Selection sort
2. Quicksort
3. Patience sort

### Selection Sort

```c
// a: array, n: size of array (as C is unable to determine its size)
void sort (int a[], int n) {
    int current, j, lowestindex, temp;
    for (current = 0; current < n-1; current++) {
        lowestindex = current;
        for (j = current+1; j < n; j++) {
            if (a[j] < a[current]) {
                lowestindex = j;
            }
        }
        if (lowestindex != current) {
            temp = a[current];
            a[current] = a[lowestindex];
            a[lowestindex] = temp;
        }
    }
}
```

### Patience Sort

Refer to [Dynamic Programming](dp.md) > Longest Increasing Subsequence.
