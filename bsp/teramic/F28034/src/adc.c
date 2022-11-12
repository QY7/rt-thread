/******************************************************************
 文 档 名：     adc.c
 D S P：       DSC28034
 使 用 库：     
 作     用：      
 说     明：      提供adc.c接口初始化配置
 ---------------------------- 使用说明 ----------------------------
 功能描述：


 版 本：V1.0.x
 时 间：2021年11月13日
 作 者：
 @ mail：support@mail.haawking.com
 ******************************************************************/

#include "adc.h"

/******************************************************************
 函数名：void  ADC_Init(void)
 参	数：无
 返回值：无
 作	用：配置ADCINA7为ADC转换通道，6个clock的采样周期，触发源为epwm1的ADCSOCA
 ******************************************************************/

void ADC_Init(void)
{
	EALLOW;
	AdcRegs.ADCCTL1.bit.ADCENABLE = 1; /* 使能ADC，并给ADC上电，写0无效，写1使能ADC */

	/* AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1;     当系统时钟是120M的时候，使能这个寄存器的位，配置为1，为SYSCLK/4 */
	/* 当系统时钟是60M的时候，可以保持默认值0，为SYSCLK/2 */
	AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1;

	while(AdcRegs.ADCCTL1.bit.ADCRDY != 1)
	{

	} /* ADC 复位完成，当ADCRDY = 1表示复位完成，0表示复位未完成 */
	AdcRegs.INTSEL1N2.bit.INT1SEL = 0; /* ADCINT1 EOC 源选择 EOC0 作为 ADCINT1作为触发源 */
	AdcRegs.INTSEL1N2.bit.INT1E = 1; /*  ADCINT1中断使能 */
	AdcRegs.INTSEL1N2.bit.INT1CONT = 0; /* 没有进一步的中断脉冲产生直到中断信号标志位被清除 */
	AdcRegs.SOCPRICTL.bit.ONESHOT = 0; /* One shot 模式不使能 */
	AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0;
	AdcRegs.SOCPRICTL.bit.RRPOINTER = 0; /* SOC0是最后一个转换，SOC1是最高的round robin优先 */
	AdcRegs.ADCSOC0CTL.bit.ACQPS = 0; /* 窗口的采样周期是2n+6个clock cycles */
	AdcRegs.ADCSOC0CTL.bit.CHSEL = 0x7; /* 选择转换的输入通道是ADCINA5 */
	AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 0x5; /* SOC0的触发源是epwm1的ADCSOCA */
	/* ADCSOCFRC1  ADCINTSOCSEL1 */
	/* 	AdcRegs.ADCINTSOCSEL1.bit.SOC0 = 1; */
	/* 	AdcRegs.ADCSOCFRC1.bit.SOC0 = 1; */
	/* 	AdcRegs.INTSEL1N2.bit.INT1CONT = 1; */
	EDIS;
}

