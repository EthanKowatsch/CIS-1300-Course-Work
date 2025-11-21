# Lab 3 — Loops and Branching

## Overview
This lab focused on using loops and conditional statements in C to build interactive programs. Students practiced handling user input, performing repeated calculations, and making decisions using `if-else` and `switch` statements within loops.  

## Learning Objectives
Upon completion of this lab, you should be able to:

- Build interactive programs that loop based on user confirmation.
- Use `scanf()`, `fgets()`, `getchar()`, and `sscanf()` to parse different input types (strings, integers, floats, characters, doubles, and formatted dates).
- Implement complex decision-making using `switch` and `if-else` statements.
- Manage program state within a loop to perform calculations and make decisions using `while`, `do..while`, and `for` loops.

## Tasks Implemented

### Looping GPA Calculator (`gpa_calculator.c`)
- Repeatedly asked the user to enter a letter grade (A, B, C, D, F).
- Converted grades to numeric points using a `switch` statement (A=4.0, B=3.0, etc.).
- Used a `do-while` loop to process multiple grades until the user chooses to stop.
- Calculated and printed the GPA for all entered courses.
- Handled invalid grade entries gracefully.

### Simple Vending Machine (`vending_machine.c`)
- Displayed a menu of items with prices.
- Used a `switch` statement to determine item prices based on user selection.
- Collected coins (nickels, dimes, quarters) in a loop until the total met the item's cost.
- Calculated and dispensed change.
- Repeated the menu loop until the user chose to exit.

## Files
- [gpa_calculator.c](gpa_calculator.c)
- [vending_machine.c](vending_machine.c)

## How to Compile

Compile and run `gpa_calculator.c`:

```bash
gcc -Wall -std=c99 gpa_calculator.c -o gpa_calculator
```
```bash
./gpa_calculator
```
Compile and run vending_machine.c:
```bash
gcc -Wall -std=c99 vending_machine.c -o vending_machine
```
```
./vending_machine
```
