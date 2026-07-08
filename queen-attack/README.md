# Queen Attack
 
Given the position of two queens on a chess board, determine whether or not they are positioned so that they can attack each other.
 
In chess, a queen can attack pieces which:
- share the same row
- share the same column
- share the same diagonal
## Chessboard Notation
 
A chessboard can be represented by an 8 by 8 grid, with columns denoted by
the letters A through H, and rows denoted by the numbers 1 through 8. In
this exercise the positions are represented as `row` and `column` values
in the range `0`–`7` instead of letters/numbers, but the logic is the same.
 
## Requirements
 
- `can_attack` returns `INVALID_POSITION` if either queen is placed
  outside the board (`row` or `column` greater than 7), or if both
  queens occupy the same square.
- `can_attack` returns `CAN_ATTACK` if the queens share the same row,
  the same column, or the same diagonal.
- `can_attack` returns `CAN_NOT_ATTACK` otherwise.
## Implementation Notes
 
- `queen1.row`, `queen1.column`, `queen2.row`, `queen2.column` are all
  `uint8_t`, so there is no need to check for negative values — an
  unsigned value can never go below 0. Only the upper bound (`<= 7`)
  needs checking.
- Same-diagonal detection works by comparing the absolute difference
  between the rows with the absolute difference between the columns:
  if `abs(row1 - row2) == abs(col1 - col2)`, the two positions lie on
  the same diagonal. Since `uint8_t` operands are automatically
  promoted to `int` in arithmetic expressions, the subtraction here
  correctly produces a signed (possibly negative) result before `abs()`
  is applied, so no explicit cast is required in this specific case.
- The "same square" case is checked first and separately, since two
  queens on the same square would otherwise be misreported as sharing
  a row/column/diagonal instead of being an invalid position.
## Example
 
```
Select a row (0-7) and a column (0-7) for the white queen leaving a space between the two values: 2 3
Select a row (0-7) and a column (0-7) for the black queen leaving a space between the two values: 5 6
The status of the two queens is: 1
Rember: 0 cannot attack, 1 can attack, 2 invalid position.
```
 
## Files
 
- `queen_attack.h` — type definitions (`attack_status_t`, `position_t`) and function prototype
- `queen_attack.c` — implementation of `can_attack`, plus a small interactive `main` for manual testing
## Build & Run
 
```bash
gcc -Wall -Wextra -std=c99 queen_attack.c -o queen_attack
./queen_attack
```
 
## Status
 
✅ Implemented and passing.
