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
;	EN = Code Enabled (non-zero) or Disabled (zero) (code type is this value to identify how to handle it)
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

org 80010000h

	db "MZ-CheatEngine"
.align 4

CHEAT_ENGINE:
	; Save Registers to Stack
	sub	sp,20h
	mov	[sp+00h],r4
	mov	[sp+04h],r5
	mov	[sp+08h],r6
	mov	[sp+0Ch],r7

	; Current Code Ptr
	; End of Codes Ptr

	movp	r4,0000D000h	; r4 = Current Code Ptr

DO_CHEAT_LOOP:

	mov	r7,[r4]		; Load code address
	nop
	jz	r7,CHEATS_DONE	; If code address == 0 then we reached the end of the list.
	movp	r5,00000000h	; clear r5 for comparison match below
	movp	r6,00000000h	; clear r6 for comparison match below
	movp	r7,00000000h	; clear r7 for comparison match below
	; Here is where the Joypad Checks to Enable/Disable should go.
	; I could have codes that only apply when holding a button combo
	; By first doing a check to enable and then after apply codes do a check
	; to disable. That way if the Enable and Disable are the same it's only applied
	; when that combo is held. Or if they are different they can be enabled and disabled
	; by two different combos. 
	; If $CFF8 == 0 then Joypad related Stuff is ignored as we can't read Joypads.

	mov	r6,[r4+0Ch]	; Load code type

	; Now we need to check for prefixes/code type

	mov	r7,30h
	nop
	je	r6,r7,APPLY_CHEAT_8
	nop
	mov	r7,80h
	nop
	je	r6,r7,APPLY_CHEAT_16
	nop
	mov	r7,0E0h ; 0xE0
	nop
	je	r6,r7,HANDLE_COMPARE_8
	nop
	mov	r7,0D0h ; 0xD0
	nop
	je	r6,r7,HANDLE_COMPARE_16

DO_CHEAT_LOOP_FOR_COMPARE:

	movp	r5,00000000h	; clear r5 for comparison match below
	movp	r6,00000000h	; clear r6 for comparison match below
	movp	r7,00000000h	; clear r7 for comparison match below

	; Here is where the Joypad Checks to Enable/Disable should go.
	; I could have codes that only apply when holding a button combo
	; By first doing a check to enable and then after apply codes do a check
	; to disable. That way if the Enable and Disable are the same it's only applied
	; when that combo is held. Or if they are different they can be enabled and disabled
	; by two different combos. 
	; If $CFF8 == 0 then Joypad related Stuff is ignored as we can't read Joypads.

	mov	r6,[r4+1Ch]	; Load code type for next code line

	; Now we need to check for prefixes/code type (only check for these 2 since we came from a compare code)

	mov	r7,30h
	nop
	je	r6,r7,APPLY_CHEAT_8_FOR_COMPARE

	mov	r7,80h
	nop
	je	r6,r7,APPLY_CHEAT_16_FOR_COMPARE

HANDLE_COMPARE_16:
	; Check Compare Value (in r5)
	nop
	movh	r5,[r4+4h]	; Load 16bit compare value at current code line
	nop
	mov	r7,[r4]		; Load current code address
	nop
	movh	r6,[r7]		; Read current 16bit value from code address
	nop
	jne	r6,r5,NEXT_CHEAT_AFTER_COMPARE
	jrel DO_CHEAT_LOOP_FOR_COMPARE

APPLY_CHEAT_16_FOR_COMPARE:
	nop
	mov	r7,[r4+10h]		; load code address from the next cheat line in R7
	movh	r5,[r4+14h]	; load 16bit data to write to this address
	nop
	movh	[r7],r5		; Write 16bit value
	jrel NEXT_CHEAT_AFTER_COMPARE

APPLY_CHEAT_16:
	nop
	mov	r7,[r4]		; Load code address
	movh	r5,[r4+4h]	; Load 16bit value to write
	nop
	movh	[r7],r5		; Write 16bit value
	jrel NEXT_CHEAT

HANDLE_COMPARE_8:
	nop
	movb	r5,[r4+4h]	; Load 8bit compare value at current code line
	nop
	mov	r7,[r4]		; Load current code address
	nop
	movb	r6,[r7]		; Read current 8bit value from code address
	nop
	jne	r6,r5,NEXT_CHEAT_AFTER_COMPARE
	jrel DO_CHEAT_LOOP_FOR_COMPARE

APPLY_CHEAT_8_FOR_COMPARE:
	mov	r7,[r4+10h]		; load code address from the next cheat line in R7
	movb	r5,[r4+14h]	; load 8bit data to write to this address
	nop
	movb	[r7],r5		; Write 8bit value
	jrel NEXT_CHEAT_AFTER_COMPARE

APPLY_CHEAT_8:
	nop
	mov	r7,[r4]		; Load Code Address, already in R7...
	movb	r5,[r4+4h]	; Load 8bit value to write
	nop
	movb	[r7],r5		; Write 8bit value
	nop
	jrel NEXT_CHEAT

NEXT_CHEAT_AFTER_COMPARE:
	nop
	add	r4,20h;	Skip the next code since it was part of the compare code just parsed
	jrel	DO_CHEAT_LOOP
	nop

NEXT_CHEAT:
	nop
	add	r4,10h
	jrel	DO_CHEAT_LOOP
	nop

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