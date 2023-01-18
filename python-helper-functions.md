# Python Helper Functions

### String

* Get all lowercase letters: `string.ascii_lowercase`
  * Not a function
  * Returns ''abcdefghijklmnopqrstuvwxyz"
* Count number of substrings in a string: `string.count(substr)`

### Dictionary

* Sort a dictionary:
```py
def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    count = Counter(nums)
    sortedCount = sorted(count.items(), key=lambda x : x[1], reverse=True)
    return list(map(lambda x : x[0], sortedCount))[:k]
``` 

### List

To instantiate a list: `list(range(n))` (gives `[0, 1, 2, 3...]`)

### Queue

FIFO operations.

```py
from queue import Queue

q = Queue()

# Add elements
namequeue.put("Alice")
namequeue.put("Bob")
namequeue.put("Charlie")
 
# Remove elements
a = namequeue.get()
b = namequeue.get()
c = namequeue.get()

# Other operations
size = q.qsize()
isEmpty = q.empty()
```

### Heap

Get n largest elements from a list: `heapq.nlargest(n, iterable, key=None)`
- Other examples of key can be `str.lower`
- key, if provided, specifies a function of one argument that is used to extract a comparison key from each element in iterable
- Equivalent to: sorted(iterable, key=key, reverse=True)[:n]
```py
def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    freq_count = Counter(nums)
    return heapq.nlargest(k, freq_count.keys(), key=freq_count.get)
```

### Class

* Check if a value is an instance of a class or type, or a tuple of type or classes: `isinstance(object, classinfo)`

### Difference between `.items()` and `.iteritems()`