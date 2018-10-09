# Tips on using GDB!

GDB is a great tool that lets you run your C programs and trace exactly where they go wrong!

## Running gdb

To make a program work with GDB, ensure you have the `-g` flag added when compiling. For example:

```bash
gcc -Wall -Werror -g -o prog prog.c
```

Run GDB by typing:

```bash
gdb ./program
```

Some copyright notices will pop up. You can silence these by adding the `-q` flag.

At this stage, GDB is waiting for your program to start running. You can enter some GDB commands here before your program starts to setup your debugging session, and when you're ready, type `run` or `r` for short to start your program.

## Inspecting a program that has crashed

When a program crashes in a GDB session, GDB will print out an error message like so:

```
Program received signal SIGSEGV, Segmentation fault.
...
```
(You may not necessarily get a segmentation fault!)

The following lines will be the *stack trace* (i.e. the path of functions that got called to reach the current position of the program).

At this point, you can inspect and interact with all the variables in scope in the program.

### Printing

To *print* any of these variables, merely type:

```gdb
(gdb) print varName
```

This will print out the contents of the variable if they are a regular variable (a float, int, char * (string), etc.), or the address otherwise.

You can also interact with data structures:

```gdb
(gdb) print array[0]
(gdb) print myStruct.var
(gdb) print list->next->next->value
```

### Moving around the stack frame

#### where
You can check the stack frame any time by by typing `where`:

```gdb
(gdb) where
#0  d () at fun.c:9
#1  0x004004f0 in c () at fun.c:14
#2  0x00400512 in b () at fun.c:18
#3  0x00400525 in a () at fun.c:22
#4  0x00400543 in main (argc=1, argv=0x7fffffffdc88) at fun.c:27
```

Each #number corresponds to the level of stack frame (0 being the current, 1 the previous, etc.). Each stack name displays the *file* the function was called from, as well as the *line number*.

#### list

To show the context of a particular stack frame, type `list`:

```gdb
(gdb) list
4   #include <stdlib.h>
5   
6   
7   int d()
8   {
9       return 7;
10  }
11  
12  int c()
13  {

```


GDB will show you the surrounding lines of context, surrounding the line your program is currently paused upon.

#### frame

You can inspect previous stack frames by typing `frame num`, where num is the name of the stack frame you wish to visit. 

```gdb
(gdb) frame 3
#3  0x0000000000400525 in a () at fun.c:22
22      return 1 + b();
```

This displays the line number as well as the actual line where that stack frame jumped to the next stack frame.


### Controlling Execution flow

#### break

You can stop program flow at a particular line number or function call by using `break` on either that line number or the function name:

```gdb
(gdb) break 20
Breakpoint 1 at 0x40051b: file fun.c, line 20.
(gdb) b funName
Breakpoint 1 at 0x4004da: file fun.c, line 9.
```

Do this **before** running your program, then run and see that your program will pause at the line/function you specified!

#### step

You can move forward one line, stepping *into* any functions on the next line by typing `step` whilst paused.

Using a combination of `break` and `run`:

```gdb
(gdb) break main
Breakpoint 1 at 0x400539: file fun.c, line 27.
(gdb) run
Starting program: /home/emmet/Documents/tutoring_1521_18s2/11_week/fun 

Breakpoint 1, main (argc=1, argv=0x7fffffffdc88) at fun.c:27
27      a();

# ^ At this point, we've paused at the start of main. Main is about to step into the line of code 'a();'.
 
(gdb) step
a () at fun.c:22he
22      return 1 + b();

# ^ Here, we've stepped inside the function a()
```

#### next 

Alternatively, you can skip over lines (and not step into functions called on those lines) by using `next`:

```gdb
Breakpoint 1, main (argc=1, argv=0x7fffffffdc88) at fun.c:27
27      a();
(gdb) n
28      return 0;
(gdb) 
```

Notice that GDB has stepped to the very next line of main, and run (but not stepped into) function `a()`.


### Quitting

Simply type `q` or `quit`, to quit at any time.
