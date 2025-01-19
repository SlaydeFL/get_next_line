# Get Next Line - 42 School Project  

**Get Next Line** is a 42 project focused on implementing a function that reads a line from a file descriptor, one at a time, with efficient memory management and dynamic allocation.

---

## 📝 Project Overview

The **Get Next Line** project introduces the challenge of reading data from a file descriptor efficiently. The function must handle:
- Any valid file descriptor, including standard input (stdin).
- Dynamic buffers to read data of varying sizes.
- Continuous reading of lines, one by one, across multiple calls.

### Function Prototype
```c
char *get_next_line(int fd);
```

### Key Requirements
- Read and return a line from a file descriptor.
- Handle multiple file descriptors simultaneously.
- Ensure efficient memory usage and avoid leaks.

---

## 📂 Project Structure

```plaintext
.
├── get_next_line.c         # Core implementation of get_next_line.
├── get_next_line.h         # Header file with prototypes and definitions.
├── get_next_line_utils.c   # Utility functions for memory and string operations.
├── main.c                  # Example main file to test get_next_line.
├── test.txt                # Example file for testing.
```

---

## ⚙️ Compilation

To compile and test the project, you can use the following command:

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

This generates an executable named `gnl`. You can then test the program with a file, for example:

```bash
./gnl test.txt
```

---

## 🚀 Features
- **Line-by-line reading** from any file descriptor.
- **Buffer size flexibility**, defined using the `BUFFER_SIZE` macro at compile time.
- **Multi-FD support**, allowing the function to handle multiple file descriptors simultaneously.

### Usage Example
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
```

---

## 📜 Norms & Requirements

This project adheres to the strict **42 coding standards**, which include:
- Functions limited to 25 lines.
- No global variables.
- Proper handling of memory to prevent leaks.

### Mandatory & Bonus
- [x] Mandatory: Basic `get_next_line` implementation.
- [ ] Bonus: Handle multiple file descriptors simultaneously and other advanced features.

