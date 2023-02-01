---
description: Greatest Common Divisor
---

# GCD

An implementation of Euclid's algorithm for computing GCD:

```python
def gcd(num1, num2):
    # Ensure that num1 and num2 are positive, if not the GCD may turn out negative
    num1 = -num1 if num1 < 0 else num1
    num2 = -num2 if num2 < 0 else num2
    
    while num2 != 0:
        temp = num1 % num2
        num1 = num2
        num2 = temp
        
    return num1
```

A less efficient of the method above is:

```python
def gcd(num1, num2):
    # Ensure that num1 and num2 are positive
    # This method will NOT work (due to -=) if at least one of either nums is negative
    num1 = -num1 if num1 < 0 else num1
    num2 = -num2 if num2 < 0 else num2

    while num1 != num2:
        if num1 < num2:
            num1, num2 = num2, num1
        num1 -= num2

    return num1
```
