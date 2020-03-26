                              1 
                              2 ;;; gcc for m6809 : Feb 15 2016 21:40:10
                              3 ;;; 4.3.6 (gcc6809)
                              4 ;;; ABI version 1
                              5 ;;; -mint8
                              6 	.module	utils.c
                              7 	.area .text
                              8 	.globl _Sync
   0D94                       9 _Sync:
   0D94 32 7C         [ 5]   10 	leas	-4,s
   0D96 BD F1 AF      [ 8]   11 	jsr	___DP_to_C8
   0D99 BE C8 8C      [ 6]   12 	ldx	_current_explosion
   0D9C AF E4         [ 5]   13 	stx	,s
                             14 	; ldx	,s	; optimization 5
   0D9E BD 02 EF      [ 8]   15 	jsr	__Explosion_Snd
   0DA1 BE C8 8A      [ 6]   16 	ldx	_current_music
   0DA4 AF 62         [ 6]   17 	stx	2,s
                             18 	; ldx	2,s	; optimization 5
   0DA6 BD 02 CB      [ 8]   19 	jsr	__Init_Music_chk
   0DA9 BD F1 92      [ 8]   20 	jsr	___Wait_Recal
   0DAC BD 02 C4      [ 8]   21 	jsr	__Do_Sound
   0DAF 32 64         [ 5]   22 	leas	4,s
   0DB1 39            [ 5]   23 	rts
ASxxxx Assembler V05.00  (Motorola 6809), page 1.
Hexidecimal [16-Bits]

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 _Sync              0000 GR  |     __Do_Sound         **** GX
    __Explosion_Sn     **** GX  |     __Init_Music_c     **** GX
    ___DP_to_C8        **** GX  |     ___Wait_Recal      **** GX
    _current_explo     **** GX  |     _current_music     **** GX

ASxxxx Assembler V05.00  (Motorola 6809), page 2.
Hexidecimal [16-Bits]

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   1E   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

