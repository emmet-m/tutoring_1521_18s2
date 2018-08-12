#include <stdio.h>

struct field {
    unsigned int sign: 1;
    unsigned int value: 31;
};

void print_field(struct field f);
void display_int(struct field * f);

int main (void) {

    printf("Size of struct field: %ld\n", sizeof(struct field));

    struct field var;

    var.sign = 0;
    var.value = 0;

    // Let's look at sign:

    print_field(var);
    var.sign++;
    print_field(var);
    var.sign++;
    print_field(var); // What?

    var.sign = 1;
    var.value = 10;

    display_int(&var);

    return 0;
}

void display_int(struct field * f) {
    // Dangerous... but works?
    int * a = (int*) f;
    printf("Int: %d\n", *a);
}


void print_field(struct field f) {
    printf("Field contents:\n sign: %d\nvalue: %d\n", f.sign,f.value);
}
