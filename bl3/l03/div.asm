.ORIG x3000

AND R0, R0, #0
ADD R0, R0, #5
ADD R1, R0, #-2
JSR DIV
HALT

; assumptions: unsigned divide, R0/R1, R0&R1 to both have a 0 sign bit
; assume without checking: R1 is positive (!= 0)
; output is R1 is floor(R0/R1), R0 is remainder (R0 % R1)
DIV

	ST R2, DIV_SAVE_R2
	NOT R1, R1
	ADD R1, R1, #1
	AND R2, R2, #0

LOOPTOP_DIV
	ADD R0, R0, R1	; subtract denominator from numerator 1 time
	BRn CLEANUP
	ADD R2, R2, #1
	BRnzp LOOPTOP_DIV

; Now: 5/2 then at this point, R0 = -1, R2 = 2, R1 = -2
CLEANUP
	NOT R1, R1
	ADD R1, R1, #1
	ADD R0, R0, R1	; restore the remainder to the pre-negative value
	ADD R1, R2, #0
	LD R2, DIV_SAVE_R2
	RET
	
; Goal: R0 = 1, R1 = 2

; 7 /3
; LOOPTOP_DIV first time: R0 = 7, R1 = -3, R2 = 0
; LOOPTOP_DIV next time: R0 = 4, R1 = -3, R2 = 1
; LOOPTOP_DIV next time: R0 = 1, R1 = -3, R2 = 2
; LOOPTOP_DIV next time: R0 = -2, R1 = -3, (break) R2 = 2
; after cleanup: R0 = 1, R1 = 2, R2 is restored

DIV_SAVE_R2 .FILL #0

.END