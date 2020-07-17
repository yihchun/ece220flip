.ORIG x3000

LEA R6, STACK_START

LD R0, FIBPARAM
; caller setup -- push parameters
ADD R6, R6, #-1
STR R0, R6, #0
JSR FIB
HALT
FIBPARAM .FILL #5

; tmp <- R5, R6
; R5 save (R5+1)
; R7 save (R5+2)
; return value (R5+3)   <= R6 after callee teardown
; n (R5+4)

FIB
	; callee setup
	ADD R6, R6, #-4		; 4 = 3 + # of local variables
	STR R5, R6, #1		; 1 = # of local variables
	ADD R5, R6, #0		; 0 = # of local variables - 1
	STR R7, R5, #2

	; if (n<=1) return n;
	LDR R0, R5, #4		; where n lives
	ADD R0, R0, #0
	BRn FIBNOTLEQ1
	ADD R1, R0, #-1
	BRp FIBNOTLEQ1
	BRnzp FIB_TEARDOWN

FIBNOTLEQ1
	; caller setup
	LDR R0, R5, #4		; where n lives
	ADD R0, R0, #-1
	ADD R6, R6, #-1
	STR R0, R6, #0
	JSR FIB
	; caller teardown
	LDR R0, R6, #0
	STR R0, R5, #0		; tmp <- returnval
	ADD R6, R6, #2		; pops return value, n-1 off of the stack
	
	; caller setup
	LDR R0, R5, #4		; where n lives
	ADD R0, R0, #-2
	ADD R6, R6, #-1
	STR R0, R6, #0
	JSR FIB
	; caller teardown
	LDR R0, R6, #0
	ADD R6, R6, #2		; pops return value, n-1 off of the stack
	LDR R1, R5, #0		; R1 <- tmp
	ADD R0, R0, R1		; what we want to return
	
FIB_TEARDOWN
	STR R0, R5, #3

	; callee teardown
	LDR R7, R5, #2
	LDR R5, R5, #1
	ADD R6, R6, #3		; 2+# of local variables	
	RET
	
.BLKW #100
STACK_START .FILL #0

.END
