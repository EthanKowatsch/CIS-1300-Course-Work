# Lab 1 — Introductory C Lab

## Overview
This lab introduced fundamental C programming concepts and the Linux workflow. It provided practice with compiling and running small programs, creating variables, performing arithmetic operations, and printing data types. This lab also prepared students for Assignment 1.

## Learned Concepts

- Connect to the SoCS Linux environment and use command-line tools.
- Organize coursework using a directory structure.
- Write, compile, and execute a basic "Hello, World!" C program.
- Declare and initialize primitive data types (`int`, `float`, `double`, `char`).
- Perform basic arithmetic operations and understand expressions.
- Print variables using `printf()` with appropriate format specifiers.
- Understand the significance of the `sizeof` operator for data types.

## Files
- [hello.c](hello.c)
- [variables.c](variables.c)

## How to Compile

Compile and run `hello.c`:

```bash
gcc -Wall -std=c99 hello.c -o hello
```
```bash
./hello
```
Compile and run variables.c:
```bash
gcc -Wall -std=c99 variables.c -o variables
```
```bash
./variables
```
