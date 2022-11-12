/******************************************************************
 �� �� ����     HX_DSC28034_SCI_FIFO_INTERRUPT
 �� �� �� ����Haawking IDE V2.0.0
 �� �� �壺     DSC28034���İ�
 D S P��         DSC28034
 ʹ �� �⣺
 ��     �ã�      ͨ������SCIģ��Ĵ�����ʹ�ܴ��ڷ��ͺͽ���
 ˵     ����      FLASH����
 -------------------------- ����ʹ��˵�� --------------------------
 ����������оƬ��Ƶ120MHz��ͨ������SCIA�ļĴ�����ʵ��SCIAģ��FIFOģʽ�ķ�
 �ͺͽ����жϹ���

 ���ӷ�ʽ��ͨ��CH340���������ӵ��Զ˵�USB��

 ���󣺣�1�����Զ�ʹ�ô��ڵ������֣�����SCIA�����еĲ������ò����ʡ�����λ��У��
 λ����ֹͣλ������4���ֽڣ�DSP�᷵��ѭ�����յ�������
 ��2��ͨ�����ڵ������ַ���һ�����ݣ���ͨ�������ж�ִ�У��ῴ��LED��һ����һ��
ע�⣺��Ҫ��hex��ʾ

 �� ����V1.0.0
 ʱ �䣺2022��8��25��
 �� �ߣ�heyang
 @ mail��support@mail.haawking.com
 ******************************************************************/

 
#include "dsc_config.h"
#include <syscalls.h>
#include "IQmathLib.h"

#include "../application/sci.h"

void InitLED(void);

int main(void)
{
	/*��ʼ��ϵͳ����*/
		InitSysCtrl();

		/*��ʼ���ڴ���ƼĴ�����ʹ���ڴ���ˮ��ģʽ*/
		InitFlash();

		/*��ʼ������ͨ�ŵ�GPIO��*/
		/*GPIO28: SCIRXDA*/
		/*GPIO29: SCITXDA*/
		InitSciGpio();
		InitLED();

		/*��ʹ��CPU�ж�*/
		IER = 0x0000;
		/*������е�CPU�жϱ�־*/
		IFR = 0x0000;
		/*��ʼ���ж�������*/
		InitPieVectTable();

		EALLOW;
		PieVectTable.SCITXINTA = &scia_transmit_isr;
		PieVectTable.SCIRXINTA = &scia_received_isr;
		EDIS;

		/*SCI�Ĵ�������*/
		Scia_Config(9600);



		/*��IER�ĵ�9���ж�����*/
		IER |= M_INT9;

		/*��PIEIER�ĵ�9��ĵ�һ��ڶ����ж�����*/
		PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
		PieCtrlRegs.PIEIER9.bit.INTx2 = 1;

		/*ʹ��ȫ���ж�����*/
		EINT;

		while(1)
		{

		}

	return 0;
}


/******************************************************************
 ��������void InitLED()
 ��	������
 ����ֵ����
 ��	�ã���ʼ��LED
 ˵	����
 ******************************************************************/
void InitLED()
{
	EALLOW;
	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;
	GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1; /*���*/
	EDIS;
}

// ----------------------------------------------------------------------------
