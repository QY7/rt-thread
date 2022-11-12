#include "../application/sci.h"



/******************************************************************
*函数名：scia_transmit_isr(void)
*返回值：无
*作   用： SCIA 发送FIFO空中断处理
******************************************************************/
void INTERRUPT scia_transmit_isr(void)
{
	uint8 cnt;
	cnt = 0x41;
//	/*用户处理代码*/
	Scia_Send(cnt);

	/*SCI发送中断清除，使得中断可连续执行多次*/
	SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;

	/*中断应答*/
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

/******************************************************************
*函数名：scia_received_isr(void)
*返回值：无
*作   用： SCIA 接收中断:循环接收发送的数据
******************************************************************/
void INTERRUPT scia_received_isr(void)
{
	uint8_t receiveData[4],i;

	/*判断SCI是否接收到数据*/
	if(SciaRegs.SCIFFRX.bit.RXFFST == 4)
	{
		for(i = 0; i < 4; i++)
		{
			receiveData[i] = SciaRegs.SCIRXBUF.bit.RXDT;
		}
		Scia_Print((char*)receiveData);
		Scia_Print("\r\n");
	}

	GpioDataRegs.GPBTOGGLE.bit.GPIO32 = 1;

    SciaRegs.SCIFFRX.bit.RXFFOVRCLR=1;   // Clear Overflow flag
    SciaRegs.SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag

	PieCtrlRegs.PIEACK.all=PIEACK_GROUP9;
}
