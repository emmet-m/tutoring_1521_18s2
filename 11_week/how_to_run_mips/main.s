    .text
main:
	# set up stack frame
	sw    $fp, -4($sp)
	la    $fp, -4($sp)
	sw    $ra, -4($fp)  # note: switch to $fp
	sw    $s0, -8($fp)  # $s0 is tmp var
	addi  $sp, $sp, -8

	la    $a0, items
	lw    $a1, NITEMS
#	la    $a1, NITEMS   # BUG: change above line to this
	jal   max           # max(items, NITEMS)
	move  $s0, $v0      # tmp = max()
	la    $a0, msg
	li    $v0, 4        # printf("Max value is ")
	syscall
	move  $a0, $s0
	li    $v0, 1        # printf("%d", tmp)
	syscall
	li    $a0, 10
	li    $v0, 11       # printf("\n")
	syscall
	
	move  $v0, $0       # return 0

	lw    $s0, -8($fp)
	lw    $ra, -4($fp)
	la    $sp, 4($fp)
	lw    $fp, ($fp)
	jr    $ra           # BUG: try removing this
