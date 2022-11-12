#include "../application/sci.h"



/******************************************************************
*��������scia_transmit_isr(void)
*����ֵ����
*��   �ã� SCIA ����FIFO���жϴ���
******************************************************************/
void INTERRUPT scia_transmit_isr(void)
{
	uint8 cnt;
	cnt = 0x41;
//	/*�û��������*/
	Scia_Send(cnt);

	/*SCI�����ж������ʹ���жϿ�����ִ�ж��*/
	SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;

	/*�ж�Ӧ��*/
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

/******************************************************************
*��������scia_received_isr(void)
*����ֵ����
*��   �ã� SCIA �����ж�:ѭ�����շ��͵�����
******************************************************************/
void INTERRUPT scia_received_isr(void)
{
	uint8_t receiveData[4],i;

	/*�ж�SCI�Ƿ���յ�����*/
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
