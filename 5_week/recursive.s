    .data
spc:
    .asciiz " "
nwln:
    .asciiz "\n"
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
    # Now our array has the number [0..9] in it

    # TODO: Test with this
    #li $t9, 100
    #sw $t9, ar+4

    # We're about to jump, save $ra
    move $s0, $ra
    # print array
    jal print_array

    # Now.... recursive max!
    # Arguments: $a0 = ar, $a1 = array
    la  $a0, ar
    lw  $a1, size 
    jal recursive_max

    # Postcondition: $v0 contains the max integer
    move $t0, $v0

    la $a0, nwln
    li $v0, 4 #print newline
    syscall

    move $a0, $t0 # Int to print
    li $v0, 1
    syscall # Print our int!

    la $a0, nwln
    li $v0, 4 #print newline
    syscall

    move $ra, $s0

    j $ra


############ FUNCTIONS ############

# Destroys $t_ registers
recursive_max:
    # Gotta push $ra and $fp onto the stack
    # Save our old $fp 
    sw    $fp, -4($sp)
    # Load the new bottom of our frame in
    la    $fp, -4($sp) 
    # Save our current return address
    sw    $ra, -8($sp) 

    # We need variables to keep on the stack
    sw    $s0, -12($sp) 
    sw    $s1, -16($sp) 
    sw    $s2, -20($sp) 

    # Update the top of our stack!
    addi  $sp, -24

    # Now, we need to keep track of our current
    #  position in the array...
    move $s0, $a0 # Array pointer

base_case:
    li  $t0, 1
    bgt $a1, $t0, recursive_case # Move to recursive case if not at end of array
    
    # End of array, take element at a[0]
    lw $v0, ($a0)
    j recursive_max_end

recursive_case:
    # Save element at current state, decrement and recurse
    lw   $s0, ($a0)

    addi $a0, 4  # Move along 4 bytes 
    addi $a1, -1 # Decrease remaining length

    jal recursive_max # Recurse

    # Check if currently returned is bigger than current level
    blt  $s0, $v0, recursive_max_end
    nop

    # Copy current element across
    move $v0, $s0

recursive_max_end:

    # Restore old variables
    lw    $s2, -16($fp) 
    lw    $s1, -12($fp) 
    lw    $s0, -8($fp) 

    # Save our current return address
    lw    $ra, -4($fp) 

    # Restore old $sp
    la    $sp, 4($fp)

    # Restore old $fp
    lw    $fp, ($fp)

    # Return
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
