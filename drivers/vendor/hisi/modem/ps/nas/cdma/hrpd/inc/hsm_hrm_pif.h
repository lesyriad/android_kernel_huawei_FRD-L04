/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2016

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2016-02-25 09:58:07
 * @file
 * @brief
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef HSM_HRM_PIF_H
#define HSM_HRM_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"
#include "cttf_hrpd_sig_public_pif.h"
#include "hrm_pif.h"

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
 * Name        : HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum HSM_HRM_PIF_MSG_TYPE_ENUM
{
    ID_HSM_HRM_SESSION_BEGIN_NTF        = 0x0000, /**< @sa HSM_HRM_SESSION_BEGIN_NTF_STRU */
    ID_HSM_HRM_SESSION_END_NTF          = 0x0001, /**< @sa HSM_HRM_SESSION_END_NTF_STRU */
    ID_HRM_HSM_DATA_IND                 = 0x0002, /**< @sa HRM_HSM_DATA_IND_STRU */
    ID_HSM_HRM_DATA_REQ                 = 0x0003, /**< @sa HSM_HRM_DATA_REQ_STRU */
    ID_HRM_HSM_DATA_CNF                 = 0x0004, /**< @sa HRM_HSM_DATA_CNF_STRU */
    ID_HRM_HSM_UATI_CMPL_SND_IND        = 0x0005, /**< @sa HRM_HSM_UATI_CMPL_SND_IND_STRU */
    ID_HSM_HRM_DATA_CANCEL_NTF          = 0x0006, /**< @sa HSM_HRM_DATA_CANCEL_NTF_STRU */
    ID_HSM_HRM_PIF_MSG_TYPE_ENUM_BUTT   = 0x0007
};
typedef VOS_UINT16 HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : HRM_HSM_DATA_CNF_RSLT_ENUM_UINT32
 *
 * Description :
 *******************************************************************************/
enum HRM_HSM_DATA_CNF_RSLT_ENUM
{
    HRM_HSM_DATA_CNF_RSLT_SUCC          = 0x00000000,
    HRM_HSM_DATA_CNF_RSLT_FAIL          = 0x00000001,
    HRM_HSM_DATA_CNF_RSLT_NO_RF         = 0x00000002,
    HRM_HSM_DATA_CNF_RSLT_ENUM_BUTT     = 0x00000003
};
typedef VOS_UINT32 HRM_HSM_DATA_CNF_RSLT_ENUM_UINT32;

/** ****************************************************************************
 * Name        : HSM_HRM_SESSION_TYPE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum HSM_HRM_SESSION_TYPE_ENUM
{
    HSM_HRM_SESSION_TYPE_UATI           = 0x0000,
    HSM_HRM_SESSION_TYPE_MO_KEEP_ALIVE  = 0x0001,
    HSM_HRM_SESSION_TYPE_ENUM_BUTT      = 0x0002
};
typedef VOS_UINT16 HSM_HRM_SESSION_TYPE_ENUM_UINT16;

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
 * Name        : HSM_HRM_SESSION_BEGIN_NTF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    HSM_HRM_SESSION_TYPE_ENUM_UINT16    enSessionType;
    VOS_UINT8                           aucRsv[2];
} HSM_HRM_SESSION_BEGIN_NTF_STRU;

/** ****************************************************************************
 * Name        : HSM_HRM_SESSION_END_NTF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    HSM_HRM_SESSION_TYPE_ENUM_UINT16    enSessionType;
    VOS_UINT8                           aucRsv[2];
} HSM_HRM_SESSION_END_NTF_STRU;

/** ****************************************************************************
 * Name        : HRM_HSM_DATA_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    CTTF_HRPD_PROTOCOL_TYPE_ENUM_UINT16 enProtocolType; /**< protocol type */
    CTTF_HRPD_INSTANCE_TYPE_ENUM_UINT8  enInstanceType; /**< InConfiguration or InUse instance */
    VOS_UINT8                           aucReserve[1];
    SNPITF_MSG_DATA_STRU                stMsgData;      /**< message data struct */
} HRM_HSM_DATA_IND_STRU;

/** ****************************************************************************
 * Name        : HSM_HRM_DATA_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    CNAS_HRM_DATA_REQ_TYPE_ENUM_UINT32  enDataReqType;
    CNAS_HRM_DATA_REQ_COMM_CONTENT_STRU stDataReqCommContent;
} HSM_HRM_DATA_REQ_STRU;

/** ****************************************************************************
 * Name        : HRM_HSM_DATA_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16                        enMsgId;
    VOS_UINT16                                              usOpId;
    HRM_HSM_DATA_CNF_RSLT_ENUM_UINT32                       enRslt;
    CTTF_HRPD_SNP_DATA_FAIL_REASON_ENUM_UINT32              enFailReason;
} HRM_HSM_DATA_CNF_STRU;

/** ****************************************************************************
 * Name        : HRM_HSM_UATI_CMPL_SND_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
} HRM_HSM_UATI_CMPL_SND_IND_STRU;

/** ****************************************************************************
 * Name        : HSM_HRM_DATA_CANCEL_NTF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER
    HSM_HRM_PIF_MSG_TYPE_ENUM_UINT16    enMsgId;
    VOS_UINT16                          usOpId;
    CNAS_HRM_DATA_REQ_TYPE_ENUM_UINT32  enDataReqType;
} HSM_HRM_DATA_CANCEL_NTF_STRU;

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
