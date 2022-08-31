<h1 align="center">
	FT_PRINTF 42
</h1>

<h3 align="center">
	<a href="#Summary">Summary</a>
	<span> · </span>
	<a href="#Usage">Usage</a>
	<span> · </span>
	<a href="#Tester">Tester</a>
	<span> · </span>
	<a href="#Tools">Tools</a>
</h3>

## Summary

> *The goal of this project is pretty straightforward. You will recode printf().
> You will mainly learn about using a variable number of arguments.*
> [Subject](https://cdn.intra.42.fr/pdf/pdf/58827/en.subject.pdf)

The code is written in accordance with 42 C coding style,  **ANSI C89 compliant** and **entirely documented with docstrings**.

## Usage

Compile the library with a simple `make -j` then add `#include "ft_printf.h"` to
your project and compile it with these additional flags:

    -I <path_to_libftprintf_include_dir>
    -L <path_to_libftprintf_dir>
    -l ftprintf

***Makefile rules***

- `make` -- compiles get_next_line.
- `make clean` -- deletes object files.
- `make fclean` -- deletes object files and get_next_line.
- `make re` -- fclean + make.

## Tester

- **[Printfest](test/printfest.c)** will try various, flags, value as well as
  undefined behavior cases to make sure that the program does not crash.

Usage: `cd test && make run`

## Tools

- **sanitizer**: `-fsanitize=address`

*Add `-g` flag when compiling with `-fsanitize=address` to print errors line numbers instead of addresses in hexadecimal.*
