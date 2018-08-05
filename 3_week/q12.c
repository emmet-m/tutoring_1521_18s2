#include <stdio.h>
#include <string.h>

int main(void)
{
    int x = 100;
    char s[8];
    int y = 200;

    strcpy(s, "a long name");

    printf("%d '%s' %d\n", x, s, y);
    printf("0x%p 0x%p 0x%p\n", &x, s, &y);

    return 0;
}
