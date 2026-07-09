# Darts
 
An implementation of the classic **Exercism C track** "Darts" exercise: given the `(x, y)` landing coordinates of a dart, calculate the score based on which ring of the target it landed in.
 
## Problem
 
Three concentric circles are drawn on a dartboard, centered at the origin `(0, 0)`:
 
| Ring          | Radius | Points |
|---------------|--------|--------|
| Inner circle  | ≤ 1    | 10     |
| Middle circle | ≤ 5    | 5      |
| Outer circle  | ≤ 10   | 1      |
| Miss          | > 10   | 0      |
 
A dart landing exactly on the boundary of a circle counts as being *within* that circle (the checks use `<=`).
 
## Approach
 
The distance from the center is computed once with the standard Euclidean distance formula:
 
```c
float distance = sqrt(landing.x * landing.x + landing.y * landing.y);
```
 
and then compared against the three radius thresholds via nested `if` statements, from the largest ring inward, returning the corresponding value from the `points_t` enum (`OUT`, `OUTER`, `MIDDLE`, `INNER`).
 
## Files
 
- `darts.c` — single-file implementation: `coordinate_t` struct, `points_t` enum, `score()`, and an interactive `main()`
## Build & Run
 
The project links against `libm` for `sqrt()`:
 
```bash
gcc darts.c -o darts -lm
```
 
> **Note:** on Linux, math functions from `<math.h>` live in a separate library (`libm`), not in the standard C library — the `-lm` flag must be passed explicitly at link time, after the source files.
 
## Example (manual mode)
 
The `main()` included here lets you try it interactively:
 
```
Points: OUT - 0, OUTER CIRCLE - 1, MIDDLE CIRCLE - 5, INNER CIRCLE - 10
Enter the x - y coordinates of the position of the dart: 0.7 0.7
You scored: 10 points
```
 
## Notes / lessons learned
 
- `sqrt()` was originally called redundantly up to three times per invocation for the same value; it's now computed once and reused.
- Float literals use the `F` suffix (`10.0F`) to avoid implicit `double → float` narrowing conversions.
- Math functions from `<math.h>` require explicit linking against `libm` (`-lm`) on Linux — omitting it causes `undefined reference to 'sqrt'` at link time, even though compilation succeeds.
 
