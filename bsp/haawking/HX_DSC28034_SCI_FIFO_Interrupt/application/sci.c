#include "../application/sci.h"

/******************************************************************
*��������Scia_Config(uint32 baud)
*��   ���� baud�����ڲ�����
*����ֵ����
*��   �ã� SCIA ��ʼ������
******************************************************************/
void Scia_Config(uint32 baud)
{
	uint32 div = 0;
	uint32 divsel = 0;
	uint32 lospcp = 0;
	uint32 lspclk = 0;
	uint16 brr = 0;

	//��ȡϵͳʱ�ӵı�Ƶ����Ƶ�͵����ⲿʱ�ӵ�ֵ
	div = SysCtrlRegs.PLLCR.bit.DIV;
	divsel = SysCtrlRegs.PLLSTS.bit.DIVSEL;
	lospcp = SysCtrlRegs.LOSPCP.bit.LSPCLK;


	if (lospcp != 0)
	{
		lospcp = lospcp * 2;
	}
	else
	{
		lospcp = 1;
	}

	/*��Ƶֵ����
	 divselΪ 0ʱ��ϵͳʱ��4��Ƶ
	 divselΪ 1ʱ��ϵͳʱ��4��Ƶ
	 divselΪ 2ʱ��ϵͳʱ��2��Ƶ
	 divselΪ 3ʱ��ϵͳʱ��1��Ƶ*/
	switch (divsel)
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

	/*SCI ֹͣλ����    0��һ��ֹͣλ   1������ֹͣλ*/
	SciaRegs.SCICCR.bit.STOPBITS = 0;

	/*SCI ��żУ��λ    0����żУ��   1��żżУ��*/
	SciaRegs.SCICCR.bit.PARITY = 0;

	/*SCI ��żУ��ʹ��   0���ر�   1������*/
	SciaRegs.SCICCR.bit.PARITYENA = 0;

	/*SCI �ַ�����   0��1���ֳ�  1��2���ֳ� ... 7��8���ֳ�*/
	SciaRegs.SCICCR.bit.SCICHAR = 7;

	/*ʹ��SCI�ķ��ͻ��ͽ��ջ�*/
	SciaRegs.SCICTL1.bit.TXENA = 1;
	SciaRegs.SCICTL1.bit.RXENA = 1;

	/*SCI 16λ������ѡ��Ĵ��� ��8λ*/
	SciaRegs.SCIHBAUD = (uint8) ((brr >> 8) & 0xff);
	/*SCI 16λ������ѡ��Ĵ��� ��8λ*/
	SciaRegs.SCILBAUD = (uint8) (brr & 0xff);

	/*SCI ��λ*/
	SciaRegs.SCIFFTX.bit.SCIRST = 1;
	/*SCI FIFO ʹ��*/
	SciaRegs.SCIFFTX.bit.SCIFFENA = 1;
	/*SCI ����FIFO����*/
	SciaRegs.SCIFFTX.bit.TXFIFOXRESET = 1;
	/*SCI ����FIFO���*/
	SciaRegs.SCIFFTX.bit.TXFFINTCLR = 1;
	/*SCI�����ж���ʹ��*/
	SciaRegs.SCIFFTX.bit.TXFFIENA=1;

	/*���� FIFO ��λ*/
	SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;
	/*���� FIFO �ж����*/
	SciaRegs.SCIFFRX.bit.RXFFINTCLR = 1;
	/*���� FIFO �ж��������*/
	SciaRegs.SCIFFRX.bit.RXFFIL = 4;
	/*SCI�����ж���ʹ��*/
	SciaRegs.SCIFFRX.bit.RXFFIENA=1;

	/*SCI����������ж�ʹ��*/
    SciaRegs.SCICTL2.bit.TXINTENA =1;
    SciaRegs.SCICTL2.bit.RXBKINTENA =1;

	/*FIFO �������Ĵ�������*/
	SciaRegs.SCIFFCT.all = 0;

	/*SCI �����λ����������SCI*/
	SciaRegs.SCICTL1.bit.SWRESET = 1;

}

/******************************************************************
*��������Scia_Send(uint8 data)
*��   ���� data��׼�����͵��ֽ�
*����ֵ����
*��   �ã� SCIA ����һ���ֽ�
******************************************************************/
void Scia_Send(uint8 data)
{
	while (SciaRegs.SCICTL2.bit.TXRDY == 0)
	{
	}
	SciaRegs.SCITXBUF = data;
}


/******************************************************************
*��������Scia_Print(char *str)
*��   ���� *str��Ҫ���͵��ַ���
*����ֵ����
*��   �ã� SCIA ����һ���ַ���
******************************************************************/
void Scia_Print(char *str)
{
	while (*str != '\0')
	{
		while (SciaRegs.SCICTL2.bit.TXRDY == 0)
		{
		}

		SciaRegs.SCITXBUF = *str++;
	}
}
