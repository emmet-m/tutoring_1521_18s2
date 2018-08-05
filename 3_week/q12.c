#include <stdio.h>
#include <string.h>

int main(void)
{
    int x = 100;
    char s[8];
    int y = 200;
    char z = 0;

    strcpy(s, "a long name asd");

    printf("%s\n", s);
    printf("0x%p 0x%p 0x%p\n", &x, s, &y);

    return 0;
}
