

#ifndef __HI_CONFIG_H__
#define __HI_CONFIG_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*****************************************************************************
    以下部分为PC测试使用的Define定义，将VC配置的部分宏定义移至此处定义，
    避免VC长度限制，自动截断问题。
*****************************************************************************/

#if (VOS_OS_VER == VOS_WIN32)                                                   /* _H2ASN_Skip */
/*V3 R7_7C1 Start */
#define PS_UE_REL_VER                           PS_PTL_VER_R9
/*V3 R7_7C1 end */
#define PS_W_GCF
#define TEST_FOR_WCDMA
#define MTT_PATCH_OBJ_FILE_STYLE                2
#define PS_VERSION                              HI4121V100R003
#endif

/*****************************************************************************
    以下部分用于定义宏开关，统一和物理层的接口
    使用该宏区分各模块之间的接口差异(历史原因)
*****************************************************************************/
#define INTERFACE_PS                    (1)
#define INTERFACE_DSP                   (2)
#ifndef INTERFACE_TYPE
#define INTERFACE_TYPE                  (INTERFACE_PS)
#endif

/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


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


#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of Hi_Config.h */
