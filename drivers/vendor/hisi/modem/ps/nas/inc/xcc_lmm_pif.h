/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2016

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2016-02-22 10:30:40
 * @file
 * @brief
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef XCC_LMM_PIF_H
#define XCC_LMM_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/


/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : XCC_LMM_PIF_MSG_TYPE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum XCC_LMM_PIF_MSG_TYPE_ENUM
{
    ID_XCC_LMM_CALL_START_NTF           = 0x0000, /**< @sa XCC_LMM_CALL_START_NTF_STRU */
    ID_XCC_LMM_CALL_END_NTF             = 0x0001, /**< @sa XCC_LMM_CALL_END_NTF_STRU */
    ID_LMM_XCC_ESR_END_IND              = 0x0002, /**< @sa LMM_XCC_ESR_END_IND_STRU */
    ID_XCC_LMM_PIF_MSG_TYPE_ENUM_BUTT   = 0x0003
};
typedef VOS_UINT16 XCC_LMM_PIF_MSG_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : LMM_XCC_ESR_RSLT_ENUM_UINT8
 *
 * Description :
 *******************************************************************************/
enum LMM_XCC_ESR_RSLT_ENUM
{
    LMM_XCC_ESR_RSLT_SUCC               = 0x00,
    LMM_XCC_ESR_RSLT_TIME_EXP           = 0x01,
    LMM_XCC_ESR_RSLT_NOT_SEND           = 0x02,
    LMM_XCC_ESR_RSLT_SEND_FAIL          = 0x03,
    LMM_XCC_ESR_RSLT_BUTT               = 0x04
};
typedef VOS_UINT8 LMM_XCC_ESR_RSLT_ENUM_UINT8;

/** ****************************************************************************
 * Name        : XCC_LMM_CALL_TYPE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum XCC_LMM_CALL_TYPE_ENUM
{
    XCC_LMM_CALL_TYPE_MO                = 0x0000,
    XCC_LMM_CALL_TYPE_MT                = 0x0001,
    XCC_LMM_CALL_TYPE_BUTT              = 0x0002
};
typedef VOS_UINT16 XCC_LMM_CALL_TYPE_ENUM_UINT16;

/*******************************************************************************
 4. Message Header declaration
*******************************************************************************/

/*******************************************************************************
 5. Message declaration
*******************************************************************************/

/*******************************************************************************
 6. STRUCT and UNION declaration
*******************************************************************************/

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : XCC_LMM_CALL_START_NTF_STRU
 *
 * Description : In SRLTE, XCC notify LMM the call start when user orig a cs
 * voice call or receive a cs voice paging. LMM need start ESR procedure in
 * normal service as it receive this msg
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    XCC_LMM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    XCC_LMM_CALL_TYPE_ENUM_UINT16       enCallType;
    VOS_UINT8                           aucReserved[2];
} XCC_LMM_CALL_START_NTF_STRU;

/** ****************************************************************************
 * Name        : XCC_LMM_CALL_END_NTF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    XCC_LMM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    VOS_UINT8                           aucReserved[4];
} XCC_LMM_CALL_END_NTF_STRU;

/** ****************************************************************************
 * Name        : LMM_XCC_ESR_END_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    XCC_LMM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    LMM_XCC_ESR_RSLT_ENUM_UINT8         enEsrRslt;
    VOS_UINT8                           aucReserved[3];
} LMM_XCC_ESR_END_IND_STRU;

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif
