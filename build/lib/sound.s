
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	sound.c
	.globl _music_off
	.area .text
_music_off:
	.word	_Vec_ADSR_FADE4
	.word	_Vec_TWANG_VIBEHL
	.byte	-128
	.byte	-128
	.byte	0
	.byte	-128
	.globl _explosion_off
_explosion_off:
	.byte	63
	.byte	0
	.byte	1
	.byte	-128
	.globl _current_music
	.area .data
_current_music:
	.word	_music_off
	.globl _current_explosion
_current_explosion:
	.word	_explosion_off
	.area .text
	.globl _sound_init
_sound_init:
	ldx	#_music_off
	stx	_current_music
	ldx	#_explosion_off
	stx	_current_explosion
	rts
	.globl _stop_explosion
_stop_explosion:
	clr	_Vec_Expl_Timer
	clr	_Vec_Expl_Flag
	ldx	#_explosion_off
	stx	_current_explosion
	rts
	.globl _stop_music
_stop_music:
	clr	_Vec_Music_Flag
	ldx	#_music_off
	stx	_current_music
	rts
	.globl _play_music
_play_music:
	leas	-2,s
	stx	,s
	jsr	_stop_explosion
	ldx	,s
	stx	_current_music
	ldb	#1
	stb	_Vec_Music_Flag
	leas	2,s
	rts
	.globl _play_explosion
_play_explosion:
	leas	-2,s
	stx	,s
	jsr	___Stop_Sound
	jsr	_stop_music
	ldx	,s
	stx	_current_explosion
	ldb	#-128
	stb	_Vec_Expl_Flag
	leas	2,s
	rts
	.globl _play_tune
_play_tune:
	leas	-13,s
	stb	2,s
	stx	,s
	ldb	2,s
	aslb
	stb	3,s
	ldd	,s
	stb	4,s	;movlsbqihi: R:d -> 4,s
	ldb	3,s
	inc	3,s
	stb	8,s
	ldb	4,s
	stb	7,s
	ldb	8,s
	stb	,-s
	ldb	8,s
	jsr	__Sound_Byte
	leas	1,s
	ldd	,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	stb	5,s	;movlsbqihi: R:d -> 5,s
	ldb	3,s
	stb	10,s
	ldb	5,s
	stb	9,s
	ldb	10,s
	stb	,-s
	ldb	10,s
	jsr	__Sound_Byte
	leas	1,s
	ldb	2,s
	addb	#8
	stb	6,s
	; ldb	6,s	; optimization 5
	stb	12,s
	ldb	15,s
	stb	11,s
	ldb	12,s
	stb	,-s
	ldb	12,s
	jsr	__Sound_Byte
	leas	1,s
	ldb	#7
	stb	,-s
	ldb	#56
	jsr	__Sound_Byte
	leas	1,s
	leas	13,s
	rts
