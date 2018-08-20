    .data
x:  .word 1
y:  .word 2
z:  .word 3
n:  .asciiz "\n"
    .globl main
main:

    # ((x*x + y*y) - x*y) * z
    lw $t0, x
    lw $t1, y
    
    mul $t2, $t0, $t1 # x * y

    mul $t0, $t0, $t0 # x * x
    mul $t1, $t1, $t1 # y * y

    add $t0, $t0, $t1 # (x*x + y*y)
    
    sub $t0, $t0, $t2 # " " - x*y

    lw  $t1, z
    mul $t0, $t0, $t1 # ___ * z

    # Print newline
    li  $v0, 4
    la  $a0, n
    syscall

    # Print number
    li   $v0, 1
    move $a0, $t0
    syscall

    # Print newline
    li  $v0, 4
    la  $a0, n
    syscall

    j $ra
