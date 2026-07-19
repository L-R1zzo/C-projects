# 🧩 C Projects
 
This repository collects the C exercises and small projects I'm working through to build solid foundations in **C, pointers, and memory management** — the core of what's needed to walk into **Fondamenti di Informatica I** already comfortable with the language, instead of learning it from zero during the semester.
 
## 🎯 Why C
 
C sits directly on top of how a computer actually works: manual memory management, pointers, the stack, the heap, compilation into machine code. Getting these fundamentals right now — before the exam clock is ticking — means less time debugging segfaults in December and more time on the actual coursework (data structures, algorithms, complexity).
 
## 🗺️ Learning path context
 
This repo is part of my prep for the first-semester exams of my first year (Computer Engineering), specifically for building solid **computer science fundamentals** — pointers, memory, and data structures — ahead of Fondamenti di Informatica I.
 
🎯 Target: strong grades at the January/February exam session.
 
> Offensive security / low-level exploitation stays a long-term interest, but the near-term goal is nailing the first-semester exams first — C fundamentals learned properly now double as prep for both.
 
## 🛠️ Environment
 
- **OS**: Fedora Linux (KDE Plasma)
- **Compiler**: GCC
- **Standard flags**: `gcc -Wall -Wextra -std=c99`
## 📂 Structure
 
Solutions are organized by track and exercise, synced automatically from Exercism via GitHub pull requests:
 
```
├── solutions
├── README.md
└── .gitignore
```
 
Each exercise folder contains:
- The exercise source file
- A README explaining the concept practiced, the approach taken, and complexity notes
- Exercism's test suite for that exercise
> Individual exercises aren't listed here on purpose — check the folder solutions directly. This keeps this README stable and avoids updating it on every push.
 
## 📖 Topics covered so far
 
- Pointers, addresses, and array decay
- Stack vs heap, stack frames, and why returning local buffers is dangerous
- Functions that return strings via caller-provided buffers
**Next targets**: dynamic memory (`malloc`/`free`/`realloc`), recursion, file I/O, linked lists.
 
## 🚀 Goal
 
Build solid, no-gaps C fundamentals — not just syntax, but *why* the language behaves the way it does at the memory level — so that Fondamenti di Informatica I is a confirmation of what I already know, not a first encounter.
