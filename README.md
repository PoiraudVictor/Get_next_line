# GNL

GNL is a function that, allows to read a line ending with a newline character ('\n') from a file descriptor, without knowing its size beforehand.

## Installation 📖

To use GNL please clone the repo :

```bash
git clone https://github.com/PoiraudVictor/Libft_42.git
```

## Usage 🎬

You are now 2 steps away from using my GNL !!

First, compile the get_next_line.c function with the main.c and the libft.a files :

```bash
gcc -Wextra -Werror -Wall get_next_line.c main.c libft.a -o gnl
```

Then, give as a file to the program so it can read it :

```bash
./gnl <your-file>
```

The output will appear on STDOUT with line number...
