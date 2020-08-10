.ORIG x3000

LEA R6, STACK_START

INFLOOPTOP
	JSR READNUM
	LDR R0, R6, #0    ; input just read
	ADD R6, R6, #1    ; caller teardown
	LEA R1, TREE_ROOT_PTR
	ADD R6, R6, #-2   ; push 2 parameters
	STR R0, R6, #1
	STR R1, R6, #0
	JSR BST_INSERT
	ADD R6, R6, #3    ; caller teardown
	BRnzp INFLOOPTOP
	

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


; unused <- R5, R6
; R5 save
; R7 save
; return value
; root
; v

BST_INSERT
	; callee setup
	ADD R6, R6, #-4
	STR R5, R6, #1
	ADD R5, R6, #0
	STR R7, R5, #2

BST_INSERT_TAIL_TARGET

	LDR R0, R5, #4
	LDR R0, R0, #0   ; *root
	BRnp GO_LEFT_OR_RIGHT
	ADD R0, R0, #3   ; R0 is 0, that's why we're here
	ADD R6, R6, #-1  ; push 3 on the stack
	STR R0, R6, #0
	JSR MALLOC
	LDR R0, R6, #0   ; output of malloc
	ADD R6, R6, #2   ; caller teardown
	LDR R1, R5, #4   ; root
	STR R0, R1, #0   ; *root = malloc()
	LDR R2, R5, #5   ; v
	STR R2, R0, #0   ; (*root)->val = v;
	AND R2, R2, #0
	STR R2, R0, #1   ; (*root)->left = NULL;
	STR R2, R0, #2   ; (*root)->right = NULL;
	LDR R7, R5, #2	 ; callee teardown
	LDR R5, R5, #1
	ADD R6, R6, #3
	RET

GO_LEFT_OR_RIGHT
	LDR R0, R5, #4	 ; get root
	LDR R1, R5, #5   ; v
	NOT R1, R1
	ADD R1, R1, #1   ; -v
	LDR R2, R0, #0   ; *root
	LDR R3, R2, #0   ; (*root)->val
	ADD R3, R3, R1   ; (*root)->val - v
	BRp GO_LEFT 	 ; if left, add 1 to R2, else add 2 to R2
	    		 ; adding 1 gets us &((*root)->left)
			 ; adding 2 gets us &((*root)->right)
	ADD R2, R2, #1
GO_LEFT
	ADD R2, R2, #1
	STR R2, R5, #4
	BRnzp BST_INSERT_TAIL_TARGET   ; tail recursion optimization

MALLOC
	LDR R0, R6, #0
	LD R1, NEXT_FREE_BLOCK
	ADD R6, R6, #-1
	STR R1, R6, #0
	ADD R1, R1, R0
	ST R1, NEXT_FREE_BLOCK
	RET


TREE_ROOT_PTR .FILL x0
STACK_END .BLKW #100
STACK_START .FILL x0

NEXT_FREE_BLOCK   .FILL THIS_MUST_BE_LAST
THIS_MUST_BE_LAST .FILL x0

.END