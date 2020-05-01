# Boston KJ
# Lecture 28 follow along

.data
	prompt: .asciiz "Enter a number: "
	password: .word 54
	responseYes: .asciiz "You got it!\n"
	responseNo: .asciiz "Try again...\n"
	
.text
attempt:
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	lw $t1, password
	beq $a0, $t1, printYes
	
	li $v0, 4
	la $a0, responseNo
	syscall
	
	j exit
	
printYes:
	li $v0, 4
	la $a0, responseYes
	syscall
	
	
exit:
	li $v0, 10
	syscall