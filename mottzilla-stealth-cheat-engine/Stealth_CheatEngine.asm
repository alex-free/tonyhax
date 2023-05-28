;	Basic Cheat Patching Engine
;	Programmed by: MottZilla, expanded by Alex Free
;
;	Memory Map
;	$C000 = Cheat Engine Program Code (strip MZ-CheatEngine text from beginning and end)
;	$CFFC = B0 (17h) Original Vector
;	$CFF8 = Ptr to Joypad Ptr in Kernel Memory
;	$D000 = $???? = Code Objects
;
;	AA = Code Object, Address 32bit
;	DD = Data 16bit (can use only first byte alternatively for 8bit)
;	JE = Joypad Enable Combo, JD = Joypad Disable Combo (neither implemented yet)
;	EN = Code Enabled (non-zero) or Disabled (zero) (code type/prefix is this value to identify how to handle it)
;	RR = Reserved (to expand format if needed, not currently used)
;	AA.AA.AA.AA.DD.DD.RR.RR.JE.JE.JD.JD.EN.RR.RR.RR
;
;	For Joypad Reading we need to know where the Ptr to the Joypad Data is in Kernel memory.
;	If we call InitPad() ourselves we can then search Kernel memory for the Ptr to our buffer.
;	This location in the Kernel memory won't change when we load up a game. But we should test to
;	see what happens with InitPad, StartPad, StopPad depending on what we are doing. 
;	74B4, 74B8, and 74C8 on different BIOS versions have contained the Ptr to the 1st Joypad buffer.
;

.nocash
.psx
.mips

org 8000C000h ; where we copy this in RAM

	db "MZ-CheatEngine"
.align 4

CHEAT_ENGINE:
	; Save Registers to Stack
	sub	sp,20h
	mov	[sp+00h],r4
	mov	[sp+04h],r5
	mov	[sp+08h],r6
	mov	[sp+0Ch],r7
	movp	r4,0000D000h	; r4 = Current Code Ptr
	nop ; Load delay slot for putting r4 into r6 next

DO_CHEAT_LOOP:
	mov	r6,[r4+0Ch]	; Load code type
	nop ; Load delay slot for r6
	jz	r6,CHEATS_DONE ; if code type byte is 0 then we reached the end of the list
	; Check for prefixes/code type
	mov	r7,30h
	nop ; Load delay slot for r7
	je	r6,r7,HANDLE_30_CODE
	mov	r7,80h
	nop ; Load delay slot for r7
	je	r6,r7,HANDLE_80_CODE
	mov	r7,0E0h ; 0xE0
	nop ; Load delay slot for r7
	je	r6,r7,HANDLE_E0_CODE
	mov	r7,0D0h ; 0xD0
	nop ; Load delay slot for r7
	je	r6,r7,HANDLE_D0_CODE
	mov	r7,0E1h ; 0xE1
	nop ; Load delay slot for r7
	je	r6,r7,HANDLE_E1_CODE
	mov	r7,0D1h ; 0xD1
	nop ; Load delay slot for r7
	je	r6,r7,HANDLE_D1_CODE
	nop ; branch delay slot
	; Never get here because we guarantee valid input from Tonyhax International loader

DO_CHEAT_LOOP_FOR_COMPARE:
	; Check for prefixes/code type (only check for these 2 since we came from a compare code and they can't be recursive)
	mov	r7,30h
	mov	r6,[r4+1Ch]	; Load code type of code on next line
	nop ; Load delay slot for R6
	je	r6,r7,HANDLE_30_CODE_FOR_COMPARE
	nop ; branch delay slot
	mov	r7,80h
	nop ; Load delay slot for R7
	je	r6,r7,HANDLE_80_CODE_FOR_COMPARE
	nop ; branch delay slot
	; Never get here because we guarantee valid input from Tonyhax International loader

HANDLE_80_CODE:
	movh r5,[r4+4h]	; Load 16bit value to write
	mov	r7,[r4]		; Load code address
	nop ; Load delay slot for R7
	movh [r7],r5		; Write 16bit value
	jrel NEXT_CHEAT
	nop

HANDLE_30_CODE:
	movb	r5,[r4+4h]	; Load 8bit value to write
	mov	r7,[r4]		; Load code address
	nop ; Load delay slot for R7
	movb [r7],r5		; Write 8bit value
	jrel NEXT_CHEAT
	nop ; branch delay slot

HANDLE_E0_CODE:
	movb	r5,[r4+4h] ; Load 8bit compare value at current code line
	mov	r7,[r4] ; Load current code address
	nop ; Load delay slot for R7
	movb r6,[r7] ; Read current 8bit value from code address
	nop ; Load delay slot for R6
	jne	r6,r5,NEXT_CHEAT_AFTER_COMPARE
	nop ; Branch delay slot
	jrel DO_CHEAT_LOOP_FOR_COMPARE
	nop ; branch delay slot

HANDLE_E1_CODE:
	movb	r5,[r4+4h] ; Load 8bit compare value at current code line
	mov	r7,[r4] ; Load current code address
	nop ; Load delay slot for R7
	movb r6,[r7] ; Read current 8bit value from code address
	nop ; Load delay slot for R6
	je r6,r5,NEXT_CHEAT_AFTER_COMPARE
	nop ; Branch delay slot
	jrel DO_CHEAT_LOOP_FOR_COMPARE
	nop ; branch delay slot

HANDLE_D0_CODE:
	movh	r5,[r4+4h]	; Load 16bit compare value at current code line
	mov	r7,[r4]		; Load current code address
	nop ; Load delay slot for R7
	movh	r6,[r7]		; Read current 16bit value from code address
	nop ; Load delay slot for R6
	jne	r6,r5,NEXT_CHEAT_AFTER_COMPARE
	nop ; Branch delay slot
	jrel DO_CHEAT_LOOP_FOR_COMPARE
	nop ; branch delay slot

HANDLE_D1_CODE:
	movh	r5,[r4+4h]	; Load 16bit compare value at current code line
	mov	r7,[r4]		; Load current code address
	nop ; Load delay slot for R7
	movh	r6,[r7]		; Read current 16bit value from code address
	nop ; Load delay slot for R6
	je r6,r5,NEXT_CHEAT_AFTER_COMPARE
	nop ; Branch delay slot
	jrel DO_CHEAT_LOOP_FOR_COMPARE
	nop ; branch delay slot

HANDLE_30_CODE_FOR_COMPARE:
	movb	r5,[r4+14h]	; load 8bit data to write to this address
	mov	r7,[r4+10h]		; load code address from the next cheat line in R7
	nop ; Load delay slot for R7
	movb	[r7],r5		; Write 8bit value
	jrel NEXT_CHEAT_AFTER_COMPARE
	nop ; branch delay slot

HANDLE_80_CODE_FOR_COMPARE:
	movh	r5,[r4+14h]	; load 16bit data to write to this address
	mov	r7,[r4+10h]		; load code address from the next cheat line in R7
	nop ; Load delay slot for R7
	movh	[r7],r5		; Write 16bit value
	jrel NEXT_CHEAT_AFTER_COMPARE
	nop ; branch delay slot

NEXT_CHEAT_AFTER_COMPARE:
	add	r4,20h;	Skip the next code line since it was part of the compare code just parsed
	jrel	DO_CHEAT_LOOP
	nop ; branch delay slot

NEXT_CHEAT:
	add	r4,10h; Advance to next code line
	jrel	DO_CHEAT_LOOP
	nop ; branch delay slot

CHEATS_DONE:
	mov	r4,[sp+00h]
	mov	r5,[sp+04h]
	mov	r6,[sp+08h]
	mov	r7,[sp+0Ch]
	add	sp,20h
	
	movp	k0,[0CFFCh]
	nop
	jmp	k0

	nop

CE_END:
	db "MZ-CheatEngine"
.align 4
	nop

END