
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	collision.c
	.area .text
	.globl _check_collision
_check_collision:
	leas	-3,s
	stb	1,s
	clr	2,s
	ldb	1,s
	cmpb	6,s	;cmpqi:
	bge	L2
	ldb	6,s
	subb	1,s
	cmpb	8,s	;cmpqi:
	bhi	L4
	inc	2,s
	bra	L4
L2:
	ldb	1,s
	subb	6,s
	cmpb	8,s	;cmpqi:
	bhi	L4
	inc	2,s
L4:
	ldb	5,s
	cmpb	7,s	;cmpqi:
	bge	L5
	ldb	7,s
	subb	5,s
	cmpb	9,s	;cmpqi:
	bhi	L7
	inc	2,s
	bra	L7
L5:
	ldb	5,s
	subb	7,s
	cmpb	9,s	;cmpqi:
	bhi	L7
	inc	2,s
L7:
	clr	,s
	ldb	2,s
	cmpb	#2	;cmpqi:
	bne	L8
	ldb	#1
	stb	,s
L8:
	ldb	,s
	leas	3,s
	rts
