# CIS*1300 Labs

This folder contains all six lab exercises for **CIS*1300: Introduction to Programming**. Each lab includes:

- **Source code (`.c` and `.h` files)** – cleaned and ready to compile  
- **Test files (`test_main.c`)** – simple programs demonstrating lab exercises  
- **README.md** – a brief overview, challenges faced, and key learnings  

---

## Labs List

- [Lab 1 – Intro to Programming](lab1_intro_to_programming)  
  *Basic program structure, printing output, and compiler usage*

- [Lab 2 – Basics of C](lab2_basics_of_c)  
  *Variables, data types, arithmetic, and simple functions*

- [Lab 3 – Loops & Branching](lab3_loops_branching)  
  *For/while loops, conditionals, and problem-solving logic*

- [Lab 4 – Modular Programming](lab4_modular_programming)  
  *Functions, headers, multiple source files, and modular design*

- [Lab 5 – Pointers & Arrays Practice](lab5_pointers_arrays_practice)  
  *Pointer arithmetic, arrays, and memory access practice*

- [Lab 6 – Strings & Structs Practice](lab6_strings_structs_practice)  
  *String manipulation, structs, and combined data structures*

---

## How to Compile

Each lab includes a `test_main.c` file demonstrating the lab exercises. For example, in the lab folder:

```bash
gcc -Wall -std=c99 test_main.c <lab_file>.c -o test_lab
./test_lab
```
