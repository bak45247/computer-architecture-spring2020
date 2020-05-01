# Boston KJ
# Lecture 37 Follow Along

.data
	integerVar: .word 100
	doubleVar: .double 3.5
	averageVar: .double 2.0
	newLine: .asciiz "\n"
	
	piePrompt: .asciiz "What is your favorite kind of pie? "
	pieResponse: .asciiz "Your favorite pie is: "
	iString: .space 21
	iStringLength: .word 20
	
	
.text
	lw $a0, integerVar
	li $v0, 1
	syscall
	
	jal printNL
	
	lw $a0, integerVar
	add $a0, $a0, $a0
	li $v0, 1
	syscall
	
	jal printNL
	
	l.d $f12, doubleVar
	add.d $f12, $f12, $f12
	li $v0, 3
	syscall
	
	jal printNL
	
	# Converting datatypes
	li $t1, 15
	li $t2, 44
	mtc1.d $t1, $f2
	cvt.d.w $f2, $f2
	mtc1.d $t2, $f4
	cvt.d.w $f4, $f4
	add.d $f6, $f2, $f4
	
	l.d $f4, averageVar
	div.d $f8, $f6, $f4
	
	li $v0, 3
	mov.d $f12, $f8
	syscall
	jal printNL
	
	li $v0, 4
	la $a0, piePrompt
	syscall
	
	li $v0, 8
	la $a0, iString
	lw $a1, iStringLength
	syscall
	
	li $v0, 4
	la $a0, pieResponse
	syscall
	
	li $v0, 4
	la $a0, iString
	syscall
	j exit
	
printNL:
	li $v0, 4
	la $a0, newLine
	syscall
	jr $ra
	
exit:
	li $v0, 10
	syscall
