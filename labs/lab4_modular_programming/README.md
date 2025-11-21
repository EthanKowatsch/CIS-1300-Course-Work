# Lab 4 — User-Defined Functions and Modular Programming

## Overview
This lab focused on designing and implementing a modular, multi-file C program. Students learned how to separate code into `.h` and `.c` files, use pointers to pass data by reference, and orchestrate program flow through a menu-driven interface.  

## Learned Concepts
- Separate a program into multiple files (`.h` and `.c`) and compile them together.
- Design and write a set of cooperating functions to solve a larger problem.
- Use function prototypes to define a module's public interface.
- Pass data by reference using pointers to return multiple values from a function.
- Build a menu-driven application where `main()` orchestrates the program flow.

## Tasks Implemented

### Modular Calculator Project (`calculator.c`, `calculator.h`, `main.c`)
- Built a menu-driven calculator that supports addition, subtraction, multiplication, and division.
- Implemented a `print_menu` function to display options.
- Implemented `get_user_inputs` to read two numbers from the user using pointers.
- Created separate arithmetic functions (`add_numbers`, `subtract_numbers`, `multiply_numbers`, `divide_numbers`) that call `get_user_inputs` and perform the calculation.
- Checked for division by zero in the divide function.
- Orchestrated the program in `main.c` with a `do-while` loop and `switch` statement for menu choices.

## Files
- [calculator.h](calculator.h)
- [calculator.c](calculator.c)
- [main.c](main.c)

## How to Compile

Compile all files together:

```bash
gcc -Wall -std=c99 main.c calculator.c -o calculator
```
```
./calculator
