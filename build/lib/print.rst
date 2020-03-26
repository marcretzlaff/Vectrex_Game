                              1 
                              2 ;;; gcc for m6809 : Feb 15 2016 21:40:10
                              3 ;;; 4.3.6 (gcc6809)
                              4 ;;; ABI version 1
                              5 ;;; -mint8
                              6 	.module	print.c
                              7 	.area .text
                              8 	.globl _print_string
   09AD                       9 _print_string:
   09AD 32 77         [ 5]   10 	leas	-9,s
   09AF E7 62         [ 5]   11 	stb	2,s
   09B1 AF E4         [ 5]   12 	stx	,s
   09B3 E6 62         [ 5]   13 	ldb	2,s
   09B5 E7 64         [ 5]   14 	stb	4,s
   09B7 E6 6B         [ 5]   15 	ldb	11,s
   09B9 E7 63         [ 5]   16 	stb	3,s
   09BB C6 CC         [ 2]   17 	ldb	#-52
   09BD D7 0C         [ 4]   18 	stb	*_dp_VIA_cntl
   09BF C6 7F         [ 2]   19 	ldb	#127
   09C1 D7 04         [ 4]   20 	stb	*_dp_VIA_t1_cnt_lo
   09C3 E6 64         [ 5]   21 	ldb	4,s
   09C5 E7 66         [ 5]   22 	stb	6,s
   09C7 E6 63         [ 5]   23 	ldb	3,s
   09C9 E7 65         [ 5]   24 	stb	5,s
   09CB E6 66         [ 5]   25 	ldb	6,s
   09CD E7 E2         [ 6]   26 	stb	,-s
   09CF E6 66         [ 5]   27 	ldb	6,s
   09D1 BD 03 02      [ 8]   28 	jsr	__Moveto_d
   09D4 32 61         [ 5]   29 	leas	1,s
   09D6 AE E4         [ 5]   30 	ldx	,s
   09D8 AF 67         [ 6]   31 	stx	7,s
                             32 	; ldx	7,s	; optimization 5
   09DA BD 01 B2      [ 8]   33 	jsr	__Print_Str
   09DD 32 69         [ 5]   34 	leas	9,s
   09DF 39            [ 5]   35 	rts
                             36 	.globl _print_unsigned_int
   09E0                      37 _print_unsigned_int:
   09E0 32 71         [ 5]   38 	leas	-15,s
   09E2 E7 65         [ 5]   39 	stb	5,s
   09E4 C6 80         [ 2]   40 	ldb	#-128
   09E6 E7 69         [ 5]   41 	stb	9,s
   09E8 C6 02         [ 2]   42 	ldb	#2
   09EA E7 6A         [ 5]   43 	stb	10,s
   09EC                      44 L4:
   09EC E6 6A         [ 5]   45 	ldb	10,s
   09EE E7 63         [ 5]   46 	stb	3,s
   09F0 E6 E8 12      [ 5]   47 	ldb	18,s
   09F3 4F            [ 2]   48 	clra		;zero_extendqihi: R:b -> R:d
   09F4 ED E4         [ 5]   49 	std	,s
   09F6 8E 00 0A      [ 3]   50 	ldx	#10
   09F9 34 10         [ 6]   51 	pshs	x
   09FB AE 62         [ 6]   52 	ldx	2,s
   09FD BD 0D B2      [ 8]   53 	jsr	_umodhi3
   0A00 32 62         [ 5]   54 	leas	2,s
   0A02 1F 10         [ 6]   55 	tfr	x,d	;movlsbqihi: R:x -> R:b
   0A04 E7 62         [ 5]   56 	stb	2,s
                             57 	; ldb	2,s	; optimization 5
   0A06 CB 30         [ 2]   58 	addb	#48
   0A08 E7 64         [ 5]   59 	stb	4,s
   0A0A E6 63         [ 5]   60 	ldb	3,s
   0A0C 4F            [ 2]   61 	clra		;zero_extendqihi: R:b -> R:d
   0A0D ED E4         [ 5]   62 	std	,s
   0A0F 30 66         [ 5]   63 	leax	6,s
   0A11 1E 01         [ 8]   64 	exg	d,x
   0A13 E3 E4         [ 6]   65 	addd	,s
   0A15 1E 01         [ 8]   66 	exg	d,x
   0A17 E6 64         [ 5]   67 	ldb	4,s
   0A19 E7 84         [ 4]   68 	stb	,x
   0A1B 6A 6A         [ 7]   69 	dec	10,s
   0A1D E6 E8 12      [ 5]   70 	ldb	18,s
   0A20 4F            [ 2]   71 	clra		;zero_extendqihi: R:b -> R:d
   0A21 ED E4         [ 5]   72 	std	,s
   0A23 8E 00 0A      [ 3]   73 	ldx	#10
   0A26 34 10         [ 6]   74 	pshs	x
   0A28 AE 62         [ 6]   75 	ldx	2,s
   0A2A BD 0D C3      [ 8]   76 	jsr	_udivhi3
   0A2D 32 62         [ 5]   77 	leas	2,s
   0A2F 1F 10         [ 6]   78 	tfr	x,d
   0A31 E7 E8 12      [ 5]   79 	stb	18,s	;movlsbqihi: R:d -> 18,s
   0A34 E6 6A         [ 5]   80 	ldb	10,s
   0A36 C1 FF         [ 2]   81 	cmpb	#-1	;cmpqi:
   0A38 26 B2         [ 3]   82 	bne	L4
   0A3A E6 65         [ 5]   83 	ldb	5,s
   0A3C E7 6C         [ 5]   84 	stb	12,s
   0A3E E6 E8 11      [ 5]   85 	ldb	17,s
   0A41 E7 6B         [ 5]   86 	stb	11,s
   0A43 C6 CC         [ 2]   87 	ldb	#-52
   0A45 D7 0C         [ 4]   88 	stb	*_dp_VIA_cntl
   0A47 C6 7F         [ 2]   89 	ldb	#127
   0A49 D7 04         [ 4]   90 	stb	*_dp_VIA_t1_cnt_lo
   0A4B E6 6C         [ 5]   91 	ldb	12,s
   0A4D E7 6E         [ 5]   92 	stb	14,s
   0A4F E6 6B         [ 5]   93 	ldb	11,s
   0A51 E7 6D         [ 5]   94 	stb	13,s
   0A53 E6 6E         [ 5]   95 	ldb	14,s
   0A55 E7 E2         [ 6]   96 	stb	,-s
   0A57 E6 6E         [ 5]   97 	ldb	14,s
   0A59 BD 03 02      [ 8]   98 	jsr	__Moveto_d
   0A5C 32 61         [ 5]   99 	leas	1,s
   0A5E 30 66         [ 5]  100 	leax	6,s
   0A60 BD 01 B2      [ 8]  101 	jsr	__Print_Str
   0A63 32 6F         [ 5]  102 	leas	15,s
   0A65 39            [ 5]  103 	rts
                            104 	.globl _print_signed_int
   0A66                     105 _print_signed_int:
   0A66 32 E8 ED      [ 5]  106 	leas	-19,s
   0A69 E7 67         [ 5]  107 	stb	7,s
   0A6B 6D E8 16      [ 7]  108 	tst	22,s
   0A6E 2C 06         [ 3]  109 	bge	L7
   0A70 C6 2D         [ 2]  110 	ldb	#45
   0A72 E7 63         [ 5]  111 	stb	3,s
   0A74 20 04         [ 3]  112 	bra	L8
   0A76                     113 L7:
   0A76 C6 2B         [ 2]  114 	ldb	#43
   0A78 E7 63         [ 5]  115 	stb	3,s
   0A7A                     116 L8:
   0A7A E6 63         [ 5]  117 	ldb	3,s
   0A7C E7 68         [ 5]  118 	stb	8,s
   0A7E C6 80         [ 2]  119 	ldb	#-128
   0A80 E7 6C         [ 5]  120 	stb	12,s
   0A82 C6 03         [ 2]  121 	ldb	#3
   0A84 E7 6D         [ 5]  122 	stb	13,s
   0A86 6D E8 16      [ 7]  123 	tst	22,s
   0A89 2C 0A         [ 3]  124 	bge	L9
   0A8B E6 E8 16      [ 5]  125 	ldb	22,s
   0A8E E7 62         [ 5]  126 	stb	2,s
                            127 	; ldb	2,s	; optimization 5
   0A90 50            [ 2]  128 	negb
   0A91 E7 64         [ 5]  129 	stb	4,s
   0A93 20 05         [ 3]  130 	bra	L10
   0A95                     131 L9:
   0A95 E6 E8 16      [ 5]  132 	ldb	22,s
   0A98 E7 64         [ 5]  133 	stb	4,s
   0A9A                     134 L10:
   0A9A E6 64         [ 5]  135 	ldb	4,s
   0A9C E7 6E         [ 5]  136 	stb	14,s
   0A9E                     137 L11:
   0A9E E6 6D         [ 5]  138 	ldb	13,s
   0AA0 E7 65         [ 5]  139 	stb	5,s
   0AA2 E6 6E         [ 5]  140 	ldb	14,s
   0AA4 4F            [ 2]  141 	clra		;zero_extendqihi: R:b -> R:d
   0AA5 ED E4         [ 5]  142 	std	,s
   0AA7 8E 00 0A      [ 3]  143 	ldx	#10
   0AAA 34 10         [ 6]  144 	pshs	x
   0AAC AE 62         [ 6]  145 	ldx	2,s
   0AAE BD 0D B2      [ 8]  146 	jsr	_umodhi3
   0AB1 32 62         [ 5]  147 	leas	2,s
   0AB3 1F 10         [ 6]  148 	tfr	x,d	;movlsbqihi: R:x -> R:b
   0AB5 E7 62         [ 5]  149 	stb	2,s
                            150 	; ldb	2,s	; optimization 5
   0AB7 CB 30         [ 2]  151 	addb	#48
   0AB9 E7 66         [ 5]  152 	stb	6,s
   0ABB E6 65         [ 5]  153 	ldb	5,s
   0ABD 4F            [ 2]  154 	clra		;zero_extendqihi: R:b -> R:d
   0ABE ED E4         [ 5]  155 	std	,s
   0AC0 30 68         [ 5]  156 	leax	8,s
   0AC2 1E 01         [ 8]  157 	exg	d,x
   0AC4 E3 E4         [ 6]  158 	addd	,s
   0AC6 1E 01         [ 8]  159 	exg	d,x
   0AC8 E6 66         [ 5]  160 	ldb	6,s
   0ACA E7 84         [ 4]  161 	stb	,x
   0ACC 6A 6D         [ 7]  162 	dec	13,s
   0ACE E6 6E         [ 5]  163 	ldb	14,s
   0AD0 4F            [ 2]  164 	clra		;zero_extendqihi: R:b -> R:d
   0AD1 ED E4         [ 5]  165 	std	,s
   0AD3 8E 00 0A      [ 3]  166 	ldx	#10
   0AD6 34 10         [ 6]  167 	pshs	x
   0AD8 AE 62         [ 6]  168 	ldx	2,s
   0ADA BD 0D C3      [ 8]  169 	jsr	_udivhi3
   0ADD 32 62         [ 5]  170 	leas	2,s
   0ADF 1F 10         [ 6]  171 	tfr	x,d
   0AE1 E7 6E         [ 5]  172 	stb	14,s	;movlsbqihi: R:d -> 14,s
   0AE3 6D 6D         [ 7]  173 	tst	13,s
   0AE5 26 B7         [ 3]  174 	bne	L11
   0AE7 E6 67         [ 5]  175 	ldb	7,s
   0AE9 E7 E8 10      [ 5]  176 	stb	16,s
   0AEC E6 E8 15      [ 5]  177 	ldb	21,s
   0AEF E7 6F         [ 5]  178 	stb	15,s
   0AF1 C6 CC         [ 2]  179 	ldb	#-52
   0AF3 D7 0C         [ 4]  180 	stb	*_dp_VIA_cntl
   0AF5 C6 7F         [ 2]  181 	ldb	#127
   0AF7 D7 04         [ 4]  182 	stb	*_dp_VIA_t1_cnt_lo
   0AF9 E6 E8 10      [ 5]  183 	ldb	16,s
   0AFC E7 E8 12      [ 5]  184 	stb	18,s
   0AFF E6 6F         [ 5]  185 	ldb	15,s
   0B01 E7 E8 11      [ 5]  186 	stb	17,s
   0B04 E6 E8 12      [ 5]  187 	ldb	18,s
   0B07 E7 E2         [ 6]  188 	stb	,-s
   0B09 E6 E8 12      [ 5]  189 	ldb	18,s
   0B0C BD 03 02      [ 8]  190 	jsr	__Moveto_d
   0B0F 32 61         [ 5]  191 	leas	1,s
   0B11 30 68         [ 5]  192 	leax	8,s
   0B13 BD 01 B2      [ 8]  193 	jsr	__Print_Str
   0B16 32 E8 13      [ 5]  194 	leas	19,s
   0B19 39            [ 5]  195 	rts
                            196 	.globl _print_long_unsigned_int
   0B1A                     197 _print_long_unsigned_int:
   0B1A 34 20         [ 6]  198 	pshs	y
   0B1C 32 E8 ED      [ 5]  199 	leas	-19,s
   0B1F E7 67         [ 5]  200 	stb	7,s
   0B21 AF 65         [ 6]  201 	stx	5,s
   0B23 C6 80         [ 2]  202 	ldb	#-128
   0B25 E7 6D         [ 5]  203 	stb	13,s
   0B27 C6 04         [ 2]  204 	ldb	#4
   0B29 E7 6E         [ 5]  205 	stb	14,s
   0B2B                     206 L14:
   0B2B E6 6E         [ 5]  207 	ldb	14,s
   0B2D E7 63         [ 5]  208 	stb	3,s
   0B2F 10 AE 65      [ 7]  209 	ldy	5,s
   0B32 8E 00 0A      [ 3]  210 	ldx	#10
   0B35 34 10         [ 6]  211 	pshs	x
   0B37 30 A4         [ 4]  212 	leax	,y
   0B39 BD 0D B2      [ 8]  213 	jsr	_umodhi3
   0B3C 32 62         [ 5]  214 	leas	2,s
   0B3E 1F 10         [ 6]  215 	tfr	x,d	;movlsbqihi: R:x -> R:b
   0B40 E7 62         [ 5]  216 	stb	2,s
                            217 	; ldb	2,s	; optimization 5
   0B42 CB 30         [ 2]  218 	addb	#48
   0B44 E7 64         [ 5]  219 	stb	4,s
   0B46 E6 63         [ 5]  220 	ldb	3,s
   0B48 4F            [ 2]  221 	clra		;zero_extendqihi: R:b -> R:d
   0B49 ED E4         [ 5]  222 	std	,s
   0B4B 30 68         [ 5]  223 	leax	8,s
   0B4D 1E 01         [ 8]  224 	exg	d,x
   0B4F E3 E4         [ 6]  225 	addd	,s
   0B51 1E 01         [ 8]  226 	exg	d,x
   0B53 E6 64         [ 5]  227 	ldb	4,s
   0B55 E7 84         [ 4]  228 	stb	,x
   0B57 6A 6E         [ 7]  229 	dec	14,s
   0B59 10 AE 65      [ 7]  230 	ldy	5,s
   0B5C 8E 00 0A      [ 3]  231 	ldx	#10
   0B5F 34 10         [ 6]  232 	pshs	x
   0B61 30 A4         [ 4]  233 	leax	,y
   0B63 BD 0D C3      [ 8]  234 	jsr	_udivhi3
   0B66 32 62         [ 5]  235 	leas	2,s
   0B68 AF 65         [ 6]  236 	stx	5,s
   0B6A E6 6E         [ 5]  237 	ldb	14,s
   0B6C C1 FF         [ 2]  238 	cmpb	#-1	;cmpqi:
   0B6E 26 BB         [ 3]  239 	bne	L14
   0B70 E6 67         [ 5]  240 	ldb	7,s
   0B72 E7 E8 10      [ 5]  241 	stb	16,s
   0B75 E6 E8 17      [ 5]  242 	ldb	23,s
   0B78 E7 6F         [ 5]  243 	stb	15,s
   0B7A C6 CC         [ 2]  244 	ldb	#-52
   0B7C D7 0C         [ 4]  245 	stb	*_dp_VIA_cntl
   0B7E C6 7F         [ 2]  246 	ldb	#127
   0B80 D7 04         [ 4]  247 	stb	*_dp_VIA_t1_cnt_lo
   0B82 E6 E8 10      [ 5]  248 	ldb	16,s
   0B85 E7 E8 12      [ 5]  249 	stb	18,s
   0B88 E6 6F         [ 5]  250 	ldb	15,s
   0B8A E7 E8 11      [ 5]  251 	stb	17,s
   0B8D E6 E8 12      [ 5]  252 	ldb	18,s
   0B90 E7 E2         [ 6]  253 	stb	,-s
   0B92 E6 E8 12      [ 5]  254 	ldb	18,s
   0B95 BD 03 02      [ 8]  255 	jsr	__Moveto_d
   0B98 32 61         [ 5]  256 	leas	1,s
   0B9A 30 68         [ 5]  257 	leax	8,s
   0B9C BD 01 B2      [ 8]  258 	jsr	__Print_Str
   0B9F 32 E8 13      [ 5]  259 	leas	19,s
   0BA2 35 A0         [ 7]  260 	puls	y,pc
                            261 	.globl _print_long_signed_int
   0BA4                     262 _print_long_signed_int:
   0BA4 34 20         [ 6]  263 	pshs	y
   0BA6 32 E8 E7      [ 5]  264 	leas	-25,s
   0BA9 E7 6A         [ 5]  265 	stb	10,s
   0BAB AF 68         [ 6]  266 	stx	8,s
                            267 	; ldx	8,s	; optimization 5
   0BAD 8C 00 00      [ 4]  268 	cmpx	#0
   0BB0 2C 06         [ 3]  269 	bge	L17
   0BB2 C6 2D         [ 2]  270 	ldb	#45
   0BB4 E7 63         [ 5]  271 	stb	3,s
   0BB6 20 04         [ 3]  272 	bra	L18
   0BB8                     273 L17:
   0BB8 C6 2B         [ 2]  274 	ldb	#43
   0BBA E7 63         [ 5]  275 	stb	3,s
   0BBC                     276 L18:
   0BBC E6 63         [ 5]  277 	ldb	3,s
   0BBE E7 6B         [ 5]  278 	stb	11,s
   0BC0 C6 80         [ 2]  279 	ldb	#-128
   0BC2 E7 E8 11      [ 5]  280 	stb	17,s
   0BC5 C6 05         [ 2]  281 	ldb	#5
   0BC7 E7 E8 12      [ 5]  282 	stb	18,s
   0BCA AE 68         [ 6]  283 	ldx	8,s
   0BCC 8C 00 00      [ 4]  284 	cmpx	#0
   0BCF 2C 0C         [ 3]  285 	bge	L19
   0BD1 AE 68         [ 6]  286 	ldx	8,s
   0BD3 1F 10         [ 6]  287 	tfr	x,d
   0BD5 40            [ 2]  288 	nega
   0BD6 50            [ 2]  289 	negb
   0BD7 82 00         [ 2]  290 	sbca	#0
   0BD9 ED 64         [ 6]  291 	std	4,s
   0BDB 20 04         [ 3]  292 	bra	L20
   0BDD                     293 L19:
   0BDD AE 68         [ 6]  294 	ldx	8,s
   0BDF AF 64         [ 6]  295 	stx	4,s
   0BE1                     296 L20:
   0BE1 EC 64         [ 6]  297 	ldd	4,s
   0BE3 ED E8 13      [ 6]  298 	std	19,s
   0BE6                     299 L21:
   0BE6 E6 E8 12      [ 5]  300 	ldb	18,s
   0BE9 E7 66         [ 5]  301 	stb	6,s
   0BEB 10 AE E8 13   [ 7]  302 	ldy	19,s
   0BEF 8E 00 0A      [ 3]  303 	ldx	#10
   0BF2 34 10         [ 6]  304 	pshs	x
   0BF4 30 A4         [ 4]  305 	leax	,y
   0BF6 BD 0D B2      [ 8]  306 	jsr	_umodhi3
   0BF9 32 62         [ 5]  307 	leas	2,s
   0BFB 1F 10         [ 6]  308 	tfr	x,d	;movlsbqihi: R:x -> R:b
   0BFD E7 62         [ 5]  309 	stb	2,s
                            310 	; ldb	2,s	; optimization 5
   0BFF CB 30         [ 2]  311 	addb	#48
   0C01 E7 67         [ 5]  312 	stb	7,s
   0C03 E6 66         [ 5]  313 	ldb	6,s
   0C05 4F            [ 2]  314 	clra		;zero_extendqihi: R:b -> R:d
   0C06 ED E4         [ 5]  315 	std	,s
   0C08 30 6B         [ 5]  316 	leax	11,s
   0C0A 1E 01         [ 8]  317 	exg	d,x
   0C0C E3 E4         [ 6]  318 	addd	,s
   0C0E 1E 01         [ 8]  319 	exg	d,x
   0C10 E6 67         [ 5]  320 	ldb	7,s
   0C12 E7 84         [ 4]  321 	stb	,x
   0C14 6A E8 12      [ 7]  322 	dec	18,s
   0C17 10 AE E8 13   [ 7]  323 	ldy	19,s
   0C1B 8E 00 0A      [ 3]  324 	ldx	#10
   0C1E 34 10         [ 6]  325 	pshs	x
   0C20 30 A4         [ 4]  326 	leax	,y
   0C22 BD 0D C3      [ 8]  327 	jsr	_udivhi3
   0C25 32 62         [ 5]  328 	leas	2,s
   0C27 AF E8 13      [ 6]  329 	stx	19,s
   0C2A 6D E8 12      [ 7]  330 	tst	18,s
   0C2D 26 B7         [ 3]  331 	bne	L21
   0C2F E6 6A         [ 5]  332 	ldb	10,s
   0C31 E7 E8 16      [ 5]  333 	stb	22,s
   0C34 E6 E8 1D      [ 5]  334 	ldb	29,s
   0C37 E7 E8 15      [ 5]  335 	stb	21,s
   0C3A C6 CC         [ 2]  336 	ldb	#-52
   0C3C D7 0C         [ 4]  337 	stb	*_dp_VIA_cntl
   0C3E C6 7F         [ 2]  338 	ldb	#127
   0C40 D7 04         [ 4]  339 	stb	*_dp_VIA_t1_cnt_lo
   0C42 E6 E8 16      [ 5]  340 	ldb	22,s
   0C45 E7 E8 18      [ 5]  341 	stb	24,s
   0C48 E6 E8 15      [ 5]  342 	ldb	21,s
   0C4B E7 E8 17      [ 5]  343 	stb	23,s
   0C4E E6 E8 18      [ 5]  344 	ldb	24,s
   0C51 E7 E2         [ 6]  345 	stb	,-s
   0C53 E6 E8 18      [ 5]  346 	ldb	24,s
   0C56 BD 03 02      [ 8]  347 	jsr	__Moveto_d
   0C59 32 61         [ 5]  348 	leas	1,s
   0C5B 30 6B         [ 5]  349 	leax	11,s
   0C5D BD 01 B2      [ 8]  350 	jsr	__Print_Str
   0C60 32 E8 19      [ 5]  351 	leas	25,s
   0C63 35 A0         [ 7]  352 	puls	y,pc
                            353 	.globl _print_binary
   0C65                     354 _print_binary:
   0C65 32 E8 EC      [ 5]  355 	leas	-20,s
   0C68 E7 65         [ 5]  356 	stb	5,s
   0C6A C6 80         [ 2]  357 	ldb	#-128
   0C6C E7 6E         [ 5]  358 	stb	14,s
   0C6E C6 07         [ 2]  359 	ldb	#7
   0C70 E7 6F         [ 5]  360 	stb	15,s
   0C72                     361 L24:
   0C72 E6 6F         [ 5]  362 	ldb	15,s
   0C74 E7 63         [ 5]  363 	stb	3,s
   0C76 E6 E8 17      [ 5]  364 	ldb	23,s
   0C79 E7 E4         [ 4]  365 	stb	,s
   0C7B C6 01         [ 2]  366 	ldb	#1
   0C7D E4 E4         [ 4]  367 	andb	,s
   0C7F E7 62         [ 5]  368 	stb	2,s
                            369 	; ldb	2,s	; optimization 5
   0C81 CB 30         [ 2]  370 	addb	#48
   0C83 E7 64         [ 5]  371 	stb	4,s
   0C85 E6 63         [ 5]  372 	ldb	3,s
   0C87 4F            [ 2]  373 	clra		;zero_extendqihi: R:b -> R:d
   0C88 ED E4         [ 5]  374 	std	,s
   0C8A 30 66         [ 5]  375 	leax	6,s
   0C8C 1E 01         [ 8]  376 	exg	d,x
   0C8E E3 E4         [ 6]  377 	addd	,s
   0C90 1E 01         [ 8]  378 	exg	d,x
   0C92 E6 64         [ 5]  379 	ldb	4,s
   0C94 E7 84         [ 4]  380 	stb	,x
   0C96 6A 6F         [ 7]  381 	dec	15,s
   0C98 64 E8 17      [ 7]  382 	lsr	23,s
   0C9B E6 6F         [ 5]  383 	ldb	15,s
   0C9D C1 FF         [ 2]  384 	cmpb	#-1	;cmpqi:
   0C9F 26 D1         [ 3]  385 	bne	L24
   0CA1 E6 65         [ 5]  386 	ldb	5,s
   0CA3 E7 E8 11      [ 5]  387 	stb	17,s
   0CA6 E6 E8 16      [ 5]  388 	ldb	22,s
   0CA9 E7 E8 10      [ 5]  389 	stb	16,s
   0CAC C6 CC         [ 2]  390 	ldb	#-52
   0CAE D7 0C         [ 4]  391 	stb	*_dp_VIA_cntl
   0CB0 C6 7F         [ 2]  392 	ldb	#127
   0CB2 D7 04         [ 4]  393 	stb	*_dp_VIA_t1_cnt_lo
   0CB4 E6 E8 11      [ 5]  394 	ldb	17,s
   0CB7 E7 E8 13      [ 5]  395 	stb	19,s
   0CBA E6 E8 10      [ 5]  396 	ldb	16,s
   0CBD E7 E8 12      [ 5]  397 	stb	18,s
   0CC0 E6 E8 13      [ 5]  398 	ldb	19,s
   0CC3 E7 E2         [ 6]  399 	stb	,-s
   0CC5 E6 E8 13      [ 5]  400 	ldb	19,s
   0CC8 BD 03 02      [ 8]  401 	jsr	__Moveto_d
   0CCB 32 61         [ 5]  402 	leas	1,s
   0CCD 30 66         [ 5]  403 	leax	6,s
   0CCF BD 01 B2      [ 8]  404 	jsr	__Print_Str
   0CD2 32 E8 14      [ 5]  405 	leas	20,s
   0CD5 39            [ 5]  406 	rts
ASxxxx Assembler V05.00  (Motorola 6809), page 1.
Hexidecimal [16-Bits]

Symbol Table

    .__.$$$.       =   2710 L   |     .__.ABS.       =   0000 G
    .__.CPU.       =   0000 L   |     .__.H$L.       =   0001 L
  2 L10                00ED R   |   2 L11                00F1 R
  2 L14                017E R   |   2 L17                020B R
  2 L18                020F R   |   2 L19                0230 R
  2 L20                0234 R   |   2 L21                0239 R
  2 L24                02C5 R   |   2 L4                 003F R
  2 L7                 00C9 R   |   2 L8                 00CD R
  2 L9                 00E8 R   |     __Moveto_d         **** GX
    __Print_Str        **** GX  |     _dp_VIA_cntl       **** GX
    _dp_VIA_t1_cnt     **** GX  |   2 _print_binary      02B8 GR
  2 _print_long_si     01F7 GR  |   2 _print_long_un     016D GR
  2 _print_signed_     00B9 GR  |   2 _print_string      0000 GR
  2 _print_unsigne     0033 GR  |     _udivhi3           **** GX
    _umodhi3           **** GX

ASxxxx Assembler V05.00  (Motorola 6809), page 2.
Hexidecimal [16-Bits]

Area Table

[_CSEG]
   0 _CODE            size    0   flags C080
   2 .text            size  329   flags  100
[_DSEG]
   1 _DATA            size    0   flags C0C0

