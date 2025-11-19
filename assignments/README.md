# CIS*1300 Assignments

This folder contains all five course assignments for **CIS*1300: Introduction to Programming**. Each assignment includes:

- **Source code (`.c` and `.h` files)** – cleaned and ready to compile  
- **Test files (`test_main.c`)** – simple programs demonstrating how to use the functions  
- **README.md** – a brief overview of the assignment, challenges faced, and key learnings  

---

## Assignments List

- [Assignment 1 – Hello World](a1_hello_world)  
  *Introduction to programming, printing output, basic C syntax*

- [Assignment 2 – AI Assistant](a2_ai_assistant)  
  *Practice with conditionals, loops, and user input*

- [Assignment 3 – Spacecraft Simulation](a3_spacecraft_simulation)  
  *Modular programming, functions, pointers, and simulation logic*

- [Assignment 4 – DNA Analysis](a4_dna_analysis)  
  *String manipulation, arrays, GC content calculations, motifs, and palindrome/anagram checks*

- [Assignment 5 – Animal DNA Database](a5_animal_dna_db)  
  *Dynamic memory, structs, file I/O, database operations (add/delete records, analytics)*

---

## How to Compile

Each assignment includes a `test_main.c` file demonstrating how to use the functions. For example, in the assignment folder:

```bash
gcc -Wall -std=c99 test_main.c <assignment_file>.c -o test_assignment
./test_assignment
```
