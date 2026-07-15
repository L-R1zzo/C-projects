# 🧩 C Projects
 
This repository collects the C exercises and small projects I'm working through as part of my learning path toward **low-level programming and offensive security**.
 
## 🎯 Why C
 
C sits directly on top of how a computer actually works: manual memory management, pointers, the stack, the heap, compilation into machine code. Understanding these fundamentals is what makes concepts like memory corruption, buffer overflows, and exploit development possible to grasp later on — rather than treating them as black boxes.
 
## 🗺️ Learning path context
 
This repo is one part of a broader offensive security roadmap:
 
1. **Python** → scripting & tooling foundations ✅
2. **C** → memory, pointers, low-level systems (this repo) 🔄
3. Networking protocols & CTF fundamentals
4. Security tools development
5. Web security (PortSwigger Academy)
6. Practical machines (HackTheBox)
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
## 🚀 Goal
 
Build a solid, exploit-development-oriented understanding of C — not just syntax, but *why* the language behaves the way it does at the memory level.
