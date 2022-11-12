/******************************************************************
 文 档 名：     epwm.c
 D S P：       DSC28034
 使 用 库：     
 作     用：      
 说     明：      提供epwm.c接口初始化配置
 ---------------------------- 使用说明 ----------------------------
 功能描述：


 版 本：V1.0.x
 时 间：2021年11月13日
 作 者：
 @ mail：support@mail.haawking.com
 ******************************************************************/

#include "epwm.h"

/******************************************************************
 函数名：void  pwm1_gpio_init(void)
 参	数：无
 返回值：无
 作	用：配置GPIO0、GPIO1为禁止上拉模式，设置GPIO0为PWM1A，GPIO1为PWM1B
 ******************************************************************/

void pwm1_gpio_init()
{
	EALLOW;

	GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1; /* Disable pull-up on GPIO(EPWM1) */

	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; /* 设置GPIO0为PWM1A */
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;

	EDIS;
}

/******************************************************************
 函数名：void  pwm1_config(void)
 参	数：无
 返回值：无
 作	用：配置pwm1为向上向下模式，配置产生epwm1socA事件，
 ******************************************************************/

void pwm1_config()
{
	EPwm1Regs.TBPRD = 0x599; /* 设定pwm的周期是1433个TBclk时钟周期 */
	EPwm1Regs.CMPA.half.CMPA = 0x200; /* 比较器A为512个TBCLK时钟周期 */
	EPwm1Regs.CMPB = 0x300; /* 比较器B为768个TBCLK时钟周期 */
	EPwm1Regs.TBCTR = 0x0000; /* clear counter */
	EPwm1Regs.TBPHS.half.TBPHS = 0x0000; /* 相位寄存器清零，是设置翻转计数器的时刻 */

	/* EPwm1Regs.AQCTLA.bit.ZRO = 0;    最小值 */
	/* EPwm1Regs.AQCTLA.bit.PRD = 0x10;   当时基计数器的值与周期寄存器的值相等时置位 */
	EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR; /* 向下计数时，时基计数器的值与CMPA寄存器的值相等时清零 */
	EPwm1Regs.AQCTLA.bit.CAU = AQ_SET; /* 向上计数时，时基计数器的值与CMPA寄存器的值相等时置1 */
	EPwm1Regs.AQCTLB.bit.CBD = AQ_CLEAR; /* 向下计数时，时基计数器的值与CMPB寄存器的值相等时清零 */
	EPwm1Regs.AQCTLB.bit.CBU = AQ_SET; /* 向上计数时，时基计数器的值与CMPB寄存器的值相等时置1 */

	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; /* 向上向下计数方式 */
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE; /* 计数寄存器装载相位寄存器禁止装载 */
	EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW; /* 当计数器的值为0时周期寄存器TBPRD装载影子寄存器的值 */
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO; /* 同步信号输出选择，当时基计数器等于0时，ePWMxSYNCO信号输出 */
	EPwm1Regs.TBCTL.bit.SWFSYNC = 0; /* 软件强制同步脉冲，写0没有效果 */
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0;

	EPwm1Regs.ETSEL.bit.INTSEL = ET_DCAEVT1SOC; /* 保留 */
	EPwm1Regs.ETSEL.bit.INTEN = 0; /* Disable EPWMx_INT generation */
	EPwm1Regs.ETSEL.bit.SOCASEL = 2; /* 当TB计数器等于周期的时候 EPWMxSOCA 脉冲将产生 */
	EPwm1Regs.ETSEL.bit.SOCAEN = 1; /* 使能EPWMxSOCA pulse */
	EPwm1Regs.ETSEL.bit.SOCBEN = 0;
	EPwm1Regs.ETSEL.bit.SOCBSEL = 0;

	EPwm1Regs.ETPS.bit.SOCAPRD = 1;
}

