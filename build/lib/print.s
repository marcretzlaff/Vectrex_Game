
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	print.c
	.area .text
	.globl _print_string
_print_string:
	leas	-9,s
	stb	2,s
	stx	,s
	ldb	2,s
	stb	4,s
	ldb	11,s
	stb	3,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	4,s
	stb	6,s
	ldb	3,s
	stb	5,s
	ldb	6,s
	stb	,-s
	ldb	6,s
	jsr	__Moveto_d
	leas	1,s
	ldx	,s
	stx	7,s
	; ldx	7,s	; optimization 5
	jsr	__Print_Str
	leas	9,s
	rts
	.globl _print_unsigned_int
_print_unsigned_int:
	leas	-15,s
	stb	5,s
	ldb	#-128
	stb	9,s
	ldb	#2
	stb	10,s
L4:
	ldb	10,s
	stb	3,s
	ldb	18,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	ldx	#10
	pshs	x
	ldx	2,s
	jsr	_umodhi3
	leas	2,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	2,s
	; ldb	2,s	; optimization 5
	addb	#48
	stb	4,s
	ldb	3,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	leax	6,s
	exg	d,x
	addd	,s
	exg	d,x
	ldb	4,s
	stb	,x
	dec	10,s
	ldb	18,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	ldx	#10
	pshs	x
	ldx	2,s
	jsr	_udivhi3
	leas	2,s
	tfr	x,d
	stb	18,s	;movlsbqihi: R:d -> 18,s
	ldb	10,s
	cmpb	#-1	;cmpqi:
	bne	L4
	ldb	5,s
	stb	12,s
	ldb	17,s
	stb	11,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	12,s
	stb	14,s
	ldb	11,s
	stb	13,s
	ldb	14,s
	stb	,-s
	ldb	14,s
	jsr	__Moveto_d
	leas	1,s
	leax	6,s
	jsr	__Print_Str
	leas	15,s
	rts
	.globl _print_signed_int
_print_signed_int:
	leas	-19,s
	stb	7,s
	tst	22,s
	bge	L7
	ldb	#45
	stb	3,s
	bra	L8
L7:
	ldb	#43
	stb	3,s
L8:
	ldb	3,s
	stb	8,s
	ldb	#-128
	stb	12,s
	ldb	#3
	stb	13,s
	tst	22,s
	bge	L9
	ldb	22,s
	stb	2,s
	; ldb	2,s	; optimization 5
	negb
	stb	4,s
	bra	L10
L9:
	ldb	22,s
	stb	4,s
L10:
	ldb	4,s
	stb	14,s
L11:
	ldb	13,s
	stb	5,s
	ldb	14,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	ldx	#10
	pshs	x
	ldx	2,s
	jsr	_umodhi3
	leas	2,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	2,s
	; ldb	2,s	; optimization 5
	addb	#48
	stb	6,s
	ldb	5,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	leax	8,s
	exg	d,x
	addd	,s
	exg	d,x
	ldb	6,s
	stb	,x
	dec	13,s
	ldb	14,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	ldx	#10
	pshs	x
	ldx	2,s
	jsr	_udivhi3
	leas	2,s
	tfr	x,d
	stb	14,s	;movlsbqihi: R:d -> 14,s
	tst	13,s
	bne	L11
	ldb	7,s
	stb	16,s
	ldb	21,s
	stb	15,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	16,s
	stb	18,s
	ldb	15,s
	stb	17,s
	ldb	18,s
	stb	,-s
	ldb	18,s
	jsr	__Moveto_d
	leas	1,s
	leax	8,s
	jsr	__Print_Str
	leas	19,s
	rts
	.globl _print_long_unsigned_int
_print_long_unsigned_int:
	pshs	y
	leas	-19,s
	stb	7,s
	stx	5,s
	ldb	#-128
	stb	13,s
	ldb	#4
	stb	14,s
L14:
	ldb	14,s
	stb	3,s
	ldy	5,s
	ldx	#10
	pshs	x
	leax	,y
	jsr	_umodhi3
	leas	2,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	2,s
	; ldb	2,s	; optimization 5
	addb	#48
	stb	4,s
	ldb	3,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	leax	8,s
	exg	d,x
	addd	,s
	exg	d,x
	ldb	4,s
	stb	,x
	dec	14,s
	ldy	5,s
	ldx	#10
	pshs	x
	leax	,y
	jsr	_udivhi3
	leas	2,s
	stx	5,s
	ldb	14,s
	cmpb	#-1	;cmpqi:
	bne	L14
	ldb	7,s
	stb	16,s
	ldb	23,s
	stb	15,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	16,s
	stb	18,s
	ldb	15,s
	stb	17,s
	ldb	18,s
	stb	,-s
	ldb	18,s
	jsr	__Moveto_d
	leas	1,s
	leax	8,s
	jsr	__Print_Str
	leas	19,s
	puls	y,pc
	.globl _print_long_signed_int
_print_long_signed_int:
	pshs	y
	leas	-25,s
	stb	10,s
	stx	8,s
	; ldx	8,s	; optimization 5
	cmpx	#0
	bge	L17
	ldb	#45
	stb	3,s
	bra	L18
L17:
	ldb	#43
	stb	3,s
L18:
	ldb	3,s
	stb	11,s
	ldb	#-128
	stb	17,s
	ldb	#5
	stb	18,s
	ldx	8,s
	cmpx	#0
	bge	L19
	ldx	8,s
	tfr	x,d
	nega
	negb
	sbca	#0
	std	4,s
	bra	L20
L19:
	ldx	8,s
	stx	4,s
L20:
	ldd	4,s
	std	19,s
L21:
	ldb	18,s
	stb	6,s
	ldy	19,s
	ldx	#10
	pshs	x
	leax	,y
	jsr	_umodhi3
	leas	2,s
	tfr	x,d	;movlsbqihi: R:x -> R:b
	stb	2,s
	; ldb	2,s	; optimization 5
	addb	#48
	stb	7,s
	ldb	6,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	leax	11,s
	exg	d,x
	addd	,s
	exg	d,x
	ldb	7,s
	stb	,x
	dec	18,s
	ldy	19,s
	ldx	#10
	pshs	x
	leax	,y
	jsr	_udivhi3
	leas	2,s
	stx	19,s
	tst	18,s
	bne	L21
	ldb	10,s
	stb	22,s
	ldb	29,s
	stb	21,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	22,s
	stb	24,s
	ldb	21,s
	stb	23,s
	ldb	24,s
	stb	,-s
	ldb	24,s
	jsr	__Moveto_d
	leas	1,s
	leax	11,s
	jsr	__Print_Str
	leas	25,s
	puls	y,pc
	.globl _print_binary
_print_binary:
	leas	-20,s
	stb	5,s
	ldb	#-128
	stb	14,s
	ldb	#7
	stb	15,s
L24:
	ldb	15,s
	stb	3,s
	ldb	23,s
	stb	,s
	ldb	#1
	andb	,s
	stb	2,s
	; ldb	2,s	; optimization 5
	addb	#48
	stb	4,s
	ldb	3,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	leax	6,s
	exg	d,x
	addd	,s
	exg	d,x
	ldb	4,s
	stb	,x
	dec	15,s
	lsr	23,s
	ldb	15,s
	cmpb	#-1	;cmpqi:
	bne	L24
	ldb	5,s
	stb	17,s
	ldb	22,s
	stb	16,s
	ldb	#-52
	stb	*_dp_VIA_cntl
	ldb	#127
	stb	*_dp_VIA_t1_cnt_lo
	ldb	17,s
	stb	19,s
	ldb	16,s
	stb	18,s
	ldb	19,s
	stb	,-s
	ldb	19,s
	jsr	__Moveto_d
	leas	1,s
	leax	6,s
	jsr	__Print_Str
	leas	20,s
	rts
