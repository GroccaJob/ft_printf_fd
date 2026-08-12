*This project has been created as part of the 42 curriculum by grocca.*

# ft_printf

## Description

`ft_printf` is a 42 School project that consists of recoding the standard C library function `printf()` from scratch. The goal is to understand how **variadic functions** (functions that take a variable number of arguments) work in C, using `stdarg.h` and its macros `va_start`, `va_arg`, `va_copy`, and `va_end`.

Unlike the original `printf()`, which always writes to standard output, this implementation adds an extra parameter that lets the caller choose which file descriptor to write to:

```c
int	ft_printf(int fd, const char *format, ...);
```

The final result is a static library, `libftprintf.a`, containing a custom `ft_printf()` function that mimics the behavior of the original `printf()`, writing to the given `fd`, for the following conversions:

| Specifier | Description                            |
|-----------|-----------------------------------------|
| `%c`      | Single character                        |
| `%s`      | String                                  |
| `%p`      | Pointer address (hexadecimal, `0x...`)  |
| `%d`      | Signed decimal integer                  |
| `%i`      | Signed decimal integer                  |
| `%u`      | Unsigned decimal integer                |
| `%x`      | Unsigned hexadecimal (lowercase)        |
| `%X`      | Unsigned hexadecimal (uppercase)        |
| `%%`      | A literal `%` character                 |

This implementation covers the **mandatory part only**. Bonus flags (`-`, `0`, `.` precision, field width, `#`, space, `+`) are not implemented.

## Instructions

 #include "ft_printf.h"

### Compilation

The project compiles into a static library using the provided `Makefile`:

```bash
make
```

This produces `libftprintf.a` at the root of the repository, built with `ar` and compiled using `-Wall -Wextra -Werror`.

### Available rules

| Rule           | Description                                              |
|----------------|------------------------------------------------------------|
| `make` / `make all` | Compiles all sources and creates `libftprintf.a`      |
| `make clean`   | Removes object files (`.o`)                                |
| `make fclean`  | Removes object files and the library                       |
| `make re`      | Recompiles everything from scratch (`fclean` + `all`)      |

### Usage

Include the header in your project:

```c
#include "ft_printf.h"
```

Compile and link against the library:

```bash
cc your_file.c -L. -lftprintf -o your_program
```

Example:

```c
#include "ft_printf.h"
#include <unistd.h>

int main(void)
{
	int	ret;

	ret = ft_printf(STDOUT_FILENO, "Hello, %s! You are %d years old.\n", "42", 21);
	ft_printf(STDOUT_FILENO, "Return value: %d\n", ret);
	ft_printf(STDOUT_FILENO, "Pointer: %p | Hex: %x | Upper hex: %X\n", &ret, 255, 255);

	/* the fd can be any valid file descriptor, e.g. a file or STDERR */
	ft_printf(STDERR_FILENO, "This goes to standard error\n");
	return (0);
}
```

## Algorithm and data structure

`ft_printf` does not use any complex data structure. The format string is parsed **character by character** in a single pass, with no pre-parsing or intermediate buffer, in accordance with the project's requirement not to reimplement `printf`'s internal buffering.

The core logic works as follows:

1. `ft_printf()` initializes a `va_list` with `va_start` and iterates over the format string.
2. Every character that is not `%` is written directly to the file descriptor `fd` passed by the caller.
3. When a `%` is encountered, control is passed to a dispatcher function (`function()`), which looks at the character immediately following `%` and calls the corresponding conversion function (`ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd`, `ft_putunsign_fd`, `ft_putpoint_fd`, or the hexadecimal helper `ft_hexstr`), each of which writes to `fd` as well.
4. Each conversion function returns the number of characters it printed (or `-1` on error), which is accumulated into a running total returned by `ft_printf` — matching the return value convention of the original `printf`.

This dispatcher pattern (one `if`/`else if` chain routing to small, single-purpose functions) was chosen because:
- it keeps each conversion isolated and easy to test/debug independently,
- it maps directly and predictably onto `va_arg`'s requirement to know the exact type of each variadic argument at each step,
- it is easy to extend, since adding a new conversion just means adding another branch and a new helper function.

Number-to-string conversions (`ft_putnbr_fd`, `ft_putunsign_fd`, `ft_hexstr`) use a fixed-size stack-allocated `char` buffer sized to the maximum possible digit count for their base and type (e.g. 12 bytes for a signed `int` in base 10, including the sign and null terminator), rather than dynamic allocation, since the maximum length is known at compile time and this avoids unnecessary `malloc`/`free` calls.

Special cases like `INT_MIN` (which cannot be negated within `int` range) and `NULL` arguments for `%s` (`(null)`) and `%p` (`(nil)`) are handled explicitly to match the original `printf`'s behavior and avoid undefined behavior.

## Resources

- [`man printf`](https://man7.org/linux/man-pages/man3/printf.3.html) — reference for the original function's behavior and conversion specifiers.
- [`man stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) — documentation on variadic function macros (`va_start`, `va_arg`, `va_copy`, `va_end`).
- 42 School's `ft_printf` subject PDF.
- [Tripouille/printfTester](https://github.com/Tripouille/printfTester) — community-made tester used to compare this implementation's output and return values against the original `printf`.

### AI usage

An AI assistant (Claude) was used strictly as a **discussion and debugging aid**, not to write the project's logic. Specifically, it was used to:
- Talk through and clarify how variadic functions work in C (i.e. functions taking a variable number of parameters) — how `va_list`, `va_start`, `va_arg`, and `va_end` behave, and why `va_arg` requires a `va_list` value rather than a pointer to one.
- Debug a Makefile syntax error (using `/` instead of `\` for line continuation) that was preventing compilation.
- Get guidance on setting up and running the `Tripouille/printfTester` testing tool.

All the conversion logic, the parsing loop, and the number-to-string algorithms in this project were designed and written independently.
