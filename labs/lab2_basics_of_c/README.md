# Lab 2 — C Variables, Operators, and Expressions

## Overview
This lab reinforced working with C variables, operators, and expressions. It provided practice with arithmetic, floating-point division, swapping variables, time conversion, and using the math library for calculations such as compound interest.  

## Learning Objectives
Upon completion of this lab, you should be able to:

- Follow the edit-compile-run cycle for multiple programs.
- Declare, initialize, and use variables of types `int`, `float`, and `double`.
- Correctly apply arithmetic operators, including division and modulo.
- Avoid pitfalls with integer division.
- Use the `pow()` function from `<math.h>` for calculations.
- Structure and compile complete C programs.

## Key Tasks Implemented

### Calculating an Average (`average.c`)
- Declared three integer scores.
- Calculated the total and the floating-point average.
- Printed total and average with precise formatting.

### Swapping Variable Values (`swap.c`)
- Declared two integer variables.
- Swapped their values using a temporary variable.
- Printed before and after swap.

### Time Conversion (`time_converter.c`)
- Converted total seconds (5000) into hours, minutes, and seconds.
- Printed in `H:M:S` format using division and modulo operators.

### Compound Interest Calculator (`interest.c`)
- Calculated compound interest using the formula `A = P(1 + r/n)^(nt)`.
- Used `pow()` from `<math.h>`.
- Printed the future value formatted to two decimal places.

## Files
- [average.c](average.c)
- [swap.c](swap.c)
- [time_converter.c](time_converter.c)
- [interest.c](interest.c)

## How to Compile

Compile and run `average.c`:

```bash
gcc -Wall -std=c99 average.c -o average
```
```bash
./average
```
Compile and run `swap.c`:
```bash
gcc -Wall -std=c99 swap.c -o swap
```
```bash
./swap
```
Compile and run `time_converter.c`:
```bash
gcc -Wall -std=c99 time_converter.c -o time_converter
```
```bash
./time_converter
```
Compile and run `interest.c` (requires linking the math library):
```bash
gcc -Wall -std=c99 interest.c -o interest -lm
```
```bash
./interest
```
