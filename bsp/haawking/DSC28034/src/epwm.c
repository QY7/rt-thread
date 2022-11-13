/******************************************************************
 文 档 名：     epwm.c
 D S P    ：     DSC28034
 使 用 库：
 作     用：
 说     明：    提供epwm.c接口初始化配置
 ---------------------------- 使用说明 ----------------------------
 功能描述：


 版 本：V1.0.0
 时 间：2022年8月25日
 作 者：heyang
 @ mail：support@mail.haawking.com
 ******************************************************************/

#include "epwm.h"

/******************************************************************
 函数名：void  InitEPwm1_Gpio(void)
 参	数：无
 返回值：无
 作	用：配置GPIO0、GPIO1、GPIO2、GPIO3配置成epwm模式，
 ******************************************************************/

void InitEPwm1_Gpio(void)
{
	EALLOW;

	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;

	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;

	EDIS;
}

/******************************************************************
 函数名：void  pwm1_config(void)
 参	数：无
 返回值：无
 作	用：
 TBCLK = SYSCLKOUT/(HSPCLKDIV*CLKDIV)
 配置pwm1为中心对齐方式，
 如果是向上或者向下计数模式PWM的周期计算公式=TBCLK*TBPRD,
 PWM1A的占空比= CMPA/TBPRD,
 PWM1B的占空比 = CMPB/TBPRD，
 中心对齐方式PWM得周期计算公式 = 2*TBCLK*TBPRD
 ******************************************************************/

void pwm1_config()
{
	EPwm1Regs.TBPRD = 3750;                                                /*设定pwm的周期是2*3750个TBCLK时钟周期，频率16K*/
	EPwm1Regs.CMPA.half.CMPA = 1875;                                /*比较器A为1875个TBCLK时钟周期,占空比1875/3750=50%*/
	EPwm1Regs.CMPB = 1000;                                                  /*比较器B为1000个TBCLK时钟周期,占空比（3750-1000）/3750=73.33%*/
	EPwm1Regs.TBCTR = 0x0000;                                             /*清除计数器*/
	EPwm1Regs.TBPHS.half.TBPHS = 0x0000;                           /*相位寄存器清零，是设置翻转计数器的时刻*/

//    EPwm1Regs.AQCTLA.bit.ZRO = 0;                                    /*最小值*/
//  	EPwm1Regs.AQCTLA.bit.PRD = 0x10;                               /*当时基计数器的值与周期寄存器的值相等时置位*/
	EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;                        /*向下计数时，时基计数器的值与CMPA寄存器的值相等时清零*/
	EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;                             /*向上计数时，时基计数器的值与CMPA寄存器的值相等时置1*/
	EPwm1Regs.AQCTLB.bit.CBD = AQ_CLEAR;                         /*向下计数时，时基计数器的值与CMPB寄存器的值相等时清零*/
	EPwm1Regs.AQCTLB.bit.CBU = AQ_SET;                              /*向上计数时，时基计数器的值与CMPB寄存器的值相等时置1*/

	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;  /*向上向下计数方式*/
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;                        /*计数寄存器装载相位寄存器禁止装载*/
	EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;                      /*当计数器的值为0时周期寄存器TBPRD装载影子寄存器的值*/
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;              /*同步信号输出选择，当时基计数器等于0时，ePWMxSYNCO信号输出*/
	EPwm1Regs.TBCTL.bit.SWFSYNC = 0;                                    /*软件强制同步脉冲，写0没有效果*/
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm1Regs.ETSEL.bit.INTSEL = ET_DCAEVT1SOC;                /*保留*/
	EPwm1Regs.ETSEL.bit.INTEN = 0;                                          /*Disable EPWMx_INT generation*/
	EPwm1Regs.ETSEL.bit.SOCASEL = 2;                                     /*当TB计数器等于周期的时候 EPWMxSOCA 脉冲将产生*/
	EPwm1Regs.ETSEL.bit.SOCAEN = 1;                                       /*使能EPWMxSOCA pulse*/
	EPwm1Regs.ETSEL.bit.SOCBEN = 0;
	EPwm1Regs.ETSEL.bit.SOCBSEL = 0;

	EPwm1Regs.ETPS.bit.SOCAPRD = 1;
}





