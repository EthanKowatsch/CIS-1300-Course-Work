# Assignment 3 — Spacecraft Mission Simulation

## Overview
This assignment focused on creating a modular C program to simulate a spacecraft mission. Key skills practiced included:

- Writing and calling user-defined functions
- Passing parameters by value and by pointer
- Implementing loops to simulate processes over time
- Structuring a program across multiple files using a header file (`.h`) and a source file (`.c`)

The program simulates a full mission, from launch to navigating asteroid hazards, with functions handling countdowns, launch sequences, solar cell charging, asteroid rendezvous, and survival in an asteroid field.

## Topics Learned
- Modular programming with functions
- Pointers and parameter passing
- `for` and `while` loops for process simulation
- Multi-file program structure with header files
- Conditional logic for mission-critical decisions
- Defensive programming with edge-case checks

## Files
- [Initial C Program](a3_initial.c)
- [Test Main File](test_main.c)
- [Final C Program](a3_final.c)

## How to Compile
Use the following command to compile the initial program:

```bash
gcc -Wall -std=c99 a3_initial.c test_main.c -o initial
```
```bash
./initial
```
```bash
gcc -Wall -std=c99 a3_final.c test_main.c -o final
```
```bash
./final
```
