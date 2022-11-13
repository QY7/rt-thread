//###########################################################################
//
// FILE:    _DSP2803x_usDelay.S
//
// TITLE:   _DSP2803x_usDelay Initialization & Support Functions.
//
//###########################################################################
// $HAAWKING Release: DSP2803x Support Library V1.1.0 $
// $Release Date: 2022-07-09 04:53:39 $
// $Copyright:
// Copyright (C) 2019-2022 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


.section  ramfuncs1, "ax", @progbits

.global	 _DSP2803x_usDelay


_DSP2803x_usDelay:

.align 1
	addi  sp,sp,-20
	sw    a1,16(sp) 
	csrr  a1,0x7c0
	sw    a1,12(sp)
	csrr  a1,mstatus
	
.align 2
	rpt a0,4
	nop
   
	csrw  mstatus,a1
	lw    a1,12(sp)
	csrw  0x7c0,a1
	lw    a1,16(sp)
	addi  sp,sp,20

	ret
	
.size  _DSP2803x_usDelay,   .-_DSP2803x_usDelay
