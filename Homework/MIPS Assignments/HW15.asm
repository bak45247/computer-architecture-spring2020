# Boston KJ
# HW15 Conditional Jumps

.data
	numberPrompt: .asciiz "Please enter a number: "
	factor: .asciiz ": is a Factor\n"
	notFactor: .asciiz ": is not a Factor\n"
	primeFactor:.asciiz ": is a Prime Factor\n"
	number: .word 0

.text
	li $v0, 4
	la $a0, numberPrompt
	syscall
	
	li $v0, 5
	syscall
	
	sw $v0, number
	lw $t7, number
	li $t6, 2 # start of prime factor check
	li $t2, 1	
factorCheck:
	lw $t1, number
	beq $t1, $t2, exit
	rem $t3, $t1, $t2
	beqz $t3, primeFactorCheck
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	move $t2, $a0
	li $v0, 4
	la $a0, notFactor
	syscall
	
increment:
	li $t6, 2 # start of prime factorization
	addi $t2, $t2, 1
	j factorCheck
	
isFactor:
	li $v0, 1
	move $a0, $t2
	syscall
	
	move $t2, $a0
	li $v0, 4
	la $a0, factor
	syscall
	
	j increment
	
primeFactorCheck:
	blt $t2, $t6, isFactor # if t2 is less than t6, it cant be a part of prime factorization
	rem $t3, $t1, $t6
	beqz $t3, primeAction
	addi $t6, $t6, 1
	j primeFactorCheck
	
primeAction:
	beq $t6, $t2, primePrint
	div $t1, $t1, $t6
	beq $t1, 1, isFactor
	j primeFactorCheck
	
primePrint:
	li $v0, 1
	move $a0, $t2
	syscall
	
	move $t2, $a0
	li $v0, 4
	la $a0, primeFactor
	syscall
	j increment

exit:
	li $v0, 10
	syscall
