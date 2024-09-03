#=======================================================================================
# mipsel-none-elf-as GNU Assembler (GNU Binutils) 2.38
# Copyright (C) 2022 Free Software Foundation, Inc.
#---------------------------------------------------------------------------------------
# Copyright (C) 2021-2024 Cybdyn Systems. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#=======================================================================================

# no opcode reordering
.set noreorder

# link this in the 'text' section
.section .text
	
# function prototypes
.global MemCardPro_Ping
.global MemCardPro_SendGameID
.global MemCardPro_PrevCH
.global MemCardPro_NextCH
.global MemCardPro_PrevDIR
.global MemCardPro_NextDIR
.global MemCardPro_Wait
.global MemCardPro_Exchng
.global MemcardPro_SimpleCommand
.global MemcardPro_InterCommandDelay

.equ JOY_DELAY_COUNTER, 170 # 170 * 3 instructions = 510 cycles


# arguments:
#	$a0 (port number)
#	$a1 (string length)
#	$a2 (string data (251 bytes maximum))
#
# return values:
#	0 = no error (MemCard Pro detected)
#	1 = bus select fail (no memory card device detected)
#	2 = game ID command start (failed to send the game ID command)
#	3 = reserve fail (reserved for future use (ignore this))
#	4 = string length fail (failed to send the string length)
#	5 = data transmission fail (failed to get the previous byte)
MemCardPro_SendGameID:
	addiu	$sp, -4
	sw		$ra, 0($sp)

	# Add 1 to the string length to include a trailing 0
	# without passing that burdern to the caller
	# i.e. allow the developer to pass strlen(gameid)
	# (MCPro still accepts the unterminated packet but this is cleaner)
	addiu	$a1,	1

	lui		$t0, IOBASE
	
	li		$v0, 0x1003					# TX Enable, joypad port select
	andi	$a0, 1
	sll		$a0, 13
	or		$v0, $a0					# Select port 2 if $a0 is 1
	
	sh		$v0, JOY_CTRL($t0)			# Set to Joypad control interface
	
	jal		MemCardPro_Wait
	li		$a0, JOY_DELAY_COUNTER
.Lread_empty_fifo_writeA:				# Flush the RX FIFO just in case
	lbu		$v1, JOY_TXRX($t0)
	lhu		$v0, JOY_STAT($t0)
	nop
	andi	$v0, 0x2
	bnez	$v0, .Lread_empty_fifo_writeA
	nop
	
	lhu		$v1, JOY_CTRL($t0)
	nop
	or		$v1, 0x10
	sh		$v1, JOY_CTRL($t0)
	
	# BYTE 0 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send the 'bus select' byte
	li		$a0, 0x81					# [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lgameid_error
	#nop
	
	bne		$v0, 0xFF, .Lgameid_error 			# If we do not get 0xFF (255d) back, branch
	addiu	$v0, $zero, 1				# Return a value of 1 [DELAY SLOT]
	
	# BYTE 1 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send the 'game ID start command' byte
	li		$a0, 0x21					# [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lgameid_error
	#nop
	
	# This response may be 0x00 or 0x08 (MCPro and regular cards)
	# Depending on when you do the ping, so we can accept both

	# We got the 0x00 ping response
	beq 	$v0, $zero, .LvalidresponseA
	nop

	addiu 	$v0, $v0, -0x08				# We got the 0x08 ping response
	beq 	$v0, $zero, .LvalidresponseA
	nop

	b		.Lgameid_error 					# If we do not get 0x00 back, branch
	addiu	$v0, $zero, 2				# Return a value of 2 [DELAY SLOT]
.LvalidresponseA:
	# BYTE 2 -----------------------------------------------------------------
	#jal	MemCardPro_Exchng			# Send 'reserved'
	#li		$a0, 0x00					# [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lgameid_error
	#nop
	
	#bnez	$v0, .Lgameid_error		 		# If we do not get 0x00 back, branch
	#addiu	$v0, $zero, 3				# Return a value of 3 [DELAY SLOT]
	
	# BYTE 3 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send 'reserved'
	li		$a0, 0x00					# [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lgameid_error
	#nop
	
	bnez	$v0, .Lgameid_error		 		# If we do not get 0x00 back, branch
	addiu	$v0, $zero, 3				# Return a value of 3 [DELAY SLOT]
	
	# BYTE 4 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send the 'string length'
	move	$a0, $a1					# copy $a1 to $a0 [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lgameid_error
	#nop
	
	bnez	$v0, .Lgameid_error		 		# If we do not get 0x00 back, branch
	addiu	$v0, $zero, 4				# Return a value of 4 [DELAY SLOT]
	
	# BYTE 5 -----------------------------------------------------------------
.strloop:
	lbu		$a0, 0($a2)					# get the byte from the string
	jal		MemCardPro_Exchng			# send the 'string data' itself
	addiu $a1, $a1, -1					# decrement remaining bytes [DELAY SLOT]
	
	bnez	$a1, .strloop				# repeat the loop until all the bytes are sent
	addiu	$a2, 1						# advance the string address [DELAY SLOT]
	# ------------------------------------------------------------------------
	
	addiu	$v0, $zero, 0				# No errors (return a value of 0)

# "error handler
.Lgameid_error:
	sb		$zero, JOY_TXRX($t0)		# Get the end byte
	nop
	
	sh		$zero, JOY_CTRL($t0)		# Apparently required

	lw		$ra, 0($sp)
	addiu	$sp, 4
	jr		$ra
	nop


# $a0 = port number
# $a1 = 0x22, 0x23, 0x24, or 0x24 to increment or decrement channels.
# $a2 = expected response (0x27 for ping, 0x20 for channel/dir switches) 
# $a2 & 0x100 = response is actually required
MemcardPro_SimpleCommand:

	addiu	$sp, -4
	sw		$ra, 0($sp)

	lui		$t0, IOBASE
	
	li		$v0, 0x1003					# TX Enable, joypad port select
	andi	$a0, 1
	sll		$a0, 13
	or		$v0, $a0					# Select port 2 if $a0 is 1
	
	sh		$v0, JOY_CTRL($t0)			# Set to Joypad control interface
	
	jal		MemCardPro_Wait
	li		$a0, JOY_DELAY_COUNTER
.Lread_empty_fifo_writeB:				# Flush the RX FIFO just in case
	lbu		$v1, JOY_TXRX($t0)
	lhu		$v0, JOY_STAT($t0)
	nop
	andi	$v0, 0x2
	bnez	$v0, .Lread_empty_fifo_writeB
	nop
	
	lhu		$v1, JOY_CTRL($t0)
	nop
	or		$v1, 0x10
	sh		$v1, JOY_CTRL($t0)
	
	# BYTE 0 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send the 'bus select' byte
	li		$a0, 0x81					# [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lerror
	#nop
	
	bne		$v0, 0xFF, .Lerror 			# If we do not get 0xFF (255d) back, branch
	addiu	$v0, $zero, 1				# Return a value of 1 [DELAY SLOT]
	
	# BYTE 1 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send the 'next channel' byte
	move	$a0, $a1					# [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lerror
	#nop
	
	# This response may be 0x00 or 0x08 (MCPro and regular cards)
	# Depending on when you do the ping, so we can accept both

	# We got the 0x00 ping response
	beq 	$v0, $zero, .LvalidresponseB
	nop

	addiu 	$v0, $v0, -0x08				# We got the 0x08 ping response
	beq 	$v0, $zero, .LvalidresponseB
	nop

	b		.Lerror 					# If we do not get 0x00 back, branch
	addiu	$v0, $zero, 2				# Return a value of 2 [DELAY SLOT]
.LvalidresponseB:
	# BYTE 2 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send 'reserved'
	li		$a0, 0x00					# [DELAY SLOT]
	
	bnez	$v0, .Lerror		 		# If we do not get 0x00 back, branch
	addiu	$v0, $zero, 3				# Return a value of 3 [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lerror
	#nop
	
	#bne	$v0, 0x00, .Lerror 			# If we do not get 0x00 back, branch
	#addiu	$v0, $zero, 3				# Return a value of 3 [DELAY SLOT]

	# BYTE 3 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send 'reserved'
	li		$a0, 0x00					# [DELAY SLOT]
	
	bnez	$v0, .Lerror		 		# If we do not get 0x00 back, branch
	addiu	$v0, $zero, 3				# Return a value of 3 [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lerror
	#nop
	
	#bne	$v0, 0x00, .Lerror 			# If we do not get 0x00 back, branch
	#addiu	$v0, $zero, 3				# Return a value of 3 [DELAY SLOT]
	
	# BYTE 4 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send the 'success' check
	li		$a0, 0x00					# [DELAY SLOT]
	
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lerror
	#nop
	
	# Do we need a response for this packet type?
	# Ping should always return 0x27
	# But older/bugged firmwares may not return 0x20
	# for directory switching, let's cover those cases
	andi	$a0,	$a2,	0x100
	beq 	$a0, $zero, .Lresponse_not_required
	nop

	andi	$a2,	$a2, 0xFF
	bne		$v0,	$a2, .Lerror 		# If we do not get 0x20/0x27 back, branch
	addiu	$v0, $zero, 4				# Return a value of 4 [DELAY SLOT]
.Lresponse_not_required:
	# BYTE 5 -----------------------------------------------------------------
	jal		MemCardPro_Exchng			# Send the 'termination signal'
	# Load 0x01 into the high word, since it's the last byte in the sequence
	lui		$a0, 0x01					# [DELAY SLOT]
		
	#jal	MemCardPro_Wait
	#li		$a0, JOY_DELAY_COUNTER
	
	# return the result now (debugging)
	#b		.Lerror
	#nop
	
	bne		$v0, 0xFF, .Lerror	 		# If we do not get 0xFF back, branch
	addiu	$v0, $zero, 5				# Return a value of 5 [DELAY SLOT]
	# ------------------------------------------------------------------------
	
	addiu	$v0, $zero, 0				# No errors (return a value of 0)


# !error handler	
.Lerror:
	sb		$zero, JOY_TXRX($t0)		# Get the end byte
	nop
	
	sh		$zero, JOY_CTRL($t0)		# Apparently required

	lw		$ra, 0($sp)
	addiu	$sp, 4
	jr		$ra
	nop


# arguments:
#	$a0 (port number)
#
# return values:
#	0 = no error (MemCard Pro detected)
#	1 = bus select fail (no memory card device detected)
#	2 = ping fail (no response from the MemCard Pro)
#	3 = reserve fail (reserved for future use (ignore this))
#	4 = card present fail (no card is present)
#	5 = termination signal fail (no termination signal detected)
MemCardPro_Ping:
	addiu	$sp, -4
	sw		$ra, 0($sp)
	
	li		$a2, 0x127
	jal		MemcardPro_SimpleCommand
	li 		$a1,	0x20
	
	lw		$ra, 0($sp)
	addiu	$sp, 4
	jr		$ra
	nop
	
# arguments:
#	$a0 (port number)
#
# return values:
#	0 = no error (MemCard Pro detected)
#	1 = bus select fail (no memory card device detected)
#	2 = next channel (failed to select the next channel)
#	3 = reserve fail (reserved for future use (ignore this))
#	4 = success fail (device success flag check failed)
#	5 = termination signal fail (no termination signal detected)
MemCardPro_NextCH:
	addiu	$sp, -4
	sw		$ra, 0($sp)
	
	li		$a2, 0x20
	jal		MemcardPro_SimpleCommand
	li 		$a1,	0x23
	
	lw		$ra, 0($sp)
	addiu	$sp, 4
	jr		$ra
	nop


# arguments:
#	$a0 (port number)
#
# return values:
#	0 = no error (MemCard Pro detected)
#	1 = bus select fail (no memory card device detected)
#	2 = previous channel (failed to select the previous channel)
#	3 = reserve fail (reserved for future use (ignore this))
#	4 = success fail (device success flag check failed)
#	5 = termination signal fail (no termination signal detected)
MemCardPro_PrevCH:
	addiu	$sp, -4
	sw		$ra, 0($sp)

	li		$a2, 0x20
	jal		MemcardPro_SimpleCommand
	li 		$a1,	0x22
	
	lw		$ra, 0($sp)
	addiu	$sp, 4
	jr		$ra
	nop


# arguments:
#	$a0 (port number)
#
# return values:
#	0 = no error (MemCard Pro detected)
#	1 = bus select fail (no memory card device detected)
#	2 = next channel (failed to select the next card)
#	3 = reserve fail (reserved for future use (ignore this))
#	4 = success fail (device success flag check failed)
#	5 = termination signal fail (no termination signal detected)
MemCardPro_NextDIR:
	addiu	$sp, -4
	sw		$ra, 0($sp)

	li		$a2, 0x20
	jal		MemcardPro_SimpleCommand
	li 		$a1,	0x25
	
	lw		$ra, 0($sp)
	addiu	$sp, 4
	jr		$ra
	nop


# arguments:
#	$a0 (port number)
#
# return values:
#	0 = no error (MemCard Pro detected)
#	1 = bus select fail (no memory card device detected)
#	2 = previous channel (failed to select the previous card)
#	3 = reserve fail (reserved for future use (ignore this))
#	4 = success fail (device success flag check failed)
#	5 = termination signal fail (no termination signal detected)
MemCardPro_PrevDIR:
	addiu	$sp, -4
	sw		$ra, 0($sp)

	li		$a2, 0x20
	jal		MemcardPro_SimpleCommand
	li 		$a1,	0x24
	
	lw		$ra, 0($sp)
	addiu	$sp, 4
	jr		$ra
	nop


# handler/processor
# $a0 = byte to send
# $a0 & 0x000010000 == final byte in the sequnce (do not wait for /ACK)
MemCardPro_Exchng:
	addiu	$sp, -4
	sw		$ra, 0($sp)
	
	# We don't need to /ACK the final byte in a sequence
	# so we can return early if this bit is set.
	lui		$t0, 0x01
	li		$t1,	0x00
	and		$t0,	$a0,	$t0
	beq 	$t0, $zero, .Lno_final_byte
	nop
	
	# It's the last byte in the sequence, so
	# set $t1 for an early return
	li		$t1,0x01
.Lno_final_byte:
	lui		$t0, IOBASE

	sb		$a0, JOY_TXRX($t0)
	nop

.Lsend_wait_exchg:
	lhu		$v0, JOY_STAT($t0)
	nop
	andi	$v0, 0x2 # JOY_STAT value
	beq 	$v0, $zero, .Lsend_wait_exchg
	nop

	# We've got a byte waiting in the RX buffer
	# But it's the last in the sequence, so 
	# We don't need to wait for an /ACK
	bnez	$t1, .Ldone
	nop

	lui		$a0, 0xBFC0
	move	$v1, $zero # set $v1 to zero
.Lwait_ack_exchg:
	bgt		$v1, 4500, .Ltimeout # ACK delay (4500 * 7 instructions = 31,500 cycles)
	nop
	lhu		$v0, JOY_STAT($t0)
	lw		$zero, 4($a0)
	lw		$zero, 0($a0)
	andi	$v0, 0x202
	bne		$v0, 0x202, .Lwait_ack_exchg
	addiu	$v1, 1
	
	b		.Ldone
	nop
.Ltimeout:
	lbu		$v0, JOY_TXRX($t0)
	nop
	b		.Lexit_exchg
	#ori		$v0, 0x100				# Add 0x100 (used as a timeout flag on bit 8 of the $v0 register. we could use andi and mask it, but we'll just nop it)
	nop
.Ldone:
	lhu		$v1, JOY_CTRL($t0)
	lbu		$v0, JOY_TXRX($t0)
	or		$v1, 0x10
	sh		$v1, JOY_CTRL($t0)
.Lexit_exchg:
	# Add a standard delay to pad us out to about 18us
	# Not strictly necessary, but it's not a noticable delay
	# and falls roughly in line with other implementations
	jal MemCardPro_Wait
	li		$a0,0x70

	lw		$ra, 0($sp)
	nop		
	addiu	$sp, 4
	jr		$ra
	nop


# simple delay loop (each instruction adds 1 cycle so a wait of 150 in $t1 results in 500 cycles)
# $a0 = delay
MemCardPro_Wait:
    addiu   $a0, -1
    bgtz    $a0, MemCardPro_Wait
    nop
	
    jr      $ra
    nop


# No pa$rams, will wait long enough to do a ping followed by a 
# SendGameID on the same f$rame
# (with a lot of wiggle room# 2.5ms in this case)
# Where possible, just wait a f$rame instead.
MemcardPro_InterCommandDelay:
	addiu	$sp, -4
	sw		$ra, 0($sp)
	
	li 		$a0, 0x7000
	jal		MemCardPro_Wait

	lw		$ra, 0($sp)
	nop		
	addiu	$sp, 4
	jr		$ra
	nop


# includes
.include "memcardpro_regs.asm"
