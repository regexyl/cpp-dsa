# Sorting

Different sorting methods in C++: https://leetcode.com/problems/sort-an-array/solutions/1401412/c-clean-code-solution-fastest-all-15-sorting-methods-detailed/

## Types of Sorting

1. [Selection sort](sorting.md#selection-sort) - take min. value to the right
2. [Quicksort](sorting.md#quicksort) - pivot sorting
3. [Patience sort](sorting.md#patience-sort) - pile of cards

### Selection Sort

**Time:** <mark style="background-color:orange;">O(n^2)</mark> - best, average, worst, **Space:** <mark style="background-color:green;">O(1)</mark>

When iterating through each element in the array at position `i`, look to the right of `i` till the end of the array to find the minimum (let's call this `j`), then swap both elements if `i` is greater than that `j`.

![](../.gitbook/assets/image.png)

```c
// a: array, n: size of array (as C is unable to determine its size)
void sort (int a[], int n) {
    int current, j, lowestindex, temp;
    for (current = 0; current < n-1; current++) {
        lowestindex = current;
        for (j = current+1; j < n; j++) {
            if (a[j] < a[lowestindex]) {
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

### Quicksort

**Time:** <mark style="background-color:green;">O(nlog(n))</mark> - best, average, <mark style="background-color:orange;">O(n^2)</mark> - worst, **Space:** <mark style="background-color:green;">O(log(n))</mark>

![](<../.gitbook/assets/image (1).png>)



```python
def partition(arr, start, end):
  pivot = arr[end]
  pivotIdx = start

  for i in range(start, end):
    if arr[i] <= pivot:
      arr[i], arr[pivotIdx] = arr[pivotIdx], arr[i]
      pivotIdx += 1

  # All elements <= pivot are arranged before pivotIdx
  arr[pivotIdx], arr[end] = arr[pivotIdx], arr[end]

  return pivotIdx

def quicksort(arr, start, end):
  if start >= end:
    return
  pivotIdx = partition(arr, start, end)

  # Pivot already at correct index, no need for inclusion
  quicksort(arr, start, pivotIdx - 1)
  quicksort(arr, pivotIdx + 1, end)
```

### Patience Sort

Refer to [Dynamic Programming](dp.md) > Longest Increasing Subsequence.
