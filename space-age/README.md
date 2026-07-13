# Space Age
 
## Problem
 
Given an age in seconds, calculate how old a person would be on each planet
in the Solar System. Each planet has a different orbital period (expressed
in Earth years), so the same number of seconds corresponds to a different
number of "years" depending on the planet.
 
The base unit is one Earth year: `31,557,600` seconds (365.25 days). For any
other planet, the age is calculated as:
 
```
age_on_planet = seconds / (orbital_period_of_planet * 31557600)
```
 
where `orbital_period_of_planet` is the planet's orbital period relative to
Earth (e.g. `0.2408467` for Mercury, `11.862615` for Jupiter, ...).
 
## Approach
 
- Modeled the eight planets with an `enum planet_t`, so the planet is passed
  around as a typed value instead of a raw string or index.
- Used a single `age()` function with a `switch` on the enum to compute the
  result, one `case` per planet, instead of writing eight near-identical
  functions.
- Took `seconds` as `int64_t` rather than `int`, since a lifetime in seconds
  easily overflows a 32-bit integer.
- Read the planet name from user input, normalized it (first letter upper,
  rest lower) with `toupper`/`tolower`, then matched it to the enum with a
  chain of `strcmp` calls.
## Concepts practiced
 
- `enum` types and `switch` statements as a cleaner alternative to
  string comparisons or magic numbers.
- Fixed-width integer types (`int64_t`) for values that must not overflow.
- Array-to-pointer decay when passing a `char[]` buffer to `scanf`.
- Basic string normalization with `<ctype.h>` (`toupper`, `tolower`) and
  comparison with `<string.h>` (`strcmp`).
- Floating point division and precision when computing a ratio of large
  integers.
## Build & run
 
```bash
gcc -Wall -Wextra -std=c99 -o space_age space_age.c
./space_age
```
 
## Example
 
```
Enter a planet that is in our solar system: mercury
Enter the time that you spent living on the planet in seconds: 1000000000
Your age on Mercury is 130.71 years.
```
 
## Notes
 
- `-Wall -Wextra` catches a couple of format-string mismatches worth fixing:
  `scanf` should receive `planet` (already a pointer via array decay), not
  `&planet`, and reading an `int64_t` should use `SCNd64` from
  `<inttypes.h>` rather than `%lld`.
