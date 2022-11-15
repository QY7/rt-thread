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

.global	 ifr_set

ifr_set:
csrs 0x344,a0  //IFR |= a0 
 ret


	

