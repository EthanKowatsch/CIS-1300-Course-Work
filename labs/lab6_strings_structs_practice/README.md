# Lab 6 — Strings, Structs, and Data Management

## Overview
This lab combined modular programming with C’s data structures. Students built a menu-driven student roster manager, learning to model real-world data using `struct`s and manipulate text using C strings.  

## Learned Concepts

- Define and use `struct` types to aggregate multiple data types.
- Declare, initialize, and safely manipulate null-terminated C strings.
- Use standard string manipulation functions from `<string.h>` (`strcpy`, `strcmp`, `strlen`).
- Create and manage an array of structs.
- Pass structs and arrays of structs to functions correctly.
- Perform aggregate data analysis on an array of structs (e.g., average grade, find max, update grade).

## Tasks Implemented

### Student Roster Manager (`main.c`, `roster.c`, `roster.h`)
- Defined a `struct student` with `first_name`, `last_name`, `student_id`, and `grade`.
- Created a menu-driven interface to manage the roster.
- Implemented `add_student` with safe string input using `fgets` and null-terminator handling.
- Implemented `print_roster` to display all students in a clean format.
- Implemented `search_by_lastname` to find a student using `strcmp`.
- Implemented `update_grade` to modify a student’s grade by ID.
- Implemented `find_highest_grade` to identify the student with the highest grade, returning a pointer to the struct.
- Implemented `grade_average` to calculate the average grade, safely handling the case of zero students.

## Files
- [roster.h](roster.h)
- [roster.c](roster.c)
- [main.c](main.c)

## How to Compile

Compile all files together:

```bash
gcc -Wall -std=c99 main.c roster.c -o roster
```
```
./roster
