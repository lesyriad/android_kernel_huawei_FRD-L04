
/*******************************************************************************
*
*
*                Copyright 2006, Huawei Technologies Co. Ltd.
*                            ALL RIGHTS RESERVED
*
*-------------------------------------------------------------------------------
*
*                              bfd_ext_var.h
*
*  Project Code: VISPV100R007
*   Module Name: BFD EXTERN
*  Date Created: 2008-07-24
*        Author: qinyun
*   Description: BFD EXTERN 全局变量
*
*-------------------------------------------------------------------------------
*  Modification History
*  DATE            NAME                DESCRIPTION    
*  -----------------------------------------------------------------------------
*
*  2008-07-24      qinyun            Create
*******************************************************************************/
#ifndef _BFD_EXT_VAR_H_
#define _BFD_EXT_VAR_H_

#ifdef __cplusplus
extern "C" {
#endif

extern BFD_OSPF_RULE_TABLE_S g_stBfdOspfRuleTable[];

/* BC3D01574 B026 liangjicheng 2009-05-25 会话关联表删除 VRF表替换了 */
/* extern BFD_RELATION_TABLE_S g_stBfdRelationTable[ ];*/

extern ULONG g_ulBFDEXTTotalSession;

extern ULONG g_ulOspfProcType;

extern ULONG g_ulRtmProcType;

extern ULONG g_ulExternBfdInitFlag;

extern ULONG g_ulExternBfd6EnableFlag;

extern ULONG g_ulStaticBfdRelationNum;

extern ULONG g_ulOspfBfdRelationNum[];

extern ULONG g_ulStaticDetectTime;

extern CHAR g_szExtBfdDebugFlage[];

extern  BFD_RM_NOTIFY_HOOK_FUNC g_pfBfdRmNotifyFunc;

extern BFD_RELATION_HASH_S *g_pstBfdVrfRelationTable;
extern BFD_RELATION_HASH_S *g_pstBfd6VrfRelationTable;

extern BFD_RELATION_HASHTABLE_S *g_pstBfdHashTable;
extern ULONG g_ulBfdHashLen;

extern BFD_GET_DYN_SESS_PRO_HOOK_FUNC  g_pstBfdGetProWithRoute;


extern SLL_S  g_BfdGlobalGcList; /*全局的垃圾回收链表*/
extern ULONG g_ulBfdGlobalGcTimerId;

#ifdef __cplusplus
}
#endif

#endif

