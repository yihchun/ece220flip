.ORIG x3000

AND R0, R0, #0
ADD R0, R0, #3
AND R1, R1, #0
ADD R1, R1, #4
JSR MULSUB
HALT

;; MULSUB specification
; R0 <- R0 * R1
; R7 changes because it has to
; R1 unchanged
MULSUB
;; MULSUB register allocation
; R2 is our accumulator
; subtract 1 from R1 and add R0 to R2 until R1 is 0
;; Save R1, R2
ST R1, MUL_R1_SAVE
ST R2, MUL_R2_SAVE

AND R2, R2, #0

MULLOOPTOP
ADD R2, R2, R0
ADD R1, R1, #-1
BRnp MULLOOPTOP

ADD R0, R2, #0
LD R1, MUL_R1_SAVE
LD R2, MUL_R2_SAVE
RET

MUL_R1_SAVE .FILL #0
MUL_R2_SAVE .FILL #0

.END