//###########################################################################
//
// FILE:   DSP2803x_SysCtrl.h
//
// TITLE:  DSP2803x Device System Control Register Definitions.
//
//###########################################################################
// $HAAWKING Release: DSP2803x Support Library V1.1.0 $
// $Release Date: 2022-07-09 04:54:32 $
// $Copyright:
// Copyright (C) 2019-2022 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################

#ifndef DSP2803x_SYS_CTRL_H
#define DSP2803x_SYS_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// System Control Individual Register Bit Definitions:
//

// XCLKOUT Control
struct XCLK_BITS   {    // bits  description
   Uint32 XCLKOUTDIV:2; // 1:0   XCLKOUT Divide Ratio
   Uint32 rsvd1:4;      // 5:2   reserved
   Uint32 XCLKINSEL:1;  // 6     XCLKIN Source Select bit
   Uint32 rsvd2:25;     // 15:7   reserved
};

union XCLK_REG {
   Uint32                     all;
   struct XCLK_BITS           bit;
};

// PLL Status Register
struct PLLSTS_BITS   {    // bits  description
   Uint32 PLLLOCKS:1;     // 0     PLL lock status
   Uint32 rsvd1:1;        // 1     reserved
   Uint32 PLLOFF:1;       // 2     PLL off bit
   Uint32 rsvd2:1;        // 3     reserved
   Uint32 MCLKCLR:1;      // 4    reserved
   Uint32 OSCOFF:1;       // 5     Oscillator clock off
   Uint32 MCLKOFF:1;      // 6     Missing clock detect
   Uint32 DIVSEL:2;       // 8:7   Divide select (/4 default)
   Uint32 rsvd4:6;        // 14:9  reserved
   Uint32 NORMRDYE:1;     // 15    VREG NORMRDY enable bit
   Uint32 rsvd:16;
};

union PLLSTS_REG {
   Uint32                     all;
   struct PLLSTS_BITS         bit;
};

// Clock Control Register
struct CLKCTL_BITS   {        // bits  description
   Uint32 OSCCLKSRCSEL:1;     // 0     Oscillator clock source select bit
   Uint32 OSCCLKSRC2SEL:1;    // 1     Oscillator 2 clock source select bit
   Uint32 WDCLKSRCSEL:1;      // 2     Watchdog clock source select bit
   Uint32 TMR2CLKSRCSEL:2;    // 4:3   CPU timer 2 clock source select bit
   Uint32 TMR2CLKPRESCALE:3;  // 7:5   CPU timer 2 clock pre-scale value
   Uint32 INTOSC1OFF:1;       // 8     Internal oscillator off bit
   Uint32 INTOSC1HALTI:1;     // 9     Internal oscillator 1 halt mode ignore bit
   Uint32 INTOSC2OFF:1;       // 10    Internal oscillator 2 off bit
   Uint32 INTOSC2HALTI:1;     // 11    Internal oscillator 2 halt mode ignore bit
   Uint32 WDHALTI:1;          // 12    Watchdog halt mode ignore bit
   Uint32 XCLKINOFF:1;        // 13    XCLKIN off bit
   Uint32 XTALOSCOFF:1;       // 14    Crystal (External) oscillator off bit
   Uint32 NMIRESETSEL:1;      // 15    NMI reset select bit
   Uint32 rsvd2:16;
};

union CLKCTL_REG {
   Uint32                     all;
   struct CLKCTL_BITS         bit;
};

// Internal Oscillator 1 Trim
struct INTOSC1TRIM_BITS   {    // bits  description
   Uint32 rsvd0:8;             // 7:0   reserved
   Uint32 rsvd1:1;             // 8     reserved
   Uint32 COARSETRIM:5;        // 13:9  6-bit fine trim value
   Uint32 rsvd2:18;            // 31:14   reserved
};

union INTOSC1TRIM_REG {
   Uint32                     all;
   struct INTOSC1TRIM_BITS    bit;
};

// Internal Oscillator 2 Trim
struct INTOSC2TRIM_BITS   {    // bits  description
   Uint32 rsvd0:8;             // 7:0   reserved
   Uint32 rsvd1:1;             // 8     reserved
   Uint32 COARSETRIM:5;        // 13:9  5-bit fine trim value
   Uint32 rsvd2:18;            // 31:14    reserved
};


union INTOSC2TRIM_REG {
   Uint32                     all;
   struct INTOSC2TRIM_BITS    bit;
};

// Low speed peripheral clock register bit definitions:
struct LOSPCP_BITS  {   // bits  description
   Uint32 LSPCLK:4;     // 3:0   Rate relative to SYSCLKOUT
   Uint32 rsvd1:28;     // 31:4  reserved
};

union LOSPCP_REG {
   Uint32                     all;
   struct LOSPCP_BITS         bit;
};

// Peripheral clock control register 0 bit definitions:
struct PCLKCR0_BITS  {  // bits  description
   Uint32 HRPWMENCLK:1; // 0     Enable low speed clk to HRPWM
   Uint32 LINAENCLK:1;  // 1     Enable  LIN clock
   Uint32 TBCLKSYNC:1;  // 2     ETWPM Module TBCLK enable/sync
   Uint32 ADCENCLK:1;   // 3     Enable high speed clk to ADC
   Uint32 I2CAENCLK:1;  // 4     Enable SYSCLKOUT to I2C-A
   Uint32 rsvd2:2;      // 6:5   reserved
/*********************
   ECAN/LIN clock divider
0:   The clock for eCAN/LIN module is SYSCLKOUT/2. (default)
1:   The clock for eCAN/LIN module is SYSCLKOUT/4
**************************/
   Uint32 ECAN_LINCLKDIV4:1;//
   Uint32 SPIAENCLK:1;   // 8     Enable low speed clk to SPI-A
   Uint32 SPIBENCLK:1;  // 9    Enable low speed clk to SPI-B
   Uint32 SCIAENCLK:1;  // 10    Enable low speed clk to SCI-A
   Uint32 rsvd4:3;      // 13:11 reserved
   Uint32 ECANAENCLK:1; // 14    ECAN-A clock enable
   Uint32 rsvd5:17;     // 31:15  reserved
};

union PCLKCR0_REG {
   Uint32                     all;
   struct PCLKCR0_BITS        bit;
};

// Peripheral clock control register 1 bit definitions:
struct PCLKCR1_BITS  {    // bits  description
   Uint32 EPWM1ENCLK:1;   // 0     Enable SYSCLKOUT to EPWM1
   Uint32 EPWM2ENCLK:1;   // 1     Enable SYSCLKOUT to EPWM2
   Uint32 EPWM3ENCLK:1;   // 2     Enable SYSCLKOUT to EPWM3
   Uint32 EPWM4ENCLK:1;   // 3     Enable SYSCLKOUT to EPWM4
   Uint32 EPWM5ENCLK:1;   // 4     Enable SYSCLKOUT to EPWM5
   Uint32 EPWM6ENCLK:1;   // 5     Enable SYSCLKOUT to EPWM6
   Uint32 EPWM7ENCLK:1;   // 6     Enable SYSCLKOUT to EPWM7
   Uint32 rsvd1:1;        // 7     reserved
   Uint32 ECAP1ENCLK:1;   // 8     Enable SYSCLKOUT to ECAP1
   Uint32 rsvd2:5;        // 13:9  reserved
   Uint32 EQEP1ENCLK:1;	  // 14  enable eqep1
   Uint32 EQEP2ENCLK:1;   // 15   enable eqep2
   Uint32 rsvd3:16;       // 31:16  reserved
};

union PCLKCR1_REG {
   Uint32                     all;
   struct PCLKCR1_BITS        bit;
};

struct PCLKCR2_BITS
{
  Uint32 rsvd1:8;		  // 7:0  reserved
  Uint32 HRCAP1ENCLK:1;   // 8  enable hrcap1  clock
  Uint32 HRCAP2ENCLK:1;   // 9  enable hrcap2  clock
  Uint32 rsvd2:22;        // 31:10 reserved
};

union   PCLKCR2_REG
{
	Uint32					   all;
	struct PCLKCR2_BITS 	   bit;

};

// Peripheral clock control register 3 bit definitions:
struct PCLKCR3_BITS  {       // bits  description
   Uint32 COMP1ENCLK:1;      // 0     Enable SYSCLKOUT to COMP1
   Uint32 COMP2ENCLK:1;      // 1     Enable SYSCLKOUT to COMP2
   Uint32 COMP3ENCLK:1;      // 2     Enable SYSCLKOUT to COMP3
   Uint32 rsvd2:5;           // 7:3   reserved
   Uint32 CPUTIMER0ENCLK:1;  // 8     Enable SYSCLKOUT to CPUTIMER0
   Uint32 CPUTIMER1ENCLK:1;  // 9     Enable SYSCLKOUT to CPUTIMER1
   Uint32 CPUTIMER2ENCLK:1;  // 10    Enable SYSCLKOUT to CPUTIMER2
   Uint32 rsvd3:2;           // 12:11 reserved
   Uint32 GPIOINENCLK:1;     // 13    Enable SYSCLKOUT to GPIO
   Uint32 rsvd4:2;           // 15:14
   Uint32 rsvd5:16;          // 31:16  reserved
};

union PCLKCR3_REG {
   Uint32              all;
   struct PCLKCR3_BITS bit;
};

// PLL control register bit definitions:
struct PLLCR_BITS {      // bits  description
   Uint32 DIV:5;         // 4:0   Set clock ratio for the PLL
   Uint32 DIVN:1;		 //	5	  Pre-divider of reference clock(CLKIN)
   Uint32 DIVM:2;		 //	7:6	  VCO output divider control signal
   Uint32 rsvd1:24;      // 31:8  reserved   
};

union PLLCR_REG {
   Uint32             all;
   struct PLLCR_BITS  bit;
};

// Low Power Mode 0 control register bit definitions:
struct LPMCR0_BITS {     // bits  description
   Uint32 LPM:2;         // 1:0   Set the low power mode
   Uint32 QUALSTDBY:6;   // 7:2   Qualification
   Uint32 rsvd1:7;       // 14:8  reserved
   Uint32 WDINTE:1;      // 15    Enables WD to wake the device from STANDBY
   Uint32 rsvd2:16;      // 31:16  reserved
};

union LPMCR0_REG {
   Uint32              all;
   struct LPMCR0_BITS  bit;
};


//---------------------------------------------------------------------------
// System Power Control Registers:
//

// BOR configuration register bit definitions:
struct BORCFG_BITS {     // bits  description
   Uint32 BORENZ:1;      // 0     BOR enable active low bit
   Uint32 rsvd1:2;       // 2:1   reserved
   Uint32 DIV_T:3;       // 5:3   BOR Trigger point
   Uint32 rsvd2:26;      // 31:6  reserved
   
};

union BORCFG_REG {
   Uint32              all;
   struct BORCFG_BITS  bit;
};

struct SYS_PWR_CTRL_REGS {
    union    BORCFG_REG   BORCFG;       // 0: BOR Configuration Register
};







//---------------------------------------------------------------------------
// System Control Register File:
//
struct SYS_CTRL_REGS {

	union	 XCLK_REG		 XCLK;		    // XCLKOUT Control		                    00
	union    PLLSTS_REG      PLLSTS;        // PLL Status Register		                04
	union    PCLKCR0_REG     PCLKCR0;       // Peripheral clock control register		08
	union    PCLKCR1_REG     PCLKCR1;       // Peripheral clock control register		0C
	union    PCLKCR2_REG     PCLKCR2;	    // Peripheral clock control register        10
	union    PCLKCR3_REG     PCLKCR3;       // Peripheral clock control register		14
	union    LOSPCP_REG      LOSPCP;        // Low-speed peripheral clock pre-scaler	18
	union    INTOSC1TRIM_REG   INTOSC1TRIM; // Internal Oscillator 1 Trim			    1C
	union    INTOSC2TRIM_REG   INTOSC2TRIM; // Internal Oscillator 2 Trim			    20
	union    CLKCTL_REG        CLKCTL;      // Clock Control Register				    24
	union    PLLCR_REG         PLLCR;       // PLL control register				        28
	Uint32                     PLLLOCKPRD;  // PLL Lock Period Register				    2C
	union    LPMCR0_REG       LPMCR0;       // Low-power mode control register 0	    30
	Uint32				    SCSR;           // System control and status register	    34
	Uint32                  WDCNTR;         // WD counter register					    38
	Uint32                  WDKEY;          // WD reset key register				    3C
	Uint32          		WDCR;		    // Watchdog Control Register    			40
	Uint32 	              JTAG_DEBUG;	    //					                        44        
};






/* --------------------------------------------------- */
/* CSM Registers                                       */
/*                                                     */
/* ----------------------------------------------------*/

/* CSM Status & Control register bit definitions */
struct  CSMSCR_BITS {      // bit   description
   Uint32     SECURE:1;    // 0     Secure flag  
   Uint32     rsvd1:30;    // 30:1  reserved
   Uint32     FORCESEC:1;  // 31 
};

/* Allow access to the bit fields or entire register */
union CSMSCR_REG {
   Uint32             all;
   struct CSMSCR_BITS bit;
};

/* CSM Register File */
struct  CSM_REGS {
   union CSMSCR_REG CSMSCR;  // CSM Status & Control register	   00
   Uint32           KEY0;    // KEY reg bits 31-0      				04
   Uint32           KEY1;    // KEY reg bits 63-32					08
   Uint32           KEY2;    // KEY reg bits 95-64					0C
   Uint32           KEY3;    // KEY reg bits 127-96					10
};

/* Password locations */
struct  CSM_PWL {
   Uint32   PSWD0;  // PSWD bits 31-0
   Uint32   PSWD1;  // PSWD bits 63-32
   Uint32   PSWD2;  // PSWD bits 95-64
   Uint32   PSWD3;  // PSWD bits 127-96
};

/* Flash Registers */

#define FLASH_SLEEP   0x0000;
#define FLASH_STANDBY 0x0001;
#define FLASH_ACTIVE  0x0003;

/* Flash Option Register bit definitions */
struct  FOPT_BITS {       // bit   description
   Uint32     ENPIPE:1;   // 0     Enable Pipeline Mode
   Uint32     rsvd:31;    // 31:1  reserved
};

/* Allow access to the bit fields or entire register */
union FOPT_REG {
   Uint32           all;
   struct FOPT_BITS bit;
};

/* Flash Power Modes Register bit definitions */
struct  FPWR_BITS {       // bit   description
   Uint32     PWR:2;      // 1:0   Power Mode bits
   Uint32     rsvd:30;    // 31:2  reserved
};

/* Allow access to the bit fields or entire register */
union FPWR_REG {
   Uint32           all;
   struct FPWR_BITS bit;
};

/* Flash Status Register bit definitions */
struct  FSTATUS_BITS {       // bit   description
   Uint32     PWRS:2;        // 1:0   Power Mode Status bits
   Uint32     STDBYWAITS:1;  // 2     Bank/Pump Sleep to Standby Wait Counter Status bits
   Uint32     ACTIVEWAITS:1; // 3     Bank/Pump Standby to Active Wait Counter Status bits
   Uint32     rsvd1:4;       // 7:4   reserved
   Uint32     V3STAT:1;      // 8     VDD3V Status Latch bit
   Uint32     rsvd2:23;      // 31:9  reserved
};

/* Allow access to the bit fields or entire register */
union FSTATUS_REG {
   Uint32              all;
   struct FSTATUS_BITS bit;
};

/* Flash Sleep to Standby Wait Counter Register bit definitions */
struct  FSTDBYWAIT_BITS {    // bit   description
   Uint32     STDBYWAIT:9;   // 8:0   Bank/Pump Sleep to Standby Wait Count bits
   Uint32     rsvd:23;       // 31:9  reserved
};

/* Allow access to the bit fields or entire register */
union FSTDBYWAIT_REG {
   Uint32                 all;
   struct FSTDBYWAIT_BITS bit;
};

/* Flash Standby to Active Wait Counter Register bit definitions */
struct  FACTIVEWAIT_BITS {   // bit   description
   Uint32     ACTIVEWAIT:9;  // 8:0   Bank/Pump Standby to Active Wait Count bits
   Uint32     rsvd:23;       // 31:9  reserved
};

/* Allow access to the bit fields or entire register */
union FACTIVEWAIT_REG {
   Uint32                  all;
   struct FACTIVEWAIT_BITS bit;
};



struct  FMERCTL_BITS
{
	Uint32 MASS_ERASE:1;   //bit0: MASS erase
	uint32 rsvd:31;
};


union FMERCTL_REG
{
	Uint32 all;
	struct  FMERCTL_BITS bit;
};


struct FPERCTL_BITS
{
	Uint32 erase:7;   //6:0
	Uint32 rsvd1:25;  //31:7  reserved
};

union FPERCTL_REG
{
	Uint32 all;
	struct FPERCTL_BITS bit;
};

struct FSTAT_BITS	  
{
	Uint32 BUSY:1;       //0  flash busy
	Uint32 READING:1;    //1  read
	Uint32 PROGRAMING:1; //2  program
	Uint32 ERASEING:1;   //3  page erase 
	Uint32 MASS_ERASE:1; // 4  flash memory block write Enable
	Uint32 rsvd1:27;
};


union FSTAT_REG 
{
	Uint32 all;
	struct FSTAT_BITS bit;
};




struct FMEMWREN_BITS
{
	Uint32 FMEMWREN:1;
	Uint32 rsvd:31;
};

union FMEMWREN_REG
{
	Uint32 all;
	struct FMEMWREN_BITS bit;
};

struct OTPSTAT_BITS
{
	Uint32 OTPSTAT_WRITE:1;
	Uint32 OTPSTAT_ERASE:1;
	Uint32 rsvd:30;
};

union OTPSTAT_REG
{
	Uint32 all;
	struct OTPSTAT_BITS bit;
};

struct OTPWREN_BITS
{
	Uint32  OTPWREN:1;
	Uint32  rsvd:31;
};


union OTPWREN_REG
{
	Uint32 all;
	struct OTPWREN_BITS bit;
};





struct FLASH_REGS {

   struct CSM_REGS 		 SYSCsmRegs;    	
   Uint32  FERREFCELL;	              
   Uint32   rsvd2[26];
   
   Uint32   FPROWAIT; 	                 //0x80
   Uint32	FPERWAIT;	                 //0x84
   Uint32	FMERWAIT;	                 //0x88
   union FMERCTL_REG FMERCTL;            //0x8C 
   union FPERCTL_REG FPERCTL;            //0x90 
   union FSTAT_REG FSTAT;                //0x94  
   union FMEMWREN_REG FMEMWREN;          //0x98
   union OTPSTAT_REG	OTPSTAT;         //0x9C
   union OTPWREN_REG	OTPWREN;         //0xA0
   Uint32 		OTPER;                   //0xA4	
   union FOPT_REG        FOPT;           //0xA8
   Uint32   FBANKWAIT;                   //0xAC
   Uint32   FNVSHWAIT;                   //0xB0
   Uint32   FNVH1WAIT;                   //0xB4
   Uint32   FPGSWAIT;                    //0xB8
};









//---------------------------------------------------------------------------
// System Control External References & Function Declarations:
//
//extern volatile struct SYS_CTRL_REGS SysCtrlRegs;


extern volatile struct SYS_CTRL_REGS  *const P_SysCtrlRegs;
extern volatile struct SYS_CTRL_REGS  SysCtrlRegs;



//#define  SysPwrCtrlRegs  (P_SysCtrlRegs->BORCFG)




#define CsmRegs   (P_FlashRegs->SYSCsmRegs)

extern volatile struct SYS_PWR_CTRL_REGS *const P_SysPwrCtrlRegs;
extern volatile struct SYS_PWR_CTRL_REGS SysPwrCtrlRegs;


extern volatile struct CSM_PWL  *const P_CsmPwl;
extern volatile struct CSM_PWL  CsmPwl;



extern volatile struct FLASH_REGS  *const  P_FlashRegs;
extern volatile struct FLASH_REGS  FlashRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif 

//===========================================================================
// End of file.
//===========================================================================

