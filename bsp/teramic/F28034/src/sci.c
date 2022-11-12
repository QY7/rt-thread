/******************************************************************
 文 档 名：     sci.c
 D S P：       DSC28034
 使 用 库：     
 作     用：      
 说     明：      提供sci.c接口初始化配置
 ---------------------------- 使用说明 ----------------------------
 功能描述：


 版 本：V1.0.x
 时 间：2021年11月13日
 作 者：
 @ mail：support@mail.haawking.com
 ******************************************************************/

#include "sci.h"

/******************************************************************
 *函数名：Scia_Config(uint32 baud)
 *参   数： baud，串口波特率
 *返回值：无
 *作   用： SCIA 初始化配置
 ******************************************************************/
void Scia_Config(uint32 baud)
{
	uint32 div = 0;
	uint32 divsel = 0;
	uint32 lospcp = 0;
	uint32 lspclk = 0;
	uint16 brr = 0;

	/*获取系统时钟的倍频、分频和低速外部时钟的值*/
	div = SysCtrlRegs.PLLCR.bit.DIV;
	divsel = SysCtrlRegs.PLLSTS.bit.DIVSEL;
	lospcp = SysCtrlRegs.LOSPCP.bit.LSPCLK;

	if(lospcp != 0)
	{
		lospcp = lospcp * 2;
	}
	else
	{
		lospcp = 1;
	}

	/*分频值设置
	 divsel为 0时，系统时钟4分频
	 divsel为 1时，系统时钟4分频
	 divsel为 2时，系统时钟2分频
	 divsel为 3时，系统时钟1分频*/
	switch(divsel)
	{
	case 0:
	case 1:
		lspclk = 12000000 * div / 4 / lospcp;
		break;
	case 2:
		lspclk = 12000000 * div / 2 / lospcp;
		break;
	case 3:
		lspclk = 12000000 * div / 1 / lospcp;
		break;
	}

	brr = lspclk / (baud * 8) - 1;

	/*SCI 停止位设置    0：一个停止位   1：两个停止位*/
	SciaRegs.SCICCR.bit.STOPBITS = 0;

	/*SCI 奇偶校验位    0：奇偶校验   1：偶偶校验*/
	SciaRegs.SCICCR.bit.PARITY = 0;

	/*SCI 奇偶校验使能   0：关闭   1：启用*/
	SciaRegs.SCICCR.bit.PARITYENA = 0;

	/*SCI 字符长度   0：1个字长  1：2个字长 ... 7：8个字长*/
	SciaRegs.SCICCR.bit.SCICHAR = 7;

	/*使能SCI的发送机和接收机*/
	SciaRegs.SCICTL1.bit.TXENA = 1;
	SciaRegs.SCICTL1.bit.RXENA = 1;

	/*SCI 16位波特率选择寄存器 高8位*/
	SciaRegs.SCIHBAUD = (uint8)((brr >> 8) & 0xff);
	/*SCI 16位波特率选择寄存器 低8位*/
	SciaRegs.SCILBAUD = (uint8)(brr & 0xff);

	/*SCI 软件复位，重新启动SCI*/
	SciaRegs.SCICTL1.bit.SWRESET = 1;
}

/******************************************************************
 *函数名：Scia_Print(char *str)
 *参   数： *str，要发送的字符串
 *返回值：无
 *作   用： SCIA 发送一个字符串
 ******************************************************************/
void Scia_Print(char *str)
{
	while(*str != '\0')
	{
		while(SciaRegs.SCICTL2.bit.TXRDY == 0)
		{
		}

		SciaRegs.SCITXBUF = *str++;
	}
}

