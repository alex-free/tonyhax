
.text
.align 4

##########
# EXTRAS #
##########

.global FakeEnqueueCdIntr
FakeEnqueueCdIntr:
	lw $31, 0x14($29)
	addi $29, 0x18
	jr $31

############
# SYSCALLS #
############

.global EnterCriticalSection
EnterCriticalSection:
	li $4, 0x01
	syscall
	jr $31

.global ExitCriticalSection
ExitCriticalSection:
	li $4, 0x02
	syscall
	jr $31

###############
# A-FUNCTIONS #
###############

.global todigit
todigit:
	li $9, 0x0A
	j 0xA0

.global strcmp
strcmp:
	li $9, 0x17
	j 0xA0

.global strncmp
strncmp:
	li $9, 0x18
	j 0xA0

.global strcpy
strcpy:
	li $9, 0x19
	j 0xA0

.global strlen
strlen:
	li $9, 0x1B
	j 0xA0

.global strchr
strchr:
	li $9, 0x1E
	j 0xA0

.global memcpy
memcpy:
	li $9, 0x2A
	j 0xA0

.global DoExecute
DoExecute:
	# Pepsiman (J) crashes if $21 is not zero
	# The BIOS leaves them $17-s6 zeroed, so we'll do the same
	li $17, 0
	li $18, 0
	li $19, 0
	li $20, 0
	li $21, 0
	li $22, 0
	li $9, 0x43
	j 0xA0

.global FlushCache
FlushCache:
	li $9, 0x44
	j 0xA0

.global init_a0_b0_c0_vectors
init_a0_b0_c0_vectors:
	li $9, 0x45
	j 0xA0

.global GPU_dw
GPU_dw:
	li $9, 0x46
	j 0xA0

.global SendGP1Command
SendGP1Command:
	li $9, 0x48
	j 0xA0

.global GPU_cw
GPU_cw:
	li $9, 0x49
	j 0xA0

.global GPU_cwp
GPU_cwp:
	li $9, 0x4A
	j 0xA0

.global LoadAndExecute
LoadAndExecute:
	li $9, 0x51
	j 0xA0

.global CdInit
CdInit:
	li $9, 0x54
	j 0xA0

.global SetConf
SetConf:
	li $9, 0x9C
	j 0xA0

.global CdReadSector
CdReadSector:
	li $9, 0xA5
	j 0xA0

.global CdGetLbn
CdGetLbn:
	li $9, 0xA4
	j 0xA0

.global SetMemSize
SetMemSize:
	li $9, 0x9F
	j 0xA0

###############
# B-FUNCTIONS #
###############

.global SetDefaultExitFromException
SetDefaultExitFromException:
	li $9, 0x18
	j 0xB0

.global FileOpen
FileOpen:
	li $9, 0x32
	j 0xB0

.global FileRead
FileRead:
	li $9, 0x34
	j 0xB0

.global FileClose
FileClose:
	li $9, 0x36
	j 0xB0

.global FormatDevice
FormatDevice:
	li $9, 0x41
	j 0xB0

.global GetLastError
GetLastError:
	li $9, 0x54
	j 0xB0

.global GetC0Table
GetC0Table:
	li $9, 0x56
	j 0xB0

.global GetB0Table
GetB0Table:
	li $9, 0x57
	j 0xB0

###############
# C-FUNCTIONS #
###############

.global InstallExceptionHandlers
InstallExceptionHandlers:
	li $9, 0x07
	j 0xC0

.global InstallDevices
InstallDevices:
	li $9, 0x12
	j 0xC0

.global AdjustA0Table
AdjustA0Table:
	li $9, 0x1C
	j 0xC0
