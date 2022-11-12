//###########################################################################
//
// FILE:    ier_unset.S
//
// TITLE:   ier_unset Initialization & Support Functions.
//
//###########################################################################
// $HAAWKING Release: DSP2803x Support Library V1.1.0 $
// $Release Date: 2022-07-09 04:53:39 $
// $Copyright:
// Copyright (C) 2019-2022 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


.section  .text 

.global	 ier_unset

ier_unset:
csrc 0x304,a0  //IER &= ~a0 
ret


	

