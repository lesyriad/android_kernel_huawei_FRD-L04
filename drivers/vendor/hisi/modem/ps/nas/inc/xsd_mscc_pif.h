/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2011

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2014-07-02
 * @file
 * @brief
 * Physical interface between XSD and MSCC
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef XSD_MSCC_PIF_H
#define XSD_MSCC_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"
#include "NasMsccPifInterface.h"
#include "PsRrmInterface.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/
#define MSCC_XSD_INVALID_MNC                     (0xffff)
#define MSCC_XSD_MAX_WHITE_LOCK_SID_NUM           (20)
/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/
/** ****************************************************************************
 * Name        : XSD_MSCC_START_RESULT_ENUM_UINT32
 * Description : Start result
 *******************************************************************************/
enum XSD_MSCC_START_RESULT_ENUM
{
    XSD_MSCC_START_RESULT_SUCC           = 0x00000000,
    XSD_MSCC_START_RESULT_FAIL           = 0x00000001,
    XSD_MSCC_START_RESULT_BUTT           = 0x00000002
};
typedef VOS_UINT32 XSD_MSCC_START_RESULT_ENUM_UINT32;



/** ****************************************************************************
 * Name        : MSCC_XSD_SYS_TYPE_ENUM_UINT8
 *
 * Description :
 *******************************************************************************/
enum MSCC_XSD_SYS_TYPE_ENUM
{
    MSCC_XSD_SYS_TYPE_CDMA2000_AI       = 0x00,
    MSCC_XSD_SYS_TYPE_CDMA2000_1X       = 0x01,
    MSCC_XSD_SYS_TYPE_ENUM_BUTT         = 0x02
};
typedef VOS_UINT8 MSCC_XSD_SYS_TYPE_ENUM_UINT8;


typedef NAS_MSCC_PIF_EMC_CALLBACK_MODE_ENUM_UINT32 MSCC_XSD_EMC_CALLBACK_MODE_ENUM_UINT32;

/** ****************************************************************************
 * Name        : MSCC_XSD_SYS_ACQ_TYPE_ENUM
 *
 * Description : CL_MUTIMODE_OPTIMIZE增加，上电开机过程中，第1次无卡开机时，填写INIT_SEARCH
                其它情况填写NORMAL。INIT_SEARCH时，XSD只同步频点，不等待系统信息
 *******************************************************************************/
enum MSCC_XSD_SYS_ACQ_TYPE_ENUM
{
    MSCC_XSD_SYS_ACQ_TYPE_NORMAL        = 0x00,      /* 正常驻留请求 */
    MSCC_XSD_SYS_ACQ_TYPE_INIT_SEARCH   = 0x01,      /* 上电开机，无卡初搜，只为了获取当前位置信息 */
    MSCC_XSD_SYS_ACQ_TYPE_BUTT          = 0x02
};
typedef VOS_UINT8 MSCC_XSD_SYS_ACQ_TYPE_ENUM_UINT8;
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
 * Name        : MSCC_XSD_START_REQ_STRU
 * Description : Start request
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                        stMsgHeader;                    /*_H2ASN_Skip*//* 消息头                                   */
    MODEM_ID_ENUM_UINT16                        enModemId;
    NAS_MSCC_PIF_CARD_STATUS_ENUM_UINT8         enCardStatus;
    VOS_UINT8                                   ucSuppRatNum;
    VOS_RATMODE_ENUM_UINT32                     aenRatMode[VOS_RATMODE_BUTT];
    VOS_UINT8                                   ucIsCardChanged;                /* 卡的ICCID是否发生改变标识 */
    VOS_UINT8                                   aucReserved[3];
}MSCC_XSD_START_REQ_STRU;

/** ****************************************************************************
 * Name        : XSD_MSCC_START_CNF_STRU
 * Description : Start confirm
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                        stMsgHeader;                    /*_H2ASN_Skip*//* 消息头                                   */
    XSD_MSCC_START_RESULT_ENUM_UINT32           enRslt;
}XSD_MSCC_START_CNF_STRU;


typedef NAS_MSCC_PIF_POWER_OFF_REQ_STRU                     MSCC_XSD_POWER_OFF_REQ_STRU;


typedef NAS_MSCC_PIF_POWER_OFF_CNF_STRU                     XSD_MSCC_POWER_OFF_CNF_STRU;


typedef NAS_MSCC_PIF_CDMA_MO_CALL_START_NTF_STRU            MSCC_XSD_MO_CALL_START_NTF_STRU;


typedef NAS_MSCC_PIF_CDMA_MO_CALL_REDIAL_SYS_ACQ_NTF_STRU   MSCC_XSD_CALL_REDIAL_SYSTEM_ACQUIRE_NTF_STRU;


typedef NAS_MSCC_PIF_CDMA_MO_CALL_SUCCESS_NTF_STRU          MSCC_XSD_MO_CALL_SUCCESS_NTF_STRU;


typedef NAS_MSCC_PIF_CDMA_MO_CALL_END_NTF_STRU              MSCC_XSD_1X_MO_CALL_END_NTF_STRU;


/** ****************************************************************************
 * Name        : MSCC_XSD_SYSTEM_ACQUIRE_REQ_STRU
 * Description : System acquire request
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                        stMsgHeader;                    /*_H2ASN_Skip*//* 消息头                                   */
    MSCC_XSD_SYS_ACQ_TYPE_ENUM_UINT8            enSysAcqType;                   /* 1x驻留类型，分正常驻留和初搜 */
    VOS_UINT8                                   aucReserve[3];
}MSCC_XSD_SYSTEM_ACQUIRE_REQ_STRU;

/** ****************************************************************************
 * Name        : XSD_MSCC_SYSTEM_ACQUIRE_CNF_STRU
 * Description : System acquire confirm
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                        stMsgHeader;                    /*_H2ASN_Skip*//* 消息头                                   */
    NAS_MSCC_PIF_ACQUIRED_RESULT_ENUM_UINT32    enRslt;

}XSD_MSCC_SYSTEM_ACQUIRE_CNF_STRU;

/** ****************************************************************************
 * Name        : XSD_MSCC_SYSTEM_ACQUIRE_IND_STRU
 * Description : System acquire indication
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                        stMsgHeader;                    /*_H2ASN_Skip*//* 消息头                                   */
    NAS_MSCC_PIF_ACQUIRED_RESULT_ENUM_UINT32    enRslt;
}XSD_MSCC_SYSTEM_ACQUIRE_IND_STRU;




typedef NAS_MSCC_PIF_1X_SYSTEM_SERVICE_INFO_IND_STRU    XSD_MSCC_1X_SYSTEM_SERVICE_INFO_IND_STRU;



/** ****************************************************************************
 * Name        : XSD_MSCC_SYSTEM_ACQUIRE_START_IND_STRU
 * Description :
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                        stMsgHeader;                    /*_H2ASN_Skip*//* 消息头                                   */
}XSD_MSCC_SYSTEM_ACQUIRE_START_IND_STRU;


typedef NAS_MSCC_PIF_CDMACSQ_SET_REQ_STRU    MSCC_XSD_CDMACSQ_SET_REQ_STRU;


typedef NAS_MSCC_PIF_CDMACSQ_SET_CNF_STRU    XSD_MSCC_CDMACSQ_SET_CNF_STRU;


typedef NAS_MSCC_PIF_CDMACSQ_IND_STRU    XSD_MSCC_CDMACSQ_IND_STRU;

/** ****************************************************************************
 * Name        : MSCC_XSD_CFREQ_LOCK_NTF_STRU
 * Description : Start confirm
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                            stMsgHeader;                /*_H2ASN_Skip*//* 消息头                                   */
    VOS_UINT32                                      ulIsSupport1x;
    NAS_MSCC_PIF_CFREQ_LOCK_SET_MODE_ENUM_UINT8     enFreqLockMode;
    VOS_UINT8                                       aucReserve[1];
    VOS_UINT16                                      usCdmaBandClass;
    VOS_UINT16                                      usSid;
    VOS_UINT16                                      usNid;
    VOS_UINT16                                      usCdmaFreq;
    VOS_UINT16                                      usCdmaPn;
}MSCC_XSD_CFREQ_LOCK_NTF_STRU;


typedef NAS_MSCC_PIF_1X_SYSTEM_TIME_IND_STRU    XSD_MSCC_1X_SYSTEM_TIME_IND_STRU;



typedef NAS_MSCC_PIF_POWER_SAVE_REQ_STRU    MSCC_XSD_POWER_SAVE_REQ_STRU;


typedef NAS_MSCC_PIF_POWER_SAVE_CNF_STRU    XSD_MSCC_POWER_SAVE_CNF_STRU;


typedef struct
{
    MSCC_MSG_HEADER_STRU                                 stMsgHeader;          /* _H2ASN_Skip */
    VOS_UINT16                                           usOpId;
    VOS_UINT8                                            ucReserved[1];
    VOS_UINT8                                            ucSuppRatNum;
    VOS_RATMODE_ENUM_UINT32                              aenRatMode[VOS_RATMODE_BUTT];
    NAS_MSCC_PIF_CDMA_BAND_STRU                          stCdmaBand;
}MSCC_XSD_SYS_CFG_REQ_STRU;


typedef NAS_MSCC_PIF_SYS_CFG_SET_CNF_STRU   XSD_MSCC_SYS_CFG_CNF_STRU;



typedef NAS_MSCC_PIF_SRV_ACQ_REQ_STRU MSCC_XSD_SRV_ACQ_REQ_STRU;


typedef NAS_MSCC_PIF_SRV_ACQ_CNF_STRU XSD_MSCC_SRV_ACQ_CNF_STRU;


typedef NAS_MSCC_PIF_BEGIN_SESSION_NOTIFY_STRU MSCC_XSD_BEGIN_SESSION_NOTIFY_STRU;


typedef NAS_MSCC_PIF_END_SESSION_NOTIFY_STRU MSCC_XSD_END_SESSION_NOTIFY_STRU;


/** ****************************************************************************
 * Name        : MSCC_XSD_HANDSET_INFO_QRY_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                stMsgHeader;                /*_H2ASN_Skip*//* 消息头                                   */
    VOS_UINT32                          ulInfoType;
    VOS_UINT16                          usOpId;
    VOS_UINT8                           aucReserve[2];
}MSCC_XSD_HANDSET_INFO_QRY_STRU;


typedef struct
{
    MSCC_MSG_HEADER_STRU                stMsgHeader;        /*_H2ASN_Skip*//* 消息头    */
    VOS_UINT32                          ulInfoType;         /* 请求的信息类型 */
    VOS_UINT8                           ucCasState;         /* cas上报的主状态 */
    VOS_UINT8                           ucCasSubSta;        /* cas上报的子状态 */
    VOS_UINT8                           ucHighVer;          /* cas上报的所支持的最高的版本 */
    VOS_UINT8                           aucRsv[1];
}XSD_MSCC_HANDSET_INFO_QRY_CNF_STRU;

/** ****************************************************************************
 * Name        : MSCC_XSD_NORMAL_SERVICE_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    MSCC_MSG_HEADER_STRU                                    stMsgHeader;                /*_H2ASN_Skip*//* 消息头                                   */
    VOS_UINT32                                              ulMcc;
    VOS_RATMODE_ENUM_UINT32                                 ulRatMode;
}MSCC_XSD_NORMAL_SERVICE_IND_STRU;



typedef NAS_MSCC_PIF_SID_NID_IND_STRU MSCC_XSD_SID_NID_IND_STRU;


typedef NAS_MSCC_PIF_EMC_CALLBACK_IND_STRU XSD_MSCC_EMC_CALLBACK_IND_STRU;


typedef NAS_MSCC_PIF_END_EMC_CALLBACK_IND_STRU MSCC_XSD_END_EMC_CALLBACK_NTF_STRU;

typedef NAS_MSCC_PIF_OPER_LOCK_SYS_WHITE_STRU MSCC_XSD_OPER_LOCK_SYS_WHITE_STRU;


typedef NAS_MSCC_PIF_SET_CSIDLIST_REQ_STRU MSCC_XSD_SET_CSIDLIST_REQ_STRU;

typedef NAS_MSCC_PIF_SET_CSIDLIST_CNF_STRU XSD_MSCC_SET_CSIDLIST_CNF_STRU;

typedef NAS_MSCC_PIF_SYNC_SERVICE_AVAILABLE_IND_STRU XSD_MSCC_SYNC_SERVICE_AVAILABLE_IND_STRU;


/** ****************************************************************************
 * Name        : XSD_MSCC_1X_STATUS_IND_STRU
 * Description : UE STATE indication
 *******************************************************************************/
typedef NAS_MSCC_PIF_1X_UE_STATUS_IND_STRU XSD_MSCC_1X_UE_STATUS_IND_STRU;


typedef struct
{
    MSCC_MSG_HEADER_STRU                        stMsgHeader;                    /*_H2ASN_Skip*//* 消息头                                   */
    NAS_MSCC_PIF_1X_OOS_CAUSE_ENUM_UINT32       en1xOosCause;
}XSD_MSCC_1X_NO_SERVICE_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                      /* _H2ASN_Skip */
    MSCC_PIF_MSG_TYPE_ENUM_UINT32       enMsgId;                        /* _H2ASN_Skip */
    VOS_UINT8                           ucHrpdConnExistFlg;
    VOS_UINT8                           ucLteEpsConnExistFlg;
    VOS_UINT8                           aucRsv[2];
}MSCC_XSD_LTE_HRPD_CONN_INFO_IND_STRU;
/** ****************************************************************************
 * Name        : XSD_MSCC_PRL_HEADER_INFO_IND_STRU
 * Description : PRL HEADER INFO
 *******************************************************************************/
typedef NAS_MSCC_PRL_HEADER_INFO_IND_STRU                   XSD_MSCC_PRL_HEADER_INFO_IND_STRU;

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/
/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    VOS_UINT16      enMsgID;                /*_H2ASN_MsgChoice_Export XSD_MSCC_PIF_MSG_TYPE_ENUM_UINT16*/
    VOS_UINT8       aucMsgBlock[2];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          XSD_MSCC_PIF_MSG_TYPE_ENUM_UINT16
        ****************************************************************************/
}XSD_MSCC_PIF_MSG_DATA;
/*_H2ASN_Length UINT16*/


typedef struct
{
    VOS_MSG_HEADER
    XSD_MSCC_PIF_MSG_DATA       stMsgData;
}Xsd_mscc_pif_MSG;



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
