# COMP1521 18s2 QtSPIM demo ... find max

    .globl  NITEMS
    .globl  items
    .globl  main
    .globl  max

    .data

## #define NITEMS 10
## int items[NITEMS] = {3,5,6,8,2,1,3,7,7,4};
NITEMS:
    .word   10
items:
    .word   3, 5, 6, 8, 2, 1, 3, 0, 7, 4
msg:
    .asciiz "Max value is "
