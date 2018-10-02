    .data
nwln:  .asciiz "\n"
nrows: .word 6
ncols: .word 12
# This is so cute lol
flag:  .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
       .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
       .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
       .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
       .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
       .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .text
    .globl main

main:

    # print the thing

    # Row
    li $t0, 0
    # Column
    li $t1, 0
    
start: 
    lw  $t2, nrows
    # Break if row_count == nrows
    beq $t2, $t1, end

    # Some vector maths:
    # $t2 = ncols * $t0 + $t1
    lw  $t2, ncols
    mul $t2, $t2, $t0
    add $t2, $t1, $t2
    
    # Print the char
    lb $a0, flag($t2) 
    li $v0, 11
    syscall

    # Increment
    addi $t1, 1

    # If we're still on this colunn, keep going
    lw   $t2, ncols 
    blt  $t1, $t2, start 

    # Done, print newline and move to next row
    addi $t0, 1  
    li $t1, 0

    # Print newline
    la $a0, nwln
    li $v0, 4
    syscall

    j start

end:

    j $ra
