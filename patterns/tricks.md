# Tricks

## Looping an array in a circular fashion

If you want to note the `i + 1` index and you're using a `for` loop, encountering the last index would give you `n` instead of the `0` you'd want (as you'd want to go back to the beginning of the array).

Just mod the `i + 1` with `n`:
```cpp
int idx = (i + 1) % n // if n = 5 and i = 4, (4 + 1) % 5 = 0
```