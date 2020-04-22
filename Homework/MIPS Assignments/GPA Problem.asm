# Boston KJ 
# Introduction to MIPS [Lecture]
# GPA Practice Problem

.data
	ageQuestion: .asciiz "Please enter your age: "
	gpaQuestion: .asciiz "Please enter your gpa: "
	agePrintout: .asciiz "Your age is: "
	gpaPrintout: .asciiz " and your GPA is: "
	age: .word 0
	gpa: .double 0.0
	

.text
	li $v0, 4
	la $a0, ageQuestion
	syscall
	
	li $v0, 5
	syscall
	
	sw $v0, age
	li $v0, 4
	la $a0, gpaQuestion
	syscall
	
	li $v0, 7
	syscall
	
	s.d $f0, gpa
	li $v0, 4
	la $a0, agePrintout
	syscall
	
	li $v0, 1
	lw $a0, age
	syscall
	
	li $v0, 4
	la $a0, gpaPrintout
	syscall
	
	li $v0, 3
	l.d $f12, gpa
	syscall
	
	li $v0, 10
	syscall