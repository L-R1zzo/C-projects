# Binary to Decimal Converter
 
An interactive C program that reads a binary string from user input and converts it to its decimal representation. Extends the Exercism "binary" exercise with a `main()` for standalone interactive use.
 
## Problem
 
Given a string containing only `0`s and `1`s, convert it to the decimal number it represents. Any character outside `{0, 1}` makes the input invalid.
 
## Approach
 
- Iterate over the input string once, tracking the positional weight `n` of each bit, starting from the most significant bit (`strlen(input) - 1`) down to `0`.
- For each `'1'`, add `2^n` to the result using a left bit-shift (`1 << n`) instead of `pow()`. This avoids pulling in `<math.h>` and sidesteps floating-point-to-int conversion for what's fundamentally an integer operation.
- Any character other than `'0'`/`'1'` triggers an immediate `return -1` (invalid input).
- `strlen(input)` is cached once in `k` before the loop instead of being recomputed on every iteration, which keeps the algorithm O(n) instead of O(n²).
## Build & Run
 
```bash
gcc -Wall -Wextra -std=c99 -o binary binary.c
./binary
```
 
Example session:
 
```
Enter a binary number: 1010
The number converted in decimal system is: 10
```
 
## Known Issues
 
- **Buffer overflow in `main()`**: `selected_number` is declared as `char selected_number[] = "";`, which allocates exactly 1 byte (just the null terminator). `scanf("%s", selected_number)` has no length bound, so any real input overflows the buffer and causes undefined behavior (classic stack buffer overflow). Needs a fixed-size buffer (e.g. `char selected_number[64];`) and a bounded format specifier (`scanf("%63s", selected_number)`) to be safe.
- No check that the input consists only of `'0'`/`'1'` before the array is written into by `scanf` — validation currently happens only after the string is already in memory.
## Concepts practiced
 
- Bitwise shift operators for integer powers of two
- `switch` statements for character-based branching
- Avoiding redundant `strlen()` calls in loop conditions
- `scanf`/buffer handling pitfalls (see Known Issues above)
