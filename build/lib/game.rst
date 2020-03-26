                              1 
                              2 ;;; gcc for m6809 : Feb 15 2016 21:40:10
                              3 ;;; 4.3.6 (gcc6809)
                              4 ;;; ABI version 1
                              5 ;;; -mint8
                              6 	.module	game.c
                              7 	.globl _current_game
                              8 	.area .data
   C880                       9 _current_game:
   C880 00 00                10 	.word	0	;skip space 9
   C882 00 00                11 	.word	0	;skip space 7
   C884 00 00                12 	.word	0	;skip space 5
   C886 00 00                13 	.word	0	;skip space 3
   C888 00                   14 	.byte	0	;skip space
                             15 	.area .text
                             16 	.globl _game_init
   05E1                      17 _game_init:
   05E1 C6 01         [ 2]   18 	ldb	#1
   05E3 F7 C8 1F      [ 5]   19 	stb	_Vec_Joy_Mux_1_X
   05E6 C6 03         [ 2]   20 	ldb	#3
   05E8 F7 C8 20      [ 5]   21 	stb	_Vec_Joy_Mux_1_Y
   05EB 7F C8 21      [ 7]   22 	clr	_Vec_Joy_Mux_2_X
   05EE 7F C8 22      [ 7]   23 	clr	_Vec_Joy_Mux_2_Y
   05F1 C6 03         [ 2]   24 	ldb	#3
   05F3 F7 C8 82      [ 5]   25 	stb	_current_game+2
   05F6 C6 01         [ 2]   26 	ldb	#1
   05F8 F7 C8 84      [ 5]   27 	stb	_current_game+4
   05FB 7F C8 86      [ 7]   28 	clr	_current_game+6
   05FE 7F C8 87      [ 7]   29 	clr	_current_game+7
   0601 F6 C8 80      [ 5]   30 	ldb	_current_game
   0604 C1 02         [ 2]   31 	cmpb	#2	;cmpqi:
   0606 26 0C         [ 3]   32 	bne	L2
   0608 C6 03         [ 2]   33 	ldb	#3
   060A F7 C8 83      [ 5]   34 	stb	_current_game+3
   060D C6 01         [ 2]   35 	ldb	#1
   060F F7 C8 85      [ 5]   36 	stb	_current_game+5
   0612 20 06         [ 3]   37 	bra	L3
   0614                      38 L2:
   0614 7F C8 83      [ 7]   39 	clr	_current_game+3
   0617 7F C8 85      [ 7]   40 	clr	_current_game+5
   061A                      41 L3:
   061A 7F C8 88      [ 7]   42 	clr	_current_game+8
   061D 39            [ 5]   43 	rts
                             44 	.globl _game_play
   061E                      45 _game_play:
   061E 32 7B         [ 5]   46 	leas	-5,s
   0620 7E 06 87      [ 4]   47 	jmp	L6
   0623                      48 L9:
   0623 BD 07 73      [ 8]   49 	jsr	_level_init
   0626 BD 07 77      [ 8]   50 	jsr	_level_play
   0629 F6 C8 89      [ 5]   51 	ldb	_current_level
   062C C1 02         [ 2]   52 	cmpb	#2	;cmpqi:
   062E 26 1E         [ 3]   53 	bne	L7
   0630 F6 C8 88      [ 5]   54 	ldb	_current_game+8
   0633 E7 61         [ 5]   55 	stb	1,s
                             56 	; ldb	1,s	; optimization 5
   0635 4F            [ 2]   57 	clra		;zero_extendqihi: R:b -> R:d
   0636 1F 01         [ 6]   58 	tfr	d,x
   0638 E6 89 C8 84   [ 8]   59 	ldb	_current_game+4,x
   063C E7 E4         [ 4]   60 	stb	,s
                             61 	; ldb	,s	; optimization 5
   063E 5C            [ 2]   62 	incb
   063F E7 E4         [ 4]   63 	stb	,s
   0641 E6 61         [ 5]   64 	ldb	1,s
   0643 4F            [ 2]   65 	clra		;zero_extendqihi: R:b -> R:d
   0644 1F 01         [ 6]   66 	tfr	d,x
   0646 E6 E4         [ 4]   67 	ldb	,s
   0648 E7 89 C8 84   [ 8]   68 	stb	_current_game+4,x
   064C 20 39         [ 3]   69 	bra	L6
   064E                      70 L7:
   064E F6 C8 88      [ 5]   71 	ldb	_current_game+8
   0651 E7 62         [ 5]   72 	stb	2,s
                             73 	; ldb	2,s	; optimization 5
   0653 4F            [ 2]   74 	clra		;zero_extendqihi: R:b -> R:d
   0654 1F 01         [ 6]   75 	tfr	d,x
   0656 E6 89 C8 82   [ 8]   76 	ldb	_current_game+2,x
   065A E7 E4         [ 4]   77 	stb	,s
                             78 	; ldb	,s	; optimization 5
   065C 5A            [ 2]   79 	decb
   065D E7 E4         [ 4]   80 	stb	,s
   065F E6 62         [ 5]   81 	ldb	2,s
   0661 4F            [ 2]   82 	clra		;zero_extendqihi: R:b -> R:d
   0662 1F 01         [ 6]   83 	tfr	d,x
   0664 E6 E4         [ 4]   84 	ldb	,s
   0666 E7 89 C8 82   [ 8]   85 	stb	_current_game+2,x
   066A E6 62         [ 5]   86 	ldb	2,s
   066C 4F            [ 2]   87 	clra		;zero_extendqihi: R:b -> R:d
   066D 1F 01         [ 6]   88 	tfr	d,x
   066F E6 89 C8 82   [ 8]   89 	ldb	_current_game+2,x
                             90 	; tstb	; optimization 6
   0673 26 03         [ 3]   91 	bne	L8
   0675 BD 06 B0      [ 8]   92 	jsr	_game_over
   0678                      93 L8:
   0678 F6 C8 80      [ 5]   94 	ldb	_current_game
   067B E7 63         [ 5]   95 	stb	3,s
   067D F6 C8 88      [ 5]   96 	ldb	_current_game+8
   0680 E0 63         [ 5]   97 	subb	3,s
   0682 50            [ 2]   98 	negb
   0683 5A            [ 2]   99 	decb
   0684 F7 C8 88      [ 5]  100 	stb	_current_game+8
   0687                     101 L6:
   0687 F6 C8 82      [ 5]  102 	ldb	_current_game+2
   068A E7 E4         [ 4]  103 	stb	,s
   068C F6 C8 83      [ 5]  104 	ldb	_current_game+3
   068F E7 64         [ 5]  105 	stb	4,s
   0691 E6 E4         [ 4]  106 	ldb	,s
   0693 EB 64         [ 5]  107 	addb	4,s
   0695 5D            [ 2]  108 	tstb
   0696 10 26 FF 89   [ 6]  109 	lbne	L9
   069A 32 65         [ 5]  110 	leas	5,s
   069C 39            [ 5]  111 	rts
   069D                     112 LC0:
   069D 47                  113 	.byte	0x47
   069E 41                  114 	.byte	0x41
   069F 4D                  115 	.byte	0x4D
   06A0 45                  116 	.byte	0x45
   06A1 20                  117 	.byte	0x20
   06A2 4F                  118 	.byte	0x4F
   06A3 56                  119 	.byte	0x56
   06A4 45                  120 	.byte	0x45
   06A5 52                  121 	.byte	0x52
   06A6 80                  122 	.byte	0x80
   06A7 00                  123 	.byte	0x00
   06A8                     124 LC1:
   06A8 50                  125 	.byte	0x50
   06A9 4C                  126 	.byte	0x4C
   06AA 41                  127 	.byte	0x41
   06AB 59                  128 	.byte	0x59
   06AC 45                  129 	.byte	0x45
   06AD 52                  130 	.byte	0x52
   06AE 80                  131 	.byte	0x80
   06AF 00                  132 	.byte	0x00
                            133 	.globl _game_over
   06B0                     134 _game_over:
   06B0 34 20         [ 6]  135 	pshs	y
   06B2 32 76         [ 5]  136 	leas	-10,s
   06B4 30 E4         [ 4]  137 	leax	,s
   06B6 BD F8 4F      [ 8]  138 	jsr	___Clear_Score
   06B9 F6 C8 88      [ 5]  139 	ldb	_current_game+8
   06BC 4F            [ 2]  140 	clra		;zero_extendqihi: R:b -> R:d
   06BD 1F 01         [ 6]  141 	tfr	d,x
   06BF E6 89 C8 86   [ 8]  142 	ldb	_current_game+6,x
   06C3 E7 68         [ 5]  143 	stb	8,s
   06C5 30 E4         [ 4]  144 	leax	,s
   06C7 E6 68         [ 5]  145 	ldb	8,s
   06C9 BD 02 86      [ 8]  146 	jsr	__Add_Score_a
   06CC 31 E4         [ 4]  147 	leay	,s
   06CE 8E CB EB      [ 3]  148 	ldx	#_Vec_High_Score
   06D1 34 10         [ 6]  149 	pshs	x
   06D3 30 A4         [ 4]  150 	leax	,y
   06D5 BD 02 9F      [ 8]  151 	jsr	__New_High_Score
   06D8 32 62         [ 5]  152 	leas	2,s
   06DA C6 96         [ 2]  153 	ldb	#-106
   06DC E7 67         [ 5]  154 	stb	7,s
   06DE                     155 L13:
   06DE BD 0D 94      [ 8]  156 	jsr	_Sync
   06E1 BD F2 A5      [ 8]  157 	jsr	___Intensity_5F
   06E4 C6 C0         [ 2]  158 	ldb	#-64
   06E6 E7 E2         [ 6]  159 	stb	,-s
   06E8 8E 06 9D      [ 3]  160 	ldx	#LC0
   06EB 5F            [ 2]  161 	clrb
   06EC BD 09 AD      [ 8]  162 	jsr	_print_string
   06EF 32 61         [ 5]  163 	leas	1,s
   06F1 C6 9C         [ 2]  164 	ldb	#-100
   06F3 E7 E2         [ 6]  165 	stb	,-s
   06F5 8E 06 A8      [ 3]  166 	ldx	#LC1
   06F8 C6 14         [ 2]  167 	ldb	#20
   06FA BD 09 AD      [ 8]  168 	jsr	_print_string
   06FD 32 61         [ 5]  169 	leas	1,s
   06FF F6 C8 88      [ 5]  170 	ldb	_current_game+8
   0702 5C            [ 2]  171 	incb
   0703 34 04         [ 6]  172 	pshs	b
   0705 C6 28         [ 2]  173 	ldb	#40
   0707 E7 E2         [ 6]  174 	stb	,-s
   0709 C6 14         [ 2]  175 	ldb	#20
   070B BD 09 E0      [ 8]  176 	jsr	_print_unsigned_int
   070E 32 62         [ 5]  177 	leas	2,s
   0710 F6 C8 88      [ 5]  178 	ldb	_current_game+8
   0713 4F            [ 2]  179 	clra		;zero_extendqihi: R:b -> R:d
   0714 1F 01         [ 6]  180 	tfr	d,x
   0716 E6 89 C8 82   [ 8]  181 	ldb	_current_game+2,x
   071A E7 69         [ 5]  182 	stb	9,s
   071C C6 69         [ 2]  183 	ldb	#105
   071E E7 E2         [ 6]  184 	stb	,-s
   0720 8E C0 E2      [ 3]  185 	ldx	#-16158
   0723 E6 6A         [ 5]  186 	ldb	10,s
   0725 BD 01 AD      [ 8]  187 	jsr	__Print_Ships
   0728 32 61         [ 5]  188 	leas	1,s
   072A BD F1 BA      [ 8]  189 	jsr	___Read_Btns
   072D 6A 67         [ 7]  190 	dec	7,s
                            191 	; tst	7,s	; optimization 1
   072F 27 0A         [ 3]  192 	beq	L14
   0731 F6 C8 11      [ 5]  193 	ldb	_Vec_Buttons
   0734 C4 08         [ 2]  194 	andb	#8
   0736 5D            [ 2]  195 	tstb
   0737 10 27 FF A3   [ 6]  196 	lbeq	L13
   073B                     197 L14:
   073B 32 6A         [ 5]  198 	leas	10,s
   073D 35 A0         [ 7]  199 	puls	y,pc
                            200 	.globl _game
   073F                     201 _game:
   073F 32 7F         [ 5]  202 	leas	-1,s
   0741 C6 02         [ 2]  203 	ldb	#2
   0743 E7 E2         [ 6]  204 	stb	,-s
   0745 C6 05         [ 2]  205 	ldb	#5
   0747 BD 02 72      [ 8]  206 	jsr	__Select_Game
   074A 32 61         [ 5]  207 	leas	1,s
   074C F6 C8 79      [ 5]  208 	ldb	_Vec_Num_Players
   074F F7 C8 80      [ 5]  209 	stb	_current_game
   0752 F6 C8 7A      [ 5]  210 	ldb	_Vec_Num_Game
   0755 F7 C8 81      [ 5]  211 	stb	_current_game+1
   0758 F6 C8 0F      [ 5]  212 	ldb	_Vec_Btn_State
   075B C4 08         [ 2]  213 	andb	#8
   075D 5D            [ 2]  214 	tstb
   075E 27 0A         [ 3]  215 	beq	L16
   0760 BD 05 E1      [ 8]  216 	jsr	_game_init
   0763 BD 06 1E      [ 8]  217 	jsr	_game_play
   0766 6F E4         [ 6]  218 	clr	,s
   0768 20 04         [ 3]  219 	bra	L17
   076A                     220 L16:
   076A C6 FF         [ 2]  221 	ldb	#-1
   076C E7 E4         [ 4]  222 	stb	,s
   076E                     223 L17:
   076E E6 E4         [ 4]  224 	ldb	,s
   0770 32 61         [ 5]  225 	leas	1,s
   0772 39            [ 5]  226 	rts
ASxxxx Assembler V05.00  (Motorola 6809), page 1.
Hexidecimal [16-Bits]

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  3 L13                00FD R   |   3 L14                015A R
  3 L16                0189 R   |   3 L17                018D R
  3 L2                 0033 R   |   3 L3                 0039 R
  3 L6                 00A6 R   |   3 L7                 006D R
  3 L8                 0097 R   |   3 L9                 0042 R
  3 LC0                00BC R   |   3 LC1                00C7 R
    _Sync              **** GX  |     _Vec_Btn_State     **** GX
    _Vec_Buttons       **** GX  |     _Vec_High_Scor     **** GX
    _Vec_Joy_Mux_1     **** GX  |     _Vec_Joy_Mux_1     **** GX
    _Vec_Joy_Mux_2     **** GX  |     _Vec_Joy_Mux_2     **** GX
    _Vec_Num_Game      **** GX  |     _Vec_Num_Playe     **** GX
    __Add_Score_a      **** GX  |     __New_High_Sco     **** GX
    __Print_Ships      **** GX  |     __Select_Game      **** GX
    ___Clear_Score     **** GX  |     ___Intensity_5     **** GX
    ___Read_Btns       **** GX  |   2 _current_game      0000 GR
    _current_level     **** GX  |   3 _game              015E GR
  3 _game_init         0000 GR  |   3 _game_over         00CF GR
  3 _game_play         003D GR  |     _level_init        **** GX
    _level_play        **** GX  |     _print_string      **** GX
    _print_unsigne     **** GX

ASxxxx Assembler V05.00  (Motorola 6809), page 2.
Hexidecimal [16-Bits]

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .data            size    9   flags  100
   3 .text            size  192   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

