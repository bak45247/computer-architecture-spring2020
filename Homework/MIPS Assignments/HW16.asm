# Boston KJ
# Homework 16: Hailstone Sequence

.data
	prompt: .asciiz "Please enter a number: "
	finish: .asciiz "\nNumber of iterations: "
	space: .asciiz " "
	
.text
main:
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	
	move $t1, $v0
	li $t3, 1
	j printIteration
	
hailstoneCheck:
	addi $t3, $t3, 1 # iteration counter
	rem $t2, $t1, 2 # t2 = t1 % 2
	beqz $t2, hailstoneDivide # if t1 % 2 is zero, we can divide and continue
	mul $t1, $t1, 3 # if t2 isn't 0, then we multiply by 3 and add 1
	addi $t1, $t1, 1
	j printIteration
	
hailstoneDivide:
	div $t1, $t1, 2
	beq $t1, 1, exit # if t1 is 1, we're done!
	j printIteration
	
printIteration:
	li $v0, 1
	move $a0, $t1
	syscall
	
	li $v0, 4
	la $a0, space
	syscall
	
	j hailstoneCheck
	
exit:
	li $v0, 1
	move $a0, $t1
	syscall
	
	li $v0, 4
	la $a0, space
	syscall # We have to print the 1

	la $a0, finish
	syscall
	
	li $v0, 1
	move $a0, $t3
	syscall
	
	li $v0, 10
	syscall