
#ifndef __SLEEPFLOW_H__
#define __SLEEPFLOW_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "mdrv.h"
#include "sleepsleep.h"
#include "phyoaminterface.h"
#include "OmApi.h"
#include "oam_cphy_interface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define BBP_AWAKE_BIT                           0x01

#define WSLEEP_32K_TO_64M_TYPE_BIT              0       /*DRX���Ѻ�ʱ���л���61.44M�ж�*/
#define WSLEEP_64M_TO_32K_TYPE_BIT              1       /*sleep*/

#define BBP_DRX_INT_SLICE_COUNT                 800       /*BBP DRX INT SLICE DELAY COUNT*/

#define SLEEP_SLOT_LEN                          15      /*Wÿ֡����15��SLOT*/
#define SLEEP_SFN_CYCLE_LEN                     (4096*SLEEP_SLOT_LEN) /*SFN��ΧΪ12bit��ÿ���ֻ�4096*/

#define SLEEP_WAKE_DELAY                        2       /*�����ӳٷ�ֹ����ִ�������������Ѿ�����*/
#define SLEEP_WAKE_INTERVAL                     30      /*ǿ�ƻ���ʱ������������ʱ�̼������Сֵ*/
#define SLEEP_WAKE_BASE_FRM_PROTECT_CHIP        (38200) /* �ھ��Լ�ʱ���Ⱥ��ж�ʱ�ܿ�֡ͷǰ��CHIP */
#define SLEEP_WAKE_BASE_FRM_PROTECT_VALUE       (500)
#define SLEEP_WAKE_BBP_POS_PROTECT_SLICE        (330)   /* BBP�������̳�ʱ����,10ms */

/* GU��֧��ģʽ��BUTTֵ */
#define SLEEP_GU_MODE_TYPE_BUTT                 (VOS_RATMODE_BUTT)

/* C��֧��ģʽ��BUTTֵ */
#define SLEEP_C_MODE_TYPE_BUTT                  (VOS_RATMODE_BUTT)

#define BBP_ERROR_VALUE                         (0xDEADBEEF)

#define SLEEP_TRACK_RECORD_NUM                  (100)

#define SLEEP_INFO_RESET_ENABLE                 (0x5A5A5A5A)

#define SLEEP_BBP_ERROR_TIMEOUT                 (30000)

#define SLEEP_IPC_TIMEOUT                       (2)   /* 20ms��ʱ */

#define SLEEP_SLAVE_MSG_TRACK_NUM               (20)

#define SLEEP_NOTIFY_MSG_TRACK_NUM              (20)

#define SLEEP_IPC_INT_DELAY_SLICE               (7)

#define SLEEP_DEVICE_POWUP(enModemId, enMode, enCommMode, enChannel) \
    { \
        mdrv_pm_pwrup((PWC_COMM_MODE_E)enMode, enCommMode, (PWC_COMM_MODEM_E)enModemId, (PWC_COMM_CHANNEL_E)enChannel); \
        if ( VOS_NULL_PTR != g_pstSleepDeviceState ) \
        { \
            g_pstSleepDeviceState->aulDevicePwState[enMode][enCommMode][enChannel]  = PWRCTRL_COMM_ON; \
            g_pstSleepDeviceState->aulDeviceUpSlice[enMode][enCommMode][enChannel]  = OM_GetSlice(); \
        } \
        \
    } \

#define SLEEP_DEVICE_POWDOWN(enModemId, enMode, enCommMode, enChannel) \
    { \
        mdrv_pm_pwrdown((PWC_COMM_MODE_E)enMode, enCommMode, (PWC_COMM_MODEM_E)enModemId, (PWC_COMM_CHANNEL_E)enChannel); \
        if ( VOS_NULL_PTR != g_pstSleepDeviceState ) \
        { \
            g_pstSleepDeviceState->aulDevicePwState[enMode][enCommMode][enChannel]   = PWRCTRL_COMM_OFF; \
            g_pstSleepDeviceState->aulDeviceDownSlice[enMode][enCommMode][enChannel] = OM_GetSlice(); \
        } \
        \
    } \

#define SLEEP_DEVICEPLL_POWUP(enModemId, enMode, enCommMode, enChannel) \
    { \
        mdrv_pm_enable_pllclk((PWC_COMM_MODE_E)enMode, enCommMode, (PWC_COMM_MODEM_E)enModemId, (PWC_COMM_CHANNEL_E)enChannel); \
        if ( VOS_NULL_PTR != g_pstSleepDeviceState ) \
        { \
            g_pstSleepDeviceState->aulPllPwState[enMode][enCommMode][enChannel]  = PWRCTRL_COMM_ON; \
            g_pstSleepDeviceState->aulPLLUpSlice[enMode][enCommMode][enChannel]  = OM_GetSlice(); \
        } \
        \
    } \


#define SLEEP_DEVICEPLL_POWDOWN(enModemId, enMode, enCommMode, enChannel) \
    { \
        mdrv_pm_disable_pllclk((PWC_COMM_MODE_E)enMode, enCommMode, (PWC_COMM_MODEM_E)enModemId, (PWC_COMM_CHANNEL_E)enChannel); \
        if ( VOS_NULL_PTR != g_pstSleepDeviceState ) \
        { \
            g_pstSleepDeviceState->aulPllPwState[enMode][enCommMode][enChannel]     = PWRCTRL_COMM_OFF; \
            g_pstSleepDeviceState->aulPLLDownSlice[enMode][enCommMode][enChannel]   = OM_GetSlice(); \
        } \
        \
    } \

/* ͨ������ */
#define SLEEP_ABB_CHAN(enMode)          (g_stChannelModeProfile.astPara[g_stChannelModeProfileId.uwProfileId].stModeBasicPara[enMode].uhwABBSwitch)
#define SLEEP_RF_CHAN(enMode)           (g_stChannelModeProfile.astPara[g_stChannelModeProfileId.uwProfileId].stModeBasicPara[enMode].uhwRFSwitch)
#define SLEEP_TCXO_CHAN(enMode)         (g_stChannelModeProfile.astPara[g_stChannelModeProfileId.uwProfileId].stModeBasicPara[enMode].uhwTCXOSwitch)
#if (FEATURE_ON == FEATURE_MODE_FEM_CHAN_EXT)
#define SLEEP_RFCLK_CHAN(enMode)        (g_stChannelModeProfile.astPara[g_stChannelModeProfileId.uwProfileId].stModeBasicPara[enMode].uhwRfClk)
#endif

#define SLEEP_DEBUG

#ifdef SLEEP_DEBUG

#define SLEEP_ISR_RECORD(ulMsgId, enMode) \
    if (VOS_NULL_PTR != g_pstSleepTrackRecord) \
    { \
        g_pstSleepTrackRecord->astIsrRecord[g_pstSleepTrackRecord->ulIsrIndex].usMsgId    = (VOS_UINT16)ulMsgId; \
        g_pstSleepTrackRecord->astIsrRecord[g_pstSleepTrackRecord->ulIsrIndex].usModeType = (VOS_UINT16)enMode; \
        g_pstSleepTrackRecord->astIsrRecord[g_pstSleepTrackRecord->ulIsrIndex].ulSlice    = OM_GetSlice(); \
        \
        g_pstSleepTrackRecord->ulIsrIndex++; \
        /* �ﵽĩβ��Ҫ��ת*/ \
        if (SLEEP_TRACK_RECORD_NUM == g_pstSleepTrackRecord->ulIsrIndex) \
        { \
            g_pstSleepTrackRecord->ulIsrIndex = 0; \
        } \
    } \

#define SLEEP_MSG_RECORD(ulMsgId, enMode, StartSlice) \
    if (VOS_NULL_PTR != g_pstSleepTrackRecord) \
    { \
        g_pstSleepTrackRecord->astMsgRecord[g_pstSleepTrackRecord->ulMsgIndex].usMsgId      = (VOS_UINT16)ulMsgId; \
        g_pstSleepTrackRecord->astMsgRecord[g_pstSleepTrackRecord->ulMsgIndex].usModeType   = (VOS_UINT16)enMode; \
        g_pstSleepTrackRecord->astMsgRecord[g_pstSleepTrackRecord->ulMsgIndex].ulStartSlice = StartSlice; \
        g_pstSleepTrackRecord->astMsgRecord[g_pstSleepTrackRecord->ulMsgIndex].ulEndSlice   = OM_GetSlice(); \
        \
        g_pstSleepTrackRecord->ulMsgIndex++; \
        /* �ﵽĩβ��Ҫ��ת*/ \
        if (SLEEP_TRACK_RECORD_NUM == g_pstSleepTrackRecord->ulMsgIndex) \
        { \
            g_pstSleepTrackRecord->ulMsgIndex = 0; \
        } \
    } \

#define SLEEP_NOR_STATE_TRACK(enMode, enType) \
    if (VOS_NULL_PTR != g_pstSleepNormalState) \
    { \
        g_pstSleepNormalState->astRecordItem[enMode][enType].aulSlice[g_pstSleepNormalState->astRecordItem[enMode][enType].ulCount%SLEEP_RECORD_TRACK_NUM] = OM_GetSlice(); \
        g_pstSleepNormalState->astRecordItem[enMode][enType].ulCount++; \
    } \

#define SLEEP_BBP_SWITCH_INT_DELAY_RECORD(ulDeltaSlice) \
    if (VOS_NULL_PTR != g_pstSleepDeviceState) \
    { \
        g_pstSleepDeviceState->stDelayRecord.astRecord[g_pstSleepDeviceState->stDelayRecord.ulCount].ulDeltaSlice = ulDeltaSlice; \
        g_pstSleepDeviceState->stDelayRecord.astRecord[g_pstSleepDeviceState->stDelayRecord.ulCount].ulSlice      = OM_GetSlice(); \
        \
        g_pstSleepDeviceState->stDelayRecord.ulCount++; \
        /* �ﵽĩβ��Ҫ��ת*/ \
        if (SLEEP_BBP_SWITCH_INT_DELAY_RECORD_MAX == g_pstSleepDeviceState->stDelayRecord.ulCount) \
        { \
            g_pstSleepDeviceState->stDelayRecord.ulCount = 0; \
        } \
    } \


#define SLEEP_WAKE_SLICE_RECORD(ulIndex) \
    /*lint -e774 -e506*/ \
    if ((VOS_NULL_PTR != g_pstSleepWakeSliceAddr) && (ulIndex < 8)) \
    /*lint +e774 +e506*/ \
    { \
        g_pstSleepWakeSliceAddr->auwCommSRStamp[ulIndex] = OM_GetSlice(); \
    } \

#define SLEEP_BBE16_NOR_STATE_TRACK(enMode, enType) \
    if (VOS_NULL_PTR != g_pstSleepBBE16NormalState) \
    { \
        g_pstSleepBBE16NormalState->astRecordItem[enType].aulSlice[g_pstSleepBBE16NormalState->astRecordItem[enType].ulCount % SLEEP_BBE16_RECORD_TRACK_NUM] = VOS_GetSlice(); \
        g_pstSleepBBE16NormalState->astRecordItem[enType].ulCount++; \
    } \

#define SLEEP_BBE16_WAKE_SLICE_RECORD(ulIndex) \
    /*lint -e774 -e506*/ \
    if ((VOS_NULL_PTR != g_pstSleepWakeSliceAddr) && (ulIndex < 8)) \
    /*lint +e774 +e506*/ \
    { \
        g_pstSleepWakeSliceAddr->auwCprocSRStamp[ulIndex] = OM_GetSlice(); \
    } \

#else

#define SLEEP_ISR_RECORD(ulMsgId, enMode)
#define SLEEP_MSG_RECORD(ulMsgId, enMode, ulStartSlice) (ulStartSlice = ulStartSlice) /* for pclint
 */
#define SLEEP_NOR_STATE_TRACK(enMode, enType)

#define SLEEP_BBP_SWITCH_INT_DELAY_RECORD(ulDeltaSlice)

#define SLEEP_BBE16_NOR_STATE_TRACK(enMode, enType)

#endif

#define HPA_UART_PRINT(data)

/* ע�ᵽSLEEPģ���PID������ */
#define SLEEP_NOTIFY_STATE_REG_PID_MAX              (16)

/* ��ЧPID���� */
#define SLEEP_INVALID_PID                           (0xFFFFFFFF)

/* ��Ȼ���������У�Ԥ��ʱ���л��жϺ����ȴ��೤ʱ���ٲ���ʱ���л��жϣ���ǰ��Ϊ4096 */
#define SLEEP_BBP_HANDSHAKE_MAX_DELAY               (4096)

/* BBP���ּĴ���(bit 0��Ч) */
#define BBP_HANDSHAKE_BIT                           (0x01)

/* ͳ��BBP�����жϷ����ӳٵĿ�ά�ɲ������У����ļ�¼���� */
#define SLEEP_BBP_SWITCH_INT_DELAY_RECORD_MAX       (100)


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


enum SLEEP_MSG_ENUM
{
    BBP_SLEEP_32K_CLOCK_SWITCH_IND          = 0x0004,
    BBP_SLEEP_WAKE_IND                      = 0x0005,
    BBP_SLEEP_NORMAL_CLOCK_SWITCH_IND       = 0x0006,
    SLEEP_WAKE_MASTER_GU_IND                = 0x0007,
    SLEEP_WAKE_SLAVE_GU_IND                 = 0x0008,
    BBE16_SLEEP_SLEEP_IND                   = 0x1001,
    BBE16_SLEEP_AWAKE_IND                   = 0x1002,
    BBE16_SLEEP_RESUME_IND                  = 0x1003,
    BBE16_SLEEP_MASTER_WAKE_IND             = 0x1004,
    BBE16_SLEEP_SLAVE_WAKE_IND              = 0x1005,
    BBE16_SLEEP_TRACE_STACK_IND             = 0x1011,
    SLEEP_MSG_BUTT                          = 0xffff
};


enum SLEEP_NORMAL_STATE_TRACK_ENUM
{
    SLEEP_MASTER_BBP_32K = 0,
    SLEEP_MASTER_PHY_HALT,
    SLEEP_MASTER_LP,
    SLEEP_MASTER_BBP_WAKE,
    SLEEP_MASTER_ACTIVATE_START,
    SLEEP_MASTER_ACTIVATE_END,
    SLEEP_MASTER_BBP_RESUME_START,
    SLEEP_MASTER_BBP_RESUME_END,
    SLEEP_MASTER_FORCE_WAKE,
    SLEEP_MASTER_BBP_NORMAL,
    SLEEP_MASTER_WAKE_PHY_PRE,
    SLEEP_MASTER_WAKE_PHY,
    SLEEP_SLAVE_PHY_HALT,
    SLEEP_SLAVE_LP,
    SLEEP_SLAVE_FORCE_WAKE,
    SLEEP_NORMAL_BUTT
};


enum SLEEP_CHANNEL_ENUM
{
    SLEEP_CHANNEL_ZERO = 0,
    SLEEP_CHANNEL_ONE,
    SLEEP_CHANNEL_BOTH,
};


enum SLEEP_BBE16_NORMAL_STATE_TRACK_ENUM
{
    /* Main Track*/
    /* Halt */
    SLEEP_BBE16_HALT_INT_TRACE = 0,
    SLEEP_BBE16_HALT_START_TRACE,
    SLEEP_BBE16_HALT_END_TRACE,

    /* Normal Wake */
    SLEEP_BBE16_NORMAL_WAKE_INT_TRACE,
    SLEEP_BBE16_NORMAL_WAKE_START_TRACE,
    SLEEP_BBE16_NORMAL_WAKE_END_TRACE,

    /* Master Force Wake */
    SLEEP_BBE16_MASTER_FORCE_WAKE_REQ_TRACE,
    SLEEP_BBE16_MASTER_FORCE_WAKE_START_TRACE,
    SLEEP_BBE16_MASTER_FORCE_WAKE_END_TRACE,

    /* Slave Force Wake */
    SLEEP_BBE16_SLAVE_FORCE_WAKE_REQ_TRACE,
    SLEEP_BBE16_SLAVE_FORCE_WAKE_START_TRACE,
    SLEEP_BBE16_SLAVE_FORCE_WAKE_END_TRACE,

    /* Resume */
    SLEEP_BBE16_RESUME_INT_TRACE,
    SLEEP_BBE16_RESUME_START_TRACE,
    SLEEP_BBE16_RESUME_END_TRACE,

    /* ACT */
    SLEEP_BBE16_DEACTIVATE_START,
    SLEEP_BBE16_DEACTIVATE_END,
    SLEEP_BBE16_ACTIVATE_START,
    SLEEP_BBE16_ACTIVATE_END,

    /* Assist Track */
    /* Halt */
    SLEEP_BBE16_HALT_INT_TO_MSG_TRACE,
    SLEEP_BBE16_HALT_SMP_TRACE,
    SLEEP_BBE16_HALT_WAKE_START_TRACE,
    SLEEP_BBE16_HALT_WAKE_END_TRACE,
    SLEEP_BBE16_HALT_CPROC_1X_SLEEP_TRACE,
    SLEEP_BBE16_HALT_CPROC_HRPD_SLEEP_TRACE,

    /* Normal Wake */
    SLEEP_BBE16_NORMAL_WAKE_INT_TO_MSG_TRACE,
    SLEEP_BBE16_NORMAL_WAKE_SMP_TRACE,
    SLEEP_BBE16_NORMAL_WAKE_PROC_TRACE,

    /* Master Force Wake */
    SLEEP_BBE16_MASTER_FORCE_WAKE_SMP_TRACE,
    SLEEP_BBE16_MASTER_FORCE_WAKE_PROC_TRACE,

    /* Slave Force Wake */
    SLEEP_BBE16_SLAVE_FORCE_WAKE_SMP_TRACE,
    SLEEP_BBE16_SLAVE_FORCE_WAKE_PROC_TRACE,

    /* Resume */
    SLEEP_BBE16_RESUME_INT_TO_MSG_TRACE,
    SLEEP_BBE16_RESUME_SMP_TRACE,
    SLEEP_BBE16_RESUME_CPROC_1X_WAKEUP_TRACE,
    SLEEP_BBE16_RESUME_CPROC_HRPD_WAKEUP_TRACE,

    /* Abnormal Track */
    SLEEP_BBE16_HALT_INT_NOT_NORMAL_TRACE,
    SLEEP_BBE16_WAKE_INT_NOT_LP_TRACE,
    SLEEP_BBE16_RESUME_INT_NOT_TEMP_TRACE,
    SLEEP_BBE16_MASTER_FORCE_WAKE_MODE_ERR_TRACE,
    SLEEP_BBE16_MBX_OTHER_CHANNEL_TRACE,

    SLEEP_BBE16_NORMAL_BUTT
};

/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

/*****************************************************************************
 �ṹ��    : SLEEP_MODE_INFO_STRU
 �ṹ˵��  : GUģ��ǰϵͳ״̬
*****************************************************************************/
typedef struct
{
    SLEEP_SYSTEM_STATE_ENUM_UINT32      enSystemState;
    UPHY_OAM_WAKE_TYPE_ENUM_UINT32      enWakeType;
}SLEEP_MODE_INFO_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_BBE16_MODE_INFO_STRU
 �ṹ˵��  : Xģ��ǰϵͳ״̬
*****************************************************************************/
typedef struct
{
    SLEEP_BBE16_SYSTEM_STATE_ENUM_UINT32    enSystemState;
    CPHY_SLEEP_TYPE_ENUM_UINT32             enCdmaSleepType;
}SLEEP_BBE16_MODE_INFO_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_MSG_FUN_STRU
 �ṹ˵��  : ָʾ����Ϣ�Ĵ�������
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulMsgId;                /* ��ϢID */
    Msg_Fun_Type                        pMsgFun;                /* ��Ϣ�������� */
}SLEEP_MSG_FUN_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_INFO_STATE_STRU
 �ṹ˵��  : GUģ��λ��Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                      ulAwakeIsrSlice;
    VOS_UINT32                      ulAwakeStartSlice;
    VOS_UINT32                      ulAwakeEndSlice;
    VOS_UINT32                      ulSwitchIsrSlice;
    VOS_UINT32                      ulSwitchTaskSlice;
    VOS_UINT32                      ulWarnEventFlag;
    VOS_UINT32                      ulWarnEventCount;
    VOS_UINT32                      ulSwitchDelayType1Count;
    VOS_UINT32                      ulSwitchDelayType2Count;
    VOS_UINT32                      ulSwitchDelayType3Count;
    VOS_UINT32                      ulSwitchDelayType4Count;
    VOS_UINT32                      ulSwitchDelayType5Count;
    VOS_UINT32                      ulEndFlag;
}SLEEP_INFO_STATE_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_ISR_MSG_STRU
 �ṹ˵��  : �ж���Ϣ��
*****************************************************************************/
typedef struct
{
   VOS_MSG_HEADER
   VOS_UINT16                           usMsgId;                /* ��ϢID */
   VOS_UINT16                           usReserved;             /* ���� */
   SLEEP_MODE_ENUM_UINT32               enRatMode;              /* �ϱ�ģʽ */
   VOS_UINT32                           ulSlice;                /* �жϽ���ʱ�� */
}SLEEP_ISR_MSG_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_RECORD_ITEM_STRU
 �ṹ˵��  : ���̼�¼��Ԫ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usMsgId;                /* ��ϢID */
    VOS_UINT16                          usModeType;             /* ģʽ���� */
    VOS_UINT32                          ulSlice;                /* Sliceֵ */
}SLEEP_RECORD_ITEM_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_RECORD_ITEM_EX_STRU
 �ṹ˵��  : ���̼�¼��չ��Ԫ
*****************************************************************************/
typedef struct
{
    VOS_UINT16                          usMsgId;                /* ��ϢID */
    VOS_UINT16                          usModeType;             /* ģʽ���� */
    VOS_UINT32                          ulStartSlice;           /* ��ʼSliceֵ */
    VOS_UINT32                          ulEndSlice;             /* ����Sliceֵ */
}SLEEP_RECORD_ITEM_EX_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_TRACK_RECORD_STRU
 �ṹ˵��  : ����SLEEP�жϺ���Ϣ���̼�¼
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulIsrIndex;             /* �жϼ�¼���� */
    VOS_UINT32                          ulMsgIndex;             /* ��Ϣ��¼���� */
    SLEEP_RECORD_ITEM_STRU              astIsrRecord[SLEEP_TRACK_RECORD_NUM]; /* �ж����̼�¼ */
    SLEEP_RECORD_ITEM_EX_STRU           astMsgRecord[SLEEP_TRACK_RECORD_NUM]; /* ��Ϣ���̼�¼ */
}SLEEP_TRACK_RECORD_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_NORMAL_STATE_RECORD_STRU
 �ṹ˵��  : ����SLEEP����״̬�л�����
*****************************************************************************/
typedef struct
{
    SLEEP_RECORD_TRACK_STRU   astRecordItem[SLEEP_GU_MODE_TYPE_BUTT][SLEEP_NORMAL_BUTT];
}SLEEP_NORMAL_STATE_RECORD_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_NOTIFY_STATE_REG_PID_STRU
 �ṹ˵��  : GUģʽ�£��ײ�(GAS/GPHY)ע��PID��SLEEP��SLEEP�ڴ�ģ�͹���״̬֪ͨ��ע��PID
*****************************************************************************/
typedef struct
{
    VOS_UINT32                      aulRegPidTbl[SLEEP_NOTIFY_STATE_REG_PID_MAX];
}SLEEP_NOTIFY_STATE_REG_PID_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_BBP_SWITCH_INT_DELAY_RECORD_STRU
 �ṹ˵��  : BBP�����жϷ����ӳ٣���¼slice�����ӳټ���
*****************************************************************************/
typedef struct
{
    VOS_UINT32                      ulDeltaSlice;         /* ��¼�ӳٵ�ʱ�Ӽ���(��λΪ32Kʱ�ӽ���) */
    VOS_UINT32                      ulSlice;              /* ��¼������Sliceֵ */
}SLEEP_BBP_SWITCH_INT_DELAY_RECORD_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_BBP_SWITCH_INT_DELAY_STATISTIC_STRU
 �ṹ˵��  : BBP�����жϷ����ӳ٣����¼��Ӧͳ����Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                              ulCount;        /* ͳ�Ƶ����쳣���� */
    SLEEP_BBP_SWITCH_INT_DELAY_RECORD_STRU                  astRecord[SLEEP_BBP_SWITCH_INT_DELAY_RECORD_MAX];    /* ͳ����Ϣ */
}SLEEP_BBP_SWITCH_INT_DELAY_STATISTIC_STRU;


/*****************************************************************************
 �ṹ��    : SLEEP_DEVICE_STATE
 �ṹ˵��  : GUģ��ǰ����״̬
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                  ulDeviceFlag;
    VOS_UINT32                                  aulDevicePwState[SLEEP_GU_MODE_TYPE_BUTT][PWC_COMM_MODULE_BUTT][PWC_COMM_CHANNEL_BUTT];
    VOS_UINT32                                  aulDeviceUpSlice[SLEEP_GU_MODE_TYPE_BUTT][PWC_COMM_MODULE_BUTT][PWC_COMM_CHANNEL_BUTT];
    VOS_UINT32                                  aulDeviceDownSlice[SLEEP_GU_MODE_TYPE_BUTT][PWC_COMM_MODULE_BUTT][PWC_COMM_CHANNEL_BUTT];
    VOS_UINT32                                  aulPllPwState[SLEEP_GU_MODE_TYPE_BUTT][PWC_COMM_MODULE_BUTT][PWC_COMM_CHANNEL_BUTT];
    VOS_UINT32                                  aulPLLUpSlice[SLEEP_GU_MODE_TYPE_BUTT][PWC_COMM_MODULE_BUTT][PWC_COMM_CHANNEL_BUTT];
    VOS_UINT32                                  aulPLLDownSlice[SLEEP_GU_MODE_TYPE_BUTT][PWC_COMM_MODULE_BUTT][PWC_COMM_CHANNEL_BUTT];
    SLEEP_RECORD_STRU                           astDevicePowerError[SLEEP_GU_MODE_TYPE_BUTT];
    SLEEP_RECORD_STRU                           stDeviceTcxoError;
    SLEEP_BBP_SWITCH_INT_DELAY_STATISTIC_STRU   stDelayRecord;
    SLEEP_RECORD_STRU                           stHandShakeRecord;    /* ��¼�������ּĴ����Ĵ�����Slice */
    VOS_UINT32                                  aulABBState[64];
    VOS_UINT32                                  ulBBPResumeTimeout;
    SLEEP_RECORD_STRU                           stDMACapError;
    VOS_UINT32                                  ulSlaveSEMTakeTimes;
    VOS_UINT32                                  ulSlaveSEMTakeStartSlice;
    VOS_UINT32                                  ulSlaveSEMTakeEndSlice;
    VOS_UINT32                                  ulSlaveSEMGiveTimes;
    VOS_UINT32                                  ulSlaveSEMGiveStartSlice;
    VOS_UINT32                                  ulSlaveSEMGiveEndSlice;
}SLEEP_DEVICE_STATE_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_CDMA_STATE_STRU
 �ṹ˵��  : CDMAģʽ��Ϣ��¼
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                  ulInfoHeadFlag;
    VOS_UINT32                                  ulBBE16PowerState;
}SLEEP_CDMA_STATE_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_SLAVE_MSG_TRACK_STRU
 �ṹ˵��  : ��ģ������Ϣ������Ϣ��¼
*****************************************************************************/
typedef struct
{
    VOS_UINT32              ulMode;
    VOS_UINT32              ulSenderPid;
    VOS_UINT32              ulMsgName;
    VOS_UINT32              ulSlice;
}SLEEP_SLAVE_MSG_TRACK_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_NOTIFY_MSG_TRACK_STRU
 �ṹ˵��  : ��ģ������Ϣ������Ϣ��¼
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulRegPid;
    VOS_RATMODE_ENUM_UINT32             enRatMode;
    SLEEP_SYSTEM_STATE_ENUM_UINT32      enState;
    SLEEP_LOWPOWER_STATE_ENUM_UINT32    enLPState;
    VOS_UINT32                          ulSlice;
}SLEEP_NOTIFY_MSG_TRACK_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_NORMAL_STATE_RECORD_STRU
 �ṹ˵��  : ����CģSLEEP����״̬�л�����
*****************************************************************************/
typedef struct
{
    SLEEP_BBE16_RECORD_TRACK_STRU   astRecordItem[SLEEP_BBE16_NORMAL_BUTT];
}SLEEP_BBE16_NORMAL_STATE_RECORD_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_BBE16_CPROC_CTRL_STRU
 �ṹ˵��  : CPROCע����Ϣ��
*****************************************************************************/
typedef struct
{
    SLEEP_BBE16_CPROC_WAKEUP_FUNC   pfnCprocWakeupProc;
    VOS_VOID                       *pulCprocWakeupPara;
    SLEEP_BBE16_CPROC_SLEEP_FUNC    pfnCprocSleepProc;
    VOS_VOID                       *pulCprocSleepPara;
}SLEEP_BBE16_CPROC_CTRL_STRU;

/*****************************************************************************
 �ṹ��    : SLEEP_BBE16_STATE_TRACK_MSG_STRU
 �ṹ˵��  : Cģ״̬�켣��Ϣ��
*****************************************************************************/
typedef struct
{
   VOS_MSG_HEADER
   VOS_UINT16                           usMsgId;                /* ��ϢID */
   VOS_UINT16                           usReserved;             /* ���� */
   SLEEP_MODE_ENUM_UINT32               enRatMode;              /* �ϱ�ģʽ */
   VOS_UINT32                           ulSlice;                /* �жϽ���ʱ�� */
   VOS_UINT32                           aulRecordInfo[0];
}SLEEP_BBE16_STATE_TRACK_MSG_STRU;
/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/
extern SLEEP_NORMAL_STATE_RECORD_STRU         *g_pstSleepNormalState;

extern SLEEP_TRACK_RECORD_STRU                *g_pstSleepTrackRecord;

extern SLEEP_BBE16_NORMAL_STATE_RECORD_STRU   *g_pstSleepBBE16NormalState;

/*****************************************************************************
  10 ��������
*****************************************************************************/
MODEM_ID_ENUM_UINT16 SLEEP_GetModemId(VOS_VOID);
VOS_VOID SLEEP_EnableDspPll(VOS_VOID);
VOS_VOID SLEEP_ExitLowPower(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_BOOL SLEEP_IsSleep(VOS_VOID);
VOS_VOID Sleep_ActiveDspPll(VOS_VOID);
VOS_VOID SLEEP_NotifySndMsg(VOS_VOID);
VOS_VOID GUSLEEP_MasterAwakeSlave(VOS_VOID);
VOS_VOID SLEEP_32KIsr(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_NormalClockIsr(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_AwakeIsr(SLEEP_MODE_ENUM_UINT32 enMode);

VOS_VOID SLEEP_VoteLock(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_VoteUnlock(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_TimeCal(VOS_VOID);
VOS_VOID SLEEP_ResumeReg(VOS_VOID);
VOS_VOID SLEEP_PowerUp(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_DeactivateHw(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_ActivateHw(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_InfoInd( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_UINT32  SLEEP_ForceWakeProtected(VOS_VOID);
VOS_UINT32  SLEEP_WakePhy(VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode, UPHY_OAM_WAKE_TYPE_ENUM_UINT32 enWakeType);
VOS_VOID    SLEEP_AwakeIsrProc(VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID    SLEEP_SleepIsrProc(VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID    SLEEP_MasterSleepMsgProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_32KClkMsgProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_WakeMasterMsgProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_NormalClkMsgProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_SlaveSleepMsgProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_WakeSlaveGUProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_WakeMasterGUProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_MasterForceWake(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID    SLEEP_SlaveForceWake(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID    SLEEP_HookMsgProc(MsgBlock *pstMsg);
VOS_VOID    SLEEP_AwakeMsgProc(MsgBlock* pstMsg);
VOS_VOID    SLEEP_SleepMsgProc(MsgBlock* pstMsg);
VOS_VOID    SLEEP_Init(VOS_VOID);
VOS_UINT32  WuepsAwakePidInit(enum VOS_INIT_PHASE_DEFINE ip);
VOS_UINT32  WuepsAwakeFidInit(enum VOS_INIT_PHASE_DEFINE ip);
VOS_UINT32  WuepsSleepPidInit(enum VOS_INIT_PHASE_DEFINE ip);
VOS_UINT32  WuepsSleepFidInit(enum VOS_INIT_PHASE_DEFINE ip);
VOS_UINT32  SLEEP_ReadBaseCntChip( VOS_VOID );

VOS_VOID    I1_SLEEP_VoteLock(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID    I1_SLEEP_PowerUp(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID    I2_SLEEP_VoteLock(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID    I2_SLEEP_PowerUp(SLEEP_MODE_ENUM_UINT32 enMode);

VOS_BOOL    SLEEP_IsAwake(SLEEP_MODE_ENUM_UINT32 enMode);

VOS_UINT32  SLEEP_InfoFileName( VOS_CHAR * cFileName );
VOS_UINT32  SLEEP_InfoWriteLog( VOS_UINT32 *pstInfo, VOS_UINT32 uLen );
VOS_VOID    SLEEP_ActivateHWMsgProc(MsgBlock *pstMsg);
VOS_UINT32  SLEEP_GetLogPath(VOS_CHAR *pucBuf, VOS_CHAR *pucOldPath, VOS_CHAR *pucUnitaryPath);

VOS_VOID SLEEP_NotifyStateToRegPid(
    VOS_RATMODE_ENUM_UINT32             enRatMode,
    SLEEP_SYSTEM_STATE_ENUM_UINT32      enState);

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
VOS_VOID SLEEP_BBE16HaltIsr( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16AwakeIsr( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16ResumeIsr( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_TaskDelay( VOS_UINT32 ulSliceDelay );
VOS_VOID SLEEP_BBE16DeactivateHw(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_VOID SLEEP_BBE16ActivateHw(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_UINT32  SLEEP_BBE16GetLowPowerState( SLEEP_MODE_ENUM_UINT32 enMode );
SLEEP_BBE16_SYSTEM_STATE_ENUM_UINT32 SLEEP_BBE16GetTwinState( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16PowerUp( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16ForceWakeProc( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16MasterForceWakeProc(MsgBlock *pstMsg);
VOS_VOID SLEEP_BBE16SlaveForceWakeProc(MsgBlock *pstMsg);
VOS_VOID SLEEP_BBE16MasterForceWake( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16SlaveForceWake( SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16HaltMsgProc( MsgBlock* pstMsg );
VOS_VOID SLEEP_BBE16AwakeMsgProc( MsgBlock* pstMsg );
VOS_VOID SLEEP_BBE16ResumeMsgProc( MsgBlock* pstMsg );
VOS_VOID SLEEP_BBE16HaltIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16AwakeIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16ResumeIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16HaltIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16AwakeIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode );
VOS_VOID SLEEP_BBE16ResumeIsrProc( VOS_UINT32 ulMsgId, SLEEP_MODE_ENUM_UINT32 enMode );

VOS_VOID SLEEP_BBE16MailBoxResumeProc(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_UINT32 SLEEP_BBE16IsMailBoxAllowCBBE16Sleep(SLEEP_MODE_ENUM_UINT32 enMode);
VOS_UINT32 SLEEP_BBE16MailBoxGetDspState(XMBX_RATMODE_ENUM_U32 enMode);
VOS_VOID SLEEP_BBE16MailBoxForceWakeDsp(XMBX_RATMODE_ENUM_U32 enMode);

VOS_VOID SLEEP_ReportEvent(VOS_UINT16 usEventId, SLEEP_MODE_ENUM_UINT32 enMode);

VOS_VOID SLEEP_BBE16DbgInit(VOS_VOID);

#endif

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __SLEEPFLOW_H__ */