#include <stdio.h>

union _all {
    int   ival;
    char cval;
    char  sval[4];
    float fval;
    unsigned int uval;
};

int main (void) {

    union _all var;

    var.uval = 0x00313233;

    // What will each of these print?
    // 
    // [00][31][32][33] BIG
    // [33][32][31][00] LITTLE

    printf("size of union: %lu\n\n", sizeof(union _all));

    printf("uval: 0x%x\n", var.uval);
    printf("ival: %d\n", var.ival);
    printf("cval: %c\n", var.cval);
    printf("sval: %s\n", var.sval);
    printf("fval: %f\n", var.fval);
    printf("fvale: %e\n", var.fval); // Scientific notation

}
