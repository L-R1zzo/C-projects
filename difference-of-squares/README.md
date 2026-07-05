# 🔢 Difference of Squares
 
A C program that calculates the difference between the **square of the sum** and the **sum of the squares** of the first N natural numbers.
 
## 🧠 Concept
 
Given the first N natural numbers, there are two different quantities to compute:
 
**Square of the sum** — sum all the numbers first, then square the result:
```
(1 + 2 + ... + N)²
```
 
**Sum of the squares** — square each number first, then sum the results:
```
1² + 2² + ... + N²
```
 
The **difference** is simply: `square of the sum - sum of the squares`.
 
### Example (N = 10)
 
| Quantity | Calculation | Result |
|---|---|---|
| Square of the sum | (1+2+...+10)² = 55² | 3025 |
| Sum of the squares | 1²+2²+...+10² | 385 |
| **Difference** | 3025 - 385 | **2640** |
 
## 🛠️ How it works
 
The program is split into three functions:
 
```c
unsigned int square_of_sum(unsigned int n);
unsigned int sum_of_squares(unsigned int n);
unsigned int difference_of_squares(unsigned int n);
```
 
- `square_of_sum` sums the numbers from 1 to `n`, then squares the total.
- `sum_of_squares` squares each number from 1 to `n` as it iterates, accumulating the total.
- `difference_of_squares` calls both functions and returns the difference between their results.
`unsigned int` is used throughout since the problem only deals with natural numbers (never negative).
 
## ▶️ Compile & Run
 
```bash
gcc -Wall -Wextra -std=c99 difference_of_squares.c -o difference_of_squares
./difference_of_squares
```
 
## 📌 Example
 
```
Choose a an integer that is greater or equal to zero: 10
 
The square of the sum of the natural numbers less or greater than 10 is: 3025
The sum of the squares of the natural numbers less or greater than 10 is: 385
The difference beetwen the square of sum and the sum of squares is: 2640
```
 
## 💡 Notes
 
- `scanf` requires the **address** of the variable (`&number`), not its value — passing the value instead causes undefined behavior (in this case, a segmentation fault), since `scanf` needs a valid memory address to write the input into.
- All variables involved in comparisons/arithmetic are kept as `unsigned int` to avoid signed/unsigned mismatch warnings and unexpected conversions.
