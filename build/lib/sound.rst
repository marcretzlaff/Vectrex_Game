                              1 
                              2 ;;; gcc for m6809 : Feb 15 2016 21:40:10
                              3 ;;; 4.3.6 (gcc6809)
                              4 ;;; ABI version 1
                              5 ;;; -mint8
                              6 	.module	sound.c
                              7 	.globl _music_off
                              8 	.area .text
   0CD6                       9 _music_off:
   0CD6 FE E8                10 	.word	_Vec_ADSR_FADE4
   0CD8 FE B6                11 	.word	_Vec_TWANG_VIBEHL
   0CDA 80                   12 	.byte	-128
   0CDB 80                   13 	.byte	-128
   0CDC 00                   14 	.byte	0
   0CDD 80                   15 	.byte	-128
                             16 	.globl _explosion_off
   0CDE                      17 _explosion_off:
   0CDE 3F                   18 	.byte	63
   0CDF 00                   19 	.byte	0
   0CE0 01                   20 	.byte	1
   0CE1 80                   21 	.byte	-128
                             22 	.globl _current_music
                             23 	.area .data
   C88A                      24 _current_music:
   C88A 0C D6                25 	.word	_music_off
                             26 	.globl _current_explosion
   C88C                      27 _current_explosion:
   C88C 0C DE                28 	.word	_explosion_off
                             29 	.area .text
                             30 	.globl _sound_init
   0CE2                      31 _sound_init:
   0CE2 8E 0C D6      [ 3]   32 	ldx	#_music_off
   0CE5 BF C8 8A      [ 6]   33 	stx	_current_music
   0CE8 8E 0C DE      [ 3]   34 	ldx	#_explosion_off
   0CEB BF C8 8C      [ 6]   35 	stx	_current_explosion
   0CEE 39            [ 5]   36 	rts
                             37 	.globl _stop_explosion
   0CEF                      38 _stop_explosion:
   0CEF 7F C8 77      [ 7]   39 	clr	_Vec_Expl_Timer
   0CF2 7F C8 67      [ 7]   40 	clr	_Vec_Expl_Flag
   0CF5 8E 0C DE      [ 3]   41 	ldx	#_explosion_off
   0CF8 BF C8 8C      [ 6]   42 	stx	_current_explosion
   0CFB 39            [ 5]   43 	rts
                             44 	.globl _stop_music
   0CFC                      45 _stop_music:
   0CFC 7F C8 56      [ 7]   46 	clr	_Vec_Music_Flag
   0CFF 8E 0C D6      [ 3]   47 	ldx	#_music_off
   0D02 BF C8 8A      [ 6]   48 	stx	_current_music
   0D05 39            [ 5]   49 	rts
                             50 	.globl _play_music
   0D06                      51 _play_music:
   0D06 32 7E         [ 5]   52 	leas	-2,s
   0D08 AF E4         [ 5]   53 	stx	,s
   0D0A BD 0C EF      [ 8]   54 	jsr	_stop_explosion
   0D0D AE E4         [ 5]   55 	ldx	,s
   0D0F BF C8 8A      [ 6]   56 	stx	_current_music
   0D12 C6 01         [ 2]   57 	ldb	#1
   0D14 F7 C8 56      [ 5]   58 	stb	_Vec_Music_Flag
   0D17 32 62         [ 5]   59 	leas	2,s
   0D19 39            [ 5]   60 	rts
                             61 	.globl _play_explosion
   0D1A                      62 _play_explosion:
   0D1A 32 7E         [ 5]   63 	leas	-2,s
   0D1C AF E4         [ 5]   64 	stx	,s
   0D1E BD F7 42      [ 8]   65 	jsr	___Stop_Sound
   0D21 BD 0C FC      [ 8]   66 	jsr	_stop_music
   0D24 AE E4         [ 5]   67 	ldx	,s
   0D26 BF C8 8C      [ 6]   68 	stx	_current_explosion
   0D29 C6 80         [ 2]   69 	ldb	#-128
   0D2B F7 C8 67      [ 5]   70 	stb	_Vec_Expl_Flag
   0D2E 32 62         [ 5]   71 	leas	2,s
   0D30 39            [ 5]   72 	rts
                             73 	.globl _play_tune
   0D31                      74 _play_tune:
   0D31 32 73         [ 5]   75 	leas	-13,s
   0D33 E7 62         [ 5]   76 	stb	2,s
   0D35 AF E4         [ 5]   77 	stx	,s
   0D37 E6 62         [ 5]   78 	ldb	2,s
   0D39 58            [ 2]   79 	aslb
   0D3A E7 63         [ 5]   80 	stb	3,s
   0D3C EC E4         [ 5]   81 	ldd	,s
   0D3E E7 64         [ 5]   82 	stb	4,s	;movlsbqihi: R:d -> 4,s
   0D40 E6 63         [ 5]   83 	ldb	3,s
   0D42 6C 63         [ 7]   84 	inc	3,s
   0D44 E7 68         [ 5]   85 	stb	8,s
   0D46 E6 64         [ 5]   86 	ldb	4,s
   0D48 E7 67         [ 5]   87 	stb	7,s
   0D4A E6 68         [ 5]   88 	ldb	8,s
   0D4C E7 E2         [ 6]   89 	stb	,-s
   0D4E E6 68         [ 5]   90 	ldb	8,s
   0D50 BD 02 A8      [ 8]   91 	jsr	__Sound_Byte
   0D53 32 61         [ 5]   92 	leas	1,s
   0D55 EC E4         [ 5]   93 	ldd	,s
   0D57 1F 89         [ 6]   94 	tfr	a,b
   0D59 4F            [ 2]   95 	clra		;zero_extendqihi: R:b -> R:d
   0D5A E7 65         [ 5]   96 	stb	5,s	;movlsbqihi: R:d -> 5,s
   0D5C E6 63         [ 5]   97 	ldb	3,s
   0D5E E7 6A         [ 5]   98 	stb	10,s
   0D60 E6 65         [ 5]   99 	ldb	5,s
   0D62 E7 69         [ 5]  100 	stb	9,s
   0D64 E6 6A         [ 5]  101 	ldb	10,s
   0D66 E7 E2         [ 6]  102 	stb	,-s
   0D68 E6 6A         [ 5]  103 	ldb	10,s
   0D6A BD 02 A8      [ 8]  104 	jsr	__Sound_Byte
   0D6D 32 61         [ 5]  105 	leas	1,s
   0D6F E6 62         [ 5]  106 	ldb	2,s
   0D71 CB 08         [ 2]  107 	addb	#8
   0D73 E7 66         [ 5]  108 	stb	6,s
                            109 	; ldb	6,s	; optimization 5
   0D75 E7 6C         [ 5]  110 	stb	12,s
   0D77 E6 6F         [ 5]  111 	ldb	15,s
   0D79 E7 6B         [ 5]  112 	stb	11,s
   0D7B E6 6C         [ 5]  113 	ldb	12,s
   0D7D E7 E2         [ 6]  114 	stb	,-s
   0D7F E6 6C         [ 5]  115 	ldb	12,s
   0D81 BD 02 A8      [ 8]  116 	jsr	__Sound_Byte
   0D84 32 61         [ 5]  117 	leas	1,s
   0D86 C6 07         [ 2]  118 	ldb	#7
   0D88 E7 E2         [ 6]  119 	stb	,-s
   0D8A C6 38         [ 2]  120 	ldb	#56
   0D8C BD 02 A8      [ 8]  121 	jsr	__Sound_Byte
   0D8F 32 61         [ 5]  122 	leas	1,s
   0D91 32 6D         [ 5]  123 	leas	13,s
   0D93 39            [ 5]  124 	rts
ASxxxx Assembler V05.00  (Motorola 6809), page 1.
Hexidecimal [16-Bits]

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
    _Vec_ADSR_FADE     **** GX  |     _Vec_Expl_Flag     **** GX
    _Vec_Expl_Time     **** GX  |     _Vec_Music_Fla     **** GX
    _Vec_TWANG_VIB     **** GX  |     __Sound_Byte       **** GX
    ___Stop_Sound      **** GX  |   3 _current_explo     0002 GR
  3 _current_music     0000 GR  |   2 _explosion_off     0008 GR
  2 _music_off         0000 GR  |   2 _play_explosio     0044 GR
  2 _play_music        0030 GR  |   2 _play_tune         005B GR
  2 _sound_init        000C GR  |   2 _stop_explosio     0019 GR
  2 _stop_music        0026 GR

ASxxxx Assembler V05.00  (Motorola 6809), page 2.
Hexidecimal [16-Bits]

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size   BE   flags  100
   3 .data            size    4   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

