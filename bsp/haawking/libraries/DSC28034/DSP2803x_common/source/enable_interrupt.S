//###########################################################################
//
// FILE:    enable_interrupt.S
//
// TITLE:   enable_interrupt Initialization & Support Functions.
//
//###########################################################################
// $HAAWKING Release: DSP2803x Support Library V1.1.0 $
// $Release Date: 2022-07-09 04:53:39 $
// $Copyright:
// Copyright (C) 2019-2022 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

.section  .text 

.global	 enable_interrupt



enable_interrupt:
    li a0, 0x88
    csrs mstatus, a0
	ret


	

