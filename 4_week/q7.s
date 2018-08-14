    .data
x:  .space 8 # 8 bytes of space, a long
y:  .space 4 # 4 bytes of space, an int
    .text
    .globl main
main:

    li $v0, 5
    syscall
    sw $v0, y
    
    lw $t0, y
    # (y + 2000) * (y + 3000)
    addi $t1, $t0, 2000
    addi $t2, $t0, 3000

    mult $t1, $t2

    mflo $a0

    li $v0, 1
    move $a0, $t0
    syscall

    j $ra
