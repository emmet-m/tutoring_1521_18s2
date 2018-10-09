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

	.text

## int main(void)
## {
## 	printf("Max value is %d\n", max(items,NITEMS));
## 	return 0;
## }

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


## int max(int a[], int n)
## {
## 	int i;  int big = -1;
## 	for (i = 0; i < n; i++) {
## 		if (a[i] > big) big = a[i];
## 	}
## 	return big;
## }

max:
	# set up stack frame
	sw    $fp, -4($sp)
	la    $fp, -4($sp)
	sw    $ra, -4($fp)  # note: switch to $fp
	sw    $s0, -8($fp)  # $s0 is a[]
	sw    $s1, -12($fp) # $s1 is n
	sw    $s2, -16($fp) # $s2 is i
	sw    $s3, -20($fp) # $s3 is big
	addi  $sp, $sp, -20

### You need to write all the code below here
	
	move  $s0, $a0
	move  $s1, $a1
	li    $s2, 0        # i = 0
	li    $s3, -1       # big = -1  # BUG: comment this out
max_for:
	bge   $s2, $s1, end_max_for
	move  $t0, $s2
	li    $t1, 4
	mul   $t0, $t0, $t1 # offset = i*4
	add   $t0, $t0, $s0 # t0 = &a[i]
	lw    $t0, ($t0)    # t0 = a[i]

	ble   $t0, $s3, max_cont
	move  $s3, $t0      # big = a[i]

max_cont:
	addi  $s2, $s2, 1   # BUG: try removing this
	j     max_for

end_max_for:
	move  $v0, $s3

### You need to write all of the code above here

	# clean up stack frame
	lw    $s3, -20($fp)
	lw    $s2, -16($fp)
	lw    $s1, -12($fp)
	lw    $s0, -8($fp)
	lw    $ra, -4,($fp)
	la    $sp, 4($fp)
	lw    $fp, ($fp)
	jr    $ra           # BUG: try removing this
