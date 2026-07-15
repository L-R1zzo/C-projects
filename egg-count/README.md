# Egg Count

**Exercism — C Track**

## Problem

Count the number of eggs laid in a nest, where a nest is represented by an integer in binary form. Each `1` bit represents an egg. The function returns the total count of eggs (i.e., a population count / popcount).

## Solution

```c
int egg_count(int decimal){
    int count = 0;
    while (decimal > 0){
        count += decimal & 1;
        decimal >>= 1;
    }
    return count;
}
```

**How it works:**
- `decimal & 1` masks and isolates the least significant bit.
- `count += ...` adds it to the running total (0 or 1).
- `decimal >>= 1` right-shifts, discarding the bit just checked.
- The loop runs until all set bits have been consumed.

**Complexity:** O(log n) time (bounded by the number of bits in the input), O(1) space.

## Why it matters

A minimal popcount implementation — a building block that shows up constantly in bitmask handling, flag parsing, and other bit-level manipulation relevant to low-level/offensive-security work.

## Build & Test

```bash
gcc -Wall -Wextra -std=c99 -o egg_count egg_count.c test_egg_count.c
./egg_count
```

## Part of

[`c-projects`](../../) — ongoing collection of C exercises from Exercism, focused on pointers, memory management, and low-level fundamentals.
