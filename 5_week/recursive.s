    .data
spc:
    .asciiz " "
debug:
    .asciiz "\nDEBUG\n"
size:
    .word  10
ar: .space 40
    .text
    .globl main

main: 
    # Load array values 
    la $t0, ar # array
    li $t1, 0  # coutner

load_loop:
    # Exit if counter == size
    lw  $t2, size
    beq $t1, $t2, end_load_loop
    
    #else, write data to array
    li  $t2, 4
    mul $t2, $t2, $t1 # Byte offset
    # Save current counter at coutner index,
    # ar[i] = i;
    sw $t1, ar($t2)

    addi $t1, $t1, 1 #increment
    j load_loop

end_load_loop:
    # Do stuff

    # We're about to jump, save $ra
    move $s0, $ra
    # print array
    jal print_array

    # Now.... recursive max!

    jal recursive_max


    move $ra, $s0

    j $ra


############ FUNCTIONS ############

# Destroys $t_ registers
recursive_max:

    j $ra

# Destroys $t_ registers
print_array:
    # Load array values 
    la $t0, ar # array
    li $t1, 0  # coutner

print_loop:
    # Exit if counter == size
    lw  $t2, size
    beq $t1, $t2, end_print_loop
    
    #else, write data to array
    li  $t2, 4
    mul $t2, $t2, $t1 # Byte offset

    # Load data
    # t = ar[i];
    lw $a0, ar($t2)

    li $v0, 1 #print int
    syscall

    la $a0, spc
    li $v0, 4 #print string
    syscall

    addi $t1, $t1, 1 #increment
    j print_loop

end_print_loop:

    j $ra
