#ifndef SCI_H_
#define SCI_H_

#include "dsc_config.h"


void Scia_Config(uint32 baud);

void Scia_Send(uint8 data);
void Scia_Print(char *str);
void INTERRUPT scia_transmit_isr(void);
void INTERRUPT scia_received_isr(void);

void InitLED(void);

#endif /* SCI_H_ */
