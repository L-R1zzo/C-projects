# 🧬 RNA Transcription in C

A lightweight, efficient C library for transcribing DNA strands into their RNA complements.

## Overview

In molecular biology, transcription is the process of copying a segment of DNA into RNA. This project provides a simple C function that takes a null-terminated DNA string and generates a new, dynamically allocated string containing the corresponding RNA sequence.

The four nucleotides found in DNA are transcribed to their RNA complements as follows:
* `G` ➔ `C`
* `C` ➔ `G`
* `T` ➔ `A`
* `A` ➔ `U`

## ✨ Features

- **Dynamic Memory Management:** Uses `malloc` to allocate precisely the required memory for the resulting RNA string plus the null terminator (`\0`).
- **Safety First:** Includes pointer validation to handle allocation failures gracefully by returning `NULL`.
- **Optimal Performance:** Achieves $O(n)$ time complexity using a clean `switch-case` structure for character mapping.

## 🚀 Getting Started

### Prerequisites
You need a standard C compiler such as `gcc` or `clang`.

### Compilation
To compile the project from your terminal, run:

```bash
gcc -Wall -Wextra -pedantic -std=c99 rna_transcription.c main.c -o rna_transcription
