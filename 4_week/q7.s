    .data
x:  .space 8 # 8 bytes of space, a long
y:  .space 4 # 4 bytes of space, an int
    .text
    .globl main
main:

    # Read in an integer
    li $v0, 5
    syscall
    sw $v0, y
    lw $t0, y

    # (y + 2000) * (y + 3000)

    # Add some constants to t1 and t2 and y
    addi $t1, $t0, 2000
    addi $t2, $t0, 3000

    # multiply them
    mult $t1, $t2

    # save the Lo register into a0 (we can't print longs yet)
    mflo $a0

    # Print out the Lo register
    li $v0, 1
    syscall

    j $ra
