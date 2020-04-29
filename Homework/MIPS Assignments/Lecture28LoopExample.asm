# Boston KJ
# Lecture 28 Loop Example

.data
	maxNum: .word 0
	maxPrompt: .asciiz "Enter a number: "
	newLine: .asciiz "\n"

.text
	li $v0, 4
	la $a0, maxPrompt
	syscall
	
	li $v0, 5
	syscall
	
	sw $v0, maxNum
	
	lw $t0, maxNum
	lw $t1, maxNum
	li $t2, 1
	
loop:
	beqz $t0, exit
	beq $t0, $t2, exit
	li $v0, 1
	move $a0, $t0
	syscall
	
	move $t0, $a0
	subi $t0, $t0, 2
	
	li $v0, 4
	la $a0, newLine
	syscall
	j loop
	
exit:
	li $v0, 10
	syscall