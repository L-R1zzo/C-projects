# Hamming Distance
 
C solution for the [Hamming Distance](https://exercism.org/tracks/c/exercises/hamming) exercise on Exercism.
 
## Problem
 
Given two DNA strands of equal length, calculate the Hamming distance between them — the number of positions at which the corresponding characters differ.
 
```
GAGCCTACTAACGGGAT
CATCGTAATGACGGCCT
^ ^ ^  ^ ^    ^^
```
 
If the two strands don't have the same length, the comparison is undefined — this implementation returns `-1` in that case.
 
## Approach
 
```c
int compute(const char *lhs, const char *rhs){
    if (strlen(lhs) != strlen(rhs)){
        return -1;
    }
 
    int differences = 0;
 
    while (*lhs != '\0'){
        if (*lhs != *rhs){
            differences++;
        }
        lhs++;
        rhs++;
    }
    return differences;
}
```
 
Both strands are walked in lockstep using pointer arithmetic rather than array indexing: `lhs` and `rhs` are advanced one byte at a time with `lhs++` / `rhs++`, and dereferenced with `*lhs` / `*rhs` to compare the current character. The loop stops as soon as it hits the null terminator on `lhs` — safe here because the length check above already guarantees both strands are the same length.
 
## Concepts practiced
 
- **Strings as pointers.** A C string isn't a distinct type — it's a `char` array in memory, terminated by `\0`. When passed to a function, the array decays to a pointer to its first byte: `char strand[]` and `char *strand` are equivalent in a function signature.
- **Passing by address, not by copy.** The function receives only the memory address of each strand (8 bytes on a 64-bit system), not a duplicate of the whole string — this is why C strings are passed as pointers instead of by value.
- **Pointer arithmetic vs. indexing.** `strand[i]` and `*(strand + i)` are the same operation. This version uses `*lhs` + `lhs++` (moving the pointer itself) instead of a fixed base address with an index — same result, different style.
- **`const` correctness.** Both parameters are `const char *` since the function only reads the strands, never modifies them.
- **`strlen`** from `<string.h>` for the equal-length precondition, relying on the null terminator rather than a stored length.
## Build & run
 
```bash
gcc -Wall -Wextra -std=c99 -o hamming hamming.c
./hamming
```
 
## Example
 
```
Write a DNA strand (example: GAGCCTACTAACGGGAT): GAGCCTACTAACGGGAT
Write a second DNA strand (example: GAGCCTACTAACGGGAT): CATCGTAATGACGGCCT
The hamming distance between the DNA strands is: 7
```
 
## Notes
 
- Input is read with `scanf("%s", ...)` into fixed 32-byte buffers — fine for this exercise, but no bounds checking is done against buffer overflow from oversized input.
- Unequal-length strands return `-1` rather than asserting or crashing, so the caller can handle the invalid case explicitly.
