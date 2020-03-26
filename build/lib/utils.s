
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	utils.c
	.area .text
	.globl _Sync
_Sync:
	leas	-4,s
	jsr	___DP_to_C8
	ldx	_current_explosion
	stx	,s
	; ldx	,s	; optimization 5
	jsr	__Explosion_Snd
	ldx	_current_music
	stx	2,s
	; ldx	2,s	; optimization 5
	jsr	__Init_Music_chk
	jsr	___Wait_Recal
	jsr	__Do_Sound
	leas	4,s
	rts
