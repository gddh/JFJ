Just For Jeff - Memory Leak Finder
================

Wrote a short program to help identify memory leaks.

# How to Use

## Instructions
1. clone/download the two files
2. Put the "jfj.c" in the directory of the program you want to test.
	- "jfj.c" can go into your `srcs/`
	- "jfj.h" can go into your `includes/`
3. include "jfj.h" in your .h file.
4. If you are using libft, go into jfj.h and jfj.c and uncomment the ```#include "libft/libft.h"```
    - uncomment the relevant functions that are mallocing. If you do not know just run jfj as is and it should tell you which ft_functions use malloc.
5. Add jfj.c or jfj.o to your Makefile
6. Add ```leaks();``` to the end of the main that is running the program.
7. make and execute.

## Just trying JFJ?
1. clone the repo
3. run ```make```
4. run ```./test```
5. Edit ```test.c``` as you need

# Supporting
1. ```malloc```
2. ```ft_memalloc```

# Bugs?
Find me on 42slack: delin
