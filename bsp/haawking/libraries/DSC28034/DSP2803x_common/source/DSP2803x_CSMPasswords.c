//###########################################################################
//
// FILE:	DSP2803x_CSMPasswords.c
//
// TITLE:	DSP2803x Code Security Module Passwords.
// 
// DESCRIPTION:
//
//         This file is used to specify password values to
//         program into the CSM password locations in Flash
//         at 0x3F7FF8 - 0x3F7FFF.
//
//         In addition, the reserved locations 0x3F7F80 - 0X3f7ff5 are 
//         all programmed to 0x0000
//
//###########################################################################
// $HAAWKING Release: DSP2803x Support Library V1.1.0 $
// $Release Date: 2022-07-09 04:53:39 $
// $Copyright:
// Copyright (C) 2019-2022 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################
#include "DSP2803x_Device.h"     //  Headerfile Include File
/**********************************************
password file
*****************************************************************/

volatile struct CSM_PWL  CODE_SECTION(".CsmPwl") CsmPwl = 
{
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
};


void init_call(void)
{
	CsmPwl.PSWD0;
	CsmPwl.PSWD1;
	CsmPwl.PSWD2;
	CsmPwl.PSWD3;
}




