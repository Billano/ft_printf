# FT_Prinftf

This project is a basic implementation of the C function printf. It represents a great exercise in programming because it enables the discovery of variadic functions in C and its a great example of a basic "dispatcher" via the use of and array of function's pointers. The key to a successful **ft_printf** is a well-structured and good extensible code.

This implementation manages the following:

> Flags: \- | + | ' '(space) | # | 0

> Specifiers: s | S | p | d | D | i | o | O | u | U | x | X | c | C | n

> Lengths: h | hh | l | ll | j | z

> Width: (number) | *

> Precision: . | .*

![alt text](extra/grade.png)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Clone this repository in your local machine and create your own **main.c** file.

### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`

## Running the Function

To test the library, first compile main.c with the library:

`gcc -o test main.c libftprintf.a`

## Built With

* C language
* Caffeine
* Lots of love

## Author

* **Eugenio Rodriguez**  [Billano](https://github.com/Billano)

## Acknowledgments

* 42 Silicon Valley
