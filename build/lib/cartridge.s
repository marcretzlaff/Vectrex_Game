
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	cartridge.c
	.globl _game_header
	.area	.cartridge
_game_header:
	.byte	0x67
	.byte	0x20
	.byte	0x47
	.byte	0x43
	.byte	0x45
	.byte	0x20
	.byte	0x32
	.byte	0x30
	.byte	0x31
	.byte	0x39
	.byte	0x80
	.word	_Vec_Music_1
	.byte	-8
	.byte	80
	.byte	24
	.byte	-86
	.byte	0x47
	.byte	0x41
	.byte	0x4D
	.byte	0x45
	.byte	0x20
	.byte	0x54
	.byte	0x45
	.byte	0x4D
	.byte	0x50
	.byte	0x4C
	.byte	0x41
	.byte	0x54
	.byte	0x45
	.byte	0x80
	.byte	0x00
