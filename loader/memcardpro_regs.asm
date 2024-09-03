# hardware register definitions

.equ IOBASE, 			0x1F80	# IO segment base

# GPU
.equ GP0, 				0x1810 	# also GPUREAD
.equ GP1, 				0x1814 	# also GPUSTAT

# CD
.equ CD_STAT, 			0x1800
.equ CD_CMD, 			0x1801 	# also response FIFO
.equ CD_DATA, 			0x1802 	# also parameters
.equ CD_IRQ, 			0x1803

.equ CD_REG0,			0x1800
.equ CD_REG1,			0x1801
.equ CD_REG2,			0x1802
.equ CD_REG3,			0x1803

.equ SBUS_5, 			0x1018
.equ COM_DELAY, 		0x1020

# SPU (must be used with 16-bit load/store instructions)
.equ SPU_VOICE_BASE,	0x1C00

.equ SPU_MASTER_VOL, 	0x1D80
.equ SPU_REVERB_VOL, 	0x1D84
.equ SPU_KEY_ON, 		0x1D88
.equ SPU_KEY_OFF, 		0x1D8C
.equ SPU_FM_MODE, 		0x1D90
.equ SPU_NOISE_MODE, 	0x1D94
.equ SPU_REVERB_ON, 	0x1D98
.equ SPU_CHAN_STATUS, 	0x1D9C

.equ SPU_REVERB_ADDR, 	0x1DA2
.equ SPU_IRQ_ADDR, 		0x1DA4
.equ SPU_ADDR,			0x1DA6
.equ SPU_DATA, 			0x1DA8

.equ SPUCNT, 			0x1DAA
.equ SPUDTCNT, 			0x1DAC
.equ SPUSTAT, 			0x1DAE

.equ SPU_CD_VOL, 		0x1DB0
.equ SPU_EXT_VOL, 		0x1DB4
.equ SPU_CURRENT_VOL, 	0x1DB8

.equ SPU_VOICE_VOL_L, 	0x00
.equ SPU_VOICE_VOL_R, 	0x02
.equ SPU_VOICE_FREQ, 	0x04
.equ SPU_VOICE_ADDR, 	0x06
.equ SPU_VOICE_ADSR_L, 	0x08
.equ SPU_VOICE_ADSR_H, 	0x0A		
.equ SPU_VOICE_LOOP, 	0x0E

# MDEC
.equ MDEC0, 			0x1820
.equ MDEC1, 			0x1824

# Pads
.equ JOY_TXRX, 			0x1040
.equ JOY_STAT, 			0x1044
.equ JOY_MODE, 			0x1048
.equ JOY_CTRL, 			0x104A
.equ JOY_BAUD, 			0x104E

# Serial
.equ SIO_TXRX, 			0x1050
.equ SIO_STAT, 			0x1054
.equ SIO_MODE, 			0x1058
.equ SIO_CTRL, 			0x105A
.equ SIO_BAUD, 			0x105E

# IRQ
.equ ISTAT, 			0x1070
.equ IMASK, 			0x1074

# DMA
.equ DPCR, 				0x10F0     
.equ DICR, 				0x10F4

.equ D0_MADR, 			0x1080
.equ D0_BCR, 			0x1084
.equ D0_CHCR, 			0x1088

.equ D1_MADR, 			0x1090
.equ D1_BCR, 			0x1094
.equ D1_CHCR, 			0x1098

.equ D2_MADR, 			0x10A0
.equ D2_BCR, 			0x10A4
.equ D2_CHCR, 			0x10A8

.equ D3_MADR, 			0x10B0
.equ D3_BCR, 			0x10B4
.equ D3_CHCR, 			0x10B8

.equ D4_MADR, 			0x10C0
.equ D4_BCR, 			0x10C4
.equ D4_CHCR, 			0x10C8

.equ D6_MADR, 			0x10E0
.equ D6_BCR, 			0x10E4
.equ D6_CHCR, 			0x10E8

# Timers
.equ T0_CNT, 			0x1100
.equ T0_MODE, 			0x1104
.equ T0_TGT, 			0x1108

.equ T1_CNT,			0x1110
.equ T1_MODE, 			0x1114
.equ T1_TGT, 			0x1118

.equ T2_CNT, 			0x1120
.equ T2_MODE, 			0x1124
.equ T2_TGT, 			0x1128
