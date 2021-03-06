

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include  "CnasHsdFsmInterSys.h"
#include  "CnasHsdFsmInterSysTbl.h"
#include  "CnasHsdCtx.h"
#include  "CnasHsdComFunc.h"
#include  "CnasPrlParse.h"
#include  "cas_hrpd_overheadmsg_nas_pif.h"
#include  "CnasHsdSndHsm.h"
#include  "CnasHsdSndMscc.h"
#include  "CnasHsdSndInternalMsg.h"
#include  "CnasHsdSysAcqStrategy.h"
#include  "CnasHsdSndCas.h"
#include  "CnasHsdAvoidStrategy.h"


#ifdef  __cplusplus
#if  __cplusplus
extern "C"{
#endif
#endif

#define THIS_FILE_ID                    PS_FILE_ID_CNAS_HSD_FSM_INTER_SYS_C

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

/*****************************************************************************
  2 全局变量定义
*****************************************************************************/

/*****************************************************************************
  3 函数定义
*****************************************************************************/
/*lint -save -e958*/

VOS_UINT32 CNAS_HSD_RcvHsdIratFromLteNtf_InterSys_Init(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 保存入口消息 */
    CNAS_HSD_SaveCurEntryMsg(ulEventType, pstMsg);

    /* 迁移到 CNAS_HSD_INTER_SYS_STA_WAIT_OHM_IND状态, 并启动保护定时器TI_CNAS_HSD_IRAT_TO_HRPD_WAIT_CAS_OHM_IND */
    CNAS_HSD_SetCurrFsmState(CNAS_HSD_INTER_SYS_STA_WAIT_OHM_IND);

    CNAS_HSD_StartTimer(TI_CNAS_HSD_WAIT_CAS_OHM_IND, TI_CNAS_HSD_WAIT_CAS_OHM_IND_LEN);

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasOhmInd_InterSys_WaitCasOhmInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    CNAS_PRL_HRPD_SYSTEM_STRU                              *pstHrpdSys;
    CAS_CNAS_HRPD_OVERHEAD_MSG_IND_STRU                    *pstCasOhmMsg;

    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_OHM_IND);

    pstCasOhmMsg = (CAS_CNAS_HRPD_OVERHEAD_MSG_IND_STRU *)pstMsg;

    pstHrpdSys   = CNAS_HSD_GetCasOhmHrpdSysAddr();

    pstHrpdSys->stFreq.enBandClass = pstCasOhmMsg->usBandClass;
    pstHrpdSys->stFreq.usChannel   = pstCasOhmMsg->usFreq;
    pstHrpdSys->ucSubnetMask       = pstCasOhmMsg->ucSubNetMask;
    NAS_MEM_CPY_S(pstHrpdSys->aucSubnet, CNAS_PRL_BYTES_IN_SUBNET, pstCasOhmMsg->aucSectorId, CNAS_PRL_BYTES_IN_SUBNET);

    /* 异系统切换失败 */
    if (CNAS_HSD_ASSN_SUCC != CNAS_HSD_CheckHrpdSysAssnWith1X(pstHrpdSys))
    {
        CNAS_HSD_SndInterSysRslt(VOS_RATMODE_HRPD, VOS_FALSE, CAS_CNAS_HRPD_NETWORK_LOST_REASON_ENUM_BUTT);
    }
    else
    {
        /* 记录属于大陆和澳门的频点 */
        CNAS_HSD_RecordHrpdCustomChannelsProc(pstCasOhmMsg);

        /* avoid模块处理 */
        CNAS_HSD_ProcAvoidEventInSubnetIdChange(pstHrpdSys);

        /* 更新history list */
        CNAS_HSD_UpdateHistorySysList(pstHrpdSys);
        CNAS_HSD_UpdateSpmSysList(&pstCasOhmMsg->stSpmChannel);

        /* 更新Hrpd驻留信息 */
        CNAS_HSD_UpdateHrpdSysInfo(pstHrpdSys);

        /* 将注留的网络保存到MRU */
        CNAS_HSD_UpdateMru0(pstHrpdSys);

        /* HSD收到CAS的overhead消息时，要给HSM转发overhead消息 */
        CNAS_HSD_SndHsmOverheadMsgInd(pstCasOhmMsg);

        CNAS_HSD_SndInterSysRslt(VOS_RATMODE_HRPD, VOS_TRUE, CAS_CNAS_HRPD_NETWORK_LOST_REASON_ENUM_BUTT);
    }

    /* 异系统切换到HRPD时，也需要给MSCC转发ohm消息*/
    CNAS_HSD_SndMsccOverheadMsgInd(pstCasOhmMsg,pstHrpdSys);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvTiWaitCasOhmIndExpired_InterSys_WaitCasOhmInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{

    /* 将层二运行结果通知层一，层一收到此消息后进行层一状态的迁移 */
    CNAS_HSD_SndInterSysRslt(VOS_RATMODE_HRPD, VOS_FALSE, CAS_CNAS_HRPD_NETWORK_LOST_REASON_ENUM_BUTT);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccPowerSaveReq_InterSys_WaitCasOhmInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_OHM_IND);

    /* 缓存power save请求 */
    CNAS_HSD_SaveCacheMsg(ulEventType, pstMsg);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccPowerOffReq_InterSys_WaitCasOhmInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_OHM_IND);

    /* 清空缓存 */
    CNAS_HSD_InitCacheMsgQueue(&(CNAS_HSD_GetHsdCtxAddr()->stCacheMsgQueue), CNAS_HSD_INIT_CTX_POWEROFF);

    /* 缓存关机请求 */
    CNAS_HSD_SaveCacheMsg(ulEventType, pstMsg);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccDataCallReq_InterSys_WaitCasOhmInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 之前已经通知MSCC有服务 */
    CNAS_HSD_SndMsccDataCallRedialSysAcqCnf(NAS_MSCC_PIF_ACQUIRED_RESULT_SUCC);

    return VOS_TRUE;
}



VOS_UINT32 CNAS_HSD_RcvCasSuspendInd_InterSys_Init(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 保存入口消息 */
    CNAS_HSD_SaveCurEntryMsg(ulEventType, pstMsg);

    /* 迁移到 CNAS_HSD_INTER_SYS_STA_WAIT_OHM_IND状态, 并启动保护定时器TI_CNAS_HSD_IRAT_TO_HRPD_WAIT_CAS_OHM_IND */
    CNAS_HSD_SetCurrFsmState(CNAS_HSD_INTER_SYS_STA_WAIT_IRAT_OR_RESUME_IND);

    CNAS_HSD_StartTimer(TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND, TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND_LEN);

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasIratToLte_InterSys_WaitIratOrResume(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND);

    CNAS_HSD_SndHsmIratToLteInd();

    CNAS_HSD_SndMsccInterSysEndInd(VOS_RATMODE_LTE);

    /* 将层二运行结果通知层一，层一收到此消息后进行层一状态的迁移 */
    CNAS_HSD_SndInterSysRslt(VOS_RATMODE_LTE, VOS_TRUE, CAS_CNAS_HRPD_NETWORK_LOST_REASON_ENUM_BUTT);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasResumeInd_InterSys_WaitIratOrResume(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND);

    CNAS_HSD_SndHsmResumeInd();

    CNAS_HSD_SndMsccInterSysEndInd(VOS_RATMODE_HRPD);

    CNAS_HSD_SndCasResumeRsp();

    /* 判断是否在打断流程中 */
    if (VOS_TRUE == CNAS_HSD_GetAbortFlg_InterSys())
    {
        /* 退出层二状态机 */
        CNAS_HSD_QuitFsmL2();

        return VOS_TRUE;
    }

    /* 迁移到 CNAS_HSD_INTER_SYS_STA_WAIT_OHM_IND状态, 并启动保护定时器TI_CNAS_HSD_IRAT_TO_HRPD_WAIT_CAS_OHM_IND */
    CNAS_HSD_SetCurrFsmState(CNAS_HSD_INTER_SYS_STA_WAIT_OHM_IND);

    CNAS_HSD_StartTimer(TI_CNAS_HSD_WAIT_CAS_OHM_IND, TI_CNAS_HSD_WAIT_CAS_OHM_IND_LEN);

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvTiWaitIratOrResumeExpired_InterSys_WaitIratOrResume(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 此异常流程不用再关心是否有打断标志，直接复位 */

    /* 重选到LTE时，既没有收到IRAT_TO_LTE也没收到RESUME_IND,此异常情况下调用底软复位 */
    CNAS_REBOOT_INFO_STRU               stCnasRebootInfo = {0};

    /* 复位底层 */
    NAS_MEM_SET_S(&stCnasRebootInfo, sizeof(CNAS_REBOOT_INFO_STRU), 0x0, sizeof(CNAS_REBOOT_INFO_STRU));
    stCnasRebootInfo.enRebootScene = CNAS_REBOOT_SCENE_TI_HSD_WAIT_CAS_SUSPEND_CNF_EXPIRED;
    stCnasRebootInfo.ulPid         = UEPS_PID_HSD;
    stCnasRebootInfo.ulFsmId       = CNAS_HSD_GetCurrFsmId();
    stCnasRebootInfo.ulFsmState    = CNAS_HSD_GetFsmTopState();

    /* 复位后直接退出 */
    CNAS_SoftReboot(stCnasRebootInfo);

    /* 退出层二状态机*/
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccPowerSaveReq_InterSys_WaitIratOrResume(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    if (VOS_TRUE == CNAS_HSD_SetAbortFlg_InterSys(VOS_TRUE, CNAS_HSD_ABORT_REASON_POWER_SAVE))
    {
        /* 停止保护定时器 */
        CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND);

        /* 缓存POWER SAVE请求 */
        CNAS_HSD_SaveCacheMsg(ulEventType, pstMsg);

        /* 通知接入层终止切换流程 */
        CNAS_HSD_SndCasSuspendRelReq();

        /* 迁移到 CNAS_HSD_INTER_SYS_STA_WAIT_OHM_IND状态, 并启动保护定时器TI_CNAS_HSD_IRAT_TO_HRPD_WAIT_CAS_OHM_IND */
        CNAS_HSD_SetCurrFsmState(CNAS_HSD_INTER_SYS_STA_WAIT_SUSPEND_REL_CNF);

        CNAS_HSD_StartTimer(TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF, TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF_LEN);
    }

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccPowerOffReq_InterSys_WaitIratOrResume(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    if (VOS_TRUE == CNAS_HSD_SetAbortFlg_InterSys(VOS_TRUE, CNAS_HSD_ABORT_REASON_POWER_OFF))
    {
        /* 停止保护定时器 */
        CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND);

        /* 缓存POWER OFF请求 */
        CNAS_HSD_SaveCacheMsg(ulEventType, pstMsg);

        /* 通知接入层终止切换流程 */
        CNAS_HSD_SndCasSuspendRelReq();

        /* 迁移到 CNAS_HSD_INTER_SYS_STA_WAIT_OHM_IND状态, 并启动保护定时器TI_CNAS_HSD_IRAT_TO_HRPD_WAIT_CAS_OHM_IND */
        CNAS_HSD_SetCurrFsmState(CNAS_HSD_INTER_SYS_STA_WAIT_SUSPEND_REL_CNF);

        CNAS_HSD_StartTimer(TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF, TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF_LEN);
    }

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccDataCallReq_InterSys_WaitIratOrResume(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* HRPD已经被挂起，不能提供正常服务 */
    CNAS_HSD_SndMsccDataCallRedialSysAcqCnf(NAS_MSCC_PIF_ACQUIRED_RESULT_FAIL);

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasNetworkLost_InterSys_WaitCasOhmInd(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    CAS_CNAS_HRPD_NETWORK_LOST_IND_STRU                    *pstCasNetworkLostMsg;
    CNAS_HSD_REDIRECTION_STRU                              *pstRedirection;

    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_OHM_IND);

    pstCasNetworkLostMsg = (CAS_CNAS_HRPD_NETWORK_LOST_IND_STRU*)pstMsg;

    pstRedirection = CNAS_HSD_GetRedirectionFreqAddr();

    if (CAS_CNAS_HRPD_NETWORK_LOST_REDIRECT == pstCasNetworkLostMsg->enNetworkLostReason)
    {
        pstRedirection->ucChanNum = pstCasNetworkLostMsg->ucChanNum;

        if (0 != pstRedirection->ucChanNum)
        {
            NAS_MEM_CPY_S(pstRedirection->aulChannel,
                          sizeof(CAS_CNAS_HRPD_DERECTION_CHANNEL_STRU) * CAS_CNAS_HRPD_MAX_REDIRECT_CH_NUM,
                          pstCasNetworkLostMsg->aulChannel,
                          sizeof(CAS_CNAS_HRPD_DERECTION_CHANNEL_STRU) * pstCasNetworkLostMsg->ucChanNum);

            /* 打印收到的频点信息 */
            CNAS_HSD_LogRedirectionFreqList(pstRedirection);
        }
    }

    CNAS_HSD_SndInterSysRslt(VOS_RATMODE_HRPD,
                             VOS_FALSE,
                             pstCasNetworkLostMsg->enNetworkLostReason);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasSuspendRelCnf_InterSys_WaitSuspendRelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF);

    CNAS_HSD_SndHsmResumeInd();

    CNAS_HSD_SndMsccInterSysEndInd(VOS_RATMODE_HRPD);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasIratToLte_InterSys_WaitSuspendRelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF);

    CNAS_HSD_SndHsmIratToLteInd();

    CNAS_HSD_SndMsccInterSysEndInd(VOS_RATMODE_LTE);

    /* 将层二运行结果通知层一，层一收到此消息后进行层一状态的迁移 */
    CNAS_HSD_SndInterSysRslt(VOS_RATMODE_LTE, VOS_TRUE, CAS_CNAS_HRPD_NETWORK_LOST_REASON_ENUM_BUTT);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasResumeInd_InterSys_WaitSuspendRelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    CNAS_HSD_SndHsmResumeInd();

    CNAS_HSD_SndCasResumeRsp();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvTiWaitSuspendRelCnfExpired_InterSys_WaitSuspendRelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    CNAS_HSD_SndHsmResumeInd();

    CNAS_HSD_SndMsccInterSysEndInd(VOS_RATMODE_HRPD);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccPowerOffReq_InterSys_WaitSuspendRelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    if (VOS_TRUE == CNAS_HSD_SetAbortFlg_InterSys(VOS_TRUE, CNAS_HSD_ABORT_REASON_POWER_OFF))
    {
        /* 清空缓存 */
        CNAS_HSD_InitCacheMsgQueue(&(CNAS_HSD_GetHsdCtxAddr()->stCacheMsgQueue), CNAS_HSD_INIT_CTX_POWEROFF);

        /* 缓存关机请求 */
        CNAS_HSD_SaveCacheMsg(ulEventType, pstMsg);
    }

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvMsccDataCallReq_InterSys_WaitSuspendRelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* HRPD已经被挂起，不能提供正常服务 */
    CNAS_HSD_SndMsccDataCallRedialSysAcqCnf(NAS_MSCC_PIF_ACQUIRED_RESULT_FAIL);

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasNetworkLost_InterSys_WaitIratOrResume(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    CAS_CNAS_HRPD_NETWORK_LOST_IND_STRU                    *pstCasNetworkLostMsg;
    CNAS_HSD_REDIRECTION_STRU                              *pstRedirection;

    pstCasNetworkLostMsg = (CAS_CNAS_HRPD_NETWORK_LOST_IND_STRU*)pstMsg;

    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_IRAT_OR_RESUME_IND);

    pstRedirection = CNAS_HSD_GetRedirectionFreqAddr();

    if (CAS_CNAS_HRPD_NETWORK_LOST_REDIRECT == pstCasNetworkLostMsg->enNetworkLostReason)
    {
        pstRedirection->ucChanNum = pstCasNetworkLostMsg->ucChanNum;

        if (0 != pstRedirection->ucChanNum)
        {
            NAS_MEM_CPY_S(pstRedirection->aulChannel,
                          sizeof(CAS_CNAS_HRPD_DERECTION_CHANNEL_STRU) * CAS_CNAS_HRPD_MAX_REDIRECT_CH_NUM,
                          pstCasNetworkLostMsg->aulChannel,
                          sizeof(CAS_CNAS_HRPD_DERECTION_CHANNEL_STRU) * pstCasNetworkLostMsg->ucChanNum);

            /* 打印收到的频点信息 */
            CNAS_HSD_LogRedirectionFreqList(pstRedirection);
        }
    }

    CNAS_HSD_SndHsmResumeInd();

    CNAS_HSD_SndMsccInterSysEndInd(VOS_RATMODE_HRPD);

    CNAS_HSD_SndInterSysRslt(VOS_RATMODE_HRPD,
                             VOS_FALSE,
                             pstCasNetworkLostMsg->enNetworkLostReason);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}


VOS_UINT32 CNAS_HSD_RcvCasNetworkLost_InterSys_WaitSuspendRelCnf(
    VOS_UINT32                          ulEventType,
    struct MsgCB                       *pstMsg
)
{
    /* 停止保护定时器 */
    CNAS_HSD_StopTimer(TI_CNAS_HSD_WAIT_CAS_SUSPEND_REL_CNF);

    CNAS_HSD_SndHsmResumeInd();

    CNAS_HSD_SndMsccInterSysEndInd(VOS_RATMODE_HRPD);

    /* 退出层二状态机 */
    CNAS_HSD_QuitFsmL2();

    return VOS_TRUE;
}

/*lint -restore*/
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */



