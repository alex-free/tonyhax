
.text
.globl __start

# $16 = realstart physical address
# $17 = file descriptor
# $18 = load address
# $19 = real save size (excluding useless trailing zeros)

__start:
	# Restore stack pointer
	li $8, 0x801FFF00
	move $29, $8

	# Call ourselves to get the current program counter in $31
	bal realstart

realstart:
	# Save real start address in $16
	move $16, $31

#ifndef BAREBONES
	# Paint blue
	li $4, 0xFF0000
	bal paintscr
#endif

	# Keep only VBlank interrupts enabled
	li $9, 0x1
	lui $8, 0x1f80
	sw $9, 0x1074($8)

	# Call ChangeClearPad(1) so the BIOS card IRQ clears the interrupt flags.
	# This prevents the PsyQ VBlank ISR from detecting that VBlank fired, and thus prevent its
	# LIBMCRD from interrupting us.
	li $9, 0x5B
	li $4, 1
	jal 0xB0

	# Call wait_card_status(0) to make sure we can access card on slot 1 safely
	li $9, 0x5D
	li $4, 0
	jal 0xB0

	# Call wait_card_status(1)
	#
	# You might be wondering, "why do we care about the status of the slot 2?".
	#
	# You see, LIBMCRD suffers from Bubsyitis and is constantly talking to memory cards, issuing
	# _card_info calls on every god damn frame.
	#
	# This wouldn't be a problem if the BIOS wasn't retarded and, when opening a file, waited
	# for the sector read to finish. In line with Sony's marvelous programming practices, it
	# instead waits for *any* memory card access to finish.
	#
	# This combination results in dev_card_open failing because it checks a buffer for the "MC"
	# signature before the actual sector read has finished.
	li $9, 0x5D
	li $4, 1
	jal 0xB0

	# Call FileOpen
	li $9, 0x32
	addi $4, $16, (splname - realstart)
	li $5, 0b00000001
	jal 0xB0

	# Save handle
	move $17, $2

#ifndef BAREBONES
	# If less than $0, it failed
	blt $2, $0, fatalerror
#endif

	# The kernel will fail to read if we don't wait a bit (here, ~1/10th of a second)
	# This is a known issue as specified in LIBOVR46.PDF section 5-11:
	# "If read() or write() is issued immediately after open(), an error occurs"
	li $8, 1000000

busywait:
	addi $8, -1
	bne $8, $0, busywait

# Load temp buffer address (originally was 0x801FA000, - 0x100 from original start addr of Tonyhax: 0x801FA100).
# This all will be cleared later by Tonyhax International's clearing ram function

#ifdef FF9
	li $18, 0x801EC300
#else
	li $18, 0x801EE180
#endif

	# Load header using FileRead
	li $9, 0x34
	move $4, $17
	move $5, $18
	li $6, 0x100
	jal 0xB0

	#ifndef BAREBONES
	# If we did not read the correct amount, lock
	bne $2, 0x100, fatalerror
	#endif

	# Load executable load address and size
	lw $19, 0x44($18)
	lw $18, 0x40($18)

	# Load executable using FileRead
	li $9, 0x34
	move $4, $17
	move $5, $18
	move $6, $19
	jal 0xB0

#ifndef BAREBONES
	# If we did not read the correct amount, lock
	bne $2, $19, fatalerror

	# Paint green
	li $4, 0x00FF00
	bal paintscr
#endif

	# Jump to it!
	jr $18

#ifndef BAREBONES
fatalerror:
	# Red
	li $4, 0x0000FF
	bal paintscr

lock:
	b lock

paintscr:
	# Add command byte to $4
	li $8, 0x02000000
	or $8, $4

	# Calculate effective address
	addi $4, $16, (redscreen - realstart)

	# Store color with command on buffer
	sw $8, 0($4)

	# Tail call GPU_cwp to paint the entire screen
	li $5, 3
	li $9, 0x4A
	j 0xA0

redscreen:
	# Space for color and command
	.word 0
	# Start X and Y = 0
	.word 0x00000000
	# Width of 1024, height of 512
	.word 0x01FF03FF
#endif

splname:
#ifdef FF9
	.asciiz "bu00:FF9"
#else
	.asciiz "bu00:HAX"
#endif
