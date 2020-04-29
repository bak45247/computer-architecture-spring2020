# Boston KJ
# Sum of three numbers, HW14

.data
	firstPrompt: .asciiz "Please enter the First Number: "
	secondPrompt: .asciiz "Please enter the Second Number: "
	thirdPrompt: .asciiz "Please enter the third Number: "
	sumPrompt: .asciiz "The total is: "
	
.text
	li $v0, 4
	la $a0, firstPrompt
	syscall
	
	li $v0, 5
	syscall
	
	move $t1, $v0
	li $v0, 4
	la $a0, secondPrompt
	syscall
	
	li $v0, 5
	syscall
	
	add $t1, $t1, $v0
	li $v0, 4
	la $a0, thirdPrompt
	syscall
	
	li $v0, 5
	syscall
	
	add $t1, $t1, $v0
	li $v0, 4
	la $a0, sumPrompt
	syscall
	
	li $v0, 1
	move $a0, $t1
	syscall
	
	li $v0, 10
	syscall