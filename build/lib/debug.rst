                              1 
                              2 ;;; gcc for m6809 : Feb 15 2016 21:40:10
                              3 ;;; 4.3.6 (gcc6809)
                              4 ;;; ABI version 1
                              5 ;;; -mint8
                              6 	.module	debug.c
                              7 	.area .text
   0427                       8 LC0:
   0427 46                    9 	.byte	0x46
   0428 49                   10 	.byte	0x49
   0429 4C                   11 	.byte	0x4C
   042A 45                   12 	.byte	0x45
   042B 3A                   13 	.byte	0x3A
   042C 80                   14 	.byte	0x80
   042D 00                   15 	.byte	0x00
   042E                      16 LC1:
   042E 4C                   17 	.byte	0x4C
   042F 49                   18 	.byte	0x49
   0430 4E                   19 	.byte	0x4E
   0431 45                   20 	.byte	0x45
   0432 3A                   21 	.byte	0x3A
   0433 80                   22 	.byte	0x80
   0434 00                   23 	.byte	0x00
   0435                      24 LC2:
   0435 56                   25 	.byte	0x56
   0436 41                   26 	.byte	0x41
   0437 4C                   27 	.byte	0x4C
   0438 55                   28 	.byte	0x55
   0439 45                   29 	.byte	0x45
   043A 3A                   30 	.byte	0x3A
   043B 80                   31 	.byte	0x80
   043C 00                   32 	.byte	0x00
                             33 	.globl __f_debug
   043D                      34 __f_debug:
   043D 34 60         [ 7]   35 	pshs	y,u
   043F 32 E8 EA      [ 5]   36 	leas	-22,s
   0442 33 E4         [ 4]   37 	leau	,s
   0444 AF 4A         [ 6]   38 	stx	10,u
   0446 E7 49         [ 5]   39 	stb	9,u
   0448 10 EF 42      [ 7]   40 	sts	2,u
   044B 30 E4         [ 4]   41 	leax	,s
   044D AF 47         [ 6]   42 	stx	7,u
   044F E6 C8 22      [ 5]   43 	ldb	34,u
   0452 4F            [ 2]   44 	clra		;zero_extendqihi: R:b -> R:d
   0453 ED C4         [ 5]   45 	std	,u
                             46 	; ldd	,u	; optimization 5
   0455 E3 C8 20      [ 7]   47 	addd	32,u
   0458 ED 4E         [ 6]   48 	std	14,u
   045A 6F C8 22      [ 7]   49 	clr	34,u
   045D 20 03         [ 3]   50 	bra	L2
   045F                      51 L4:
   045F 6C C8 22      [ 7]   52 	inc	34,u
   0462                      53 L2:
   0462 EC 4E         [ 6]   54 	ldd	14,u
   0464 C3 FF FF      [ 4]   55 	addd	#-1
   0467 ED 4E         [ 6]   56 	std	14,u
   0469 E6 D8 0E      [ 8]   57 	ldb	[14,u]
   046C C1 5C         [ 2]   58 	cmpb	#92	;cmpqi:
   046E 27 07         [ 3]   59 	beq	L3
   0470 AE 4E         [ 6]   60 	ldx	14,u
   0472 AC C8 20      [ 7]   61 	cmpx	32,u	;cmphi:
   0475 26 E8         [ 3]   62 	bne	L4
   0477                      63 L3:
   0477 E6 C8 22      [ 5]   64 	ldb	34,u
   047A 6A C8 22      [ 7]   65 	dec	34,u
   047D 4F            [ 2]   66 	clra		;zero_extendqihi: R:b -> R:d
   047E ED C4         [ 5]   67 	std	,u
   0480 1F 40         [ 6]   68 	tfr	s,d
   0482 A3 C4         [ 6]   69 	subd	,u	;subhi: R:d -= ,u
   0484 1F 04         [ 6]   70 	tfr	d,s
   0486 10 EF 45      [ 7]   71 	sts	5,u
   0489 10 AE 45      [ 7]   72 	ldy	5,u
   048C 30 20         [ 5]   73 	leax	0,y
   048E AF 45         [ 6]   74 	stx	5,u
   0490 EC 45         [ 6]   75 	ldd	5,u
   0492 ED 4C         [ 6]   76 	std	12,u
   0494 6F C8 10      [ 7]   77 	clr	16,u
   0497 20 31         [ 3]   78 	bra	L5
   0499                      79 L7:
   0499 EC 4E         [ 6]   80 	ldd	14,u
   049B C3 00 01      [ 4]   81 	addd	#1
   049E ED 4E         [ 6]   82 	std	14,u
   04A0 E6 D8 0E      [ 8]   83 	ldb	[14,u]
   04A3 E7 C8 11      [ 5]   84 	stb	17,u
                             85 	; ldb	17,u	; optimization 5
   04A6 C1 60         [ 2]   86 	cmpb	#96	;cmpqi:
   04A8 23 0F         [ 3]   87 	bls	L6
   04AA E6 C8 11      [ 5]   88 	ldb	17,u
   04AD C1 7A         [ 2]   89 	cmpb	#122	;cmpqi:
   04AF 22 08         [ 3]   90 	bhi	L6
   04B1 E6 C8 11      [ 5]   91 	ldb	17,u
   04B4 CB E0         [ 2]   92 	addb	#-32
   04B6 E7 C8 11      [ 5]   93 	stb	17,u
   04B9                      94 L6:
   04B9 E6 C8 10      [ 5]   95 	ldb	16,u
   04BC 4F            [ 2]   96 	clra		;zero_extendqihi: R:b -> R:d
   04BD 10 AE 4C      [ 7]   97 	ldy	12,u
   04C0 30 AB         [ 8]   98 	leax	d,y
   04C2 E6 C8 11      [ 5]   99 	ldb	17,u
   04C5 E7 84         [ 4]  100 	stb	,x
   04C7 6C C8 10      [ 7]  101 	inc	16,u
   04CA                     102 L5:
   04CA E6 C8 10      [ 5]  103 	ldb	16,u
   04CD E1 C8 22      [ 5]  104 	cmpb	34,u	;cmpqi:
   04D0 25 C7         [ 3]  105 	blo	L7
   04D2 E6 C8 22      [ 5]  106 	ldb	34,u
   04D5 4F            [ 2]  107 	clra		;zero_extendqihi: R:b -> R:d
   04D6 10 AE 4C      [ 7]  108 	ldy	12,u
   04D9 30 AB         [ 8]  109 	leax	d,y
   04DB C6 80         [ 2]  110 	ldb	#-128
   04DD E7 84         [ 4]  111 	stb	,x
   04DF                     112 L13:
   04DF BD F1 AF      [ 8]  113 	jsr	___DP_to_C8
   04E2 BE C8 8C      [ 6]  114 	ldx	_current_explosion
   04E5 AF C8 12      [ 6]  115 	stx	18,u
                            116 	; ldx	18,u	; optimization 5
   04E8 BD 02 EF      [ 8]  117 	jsr	__Explosion_Snd
   04EB BE C8 8A      [ 6]  118 	ldx	_current_music
   04EE AF C8 14      [ 6]  119 	stx	20,u
                            120 	; ldx	20,u	; optimization 5
   04F1 BD 02 CB      [ 8]  121 	jsr	__Init_Music_chk
   04F4 BD F1 92      [ 8]  122 	jsr	___Wait_Recal
   04F7 BD 02 C4      [ 8]  123 	jsr	__Do_Sound
   04FA BD F2 A5      [ 8]  124 	jsr	___Intensity_5F
   04FD C6 88         [ 2]  125 	ldb	#-120
   04FF E7 E2         [ 6]  126 	stb	,-s
   0501 AE 4A         [ 6]  127 	ldx	10,u
   0503 C6 5A         [ 2]  128 	ldb	#90
   0505 BD 09 AD      [ 8]  129 	jsr	_print_string
   0508 32 61         [ 5]  130 	leas	1,s
   050A C6 88         [ 2]  131 	ldb	#-120
   050C E7 E2         [ 6]  132 	stb	,-s
   050E 8E 04 27      [ 3]  133 	ldx	#LC0
   0511 C6 32         [ 2]  134 	ldb	#50
   0513 BD 09 AD      [ 8]  135 	jsr	_print_string
   0516 32 61         [ 5]  136 	leas	1,s
   0518 AE 4C         [ 6]  137 	ldx	12,u
   051A C6 88         [ 2]  138 	ldb	#-120
   051C E7 E2         [ 6]  139 	stb	,-s
   051E C6 1E         [ 2]  140 	ldb	#30
   0520 BD 09 AD      [ 8]  141 	jsr	_print_string
   0523 32 61         [ 5]  142 	leas	1,s
   0525 C6 88         [ 2]  143 	ldb	#-120
   0527 E7 E2         [ 6]  144 	stb	,-s
   0529 8E 04 2E      [ 3]  145 	ldx	#LC1
   052C 5F            [ 2]  146 	clrb
   052D BD 09 AD      [ 8]  147 	jsr	_print_string
   0530 32 61         [ 5]  148 	leas	1,s
   0532 C6 88         [ 2]  149 	ldb	#-120
   0534 E7 E2         [ 6]  150 	stb	,-s
   0536 AE C8 23      [ 6]  151 	ldx	35,u
   0539 C6 EC         [ 2]  152 	ldb	#-20
   053B BD 0B 1A      [ 8]  153 	jsr	_print_long_unsigned_int
   053E 32 61         [ 5]  154 	leas	1,s
   0540 AE C8 1C      [ 6]  155 	ldx	28,u
   0543 8C 00 00      [ 4]  156 	cmpx	#0
   0546 10 27 00 7F   [ 6]  157 	lbeq	L8
   054A C6 88         [ 2]  158 	ldb	#-120
   054C E7 E2         [ 6]  159 	stb	,-s
   054E 8E 04 35      [ 3]  160 	ldx	#LC2
   0551 C6 CE         [ 2]  161 	ldb	#-50
   0553 BD 09 AD      [ 8]  162 	jsr	_print_string
   0556 32 61         [ 5]  163 	leas	1,s
   0558 E6 49         [ 5]  164 	ldb	9,u
   055A E7 44         [ 5]  165 	stb	4,u
                            166 	; ldb	4,u	; optimization 5
   055C C1 01         [ 2]  167 	cmpb	#1	;cmpqi:
   055E 27 2A         [ 3]  168 	beq	L10
   0560 E6 44         [ 5]  169 	ldb	4,u
   0562 C1 01         [ 2]  170 	cmpb	#1	;cmpqi:
   0564 25 0D         [ 3]  171 	blo	L9
                            172 	; ldb	4,u; optimization 8
   0566 C1 02         [ 2]  173 	cmpb	#2	;cmpqi:
   0568 27 37         [ 3]  174 	beq	L11
   056A E6 44         [ 5]  175 	ldb	4,u
   056C C1 03         [ 2]  176 	cmpb	#3	;cmpqi:
   056E 27 46         [ 3]  177 	beq	L12
   0570 7E 05 C9      [ 4]  178 	jmp	L8
   0573                     179 L9:
   0573 AE C8 1C      [ 6]  180 	ldx	28,u
   0576 10 AE C8 1E   [ 7]  181 	ldy	30,u
   057A E6 A4         [ 4]  182 	ldb	,y
   057C 34 04         [ 6]  183 	pshs	b
   057E C6 88         [ 2]  184 	ldb	#-120
   0580 E7 E2         [ 6]  185 	stb	,-s
   0582 C6 BA         [ 2]  186 	ldb	#-70
   0584 AD 84         [ 7]  187 	jsr	,x
   0586 32 62         [ 5]  188 	leas	2,s
   0588 20 3F         [ 3]  189 	bra	L8
   058A                     190 L10:
   058A AE C8 1C      [ 6]  191 	ldx	28,u
   058D 10 AE C8 1E   [ 7]  192 	ldy	30,u
   0591 E6 A4         [ 4]  193 	ldb	,y
   0593 34 04         [ 6]  194 	pshs	b
   0595 C6 88         [ 2]  195 	ldb	#-120
   0597 E7 E2         [ 6]  196 	stb	,-s
   0599 C6 BA         [ 2]  197 	ldb	#-70
   059B AD 84         [ 7]  198 	jsr	,x
   059D 32 62         [ 5]  199 	leas	2,s
   059F 20 28         [ 3]  200 	bra	L8
   05A1                     201 L11:
   05A1 10 AE C8 1C   [ 7]  202 	ldy	28,u
   05A5 AE C8 1E      [ 6]  203 	ldx	30,u
   05A8 AE 84         [ 5]  204 	ldx	,x
   05AA C6 88         [ 2]  205 	ldb	#-120
   05AC E7 E2         [ 6]  206 	stb	,-s
   05AE C6 BA         [ 2]  207 	ldb	#-70
   05B0 AD A4         [ 7]  208 	jsr	,y
   05B2 32 61         [ 5]  209 	leas	1,s
   05B4 20 13         [ 3]  210 	bra	L8
   05B6                     211 L12:
   05B6 10 AE C8 1C   [ 7]  212 	ldy	28,u
   05BA AE C8 1E      [ 6]  213 	ldx	30,u
   05BD AE 84         [ 5]  214 	ldx	,x
   05BF C6 88         [ 2]  215 	ldb	#-120
   05C1 E7 E2         [ 6]  216 	stb	,-s
   05C3 C6 BA         [ 2]  217 	ldb	#-70
   05C5 AD A4         [ 7]  218 	jsr	,y
   05C7 32 61         [ 5]  219 	leas	1,s
   05C9                     220 L8:
   05C9 BD F1 BA      [ 8]  221 	jsr	___Read_Btns
   05CC F6 C8 11      [ 5]  222 	ldb	_Vec_Buttons
   05CF C4 01         [ 2]  223 	andb	#1
   05D1 5D            [ 2]  224 	tstb
   05D2 10 27 FF 09   [ 6]  225 	lbeq	L13
   05D6 10 EE 47      [ 7]  226 	lds	7,u
   05D9 10 EE 42      [ 7]  227 	lds	2,u
   05DC 32 E8 16      [ 5]  228 	leas	22,s
   05DF 35 E0         [ 8]  229 	puls	y,u,pc
ASxxxx Assembler V05.00  (Motorola 6809), page 1.
Hexidecimal [16-Bits]

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 L10                0163 R   |   2 L11                017A R
  2 L12                018F R   |   2 L13                00B8 R
  2 L2                 003B R   |   2 L3                 0050 R
  2 L4                 0038 R   |   2 L5                 00A3 R
  2 L6                 0092 R   |   2 L7                 0072 R
  2 L8                 01A2 R   |   2 L9                 014C R
  2 LC0                0000 R   |   2 LC1                0007 R
  2 LC2                000E R   |     _Vec_Buttons       **** GX
    __Do_Sound         **** GX  |     __Explosion_Sn     **** GX
    __Init_Music_c     **** GX  |     ___DP_to_C8        **** GX
    ___Intensity_5     **** GX  |     ___Read_Btns       **** GX
    ___Wait_Recal      **** GX  |   2 __f_debug          0016 GR
    _current_explo     **** GX  |     _current_music     **** GX
    _print_long_un     **** GX  |     _print_string      **** GX

ASxxxx Assembler V05.00  (Motorola 6809), page 2.
Hexidecimal [16-Bits]

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  1BA   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

