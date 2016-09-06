

#ifndef __CNAS_XREG_FSM_SWITCH_ON_TBL_H__
#define __CNAS_XREG_FSM_SWITCH_ON_TBL_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"
#include  "NasFsm.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 全局变量声明
*****************************************************************************/
extern NAS_STA_STRU                                         g_astCnasXregSwitchOnStaTbl[];

/*****************************************************************************
  3 宏定义
*****************************************************************************/
#define CNAS_XREG_GetSwitchOnStaTbl()                      (g_astCnasXregSwitchOnStaTbl)

/*****************************************************************************
  4 枚举定义
*****************************************************************************/

enum CNAS_XREG_SWITCH_ON_STA_ENUM
{
    /* 开机状态机，初始状态 */
    CNAS_XREG_SWITCH_ON_STA_INIT                             = 0x00,

    /* 开机初始化过程,等待获取卡文件的回复消息 */
    CNAS_XREG_SWITCH_ON_STA_WAIT_CARD_FILE_CNF               = 0x01,

    CNAS_XREG_SWITCH_ON_STA_BUTT
};
typedef VOS_UINT32 CNAS_XREG_SWITCH_ON_STA_ENUM_UINT32;

/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
VOS_UINT32 CNAS_XREG_GetSwitchOnStaTblSize(VOS_VOID);

NAS_FSM_DESC_STRU * CNAS_XREG_GetSwitchOnFsmDescAddr(VOS_VOID);

#endif



#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of CnasXregFsmSwitchOnTbl.h */
