
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	game.c
	.globl _current_game
	.area .data
_current_game:
	.word	0	;skip space 9
	.word	0	;skip space 7
	.word	0	;skip space 5
	.word	0	;skip space 3
	.byte	0	;skip space
	.area .text
	.globl _game_init
_game_init:
	ldb	#1
	stb	_Vec_Joy_Mux_1_X
	ldb	#3
	stb	_Vec_Joy_Mux_1_Y
	clr	_Vec_Joy_Mux_2_X
	clr	_Vec_Joy_Mux_2_Y
	ldb	#3
	stb	_current_game+2
	ldb	#1
	stb	_current_game+4
	clr	_current_game+6
	clr	_current_game+7
	ldb	_current_game
	cmpb	#2	;cmpqi:
	bne	L2
	ldb	#3
	stb	_current_game+3
	ldb	#1
	stb	_current_game+5
	bra	L3
L2:
	clr	_current_game+3
	clr	_current_game+5
L3:
	clr	_current_game+8
	rts
	.globl _game_play
_game_play:
	leas	-5,s
	jmp	L6
L9:
	jsr	_level_init
	jsr	_level_play
	ldb	_current_level
	cmpb	#2	;cmpqi:
	bne	L7
	ldb	_current_game+8
	stb	1,s
	; ldb	1,s	; optimization 5
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_current_game+4,x
	stb	,s
	; ldb	,s	; optimization 5
	incb
	stb	,s
	ldb	1,s
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	,s
	stb	_current_game+4,x
	bra	L6
L7:
	ldb	_current_game+8
	stb	2,s
	; ldb	2,s	; optimization 5
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_current_game+2,x
	stb	,s
	; ldb	,s	; optimization 5
	decb
	stb	,s
	ldb	2,s
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	,s
	stb	_current_game+2,x
	ldb	2,s
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_current_game+2,x
	; tstb	; optimization 6
	bne	L8
	jsr	_game_over
L8:
	ldb	_current_game
	stb	3,s
	ldb	_current_game+8
	subb	3,s
	negb
	decb
	stb	_current_game+8
L6:
	ldb	_current_game+2
	stb	,s
	ldb	_current_game+3
	stb	4,s
	ldb	,s
	addb	4,s
	tstb
	lbne	L9
	leas	5,s
	rts
LC0:
	.byte	0x47
	.byte	0x41
	.byte	0x4D
	.byte	0x45
	.byte	0x20
	.byte	0x4F
	.byte	0x56
	.byte	0x45
	.byte	0x52
	.byte	0x80
	.byte	0x00
LC1:
	.byte	0x50
	.byte	0x4C
	.byte	0x41
	.byte	0x59
	.byte	0x45
	.byte	0x52
	.byte	0x80
	.byte	0x00
	.globl _game_over
_game_over:
	pshs	y
	leas	-10,s
	leax	,s
	jsr	___Clear_Score
	ldb	_current_game+8
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_current_game+6,x
	stb	8,s
	leax	,s
	ldb	8,s
	jsr	__Add_Score_a
	leay	,s
	ldx	#_Vec_High_Score
	pshs	x
	leax	,y
	jsr	__New_High_Score
	leas	2,s
	ldb	#-106
	stb	7,s
L13:
	jsr	_Sync
	jsr	___Intensity_5F
	ldb	#-64
	stb	,-s
	ldx	#LC0
	clrb
	jsr	_print_string
	leas	1,s
	ldb	#-100
	stb	,-s
	ldx	#LC1
	ldb	#20
	jsr	_print_string
	leas	1,s
	ldb	_current_game+8
	incb
	pshs	b
	ldb	#40
	stb	,-s
	ldb	#20
	jsr	_print_unsigned_int
	leas	2,s
	ldb	_current_game+8
	clra		;zero_extendqihi: R:b -> R:d
	tfr	d,x
	ldb	_current_game+2,x
	stb	9,s
	ldb	#105
	stb	,-s
	ldx	#-16158
	ldb	10,s
	jsr	__Print_Ships
	leas	1,s
	jsr	___Read_Btns
	dec	7,s
	; tst	7,s	; optimization 1
	beq	L14
	ldb	_Vec_Buttons
	andb	#8
	tstb
	lbeq	L13
L14:
	leas	10,s
	puls	y,pc
	.globl _game
_game:
	leas	-1,s
	ldb	#2
	stb	,-s
	ldb	#5
	jsr	__Select_Game
	leas	1,s
	ldb	_Vec_Num_Players
	stb	_current_game
	ldb	_Vec_Num_Game
	stb	_current_game+1
	ldb	_Vec_Btn_State
	andb	#8
	tstb
	beq	L16
	jsr	_game_init
	jsr	_game_play
	clr	,s
	bra	L17
L16:
	ldb	#-1
	stb	,s
L17:
	ldb	,s
	leas	1,s
	rts
