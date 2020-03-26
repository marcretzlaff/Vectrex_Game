
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	main.c
	.area .text
	.globl _main
_main:
	leas	-1,s
L2:
	jsr	_game
	stb	,s
	; tst	,s	; optimization 3
	beq	L2
	ldb	,s
	leas	1,s
	rts
