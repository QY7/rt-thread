

#ifndef  DSC_CONFIG_H
#define  DSC_CONFIG_H


#ifdef DSC28027_BBB

    #include "F2802x_Device.h"
	#include "f2802x_examples.h"
	
#endif

#ifdef DSC28027_DCC

    #include "F2802x_Device.h"
	#include "f2802x_Examples.h"

#endif

#ifdef  DSC28027_ECD

    #include "F2802x_Device.h"
	#include "f2802x_examples.h"
#endif



#ifdef  DSC28034_BBB

	#include "DSP2803x_Device.h"
	#include "DSP2803x_Examples.h"

#endif

#ifdef  DSC28034_BBC

	#include "DSP2803x_Device.h"
	#include "DSP2803x_Examples.h"

#endif

#ifdef  DSC28034_CDD

	#include "DSP2803x_Device.h"
	#include "DSP2803x_Examples.h"

#endif


#ifdef  DSC28335_CDB

	#include "DSP2833x_Device.h"
	#include "DSP2833x_Examples.h"

#endif

#endif

