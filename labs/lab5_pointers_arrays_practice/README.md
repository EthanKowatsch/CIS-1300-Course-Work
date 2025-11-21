# Lab 5 — Pointers, Arrays, and Data Analysis

## Overview
This lab built on Lab 4’s modular programming concepts by introducing arrays and deepening understanding of pointers. Students wrote a statistics module to process collections of data, calculate metrics, and modify an array in-place.  

## Learned Concepts
- Declare, initialize, and populate C arrays.
- Pass arrays to functions for processing (passing by reference).
- Understand and demonstrate the relationship between arrays and pointers.
- Implement functions using both array notation (`arr[i]`) and pointer arithmetic (`*(arr + i)`).
- Write functions that modify an array "in-place" (e.g., reversing an array).

## Tasks Implemented

### Array Statistics Project (`stats.c`, `stats.h`, `main.c`)
- Declared a fixed-size array in `main.c` and populated it with user input.
- Implemented `calculate_sum` and `calculate_average` using array notation (`arr[i]`).
- Implemented `find_max` and `find_min` using pointer arithmetic (`*(arr + i)`).
- Implemented `reverse_array` to modify the array in-place by swapping elements.
- Printed all calculated statistics (sum, average, max, min) and the reversed array.

## Files
- [stats.h](stats.h)
- [stats.c](stats.c)
- [main.c](main.c)

## How to Compile

Compile all files together:

```bash
gcc -Wall -std=c99 main.c stats.c -o stats_analyzer
```
```
./stats_analyzer
