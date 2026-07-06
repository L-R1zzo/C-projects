# Collatz Conjecture
 
Exercise from [Exercism.io](https://exercism.org/tracks/c) — C track.
 
## The problem
 
Given a positive integer `n`, repeatedly apply this rule until you reach 1:
 
- if `n` is even → `n = n / 2`
- if `n` is odd → `n = 3n + 1`
The goal is to return the number of steps (transformations) needed to reach 1.
 
## Approach
 
Recursive solution:
 
```c
int steps(int start){
    if (start < 1){
        return -1;
    }
    if (start == 1){
        return 0;
    }
    if (start % 2 == 0){
        return 1 + steps(start/2);
    }
    return 1 + steps(3*start + 1);
}
```
 
- `start < 1` handles invalid input by returning `-1`.
- `start == 1` is the base case: 0 steps, you've already arrived.
- Each recursive call applies one transformation and adds 1 to the step count, which accumulates as the call stack unwinds.
## Build and test
 
```bash
gcc -Wall -Wextra -std=c99 collatz_conjecture.c -o test_collatz
```
 
All tests provided by Exercism pass.
 
## Possible improvements (to explore)
 
From a mentor review on Exercism, a few optimization ideas came up:
 
- **Tail-call recursion**: rewrite the function using a helper with an accumulator parameter, so the recursive call is the last instruction executed (no operation performed after it). This allows the compiler to apply *tail call optimization* (with `-O2` or higher), removing the stack overhead typical of recursion.
- **Optimized iterative version**: exploit the fact that an odd number in the Collatz sequence is always followed by an even number, reducing branching in the loop.
- **`__builtin_ctzll`**: for the part handling consecutive divisions by 2, use this GCC builtin (counts trailing zeros in binary) to compute in a single step how many divisions by 2 are needed, instead of a bit-by-bit loop.
These points are to be implemented and tested in a follow-up version of the exercise.
 
## Notes
 
Part of the C learning path in [C-projects](https://github.com/L-R1zzo/C-projects), preparatory to the path towards offensive security / exploit development.
