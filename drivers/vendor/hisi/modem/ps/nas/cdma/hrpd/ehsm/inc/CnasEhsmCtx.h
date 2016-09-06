

#ifndef __CNAS_EHSM_CTX_H__
#define __CNAS_EHSM_CTX_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "NasFsm.h"
#include "CnasPrlApi.h"
#include "PsCommonDef.h"
#include "CnasEhsmFsmMainTbl.h"
#include "CnasEhsmTimerMgmt.h"
#include "ehsm_esm_pif.h"
#include "ehsm_aps_pif.h"
#include "ehsm_hsm_pif.h"
#include "cnas_cttf_ehrpd_ehsm_ppp_pif.h"
#include "CnasEhsmComFunc.h"
#include "Nas_Mem.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define CNAS_EHSM_MAX_FSM_STACK_DEPTH                        (4)                 /* 状态机栈的深度 */

#define CNAS_EHSM_MAX_CACHE_MSG_QUEUE_NUM                    (12)                 /* 最大缓存消息的个数 */

#define CNAS_EHSM_MAX_INT_MSG_QUEUE_NUM                      (8)

#define CNAS_EHSM_MAX_MSG_BUFFER_LEN                         (1600)              /* 消息的最大长度，包括状态机保存的入口消息和CACHE消息 */

/* 存储的最大的MRU个数，CGD 130 5.2.2 The number of entries in an MRU list is implementation dependent but a typical number may be 12 */
#define CNAS_EHSM_MAX_MRU_SYS_NUM                            (12)

#define CNAS_EHSM_MAX_PDN_NUM                                (15)

#define CNAS_EHSM_CID_NV_NUM                                 (12)              /* NV参数的数目 */

#define CNAS_EHSM_DEFAULT_MAX_RETRY_CONN_EST                 (3)

#define CNAS_EHSM_DEFAULT_MAX_RETRY_PDN_SETUP                (2)

#define CNAS_EHSM_MAX_RETRY_PDN_SETUP_FOR_LCP_OTHER_FAIL     (2)

#define CNAS_EHSM_DEFAULT_RETRY_CONN_EST_TIMER_LENGTH        (5000)

#define CNAS_EHSM_DEFAULT_RETRY_PDN_SETUP_TIMER_LENGTH       (10000)

#define CNAS_EHSM_INVALID_PDN_ID                             (0xff)

#define CNAS_EHSM_DEFAULT_CID                                (0)

#define CNAS_EHSM_PCO_MAX_LEN                                ( 251 )
#define CNAS_EHSM_MAX_APN_LEN                                ( 100 )
#define CNAS_EHSM_IPV4_ADDR_LEN                              ( 4 )

#define CNAS_EHSM_IPV6_IFID_LEN                              ( 8 )

#define CNAS_EHSM_IPV6_ADDR_LEN                              ( 16 )
#define CNAS_EHSM_IPV4V6_ADDR_LEN                            ( 12 )
#define CNAS_EHSM_MAX_AUTHDATA_PASSWORD_LEN                  ( 127 )
#define CNAS_EHSM_MAX_AUTHDATA_USERNAME_LEN                  ( 127 )
#define CNAS_EHSM_IPV6_DNS_LEN                               ( 16 )
#define CNAS_EHSM_IPV6_PCSCF_LEN                             ( 16 )

#define CNAS_EHSM_INVALID_RETRY_CNT                          (0xFF)



#define CNAS_EHSM_CURR_PDN_NUM_1                            (1)
#define CNAS_EHSM_CURR_PDN_NUM_2                            (2)

#define CNAS_EHSM_MAX_ERROR_LOG_INFO_NUM                    (10)

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum CNAS_EHSM_FSM_ID_ENUM
{
    /***********************************************************************
     * EHSM L1 MAin FSM
     ***********************************************************************/
    CNAS_EHSM_FSM_L1_MAIN                                    =0x00,

    /***********************************************************************
     * EHSM L2 FSM id
     ***********************************************************************/
    /* Activating FSM */
    CNAS_EHSM_FSM_ACTIVATING                                 =0x01,

    /* Deactivating FSM */
    CNAS_EHSM_FSM_DEACTIVATING                               =0x02,

    CNAS_EHSM_FSM_BUTT

};
typedef VOS_UINT32 CNAS_EHSM_FSM_ID_ENUM_UINT32;



enum CNAS_EHSM_EHRPD_STA_ENUM
{
    CNAS_EHSM_EHRPD_INACTIVE_STA                                    =0x00,
    CNAS_EHSM_EHRPD_ACTIVE_STA,
    CNAS_EHSM_EHRPD_DORMANT_STA,
    CNAS_EHSM_EHRPD_SUSPEND_STA,
    CNAS_EHSM_EHRPD_STA_BUTT
};
typedef VOS_UINT32 CNAS_EHSM_EHRPD_STA_ENUM_UINT32;


enum CNAS_EHSM_INIT_CTX_TYPE_ENUM
{
    CNAS_EHSM_INIT_CTX_STARTUP                    = 0,
    CNAS_EHSM_INIT_CTX_POWEROFF                   = 1,
    CNAS_EHSM_INIT_CTX_BUTT
};
typedef VOS_UINT8 CNAS_EHSM_INIT_CTX_TYPE_ENUM_UINT8;



enum CNAS_EHSM_HRPD_WORK_MODE_ENUM
{
    CNAS_EHSM_HRPD_WORK_MODE_SLAVE            = 0x0000,
    CNAS_EHSM_HRPD_WORK_MODE_MASTER           = 0x0001,
    CNAS_EHSM_HRPD_WORK_MODE_BUTT             = 0x0002
};
typedef VOS_UINT8 CNAS_EHSM_HRPD_WORK_MODE_ENUM_UINT8;


enum CNAS_EHSM_ERROR_CODE_ENUM
{
    CNAS_EHSM_ERROR_CODE_NO_ERROR                   = 0x0000,
    CNAS_EHSM_ERROR_CODE_PREPROC                    = 0x0001,
    CNAS_EHSM_ERROR_CODE_INACTIVE                   = 0x0002,
    CNAS_EHSM_ERROR_CODE_SUSPEND                    = 0x0003,
    CNAS_EHSM_ERROR_CODE_NO_SYNC                    = 0x0004,
    CNAS_EHSM_ERROR_CODE_PDN_DIFFER                 = 0x0005,
    CNAS_EHSM_ERROR_CODE_BUTT
};
typedef VOS_UINT8 CNAS_EHSM_ERROR_CODE_ENUM_UINT8;



enum CNAS_EHSM_ABORT_FSM_TYPE
{
    CNAS_EHSM_ABORT_FSM_IMMEDIATELY           = 0,
    CNAS_EHSM_ABORT_FSM_DELAY                 = 1,
    CNAS_EHSM_ABORT_BUTT
};
typedef VOS_UINT8 CNAS_EHSM_ABORT_FSM_TYPE_UINT8;


enum CNAS_EHSM_MSG_COMPARE_PRIO_RSLT_ENUM
{
    CNAS_EHSM_MSG_COMPARE_PRIO_RSLT_ABORT              ,                        /* 高优先级消息中断当前流程 */
    CNAS_EHSM_MSG_COMPARE_PRIO_RSLT_STORE              ,                        /* 需要缓存的消息 */
    CNAS_EHSM_MSG_COMPARE_PRIO_RSLT_INITFSM            ,                        /* 进入状态机中处理 */
    CNAS_EHSM_MSG_COMPARE_PRIO_RSLT_DISCARD            ,                        /* 直接丢弃的消息 */

    CNAS_EHSM_MSG_COMPARE_PRIO_RSLT_BUTT
};
typedef VOS_UINT32 CNAS_EHSM_MSG_COMPARE_PRIO_RSLT_ENUM_UINT32;

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


typedef struct
{
    VOS_UINT32                          ulEventType;
    VOS_UINT8                           aucMsgBuffer[CNAS_EHSM_MAX_MSG_BUFFER_LEN];
}CNAS_EHSM_MSG_STRU;



typedef struct
{
    VOS_UINT16                              usCurConnEstRetryTimes;
    VOS_UINT16                              usLcpOtherFailRetryTimes;
}CNAS_EHSM_ACTIVATING_RETRY_INFO_STRU;


typedef struct
{
    CNAS_EHSM_ACTIVATING_RETRY_INFO_STRU    stRetryInfo;
    VOS_UINT8                               ucPdnId;
    VOS_UINT8                               ucCid;
    VOS_UINT8                               ucAbortFlag;                        /* VOS_TRUE: there is a abort req; VOS_FALSE: there no power off abort req*/
    VOS_UINT8                               ucSendPdnActFlag;
    VOS_UINT32                              ulAbortEventType;
}CNAS_EHSM_FSM_ACTIVATING_CTX_STRU;



typedef struct
{
    VOS_UINT16                              usCurConnEstRetryTimes;
    VOS_UINT8                               aucReserved[2];
}CNAS_EHSM_DEACTIVATING_RETRY_INFO_STRU;


typedef struct
{
    CNAS_EHSM_DEACTIVATING_RETRY_INFO_STRU  stRetryInfo;
    VOS_UINT8                               ucAbortFlag;                         /*1: there is a abort req; 0: there no power off abort req*/
    VOS_UINT8                               ucSendPdnDeactFlag;
    VOS_UINT8                               ucSendPdnDetachFlag;
    VOS_UINT8                               aucReserved[1];
    VOS_UINT32                              ulAbortEventType;
}CNAS_EHSM_FSM_DEACTIVATING_CTX_STRU;


typedef union
{
    /* remove this reserved memeber while adding FSM details */
    CNAS_EHSM_FSM_ACTIVATING_CTX_STRU       stActivatingCtx;
    CNAS_EHSM_FSM_DEACTIVATING_CTX_STRU     stDeactivatingCtx;
}CNAS_EHSM_FSM_EXTRA_CTX_UNION;



typedef struct
{
    /* FSM Descriptor containing the State table, init handle  */
    NAS_FSM_DESC_STRU                  *pstFsmDesc;

    /* Stores the ID of the current FSM */
    CNAS_EHSM_FSM_ID_ENUM_UINT32        enFsmId;

    /* Stores the ID of the parent FSM */
    CNAS_EHSM_FSM_ID_ENUM_UINT32        enParentFsmId;

    /* Stores the Event type of the parent FSM */
    VOS_UINT32                          ulParentEventType;

    /* Stores the current state of the FSM */
    VOS_UINT32                          ulState;

    /* Stores the current entry message  */
    CNAS_EHSM_MSG_STRU                  stEntryMsg;

    /* Stores Context details specific to FSM */
    CNAS_EHSM_FSM_EXTRA_CTX_UNION       unFsmCtx;

}CNAS_EHSM_FSM_CTX_STRU;


typedef struct
{
    VOS_UINT16                          usStackDepth;                           /* Stores the current Stack depth */
    VOS_UINT16                          usStackPopFlg;                          /* 当前栈pop标志 */
    CNAS_EHSM_FSM_CTX_STRU              astFsmStack[CNAS_EHSM_MAX_FSM_STACK_DEPTH];  /* Array of FSM contexts */
}CNAS_EHSM_FSM_STACK_STRU;


typedef struct
{
    VOS_UINT8                           ucCacheMsgNum;                          /* Stores the number of Cache messages */
    VOS_UINT8                           aucReserve[3];                          /* Required for padding */
    VOS_UINT8                          *pastCacheMsg[CNAS_EHSM_MAX_CACHE_MSG_QUEUE_NUM]; /* Queue of cache messages */
}CNAS_EHSM_CACHE_MSG_QUEUE_STRU;


typedef struct
{
    VOS_UINT8                           ucIntMsgNum;                                /* Number of internal messages */
    VOS_UINT8                           aucReserve[3];
    VOS_UINT8                          *pastIntMsg[CNAS_EHSM_MAX_INT_MSG_QUEUE_NUM]; /* Queue of internal messages */
}CNAS_EHSM_INT_MSG_QUEUE_STRU;

/** ****************************************************************************
 * Name        : CNAS_EHSM_PCO_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucPcoLen;
    VOS_UINT8                           aucProl[CNAS_EHSM_PCO_MAX_LEN];
}CNAS_EHSM_PCO_STRU;

/** ****************************************************************************
 * Name        : CNAS_EHSM_APN_STRU
 *
 * Description : APN格式:"HUAWEI.COM"---6HUAWEI3COM
 *******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucApnLen;
    VOS_UINT8                           aucReserved[3];
    VOS_UINT8                           aucApn[CNAS_EHSM_MAX_APN_LEN];
} CNAS_EHSM_APN_STRU;

/** ****************************************************************************
 * Name        : EHSM_APS_PDN_ADDR_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    CNAS_EHSM_PDN_TYPE_ENUM_UINT8       enPdnType;
    VOS_UINT8                           ucSyncToEsmIpv6Addr;
    VOS_UINT8                           aucReserved[2];
    VOS_UINT8                           aucIpv4Addr[CNAS_EHSM_IPV4_ADDR_LEN];
    VOS_UINT8                           aucIpv6Addr[CNAS_EHSM_IPV6_ADDR_LEN];
} CNAS_EHSM_PDN_ADDR_STRU;

/** ****************************************************************************
 * Name        : CNAS_EHSM_APN_AMBR_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpDLApnAmbr:1;
    VOS_UINT32                          bitOpULApnAmbr:1;
    VOS_UINT32                          bitOpDLApnAmbrExt:1;
    VOS_UINT32                          bitOpULApnAmbrExt:1;
    VOS_UINT32                          bitOpDLApnAmbrExt2:1;
    VOS_UINT32                          bitOpULApnAmbrExt2:1;
    VOS_UINT32                          bitOpSpare:26;
    VOS_UINT8                           ucDLApnAmbr;
    VOS_UINT8                           ucULApnAmbr;
    VOS_UINT8                           ucDLApnAmbrExt;
    VOS_UINT8                           ucULApnAmbrExt;
    VOS_UINT8                           ucDLApnAmbrExt2;
    VOS_UINT8                           ucULApnAmbrExt2;
    VOS_UINT8                           aucReserved[2];
} CNAS_EHSM_APN_AMBR_STRU;
/** ****************************************************************************
 * Name        : CNAS_EHSM_PCO_IPV4_ITEM_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPriDns:1;
    VOS_UINT32                          bitOpSecDns:1;
    VOS_UINT32                          bitOpGateWay:1;
    VOS_UINT32                          bitOpPriNbns:1;
    VOS_UINT32                          bitOpSecNbns:1;
    VOS_UINT32                          bitOpPriPcscf:1;
    VOS_UINT32                          bitOpSecPcscf:1;
    VOS_UINT32                          bitOpSpare:25;
    VOS_UINT8                           aucPriDns[CNAS_EHSM_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecDns[CNAS_EHSM_IPV4_ADDR_LEN];
    VOS_UINT8                           aucGateWay[CNAS_EHSM_IPV4_ADDR_LEN];
    VOS_UINT8                           aucPriNbns[CNAS_EHSM_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecNbns[CNAS_EHSM_IPV4_ADDR_LEN];
    VOS_UINT8                           aucPriPcscf[CNAS_EHSM_IPV4_ADDR_LEN];
    VOS_UINT8                           aucSecPcscf[CNAS_EHSM_IPV4_ADDR_LEN];
} CNAS_EHSM_PCO_IPV4_ITEM_STRU;

/** ****************************************************************************
 * Name        : CNAS_EHSM_PCO_IPV6_ITEM_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpPriDns:1;
    VOS_UINT32                          bitOpSecDns:1;
    VOS_UINT32                          bitOpPriPcscf:1;
    VOS_UINT32                          bitOpSecPcscf:1;
    VOS_UINT32                          bitOpSpare:28;
    VOS_UINT8                           aucPriDns[CNAS_EHSM_IPV6_DNS_LEN];
    VOS_UINT8                           aucSecDns[CNAS_EHSM_IPV6_DNS_LEN];
    VOS_UINT8                           aucPriPcscf[CNAS_EHSM_IPV6_PCSCF_LEN];
    VOS_UINT8                           aucSecPcscf[CNAS_EHSM_IPV6_PCSCF_LEN];
} CNAS_EHSM_PCO_IPV6_ITEM_STRU;

typedef struct
{
    VOS_UINT8                                               ucPdnId;
    VOS_UINT8                                               ucInUsed;
    VOS_UINT8                                               ucCid;
    VOS_UINT8                                               ucIsPdnActive;
    VOS_UINT32                                              ulEpsbId;
    CNAS_EHSM_PDN_ADDR_STRU                                 stPdnAddr;
    CNAS_EHSM_APN_STRU                                      stApn;
    CNAS_EHSM_APN_AMBR_STRU                                 stApnAmbr;
    CNAS_EHSM_ATTACH_TYPE_ENUM_UINT8                        enAttachType;
    CNAS_EHSM_PDN_TYPE_ENUM_UINT8                           enPdnType;                                                     /**< to indicate IPv4 or v6, or both */
    VOS_UINT16                                              usMtu;
    CNAS_EHSM_AUTH_TYPE_ENUM_UINT8                          enAuthType;
    VOS_UINT8                                               ucUserNameLen;
    VOS_UINT8                                               ucPwdLen;
    VOS_UINT8                                               ucRetryTotalCnt;
    VOS_UINT8                                               aucIpv4DefaultRouterAddress[CNAS_CTTF_EHRPD_IPV4_ADDRESS_LEN];
    VOS_UINT8                                               aucUserName[CNAS_EHSM_MAX_AUTHDATA_USERNAME_LEN+1];
    VOS_UINT8                                               aucPwd[CNAS_EHSM_MAX_AUTHDATA_PASSWORD_LEN+1];
    CNAS_EHSM_PCO_IPV4_ITEM_STRU                            stPcoIpv4Item;
    CNAS_EHSM_PCO_IPV6_ITEM_STRU                            stPcoIpv6Item;
}CNAS_EHSM_EHRPD_PDN_BEAR_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucInUsed;
    VOS_UINT8                           ucCid;
    CNAS_EHSM_PDN_TYPE_ENUM_UINT8       enPdnType;                                                     /**< to indicate IPv4 or v6, or both */
    VOS_UINT8                           aucReserved[1];
    VOS_UINT32                          ulEpsbId;
    CNAS_EHSM_PDN_ADDR_STRU             stPdnAddr;
    CNAS_EHSM_APN_STRU                  stApn;
    CNAS_EHSM_APN_AMBR_STRU             stApnAmbr;
    CNAS_EHSM_PCO_IPV4_ITEM_STRU        stPcoIpv4Item;
    CNAS_EHSM_PCO_IPV6_ITEM_STRU        stPcoIpv6Item;
}CNAS_EHSM_LTE_PDN_BEAR_INFO_STRU;

typedef struct
{
    VOS_UINT32                          ulExpireTimerLen;
    VOS_UINT16                          usMaxNoOfRetry;
    VOS_UINT8                           aucReserved[2];
}CNAS_EHSM_RETRY_CONN_EST_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucCurrRetryCnt;
    VOS_UINT8                           aucReserved[3];
    CNAS_EHSM_APN_STRU                  stApn;
}CNAS_EHSM_RETRY_PDN_BEAR_INFO_STRU;


typedef struct
{
    VOS_UINT32                          ulExpireTimerLen;
    VOS_UINT16                          usMaxNoOfRetry;
    VOS_UINT8                           aucReserved[2];
    CNAS_EHSM_RETRY_PDN_BEAR_INFO_STRU  astRetryApnfo[CNAS_EHSM_MAX_PDN_NUM];
}CNAS_EHSM_RETRY_PDN_SETUP_INFO_STRU;


typedef struct
{
    CNAS_EHSM_RETRY_CONN_EST_INFO_STRU  stRetryConnEstInfo;                     /* Contains the details about common conn est retry information */
    CNAS_EHSM_RETRY_PDN_SETUP_INFO_STRU stRetryPdnSetupInfo;                    /* Contains the details about PDN setup retry information */
}CNAS_EHSM_RETRY_CTRL_INFO_STRU;



typedef struct
{
    VOS_UINT32                          ulTime;
    CNAS_EHSM_FSM_ID_ENUM_UINT32        enFsmId;                                /* Stores the ID of the current FSM */
    VOS_UINT32                          ulState;                                /* Stores the current state of the FSM */
    VOS_UINT32                          ulParentEventType;                      /* Stores the Event type of the parent FSM */
    CNAS_EHSM_EHRPD_STA_ENUM_UINT32     enEhrpdState;                           /* Stores the State of the Ehrpd */

    CNAS_EHSM_ERROR_CODE_ENUM_UINT8     enErrorCode;                            /* Recodes the option for Lte Pdn info */
    CNAS_EHSM_HRPD_WORK_MODE_ENUM_UINT8 enEhrpdWorkMode;
    VOS_UINT8                           ucLteAttachFlag;                        /* Stores the attach flag for Lte Pdn info */
    VOS_UINT8                           ucLteOption;                            /* Stores the option for Lte Pdn info */
    VOS_UINT32                          ulBitCid;
    VOS_UINT32                          ulEpsbId;

}CNAS_EHSM_ERROR_INFO_STRU;



typedef struct
{
    VOS_UINT32                          ulCount;
    CNAS_EHSM_ERROR_INFO_STRU           astErrorInfo[CNAS_EHSM_MAX_ERROR_LOG_INFO_NUM];
}CNAS_EHSM_ERROR_INFO_TOTAL_STRU;



typedef struct
{
    CNAS_EHSM_FSM_CTX_STRU              stCurFsm;                               /* Current FSm details */
    CNAS_EHSM_FSM_STACK_STRU            stFsmStack;                             /* FSM stack details */
    CNAS_EHSM_CACHE_MSG_QUEUE_STRU      stCacheMsgQueue;
    CNAS_EHSM_INT_MSG_QUEUE_STRU        stIntMsgQueue;
    CNAS_EHSM_TIMER_CTX_STRU            astEhsmTimerCtx[TI_CNAS_EHSM_TIMER_BUTT];    /* EHSM Timer context details */
    CNAS_EHSM_EHRPD_PDN_BEAR_INFO_STRU  astLocalPdnBearInfo[CNAS_EHSM_MAX_PDN_NUM];
    CNAS_EHSM_LTE_PDN_BEAR_INFO_STRU    astLtePdnBearInfo[CNAS_EHSM_MAX_PDN_NUM];
    CNAS_EHSM_EHRPD_STA_ENUM_UINT32     enEhrpdState;                                /* 0:inactive 1:active 2:dormant 3:suspend(activating/deactivating/interwork)*/
    EHSM_HSM_SESSION_TYPE_ENUM_UINT32   enSessionType;
    VOS_UINT32                          ulAirLinkExist;                              /* 0: air link not exist 1: air link exist */
    CNAS_EHSM_RETRY_CTRL_INFO_STRU      stRetryCtrlInfo;
    CNAS_EHSM_HRPD_WORK_MODE_ENUM_UINT8 enWorkMode;                             /* 0:从模 1:主模 */
    VOS_UINT8                           ucHandOverFailFlag;                     /* 记录L2C时，最近的一次attach协商是否是失败的 */
    VOS_UINT8                           aucReserved[2];
    VOS_UINT32                          ulAutoAttachFlag;                       /* 自动发起Auto Attach的标记 */

    CNAS_EHSM_ERROR_INFO_TOTAL_STRU           stErrorLogInfo;                         /* 目前CL互操作切换不稳定，需要记录错误原因 */
}CNAS_EHSM_CTX_STRU;


typedef struct
{
    VOS_UINT32                                              ulAutoAttachFlag;                       /* 自动发起Auto Attach的标记 */
    VOS_UINT32                                              ulExpireTimerLenOfRetryConn;
    VOS_UINT32                                              ulExpireTimerLenOfRetryPdn;
    VOS_UINT16                                              usMaxNoOfRetryConn;
    VOS_UINT16                                              usMaxNoOfRetryPdn;
}CNAS_EHSM_PC_REPLAY_FIXED_CONTEXT_MSG_STRU;


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
CNAS_EHSM_CTX_STRU* CNAS_EHSM_GetEhsmCtxAddr(VOS_VOID);

VOS_VOID CNAS_EHSM_InitCtx(
    CNAS_EHSM_INIT_CTX_TYPE_ENUM_UINT8  enInitType
);

VOS_VOID CNAS_EHSM_ClearCtx(
    CNAS_EHSM_INIT_CTX_TYPE_ENUM_UINT8  enInitType
);

CNAS_EHSM_TIMER_CTX_STRU *CNAS_EHSM_GetTimerCtxAddr(VOS_VOID);

VOS_VOID  CNAS_EHSM_LoadSubFsm(
    CNAS_EHSM_FSM_ID_ENUM_UINT32        enFsmId,
    CNAS_EHSM_FSM_CTX_STRU             *pstCurFsm
);

VOS_VOID CNAS_EHSM_InitFsmL2(
    CNAS_EHSM_FSM_ID_ENUM_UINT32        enFsmId
);
VOS_VOID CNAS_EHSM_PopFsm( VOS_VOID );

VOS_VOID CNAS_EHSM_PushFsm(
    CNAS_EHSM_FSM_STACK_STRU            *pstFsmStack,
    CNAS_EHSM_FSM_CTX_STRU              *pstNewFsm
);

VOS_VOID CNAS_EHSM_QuitFsmL2(VOS_VOID);

VOS_VOID  CNAS_EHSM_SetCurrFsmState(
    VOS_UINT32                          ulCurrState
);

VOS_UINT32 CNAS_EHSM_GetFsmTopState(VOS_VOID);

CNAS_EHSM_CACHE_MSG_QUEUE_STRU* CNAS_EHSM_GetCacheMsgAddr(VOS_VOID);

VOS_UINT32  CNAS_EHSM_SaveCacheMsg(
    VOS_UINT32                          ulEventType,
    VOS_VOID                           *pstMsg,
    CNAS_EHSM_ABORT_FSM_TYPE_UINT8      enAbortType
);

VOS_UINT32 CNAS_EHSM_GetNextCachedMsg(
    CNAS_EHSM_MSG_STRU                 *pstEntryMsg
);

CNAS_EHSM_FSM_CTX_STRU* CNAS_EHSM_GetCurFsmAddr(VOS_VOID);

NAS_FSM_DESC_STRU* CNAS_EHSM_GetCurFsmDesc(VOS_VOID);

CNAS_EHSM_FSM_ID_ENUM_UINT32 CNAS_EHSM_GetCurrFsmId(VOS_VOID);

CNAS_EHSM_MSG_STRU* CNAS_EHSM_GetCurrFsmEntryMsgAddr(VOS_VOID);

CNAS_EHSM_FSM_STACK_STRU* CNAS_EHSM_GetFsmStackAddr(VOS_VOID);

VOS_UINT16 CNAS_EHSM_GetFsmStackDepth(VOS_VOID);

CNAS_EHSM_INT_MSG_QUEUE_STRU* CNAS_EHSM_GetIntMsgQueueAddr(VOS_VOID);

VOS_VOID CNAS_EHSM_InitInternalBuffer(
    CNAS_EHSM_INT_MSG_QUEUE_STRU       *pstIntMsgQueue
);

VOS_VOID CNAS_EHSM_PutMsgInIntMsgQueue(
    VOS_UINT8                          *pstMsg
);

VOS_UINT8 *CNAS_EHSM_GetNextIntMsg(VOS_VOID);

VOS_UINT8 CNAS_EHSM_GetIntMsgNum(VOS_VOID);


VOS_VOID CNAS_EHSM_ClearCacheMsg(
    VOS_UINT8                           ucIndex
);

VOS_VOID CNAS_EHSM_ClearAllCacheMsg(VOS_VOID);

VOS_VOID CNAS_EHSM_SaveCacheMsgInMsgQueue(
    VOS_UINT32                          ulEventType,
    VOS_VOID                           *pstMsg,
    CNAS_EHSM_ABORT_FSM_TYPE_UINT8      enAbortType
);

VOS_VOID CNAS_EHSM_InitCacheMsgQueue(
    CNAS_EHSM_INIT_CTX_TYPE_ENUM_UINT8  enInitType,
    CNAS_EHSM_CACHE_MSG_QUEUE_STRU     *pstCacheMsgQueue
);


VOS_VOID CNAS_EHSM_SaveCurEntryMsg(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
);


VOS_VOID CNAS_EHSM_InitCurrFsmCtx(
    CNAS_EHSM_FSM_CTX_STRU              *pstCurrFsmCtx
);

VOS_VOID CNAS_EHSM_InitFsmStackCtx(
    CNAS_EHSM_FSM_STACK_STRU           *pstFsmStack
);



VOS_VOID CNAS_EHSM_InitTimerCtx(
    CNAS_EHSM_TIMER_CTX_STRU           *pstTimerCtx
);

APS_EHSM_PS_RATTYPE_ENUM_UINT32 CNAS_EHSM_GetPsRatType(VOS_VOID);

VOS_VOID CNAS_EHSM_SetSessionType(
    EHSM_HSM_SESSION_TYPE_ENUM_UINT32   enSessionType
);

EHSM_HSM_SESSION_TYPE_ENUM_UINT32 CNAS_EHSM_GetSessionType(VOS_VOID);

VOS_VOID CNAS_EHSM_UpdateEhrpdLocalPdnInfoFromPdnConnCnf(
    CNAS_EHSM_EHRPD_PDN_BEAR_INFO_STRU                     *pstPdnInfo,
    CTTF_CNAS_EHRPD_PDN_CONN_CNF_STRU                      *pStPdnSetUpCnf
);

VOS_VOID CNAS_EHSM_UpdateEhrpdLocalPdnInfoFromAttachCnf(
    CNAS_EHSM_EHRPD_PDN_BEAR_INFO_STRU                     *pstPdnInfo,
    CTTF_CNAS_EHRPD_ATTACH_CNF_STRU                        *pStAttachCnf
);

VOS_VOID CNAS_EHSM_ClearEhrpdLocalPdnInfo(
    VOS_UINT8                           ucPdnId
);
VOS_VOID CNAS_EHSM_SaveLteLocalPdnInfo(
    VOS_UINT8                           ucIndex,
    ESM_EHSM_SYNC_PDN_INFO_IND_STRU    *pstSynPdnInfo
);
VOS_VOID CNAS_EHSM_ClearLteLocalPdnInfo(
    VOS_UINT8                           ucCid
);
VOS_VOID CNAS_EHSM_InitRetryConnEstInfo(
    CNAS_EHSM_RETRY_CONN_EST_INFO_STRU *pstRetryConnEstInfo
);

VOS_VOID CNAS_EHSM_InitRetryPdnsetupInfo(
    CNAS_EHSM_RETRY_PDN_SETUP_INFO_STRU                    *pstRetryPdnSetupInfo
);

VOS_UINT32 CNAS_EHSM_GetLocalActivePdnConnNum(VOS_VOID);

VOS_UINT32 CNAS_EHSM_GetLocalAllocatedPdnIdNum(VOS_VOID);

VOS_VOID CNAS_EHSM_InitPdnIdInLocalPdnBearInfo(
    CNAS_EHSM_EHRPD_PDN_BEAR_INFO_STRU *pstLocalPdnBearerInfo
);

VOS_VOID CNAS_EHSM_InitPdnIdInLtePdnBearInfo(
    CNAS_EHSM_LTE_PDN_BEAR_INFO_STRU *pstLtePdnBearerInfo
);

VOS_UINT32 CNAS_EHSM_GetLteActivePdnNum(VOS_VOID);

VOS_VOID CNAS_EHSM_InitEhrpdAutoAttachFlag(VOS_VOID);

VOS_UINT32 CNAS_EHSM_IsPdnActived(
    VOS_UINT8                           ucPdnId
);

VOS_UINT8  CNAS_EHSM_AllocPdnId(VOS_VOID);

VOS_UINT8  CNAS_EHSM_GetLtePdnUnusedIndex(VOS_VOID);

VOS_UINT8  CNAS_EHSM_AllocCid(VOS_VOID);



VOS_VOID CNAS_EHSM_InitFsmCtx_Activating(VOS_VOID);
VOS_VOID CNAS_EHSM_InitFsmCtx_Deactivating(VOS_VOID);
CNAS_EHSM_ACTIVATING_RETRY_INFO_STRU* CNAS_EHSM_GetRetryInfo_Activating(VOS_VOID);
CNAS_EHSM_DEACTIVATING_RETRY_INFO_STRU* CNAS_EHSM_GetRetryInfo_Deactivating(VOS_VOID);

VOS_UINT8 CNAS_EHSM_CheckLtePdnIsActive(VOS_VOID);
VOS_UINT8   CNAS_EHSM_GetPdnIdByCid(
    VOS_UINT8                           ucCid
);
VOS_UINT8 CNAS_EHSM_GetLtePdnInfoIndexByEpsbId(
    VOS_UINT32                          ulEpsbId
);

VOS_UINT8 CNAS_EHSM_GetPdnId_Activating(VOS_VOID);
VOS_VOID CNAS_EHSM_SetPdnId_Activating(
    VOS_UINT8                           ucPdnId
);
VOS_VOID CNAS_EHSM_SetCid_Activating(
    VOS_UINT8                           ucCid
);
VOS_VOID CNAS_EHSM_GetSdfParaAndSaveLocalPdnInfo(
    VOS_UINT8                           ucPdnId,
    VOS_UINT8                           ucCid
);
VOS_VOID CNAS_EHSM_LoadLocalPdnInfoFromLteInfo(
    VOS_UINT8                           ucLocPdnId,
    VOS_UINT8                           ucLtePdnIndex
);

VOS_UINT8 CNAS_EHSM_GetCid_Activating(VOS_VOID);

VOS_VOID CNAS_EHSM_SetPdnIdCid_Activating(
    VOS_UINT8                           ucPdnId,
    VOS_UINT8                           ucCid
);


VOS_VOID CNAS_EHSM_SetAbortFlag_Deactivating(
    VOS_UINT8                 ucAbortFlag
);
VOS_UINT8 CNAS_EHSM_GetAbortFlag_Deactivating(VOS_VOID);


VOS_VOID CNAS_EHSM_SetPsRatType(APS_EHSM_PS_RATTYPE_ENUM_UINT32 enPsRatType);

VOS_VOID CNAS_EHSM_SetAirLinkExistFlag(VOS_UINT32 ulAirLinkExist);

VOS_UINT32 CNAS_EHSM_GetAirLinkExistFlag(VOS_VOID);

VOS_VOID CNAS_EHSM_SetHrpdWorkMode(
    CNAS_EHSM_HRPD_WORK_MODE_ENUM_UINT8 enWorkMode
);

CNAS_EHSM_HRPD_WORK_MODE_ENUM_UINT8 CNAS_EHSM_GetHrpdWorkMode(VOS_VOID);

VOS_UINT32 CNAS_EHSM_GetEhrpdAutoAttachFlag(VOS_VOID);

VOS_VOID CNAS_EHSM_SetEhrpdAutoAttachFlag(
    VOS_UINT32                          ulAutoAttachFlag
);

VOS_VOID CNAS_EHSM_ClearAllEhrpdLocalPdnInfo(VOS_VOID);

VOS_VOID CNAS_EHSM_ClearAllLteLocalPdnInfo(VOS_VOID);

CNAS_EHSM_EHRPD_STA_ENUM_UINT32 CNAS_EHSM_GetEhrpdState(VOS_VOID);

VOS_VOID CNAS_EHSM_SetEhrpdState(
    CNAS_EHSM_EHRPD_STA_ENUM_UINT32     enState
);

VOS_VOID CNAS_EHSM_SetAbortEventType_Deactivating(
    VOS_UINT32                ulAbortEventType
);



VOS_UINT8   CNAS_EHSM_GetCidByPdnId(
    VOS_UINT8                           ucPdnId
);

VOS_UINT32 CNAS_EHSM_GetEpsbIdByPdnId(
    VOS_UINT8                           ucPdnId
);

VOS_VOID  CNAS_EHSM_SetFsmStackPopFlg(
    VOS_UINT16                          ucStackPopFlg
);

VOS_UINT16  CNAS_EHSM_GetFsmStackPopFlg( VOS_VOID );

VOS_VOID CNAS_EHSM_SaveApnAmbrInfo(
    CNAS_EHSM_APN_AMBR_STRU                                *pstLocalApnAmbr,
    CNAS_CTTF_EHRPD_APN_AMBR_STRU                          *pstApnAmbr
);
VOS_VOID CNAS_EHSM_SaveDecoPcoInfo(
    CNAS_EHSM_EHRPD_PDN_BEAR_INFO_STRU                     *pstPdnInfo,
    CNAS_CTTF_EHRPD_PCO_STRU                               *pStPcoInfo
);

VOS_VOID CNAS_EHSM_FillPcoInfoForSyncPndInfoInd(
    EHSM_ESM_SYNC_PDN_INFO_IND_STRU    *pstMsg,
    CNAS_EHSM_PCO_IPV4_ITEM_STRU       *pstPcoIpv4Item,
    CNAS_EHSM_PCO_IPV6_ITEM_STRU       *pstPcoIpv6Item
);
VOS_VOID CNAS_EHSM_FillPdnAddrInfoForSyncPndInfoInd(
    EHSM_ESM_SYNC_PDN_INFO_IND_STRU    *pstMsg,
    CNAS_EHSM_PDN_ADDR_STRU            *pstPdnAddr
);

VOS_VOID CNAS_EHSM_FillApnAmbrInfoForSyncPndInfoInd(
    EHSM_ESM_SYNC_PDN_INFO_IND_STRU    *pstMsg,
    CNAS_EHSM_APN_AMBR_STRU            *pstApnAmbr
);

VOS_UINT8 CNAS_EHSM_GetLtePdnIndexWithMinEspbId(VOS_VOID);

VOS_VOID CNAS_EHSM_SaveApnAmbrWithEsmPdnInfo(
    CNAS_EHSM_APN_AMBR_STRU            *pstApnAmbr,
    ESM_EHSM_SYNC_PDN_INFO_IND_STRU    *pstSynPdnInfo
);

VOS_VOID CNAS_EHSM_SavePcoIpv6ItemWithEsmPdnInfo(
    CNAS_EHSM_PCO_IPV6_ITEM_STRU       *pstPcoIpv6Item,
    ESM_EHSM_SYNC_PDN_INFO_IND_STRU    *pstSynPdnInfo
);

VOS_VOID CNAS_EHSM_SavePcoIpv4ItemWithEsmPdnInfo(
    CNAS_EHSM_PCO_IPV4_ITEM_STRU       *pstPcoIpv4Item,
    ESM_EHSM_SYNC_PDN_INFO_IND_STRU    *pstSynPdnInfo
);

VOS_VOID CNAS_EHSM_SavePdnAddressWithEsmPdnInfo(
    CNAS_EHSM_PDN_ADDR_STRU            *pstPdnAddr,
    ESM_EHSM_SYNC_PDN_INFO_IND_STRU    *pstSynPdnInfo
);

VOS_VOID CNAS_EHSM_SaveApnInfoWithEsmPdnInfo(
    CNAS_EHSM_APN_STRU                 *pstApn,
    ESM_EHSM_SYNC_PDN_INFO_IND_STRU    *pstSynPdnInfo
);

VOS_VOID CNAS_EHSM_InitApnRetryInfo(VOS_VOID);

CNAS_EHSM_RETRY_PDN_BEAR_INFO_STRU* CNAS_EHSM_GetRetryApnAddr(VOS_VOID);


VOS_UINT8 CNAS_EHSM_GetSpecialApnRetryCnt
(
    CNAS_EHSM_APN_STRU                 *pstApn
);

VOS_VOID CNAS_EHSM_IncreSpecialApnRetryCnt
(
    CNAS_EHSM_APN_STRU                                     *pstApn
);

VOS_UINT16 CNAS_EHSM_GetMaxNumOfApnRetry(VOS_VOID);

VOS_UINT8  CNAS_EHSM_GetNumOfLocalLtePdn(VOS_VOID);

VOS_VOID CNAS_EHSM_SetSendPdnActFlag_Activating(
    VOS_UINT8                           ucFlag
);

VOS_UINT8 CNAS_EHSM_GetSendPdnActFlag_Activating(VOS_VOID);

VOS_VOID CNAS_EHSM_SetSendPdnDeactFlag_Deactivating(
    VOS_UINT8                           ucFlag
);

VOS_UINT8 CNAS_EHSM_GetSendPdnDeactFlag_Deactivating(VOS_VOID);

VOS_VOID CNAS_EHSM_SetSendPdnDetachFlag_Deactivating(
    VOS_UINT8                           ucFlag
);

VOS_UINT8 CNAS_EHSM_GetSendPdnDetachFlag_Deactivating(VOS_VOID);


VOS_VOID CNAS_EHSM_GetApnFromLteInfo(
    CNAS_EHSM_APN_STRU                 *pstEhrpdApn,
    CNAS_EHSM_APN_STRU                 *pstLteApn
);

VOS_UINT32 CNAS_EHSM_GetCidSdfParaInfoForEhsm(
    VOS_UINT8                           ucCid,
    APS_EHSM_SDF_PARA_INFO_STRU        *pstSdfParaInfo
);

CNAS_EHSM_EHRPD_PDN_BEAR_INFO_STRU* CNAS_EHSM_GetEhrpdLocPdnAddr(
    VOS_UINT8                           ucPdnId
);


VOS_VOID CNAS_EHSM_SyncEhrpdIpv6PrfixWithLtePdnInfo(
    VOS_UINT8                           ucPdnId
);

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
extern VOS_UINT32 I1_TAF_APS_GetCidSdfParaInfoForEhsm(
    VOS_UINT8                           ucCid,
    APS_EHSM_SDF_PARA_INFO_STRU        *pstSdfParaInfo
);

#if (3 == MULTI_MODEM_NUMBER)
extern VOS_UINT32 I2_TAF_APS_GetCidSdfParaInfoForEhsm(
    VOS_UINT8                           ucCid,
    APS_EHSM_SDF_PARA_INFO_STRU        *pstSdfParaInfo
);
#endif
#endif

VOS_UINT8 CNAS_EHSM_GetPdnRetryTotal(
    VOS_UINT8                           ucPdnId
);

VOS_VOID CNAS_EHSM_IncreasePdnRetryTotal(
    VOS_UINT8                           ucPdnId
);


VOS_UINT8 CNAS_EHSM_GetPdnAttachType(
    VOS_UINT8                           ucPdnId
);



VOS_VOID CNAS_EHSM_InitErorLogInfo(VOS_VOID);

VOS_UINT32 CNAS_EHSM_GetCurrErrorLogICount(VOS_VOID);

VOS_VOID CNAS_EHSM_AllocErrorLog(VOS_VOID);

VOS_VOID CNAS_EHSM_RecodeErrorLogInfo(
    VOS_UINT32                          ulAttachFlag,
    VOS_UINT32                          ulPdnOption,
    VOS_UINT32                          ulBitCid,
    VOS_UINT32                          ulEpsbId,
    CNAS_EHSM_ERROR_CODE_ENUM_UINT8     enErrorCode
);

VOS_VOID CNAS_EHSM_SetHandOverFailFlag(
    VOS_UINT8                           ucHandoverFail
);

VOS_UINT8 CNAS_EHSM_GetHandOverFailFlag(VOS_VOID);



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

#endif /* end of CnasEhsmCtx.h */

