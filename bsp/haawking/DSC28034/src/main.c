/******************************************************************
 文 档 名：       HX_DSC28034_EPWM
 开 发 环 境：  Haawking IDE V2.0.0
 开 发 板：      Core_DSC28034_V1.3
                       Start_DSC28034_V1.2
 D S P：          DSC28034
 使 用 库：
 作     用：     通过对PWM的配置，演示PWM的简单使用
 说     明：      FLASH工程
 -------------------------- 例程使用说明 --------------------------
 功能描述：

 连接方式：

 现象：

 版 本：      V1.0.0
 时 间：      2022年8月25日
 作 者：      heyang
 @ mail：   support@mail.haawking.com
 ******************************************************************/

#include "dsc_config.h"
#include <syscalls.h>
#include "IQmathLib.h"

#include"epwm.h"

int main(void)
{

	/*系统初始化配置*/
	InitSysCtrl();

	/*配置GPIO0,1为PWM波输出模式*/
	InitEPwm1_Gpio();

	/*16k的PWM频率*/
	pwm1_config();

	while (1)
	{

	}

	return 0;
}

// ----------------------------------------------------------------------------
