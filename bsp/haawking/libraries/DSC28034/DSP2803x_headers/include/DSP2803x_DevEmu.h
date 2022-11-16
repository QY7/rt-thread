//###########################################################################
//
// FILE:   DSP2803x_DevEmu.h
//
// TITLE:  DSP2803x Device Emulation Register Definitions.
//
//###########################################################################
// $HAAWKING Release: DSP2803x Support Library V1.1.0 $
// $Release Date: 2022-07-09 04:54:32 $
// $Copyright:
// Copyright (C) 2019-2022 Beijing Haawking Technology Co.,Ltd - http://www.haawking.com/
//###########################################################################


#ifndef DSP2803x_DEV_EMU_H
#define DSP2803x_DEV_EMU_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// Device Emulation Register Bit Definitions:
//
// Device Configuration Register Bit Definitions
struct DEVICECNF_BITS  {     // bits  description
   Uint32 rsvd1:5;           // 4:0   reserved
   Uint32 XRSn:1;            // 5     XRSn Signal Status
   Uint32 rsvd3:21;          // 26:6  reserved
   Uint32 TRSTn:1;           // 27    Status of TRSTn signal
   Uint32 rsvd6:4;           // 31:28 reserved
};

union DEVICECNF_REG {
   Uint32                 all;
   struct DEVICECNF_BITS  bit;
};

// CLASSID
struct CLASSID_BITS   {  // bits  description
   Uint32 CLASSNO:8;     // 7:0   Class Number
   Uint32 PARTTYPE:8;    // 15:8  Part Type
   Uint32 resvd1:16;     // 31:16 reserved
};

union CLASSID_REG {
   Uint32               all;
   struct CLASSID_BITS  bit;
};


struct DEV_EMU_REGS {
   union DEVICECNF_REG DEVICECNF;  // Device Configuration
   union CLASSID_REG   CLASSID;    // Class ID
   Uint32              REVID;      // Device ID
};




//---------------------------------------------------------------------------
// Device Emulation Register References & Function Declarations:
//
extern 	volatile struct DEV_EMU_REGS  *const P_DevEmuRegs;
extern  volatile struct DEV_EMU_REGS DevEmuRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2803x_DEV_EMU_H definition

//===========================================================================
// End of file.
//===========================================================================
