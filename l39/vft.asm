.ORIG x3000

; a->show();
LD R0, MAIN_A ; address of the a object
LDR R0, R0, #0 ; address of the virtual function table
LDR R0, R0, #0 ; address of the show() virtual function
JSRR R0

; a = &bar
LEA R0, MAIN_BAR
ST R0, MAIN_A

; a->show();
LD R0, MAIN_A ; address of the a object
LDR R0, R0, #0 ; address of the virtual function table
LDR R0, R0, #0 ; address of the show() virtual function
JSRR R0

; a = new Base;
LEA R0, MALLOC_RET  ; alloc space
ST R0, MAIN_A       ; assign
LEA R1, VFT_BASE    ; initialize the VFT for the new Base
STR R1, R0, #0

; a->show();
LD R0, MAIN_A ; address of the a object
LDR R0, R0, #0 ; address of the virtual function table
LDR R0, R0, #0 ; address of the show() virtual function
JSRR R0

HALT

MAIN_FOO .FILL VFT_FOO
	 .FILL x0 ; other instance variables for foo...
MAIN_BAR .FILL VFT_BAR
MAIN_A   .FILL MAIN_FOO

FOO_SHOW
	ST R7, SAVE_R7
	LEA R0, FOO_MSG
	PUTS
	LD R7, SAVE_R7
	RET

BASE_SHOW
	ST R7, SAVE_R7
	LEA R0, BASE_MSG
	PUTS
	LD R7, SAVE_R7
	RET

BAR_SHOW
	ST R7, SAVE_R7
	LEA R0, BAR_MSG
	PUTS
	LD R7, SAVE_R7
	RET

SAVE_R7 .FILL #0
VFT_BASE .FILL BASE_SHOW
VFT_FOO  .FILL FOO_SHOW
VFT_BAR  .FILL BAR_SHOW

BASE_MSG .STRINGZ "I am a Base"
FOO_MSG .STRINGZ "I am a Foo"
BAR_MSG .STRINGZ "I am a Bar"

MALLOC_RET .FILL x0

.END