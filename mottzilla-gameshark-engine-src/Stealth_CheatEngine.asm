;	Basic Cheat Patching Engine
;	Programmed by: MottZilla
;
;	Memory Map
;	$C000 = Cheat Engine Program Code
;	$CFFC = B0 (17h) Original Vector
;	$CFF8 = Ptr to Joypad Ptr in Kernel Memory
;	$D000 = $???? = Code Objects
;
;	Code Object: AA = Address 32bit, DD = Data 16bit, JE = Joypad Enable Combo, JD = Joypad Disable Combo
;			EN = Code Enabled or Disabled, CC = Compare Value
;	AA.AA.AA.AA.DD.DD.CC.CC.JE.JE.JD.JD.EN.EN.EN.EN
;
;	For Joypad Reading we need to know where the Ptr to the Joypad Data is in Kernel memory.
;	If we call InitPad() ourselves we can then search Kernel memory for the Ptr to our buffer.
;	This location in the Kernel memory won't change when we load up a game. But we should test to
;	see what happens with InitPad, StartPad, StopPad depending on what we are doing. 
;	74B4, 74B8, and 74C8 on different BIOS versions have contained the Ptr to the 1st Joypad buffer.
;
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
	; 

	movp	r4,0000D000h	; r4 = Current Code Ptr
DO_CHEAT_LOOP:
	mov	r7,[r4]		; Load Code Address
	movh	r5,[r4+06h]	; Load Code Data Compare
	jz	r7,CHEATS_DONE	; If Code Address == 0 then we reached the end of the list.

	; Here is where the Joypad Checks to Enable/Disable should go.
	; I could have codes that only apply when holding a button combo
	; By first doing a check to enable and then after apply codes do a check
	; to disable. That way if the Enable and Disable are the same it's only applied
	; when that combo is held. Or if they are different they can be enabled and disabled
	; by two different combos. 
	; If $CFF8 == 0 then Joypad related Stuff is ignored as we can't read Joypads.

	; Check if this Code is Enabled
	mov	r7,[r4+0Ch]	; Load Code Enable State
	nop
	jz	r7,NEXT_CHEAT	; If not we proceed to the next Cheat Slot.
	nop

	; Applying Code. r4 = code ptr. r5 = code DATA Compare.
	mov	r6,[r4]		; Load Code Address into r6
	movp	r7,0FF000000h	; Mask to Apply
	and	r6,r7,r6	; Apply Mask to Code Address

	; Now we need to check for prefixes
	; 80 = 16-bit
	; 30 = 8-bit
	; Honestly we can probably ignore anything that isn't 80.

	movp	r7,80000000h
	jne	r6,r7,NEXT_CHEAT	; If Cheat not 80XXXXXX we ignore it.
	nop

	; Check Compare Value (in r5)
	mov	r7,[r4]		; Load Code Address
	jz	r5,APPLY_CHEAT
	movh	r6,[r7]		; Read from Code Address
	nop
	jne	r6,r5,NEXT_CHEAT
	

APPLY_CHEAT:
	; Applying the Cheat
	;mov	r7,[r4]		; Load Code Address, already in R7...
	movh	r5,[r4+4h]	; Load Code Data to write
	nop
	movh	[r7],r5		; Write Data

NEXT_CHEAT:
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