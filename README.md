# get_next_line

A function written by me (Helvi Lainekallio) during my studies in Hive Helsinki.

```
int     get_next_line(const int fd, char **line);
```
[Subject for this project](get_next_line.en.pdf)

The function takes as parameter the *fd* where if reads from and a string *line*, where it writes the data it has read, until newline
or EOF has been reached. The function returns 1 every time it has read a line and 0 when it finds EOF. The function is able to handle multiple open file descriptors.

The function uses the library libft, also written by me during my studies. 

There is also a folder in this repo with tests written by me to test the get_next_line function, and also some test files that
make it easy to test different cases. To use the test:

The mains, the Makefile and the function should be in the same folder. Libft is ment to be on its own folder, with libft.h inside 
that folder in a folder called includes.
If the library is not compiled, use make in libft folder to compile it.
You can use the ready made Makefile with commands "make thenX" where the X is the number of the main you want to use. 
To use the mains, you can use some of them without parameters to read from stdin, or open one or multiple files giving them as
parameters.

