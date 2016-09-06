

/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include  "CsdDebug.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#if( FEATURE_ON == FEATURE_CSD )

/*****************************************************************************
  2 全局变量定义
*****************************************************************************/
CSD_UL_STATUS_INFO_STRU                 g_stCsdStatusInfo = {0};

/*****************************************************************************
  3 函数实现
*****************************************************************************/

VOS_VOID CSD_ShowULStatus(VOS_VOID)
{
    (VOS_VOID)vos_printf("CSD收到上行数据的个数                             %d\n",g_stCsdStatusInfo.ulULRecvPktNum);
    (VOS_VOID)vos_printf("CSD上行缓存中数据包的个数                         %d\n",g_stCsdStatusInfo.ulULSaveBuffPktNum);
    (VOS_VOID)vos_printf("CSD上行入队失败的次数                             %d\n",g_stCsdStatusInfo.ulULEnQueFail);
    (VOS_VOID)vos_printf("CSD发送上行缓存包数量                             %d\n",g_stCsdStatusInfo.ulULSendPktNum);
    (VOS_VOID)vos_printf("CSD发送上行数据时从队列中获取到空指针包数目       %d\n",g_stCsdStatusInfo.ulULQueNullNum);
    (VOS_VOID)vos_printf("CSD发送上行数据sk_buffer头转换到IMM头失败的包数目 %d\n",g_stCsdStatusInfo.ulULZcToImmFailNum);
    (VOS_VOID)vos_printf("CSD发送上行数据插入DICC通道失败的包数目           %d\n",g_stCsdStatusInfo.ulULInsertDiccFailNum);
    (VOS_VOID)vos_printf("\r\n");

    return;
}

VOS_VOID CSD_ShowDLStatus(VOS_VOID)
{
    (VOS_VOID)vos_printf("CSD收到下行数据的个数                             %d\n",g_stCsdStatusInfo.ulDLRecvPktNum);
    (VOS_VOID)vos_printf("CSD发送下行缓存包数量                             %d\n",g_stCsdStatusInfo.ulDLSendPktNum);
    (VOS_VOID)vos_printf("CSD下行发送失败包的数目                           %d\n",g_stCsdStatusInfo.ulDLSendFailNum);
    (VOS_VOID)vos_printf("\r\n");

    return;
}

VOS_VOID CSD_Help(VOS_VOID)
{
    (VOS_VOID)vos_printf("********************CSD软调信息************************\n");
    (VOS_VOID)vos_printf("CSD_ShowULStatus                         显示CSD上行统计信息\n");
    (VOS_VOID)vos_printf("CSD_ShowDLStatus                         显示CSD下行统计信息\n");

    return;
}









#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
