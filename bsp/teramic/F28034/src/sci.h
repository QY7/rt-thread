/******************************************************************
 文 档 名：     sci.h
 D S P：       DSC28034
 使 用 库：     
 作     用：      
 说     明：      提供sci.h接口初始化配置
 ---------------------------- 使用说明 ----------------------------
 功能描述：


 版 本：V1.0.x
 时 间：2021年11月13日
 作 者：
 @ mail：support@mail.haawking.com
 ******************************************************************/
#ifndef SCI_H_
#define SCI_H_

#include "dsc_config.h"


void Scia_Config(uint32 baud);
void Scia_Print(char *str);

#endif /* SCI_H_ */
