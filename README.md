# MiniLibC

MiniLibC is a small x86-64 assembly library that reimplements a selection of common C standard-library string and memory functions.

The project is built as a shared library named `libasm.so`. It is intended for Linux environments and follows the System V AMD64 calling convention.

## Implemented functions

### String functions

- `strlen`
- `strchr`
- `strrchr`
- `strcmp`
- `strncmp`
- `strcasecmp`
- `strstr`
- `strpbrk`
- `strcspn`

### Memory functions

- `memset`
- `memcpy`
- `memmove`

## Requirements

- A Linux x86-64 environment
- `make`
- NASM
- GCC
- GNU `ld`
- `gcovr` (only required for coverage reports)

On Windows, use WSL or another Linux-compatible environment.

## Build the library

From the project root, run:

```sh
make
```

This assembles the `.asm` files into object files and links them into:

```text
libasm.so
```

## Run the tests

Build the library and compile the test program with:

```sh
make test_run
```

The test executable is created at `tests/test_main` and runs immediately after compilation.

If the dynamic linker cannot find the shared library, set the library path manually:

```sh
LD_LIBRARY_PATH=. ./tests/test_main
```

You can also run the test target through its alias:

```sh
make tests_run
```

## Generate a coverage report

Install `gcovr` if needed, then run:

```sh
make coverage
```

## Clean build files

Remove object files and other generated files:

```sh
make clean
```

Remove the shared library and all generated test or coverage files:

```sh
make fclean
```

Clean everything and rebuild the library:

```sh
make re
```

For example:

```c
#include <stddef.h>

extern size_t strlen(const char *str);

int main(void)
{
    return strlen("Hello") == 5 ? 0 : 1;
}
```

The assembly implementations use the same function names and signatures as their standard C counterparts.
