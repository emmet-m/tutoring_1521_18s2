int  a;
char b[100];
 
int fun1() { 
    int c, d;

    (void) c;
    (void) d;

    return 0;
}
 
double e;
 
int fun2() { 
    int f;
    static int ff;

    (void) f;
    (void) ff;

    return fun1();
}
 
unsigned int g;
 
int main(void) { 
    char h[10];
    int i;

    (void) i;
    (void) h;

    return fun2();
}
