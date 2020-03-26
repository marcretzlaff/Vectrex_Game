
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	debug.c
	.area .text
LC0:
	.byte	0x46
	.byte	0x49
	.byte	0x4C
	.byte	0x45
	.byte	0x3A
	.byte	0x80
	.byte	0x00
LC1:
	.byte	0x4C
	.byte	0x49
	.byte	0x4E
	.byte	0x45
	.byte	0x3A
	.byte	0x80
	.byte	0x00
LC2:
	.byte	0x56
	.byte	0x41
	.byte	0x4C
	.byte	0x55
	.byte	0x45
	.byte	0x3A
	.byte	0x80
	.byte	0x00
	.globl __f_debug
__f_debug:
	pshs	y,u
	leas	-22,s
	leau	,s
	stx	10,u
	stb	9,u
	sts	2,u
	leax	,s
	stx	7,u
	ldb	34,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	; ldd	,u	; optimization 5
	addd	32,u
	std	14,u
	clr	34,u
	bra	L2
L4:
	inc	34,u
L2:
	ldd	14,u
	addd	#-1
	std	14,u
	ldb	[14,u]
	cmpb	#92	;cmpqi:
	beq	L3
	ldx	14,u
	cmpx	32,u	;cmphi:
	bne	L4
L3:
	ldb	34,u
	dec	34,u
	clra		;zero_extendqihi: R:b -> R:d
	std	,u
	tfr	s,d
	subd	,u	;subhi: R:d -= ,u
	tfr	d,s
	sts	5,u
	ldy	5,u
	leax	0,y
	stx	5,u
	ldd	5,u
	std	12,u
	clr	16,u
	bra	L5
L7:
	ldd	14,u
	addd	#1
	std	14,u
	ldb	[14,u]
	stb	17,u
	; ldb	17,u	; optimization 5
	cmpb	#96	;cmpqi:
	bls	L6
	ldb	17,u
	cmpb	#122	;cmpqi:
	bhi	L6
	ldb	17,u
	addb	#-32
	stb	17,u
L6:
	ldb	16,u
	clra		;zero_extendqihi: R:b -> R:d
	ldy	12,u
	leax	d,y
	ldb	17,u
	stb	,x
	inc	16,u
L5:
	ldb	16,u
	cmpb	34,u	;cmpqi:
	blo	L7
	ldb	34,u
	clra		;zero_extendqihi: R:b -> R:d
	ldy	12,u
	leax	d,y
	ldb	#-128
	stb	,x
L13:
	jsr	___DP_to_C8
	ldx	_current_explosion
	stx	18,u
	; ldx	18,u	; optimization 5
	jsr	__Explosion_Snd
	ldx	_current_music
	stx	20,u
	; ldx	20,u	; optimization 5
	jsr	__Init_Music_chk
	jsr	___Wait_Recal
	jsr	__Do_Sound
	jsr	___Intensity_5F
	ldb	#-120
	stb	,-s
	ldx	10,u
	ldb	#90
	jsr	_print_string
	leas	1,s
	ldb	#-120
	stb	,-s
	ldx	#LC0
	ldb	#50
	jsr	_print_string
	leas	1,s
	ldx	12,u
	ldb	#-120
	stb	,-s
	ldb	#30
	jsr	_print_string
	leas	1,s
	ldb	#-120
	stb	,-s
	ldx	#LC1
	clrb
	jsr	_print_string
	leas	1,s
	ldb	#-120
	stb	,-s
	ldx	35,u
	ldb	#-20
	jsr	_print_long_unsigned_int
	leas	1,s
	ldx	28,u
	cmpx	#0
	lbeq	L8
	ldb	#-120
	stb	,-s
	ldx	#LC2
	ldb	#-50
	jsr	_print_string
	leas	1,s
	ldb	9,u
	stb	4,u
	; ldb	4,u	; optimization 5
	cmpb	#1	;cmpqi:
	beq	L10
	ldb	4,u
	cmpb	#1	;cmpqi:
	blo	L9
	; ldb	4,u; optimization 8
	cmpb	#2	;cmpqi:
	beq	L11
	ldb	4,u
	cmpb	#3	;cmpqi:
	beq	L12
	jmp	L8
L9:
	ldx	28,u
	ldy	30,u
	ldb	,y
	pshs	b
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	,x
	leas	2,s
	bra	L8
L10:
	ldx	28,u
	ldy	30,u
	ldb	,y
	pshs	b
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	,x
	leas	2,s
	bra	L8
L11:
	ldy	28,u
	ldx	30,u
	ldx	,x
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	,y
	leas	1,s
	bra	L8
L12:
	ldy	28,u
	ldx	30,u
	ldx	,x
	ldb	#-120
	stb	,-s
	ldb	#-70
	jsr	,y
	leas	1,s
L8:
	jsr	___Read_Btns
	ldb	_Vec_Buttons
	andb	#1
	tstb
	lbeq	L13
	lds	7,u
	lds	2,u
	leas	22,s
	puls	y,u,pc
