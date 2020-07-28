.ORIG x3000

LEA R6, STACK_END
JSR ARRAYSUM
HALT

ARRAYSUM
	; callee setup
	ADD R6, R6, #-15
	STR R5, R6, #1
	ADD R5, R6, #11
	STR R7, R5, #2

	AND R0, R0, #0
	STR R0, R5, #-11 ; i
	STR R0, R5, #-10 ; sum

FIRSTLOOP
	JSR READNUM
	LDR R0, R6, #0    ; return value
	ADD R6, R6, #1    ; caller teardown
	LDR R1, R5, #-11  ; i
	ADD R1, R1, R5    ; compute location of arr[i] (except off by 9)
	STR R0, R1, #-9
	ADD R0, R0, #1    ; check for -1
	BRz ENDFIRSTLOOP
	LDR R1, R5, #-11 ; i++
	ADD R1, R1, #1
	STR R1, R5, #-11
	BRnzp FIRSTLOOP
	
ENDFIRSTLOOP
	AND R0, R0, #0
	STR R0, R5, #-11 ; i = 0

SECONDLOOP
	LDR R1, R5, #-11  ; i
	ADD R1, R1, R5    ; compute location of arr[i] (off by 9)
	LDR R0, R1, #-9   ; fetch arr[i]
	ADD R1, R0, #1    ; check for -1
	BRz ENDSECONDLOOP
	LDR R1, R5, #-10  ; get sum
	ADD R0, R0, R1    ; add arr[i] to sum
	STR R0, R5, #-10  ; store it back
	LDR R1, R5, #-11  ; get i
	ADD R1, R1, #1    ; i++
	STR R1, R5, #-11
	BRnzp SECONDLOOP

ENDSECONDLOOP
	; not going to deal with the print out and return
	
	; callee teardown
	LDR R7, R5, #2
	LDR R5, R5, #1
	ADD R6, R6, #14
	RET

READNUM
	; callee setup
	ADD R6, R6, #-4
	STR R5, R6, #1
	ADD R5, R6, #0
	STR R7, R5, #2

	AND R0, R0, #0
	STR R0, R5, #0

LOOPTOP
	GETC
	; subtract x30 from R0
	ADD R0, R0, #-16
	ADD R0, R0, #-16
	ADD R0, R0, #-16
	BRn LOOPEND
	ADD R1, R0, #-9
	BRp LOOPEND
	; R0 is a digit and it's the one we want
	LDR R1, R5, #0
	ADD R1, R1, R1
	ADD R2, R1, R1 ; 4*R1
	ADD R2, R2, R2 ; 8*R1
	ADD R1, R1, R2 ; 10*R1
	ADD R1, R1, R0
	STR R1, R5, #0
	BRnzp LOOPTOP

LOOPEND
	LDR R1, R5, #0
	STR R1, R5, #3
	; callee teardown
	LDR R7, R5, #2
	LDR R5, R5, #1
	ADD R6, R6, #3
	RET


.BLKW #100
STACK_END .FILL #0
.END