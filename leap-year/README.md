# 📅 Leap Year
 
A simple C program that determines whether a given year is a leap year, following the standard Gregorian calendar rules.
 
## 🧠 Concept
 
A year is a leap year if:
 
| Rule | Condition |
|---|---|
| Divisible by 4 | Base condition for a leap year |
| **Exception**: divisible by 100 | NOT a leap year, unless... |
| **Exception to the exception**: divisible by 400 | IS a leap year |
 
Examples:
- `2024` → leap year (divisible by 4, not by 100)
- `1900` → NOT a leap year (divisible by 100, not by 400)
- `2000` → leap year (divisible by 400)
## 🛠️ How it works
 
The program reads a year from standard input using `scanf`, then passes it to `leap_year()`, which evaluates the rules above and prints the result directly to stdout.
 
```c
void leap_year(int year);
```
 
The function takes the year as a parameter and prints whether it's a leap year, along with the reason (which rule determined the outcome).
 
## ▶️ Compile & Run
 
```bash
gcc -Wall -Wextra -std=c99 leap_year.c -o leap_year
./leap_year
```
 
## 📌 Example
 
```
Select a year: 1900
1900 was not a leap year as it's not divisible by 400.
```
 
## 💡 Notes
 
- Input validation (checking `scanf`'s return value) was intentionally kept simple for this exercise, but is something to consider for input coming from untrusted sources.
