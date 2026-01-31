*This project has been created as part of the 42 curriculum by ichtioui*

# push_swap

## Description
**push_swap** is a simple yet highly structured algorithmic project: data must be sorted.
You have at your disposal a set of integer values, two stacks, and a set of instructions to manipulate both stacks

The goal is to write a program in C called `push_swap` that calculates and displays the shortest sequence of instructions needed to sort the integers received as arguments

This project involves:
* Sorting algorithms.
* Stack manipulation.
* Optimization to minimize operations.

## Instructions

### 1. Compilation
To compile the mandatory part:
```bash
make
```
To compile the bonus part:
```bash
make bonus
```

### 2. Execution

Running Push_swap: The program takes a list of integers as arguments and outputs the instructions to sort them.
```bash
./push_swap 2 1 3 6 5 8
```

Running the Checker (Bonus): The checker takes the same arguments as push_swap, waits for instructions on Standard Input, and checks if the stack is sorted.

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
* Displays OK if the stack is sorted.
* Displays KO if not.

## Resources

### References
* GeeksforGeeks: Stack Data Structure
* Wikipedia: Stack (abstract data type)
* Wikipedia: Analysis of algorithms

### AI usage

* Debugging: Used AI to help identify logic errors in the parsing functions and stack_parse logic.
* Concept Clarification: Used AI to help with the understanding of multiple part through out the project and the visualisation of the sorting algorithm