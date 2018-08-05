#define LIFE 42
#define VAL  random()%20
#define sq(x) (x*x)
#define woof(y) (LIFE+y)

int main()
{
    char s[LIFE];
    int  i = woof(5);
    i = VAL;
    // What happens to the below sq() statement?
    // Compile with `gcc -E q1.c` to find out!
    return (sq(i++) > LIFE) ? 1 : 0;
}
