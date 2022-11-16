///*
// * Copyright (c)
// * All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are
// * met: redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer;
// * redistributions in binary form must reproduce the above copyright
// * notice, this list of conditions and the following disclaimer in the
// * documentation and/or other materials provided with the distribution;
// * neither the name of the copyright holders nor the names of its
// * contributors may be used to endorse or promote products derived from
// * this software without specific prior written permission.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
// * Authors:
// * Email  :
// * FILE   : main.c
// *****************************************************************/
//
///******************************************************************
// 项目名：  TEST
// DSP:    DSC28034
// IDE：      teramic-workspace-V1.5.01
// 版	本：  V0.0.2
// 时	间：   2021年11月13日 15:48
// 作	者：
// mail :
// ******************************************************************/
//
//#include "dsc_config.h"
//#include <syscalls.h>
//#include "IQmathLib.h"
//#include "sci.h"
//
///*函数原型*/
//void InitKEY(void);
//void InitLED(void);
//
//char flag = 1;
//
//
//void adc_isr();
//
//int main(void)
//{
//	InitSysCtrl(); /*Initializes the System Control registers to a known state.*/
//	InitSciGpio();
//	DINT;
//	IER_DISABLE(0xffff); /*禁能所有中断*/
//	IFR_DISABLE(0xffff); /*清所有中断标志位*/
//	InitPieVectTable(); /*This function initializes the PIE vector table to a known state.This function must be executed after boot time.*/
//
//	EALLOW;
//	PieCtrlRegs.PIEACK.all = 0xffff; /*清除所有中断*/
//	EDIS;
//
//	InitKEY();
//	InitLED();
//	Scia_Config(9600);
//
//	EINT;
//	ERTM;
//
//	while (1)
//	{
//		if (GpioDataRegs.GPBDAT.bit.GPIO43 == 0)
//		{
//			GpioDataRegs.GPBCLEAR.bit.GPIO44 = 1;
//			GpioDataRegs.GPBSET.bit.GPIO39 = 1;
//			if(flag == 1){
//				Scia_Print("Press down\r\n ");
//				flag = 0;
//			}
//		}
//		else
//		{
//			GpioDataRegs.GPBCLEAR.bit.GPIO39 = 1;
//			GpioDataRegs.GPBSET.bit.GPIO44 = 1;
//			if(flag == 0){
//				Scia_Print("Press up\r\n ");
//				flag = 1;
//			}
//		}
//
//	}
//
//	return 0;
//}
//
///******************************************************************
// 函数名：void  InitKEY(void)
// 参	数：无
// 返回值：无
// 作	用：配置GPIO43为输入模式，上拉禁止
// ******************************************************************/
//
//void InitKEY(void)
//{
//	EALLOW;
//	GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 0;
//	GpioCtrlRegs.GPBDIR.bit.GPIO43 = 0;
//	GpioCtrlRegs.GPBPUD.bit.GPIO43 = 1;
//	EDIS;
//
//}
//
///******************************************************************
// 函数名：void  InitLED(void)
// 参	数：无
// 返回值：无
// 作	用：配置GPIO00 1为输出模式
// ******************************************************************/
//
//void InitLED(void)
//{
//	EALLOW;
//	GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 0;  //普通IO，对应D400，LED灯
//	GpioCtrlRegs.GPBDIR.bit.GPIO44 = 1;   //输出
//	GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 0;   //普通IO，对应D401，LED灯
//	GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 0;  //普通IO，对应D400，LED灯
//	GpioCtrlRegs.GPBDIR.bit.GPIO39= 1;   //输出
//	GpioCtrlRegs.GPBMUX1.bit.GPIO39= 0;   //普通IO，对应D401，LED灯
//	EDIS;
//
//}
//
//// ----------------------------------------------------------------------------
