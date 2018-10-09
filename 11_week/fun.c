// COMP1521 18s2 GDB debugging example

#include <stdio.h>
#include <stdlib.h>


int funName()
{
    return 7;
}

int c()
{
    return funName() + funName() + 1;
}
int b()
{
    return c() + 14;
}
int a()
{
    return 1 + b();
}

int main(int argc, char **argv)
{
    a();
    return 0;
}

