

#ifndef __CNAS_XSD_FSM_POWER_OFF_TBL_H__
#define __CNAS_XSD_FSM_POWER_OFF_TBL_H__

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
extern NAS_STA_STRU                                         g_astCnasXsdPowerOffStaTbl[];

/*****************************************************************************
  3 宏定义
*****************************************************************************/
#define CNAS_XSD_GetPowerOffStaTbl()                        (g_astCnasXsdPowerOffStaTbl)

/*****************************************************************************
  4 枚举定义
*****************************************************************************/

enum CNAS_XSD_POWER_OFF_STA_ENUM
{
    /* 收到关机消息初始状态 */
    CNAS_XSD_POWER_OFF_STA_INIT                             = 0x00,

    /* 等待XCC关机回复确认消息 */
    CNAS_XSD_POWER_OFF_STA_WAIT_XCC_POWEROFF_CNF            = 0x01,

    /* 等待XREG关机回复确认消息 */
    CNAS_XSD_POWER_OFF_STA_WAIT_XREG_POWEROFF_CNF           = 0x02,

    /* 等待CAS关机回复确认消息 */
    CNAS_XSD_POWER_OFF_STA_WAIT_CAS_POWEROFF_CNF            = 0x03,

    /* 等待CAS上报SD指示 */
    CNAS_XSD_POWER_OFF_STA_WAIT_CAS_SYS_DETERMIN_IND        = 0x04,

    /* 等待XSD上报捕获结果指示 */
    CNAS_XSD_POWER_OFF_STA_WAIT_XSD_SYSTEM_ACQUIRE_RSLT_CNF = 0x05,

    CNAS_XSD_POWER_OFF_STA_WAIT_CAS_SUSPEND_CNF             = 0x06,

    CNAS_XSD_POWER_OFF_STA_BUTT
};
typedef VOS_UINT32 CNAS_XSD_POWER_OFF_STA_ENUM_UINT32;

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

VOS_UINT32 CNAS_XSD_GetPowerOffStaTblSize( VOS_VOID  );

NAS_FSM_DESC_STRU * CNAS_XSD_GetPowerOffFsmDescAddr(VOS_VOID);



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

#endif /* end of CnasXsdFsmPowerOffTbl.h */
