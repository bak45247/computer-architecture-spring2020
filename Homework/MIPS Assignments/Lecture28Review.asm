# Boston KJ
# Lecture 28 Review

.data
	firstPrompt: .asciiz "Enter the first number: "
	secondPrompt: .asciiz "Enter the second number: "
	thirdPrompt: .asciiz "Enter the third number: "
	sumResponse: .asciiz "The sum is: "
	
	firstNum: .word 0
	secondNum: .word 0
	sum: .word 0
	
.text
	li $v0, 4
	la $a0, firstPrompt
	syscall
	
	li $v0, 5
	syscall
	
	sw $v0 firstNum
	
	li $v0, 4
	la $a0, secondPrompt
	syscall
	
	li $v0, 5
	syscall
	
	sw $v0 secondNum
	
	li $v0, 4
	la $a0, secondPrompt
	syscall
	
	li $v0, 5
	syscall
	
	sw $v0 sum
	
	lw $t1, sum
	lw $t2, firstNum
	lw $t3, secondNum
	
	add $t1, $t1, $t2
	add $t1, $t1, $t3
	syscall
	
	li $v0, 4
	la $a0, sumResponse
	syscall
	
	li $v0, 1
	move $a0, $t1
	syscall
	
	li $v0, 10
	syscall