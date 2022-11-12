/******************************************************************
 文 档 名：     HX_DSC28034_SCI_FIFO_INTERRUPT
 开 发 环 境：Haawking IDE V2.0.0
 开 发 板：     DSC28034核心板
 D S P：         DSC28034
 使 用 库：
 作     用：      通过配置SCI模块寄存器，使能串口发送和接收
 说     明：      FLASH工程
 -------------------------- 例程使用说明 --------------------------
 功能描述：芯片主频120MHz，通过配置SCIA的寄存器，实现SCIA模块FIFO模式的发
 送和接收中断功能

 连接方式：通过CH340串口线连接电脑端的USB口

 现象：（1）电脑端使用串口调试助手，按照SCIA配置中的参数设置波特率、数据位、校验
 位、和停止位。发送4个字节，DSP会返回循环接收到的数据
 （2）通过串口调试助手发送一次数据，可通过接收中断执行，会看到LED亮一次灭一次
注意：不要用hex显示

 版 本：V1.0.0
 时 间：2022年8月25日
 作 者：heyang
 @ mail：support@mail.haawking.com
 ******************************************************************/

 
#include "dsc_config.h"
#include <syscalls.h>
#include "IQmathLib.h"

#include "../application/sci.h"

void InitLED(void);

int main(void)
{
	/*初始化系统控制*/
		InitSysCtrl();

		/*初始化内存控制寄存器，使能内存流水线模式*/
		InitFlash();

		/*初始化串口通信的GPIO口*/
		/*GPIO28: SCIRXDA*/
		/*GPIO29: SCITXDA*/
		InitSciGpio();
		InitLED();

		/*不使能CPU中断*/
		IER = 0x0000;
		/*清除所有的CPU中断标志*/
		IFR = 0x0000;
		/*初始化中断向量表*/
		InitPieVectTable();

		EALLOW;
		PieVectTable.SCITXINTA = &scia_transmit_isr;
		PieVectTable.SCIRXINTA = &scia_received_isr;
		EDIS;

		/*SCI寄存器配置*/
		Scia_Config(9600);



		/*打开IER的第9组中断向量*/
		IER |= M_INT9;

		/*打开PIEIER的第9组的第一与第二个中断向量*/
		PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
		PieCtrlRegs.PIEIER9.bit.INTx2 = 1;

		/*使能全局中断向量*/
		EINT;

		while(1)
		{

		}

	return 0;
}


/******************************************************************
 函数名：void InitLED()
 参	数：无
 返回值：无
 作	用：初始化LED
 说	明：
 ******************************************************************/
void InitLED()
{
	EALLOW;
	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1; /*输出*/
	EDIS;
}

// ----------------------------------------------------------------------------
