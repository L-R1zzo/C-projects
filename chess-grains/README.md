# 🌾 Grains
 
A C program that solves the classic "wheat and chessboard" riddle: calculating how many grains of wheat end up on each square of a chessboard, where every square holds double the grains of the previous one.
 
## 🧠 Concept
 
The rule: square 1 holds 1 grain, and each following square doubles the previous one.
 
| Square | Grains | As a power of 2 |
|---|---|---|
| 1 | 1 | 2⁰ |
| 2 | 2 | 2¹ |
| 3 | 4 | 2² |
| 4 | 8 | 2³ |
| ... | ... | ... |
| 64 | 18,446,744,073,709,551,616 / 2 | 2⁶³ |
 
The number of grains on square `n` is `2^(n-1)`. The total across the whole board is the sum of grains on all 64 squares.
 
## ⚙️ Implementation notes
 
**Bit shifting instead of `pow()`**: `2^(n-1)` is calculated using the left shift operator (`1ULL << (n - 1)`) instead of `pow(2, n-1)`. `pow()` operates on `double`, which loses precision for numbers this large (up to 2⁶³) — shifting works directly on bits and is always exact.
 
**`uint64_t` instead of `unsigned long`**: the total number of grains on the last square alone is close to the limit of a 64-bit unsigned integer. `unsigned long` isn't guaranteed to be 64 bits on every platform, while `uint64_t` (from `<stdint.h>`) always is — this keeps the result portable and correct everywhere.
 
**`uint8_t` for the square index**: square numbers only ever range from 1 to 64, so an 8-bit unsigned type is enough and makes the intent clear.
 
## 🛠️ Functions
 
```c
uint64_t square(uint8_t index);   // grains on a single square (1-64)
uint64_t total(void);              // grains on the entire chessboard
```
 
`square` returns `0` for any index outside the valid 1–64 range.
 
## ▶️ Compile & Run
 
```bash
gcc -Wall -Wextra -std=c99 grains.c -o grains
```
 
## 💡 Key takeaway
 
This exercise highlighted why `pow()` isn't safe for large integer exponents, and why fixed-width types (`uint64_t`, `uint8_t`) are preferable to `int`/`unsigned long` when the exact size of a number matters — both for correctness and portability across platforms.
