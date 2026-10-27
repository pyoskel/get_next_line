_This project has been created as part of the 42 curriculum by **pabartoc** (42 Heilbronn)._

# 📜 get_next_line - 42 Project

## 📖 Description

**get_next_line** is a core project from the 42 curriculum. The goal is to code a function in C that reads and returns a single line from a file descriptor (`fd`), one call at a time.

The main objective of this project is to learn about **static variables** in C, deepen the understanding of file descriptors and the `read` system call, and master dynamic memory allocation (`malloc` and `free`) without causing any memory leaks.

This implementation also includes the **Bonus part**, allowing the function to manage multiple file descriptors simultaneously using only a single static variable (an array of static pointers indexed by the file descriptor).

## ✨ Features & Specifications

The function has the following prototype:

```
char *get_next_line(int fd);

```

| Feature | Description | Implementation Details | 
| ----- | ----- | ----- | 
| **Line-by-Line Reading** | Reads from a file or standard input until a newline `\n` or `EOF` is reached. | Returns the read line including the terminating `\n` character (unless `EOF` was reached without a `\n`). | 
| **Dynamic `BUFFER_SIZE`** | Works with any buffer size specified at compilation (`-D BUFFER_SIZE=n`). | Efficiently joins chunks using custom string manipulation functions (`ft_strjoin`, `ft_strchr`, etc.). | 
| **Multiple File Descriptors (Bonus)** | Can read from multiple different `fd`s alternately without losing the reading state of any of them. | Uses a static array `static char *left_str[FD_MAX]` (up to `10240` file descriptors). | 
| **Robust Error Handling** | Safely handles invalid file descriptors, read errors (`-1`), and `BUFFER_SIZE <= 0`. | Frees allocated memory immediately upon read errors to prevent leaks. | 

**Return value:**

* The string containing the line that was read.

* `NULL` if there is nothing else to read (`EOF`) or if an error occurred.

## 📂 Project Structure

To comply with 42 evaluation standards, all source and header files are located directly in the root directory:

```
get_next_line/
├── README.md
├── get_next_line.c              # Mandatory: Core logic for single fd reading
├── get_next_line.h              # Mandatory: Header file with prototypes & BUFFER_SIZE macro
├── get_next_line_utils.c        # Mandatory: Helper functions (strchr, strjoin, strlen, etc.)
├── get_next_line_bonus.c        # Bonus: Core logic supporting multiple fds simultaneously
├── get_next_line_bonus.h        # Bonus: Header file including FD_MAX (10240)
└── get_next_line_utils_bonus.c  # Bonus: Helper functions for the bonus part

```

## 🛠️ Instructions (Compilation & Execution)

### Prerequisites

* A C compiler (e.g., `cc`, `gcc`, or `clang`)

### Compiling the Code

Since `get_next_line` does not require a `Makefile`, you compile the source files directly alongside your own `main.c` test file. You can define the `BUFFER_SIZE` at compile time using the `-D` flag (if omitted, it defaults to `42` as defined in the header).

**1. Compiling the Mandatory Part:**

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test

```

**2. Compiling the Bonus Part (Multiple FDs):**

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus_test

```

## 🚀 Usage

To test `get_next_line`, create a sample text file (e.g., `test.txt`) and a `main.c` file in your directory.

### 1. Example (`main.c` for Mandatory & Bonus):

```
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h" // Or "get_next_line.h" for mandatory

int main(void)
{
    int     fd1;
    int     fd2;
    char    *line;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);

    // Reading alternately from two different files (Bonus feature)
    line = get_next_line(fd1);
    printf("FD1 Line 1: %s", line);
    free(line);

    line = get_next_line(fd2);
    printf("FD2 Line 1: %s", line);
    free(line);

    // Loop through the rest of fd1
    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("FD1 Next  : %s", line);
        free(line);
    }

    close(fd1);
    close(fd2);
    return (0);
}

```

### 2. Run the Program:

```
# Run the Mandatory test:
./gnl_test

# Run the Bonus test:
./gnl_bonus_test

```

*(Important: Always remember to `free()` the line returned by `get_next_line` in your `main` function after using it!)*

## 🧪 Testing

### Edge Cases to Consider

When testing your implementation, pay special attention to:

* Extreme `BUFFER_SIZE` values: `1`, `42`, `9999`, or `10000000`.

* Invalid inputs: `fd < 0` (e.g., `-1`), arbitrary unopened file descriptors (e.g., `42`), or `BUFFER_SIZE <= 0`.

* File variations: Empty files, files with only newlines `\n`, very long lines (2k+ characters) without newlines, and files ending without a newline before `EOF`.

* Reading from Standard Input (`fd = 0`).

### Using Francinette (paco)

To run automated unit and memory tests via Francinette:

1. Navigate to your `get_next_line` root directory.

2. Run the test suite:

   ```
   paco
   
   ```

   Or for strict memory and crash testing:

   ```
   paco -s
   
   ```

   *(Ensure you do not have an active `main.c` or left-over executables in the folder when running `paco`!)*

### Memory Leak Testing with Valgrind

Because `get_next_line` relies heavily on dynamic memory allocation (`malloc` and `free`), checking for memory leaks and uninitialized values is critical. Run your compiled test program with Valgrind:

```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gnl_test

```

If every returned line in your `main` is freed properly and all file descriptors are read until `EOF` (or handled properly), Valgrind will report:
`All heap blocks were freed -- no leaks are possible`.