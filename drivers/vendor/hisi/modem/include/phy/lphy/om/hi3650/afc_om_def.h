
#ifndef __AFC_OM_DEF_H__
#define __AFC_OM_DEF_H__


#ifdef __cplusplus
#if __cplusplus
    extern "C"{
#endif
#endif /* __cplusplus */

/************************************************************
                     包含其它模块的头文件
************************************************************/
#include "lte_nv_para_define.h"             /**/
/************************************************************
                               宏定义
************************************************************/

#define AFC_MAX_NCELL_PER_FREQ_NUM   (3)
#ifndef LPHY_MAX_RX_ANTENNA_NUM
#define LPHY_MAX_RX_ANTENNA_NUM      (2)
#endif
#define AFC_MAX_RS_WIN_LEN           (130)

#define AFC_DRX_PPM_WINDOW_LEN       (32)         /*DRX 滑动窗PPM样点个数*/
#define AFC_NON_CDRX_PPM_WINDOW_LEN  (64)         /*非DRX 滑动窗PPM样点个数*/

#define AFC_HST_MODE
#define AFC_PDM_WINDOW_LEN           (128)

#define TL_DCXO_POLY_COEF_NUM_SG     (4)          /*TL_DCXO_POLY_COEF_NUM*/

/************************************************************
                             数据结构定义
************************************************************/

/************************************************************
                             接口函数声明
 ************************************************************/


/************************************************************
                           1. REQ命令和对应的数据结构定义
************************************************************/
typedef enum
{
    LPHY_REQ_AFC_REPORT_ENA         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_REQ, 0x0),
    LPHY_REQ_AFC_PD_STATUS_ENA,
    LPHY_REQ_AFC_LOOP_STATE_ENA,
    LPHY_REQ_AFC_FIXED_PDM_ENA,
    LPHY_REQ_AFC_FILTER_STEP_SELECTION_ENA,
    LPHY_REQ_AFC_FIXED_FILTER_STEP_ENA,
    LPHY_REQ_NC_AFC_REPORT_ENA,
    LPHY_REQ_MBMS_STUB_ENA,
    LPHY_REQ_AFC_TEMP_COMP_ENA,
    LPHY_REQ_AFC_HST_ENA,
    LPHY_REQ_AFC_HST_OPEN_ENA,
    LPHY_DT_AFC_REPORT_REQ          = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_REQ, 0x100),
}LPHY_REQ_AFC_ENUM;

typedef enum
{
    AFC_OM_SWITCH_OFF = 0,
    AFC_OM_SWITCH_ON,
}AFC_OM_SWITCH_ENUM;
typedef UINT16 AFC_OM_SWITCH_ENUM_UINT16;

typedef struct
{
   AFC_OM_SWITCH_ENUM_UINT16    enNcAfcReportEn;
}LPHY_REQ_NC_AFC_REPORT_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16      usFixedPDMEn;    /*1 使能固定PDM*/
    UINT16      usFixedPDM;      /*1 固定PDM值*/
}LPHY_REQ_AFC_FIXED_PDM_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16   enAfcMbmsStubEn;
}LPHY_REQ_AFC_MBMS_STUB_ENA_STRU;
/*typedef union
{
    // Define the struct bits
    struct
    {
        UINT32    CpSel               : 1   ; // [0]
        UINT32    DtxcpSel            : 1   ; // [1]
        UINT32    PssSel              : 1   ; // [2]
        UINT32    ForceOL             : 1   ; // [3]
        UINT32    Reserved            : 28  ; //[31..4]
    } bits;

    // Define an unsigned member
    UINT32    ulOLPDSel;

} AFC_OLPD_SEL_UNION;
*/
// Define the struct bits
typedef struct
{
    UINT32    CpSel               : 1   ; // [0]
    UINT32    DtxcpSel            : 1   ; // [1]
    UINT32    PssSel              : 1   ; // [2]
    UINT32    ForceOL             : 1   ; // [3]
    UINT32    Reserved            : 28  ; //[31..4]
} AFC_OLPD_SEL_BITS_STRU;

typedef union
{
    AFC_OLPD_SEL_BITS_STRU  bits;

    // Define an unsigned member
    UINT32    ulOLPDSel;

} AFC_OLPD_SEL_UNION;


typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16      enOLPDSelEn;    /*1 使能外环鉴频模式*/
    AFC_OLPD_SEL_UNION      unOPLDFlag;      /*1 外环鉴频模式*/
}LPHY_REQ_AFC_OLPD_SELECTION_ENA_STRU;

typedef enum
{
    AFC_KLOW_SELECTION  = 0,
	AFC_KHIGH_SELECTION = 1,
}AFC_FILTER_STEP_MODE_ENUM;
typedef UINT16 AFC_FILTER_STEP_MODE_ENUM_UINT16;
typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16             enFilterStepSelEn;    /*1 使能选择滤波步长模式*/
    AFC_FILTER_STEP_MODE_ENUM_UINT16      enFilterStepMode;      /*1 滤波步长模式*/
}LPHY_REQ_AFC_FILTER_STEP_SELECTION_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16      enFixedFilterStepEn;    /*1 使能固定滤波步长*/
    UINT16                         usFixedFilterStep;      /*1 固定滤波步长值*/
}LPHY_REQ_AFC_FIXED_FILTER_STEP_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16 enReportEn;    /*1 使能AFC状态上报*/
    UINT16 usRsv;
}LPHY_REQ_AFC_REPORT_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16 enReportEn;    /*1 使能AFC状态上报*/
    UINT16 usRsv;
}LPHY_REQ_AFC_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16 enReportEn;    /*1 使能AFC状态上报*/
    UINT16 usRsv;
}LPHY_REQ_AFC_PPM_ENA_STRU;


typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16 enReportEn;    /*1 使能AFC状态上报*/
    UINT16 usRsv;
}LPHY_REQ_AFC_UL_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16 enReportEn;    /*1 使能AFC状态上报*/
    UINT16 usRsv;
}LPHY_REQ_AFC_HST_REPORT_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM                  enDebugEn;    /*1 使能AFC状态上报*/
}LPHY_REQ_AFC_LOOP_STATE_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16           enPDStatusEn;
}LPHY_REQ_AFC_PD_STATUS_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16           enReportEn;    /*1 使能AFC温补功能*/
}LPHY_REQ_AFC_TEMP_COMP_ENA_STRU;


typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16 enReportEn;    /*1 使能AFC状态上报*/
    UINT16 usRsv;
}LPHY_REQ_AFC_RFIC_FREQ_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16 enReportEn;    /*1 使能AFC状态上报*/
    UINT16 usRsv;
}LPHY_REQ_AFC_SCC_TPA_ENA_STRU;


typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16           enHstEn;       /* fixed to 1 for lab-test only, to get a better high speed(such as 250km/h) performance. */
    UINT16                              usAfcAccFoReadPeriod;
    INT32                               lHstVelThrsh;
    UINT16                              usTempDelta;
    UINT16                              usTestHstEn;
    INT32                               lFoVarThresh;
    UINT32                              ulLowThredCounter;
}LPHY_REQ_AFC_HST_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16           enHstOpenEn;
    UINT16                              usRev;
}LPHY_REQ_AFC_HST_OPEN_ENA_STRU;

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16           enMlOpenEn;
    UINT16                              usRev;
}LPHY_REQ_AFC_ML_OPEN_ENA_STRU;

/************************************************************
                           2. CNF数据结构定义
************************************************************/

typedef enum
{
    AFC_RUN_STATE = 0,              /*AFC周期鉴频启动*/
    AFC_STOP_STATE,             /*AFC周期鉴频停止*/
} AFC_STATE_ENUM;
typedef UINT16 AFC_STATE_ENUM_UINT16;

typedef enum
{
    AFC_IN_CYCLE_UNLOCK = 0,             /*AFC内环失锁*/
    AFC_IN_CYCLE_LOCK = 1,           /*AFC内环锁定*/
} AFC_LOOP_STATE_ENUM;
typedef UINT16 AFC_LOOP_STATE_ENUM_UINT16;

typedef enum
{
    AFC_OL_STOP = 0,              /*AFC外环鉴频停止*/
    AFC_TDPD_CP = 1,              /*AFC外环 CP鉴频*/
    AFC_TDPD_DTXCP  = 2,          /*AFC外环 DTXCP鉴频*/
    AFC_TDPD_PSS  = 3,            /*AFC外环 PSS鉴频*/
} AFC_OLPD_MODE_ENUM;
typedef UINT16 AFC_OLPD_MODE_ENUM_UINT16;

typedef enum
{
    AFC_RSPD = 0,
    AFC_OLPD_CP,
    AFC_OLPD_DTX,
    AFC_OLPD_PSS,
}AFC_PD_TYPE_ENUM;
typedef UINT16   AFC_PD_TYPE_ENUM_UINT16;

typedef enum
{
    AFC_NORMAL_TMPERATURE,
    AFC_NON_NORMAL_TMPERATURE
}AFC_TMPERATUR_RANGE_ENUM;
typedef UINT16 AFC_TMPERATUR_RANGE_ENUM_UINT16;

typedef enum
{
    AFC_HIGH_DRX_PERIOD,
    AFC_LOW_DRX_PERIOD
}AFC_DRX_PERIOD_ENUM;
typedef UINT16 AFC_DRX_PERIOD_ENUM_UINT16;

typedef enum
{
    PPM_DRX_NULL_STATE = 0,
    PPM_DRX_IDRX_STATE,
    PPM_DRX_CDRX_STATE,
    PPM_CON_NON_CDRX_STATE,
    PPM_DRX_STATE_BUTT
} PPM_DRX_STATE_DCXO;
typedef UINT16 PPM_DRX_STATE_DCXO_UINT16;


typedef enum
{
    DCXO_PPM_HTRAINMODE = 0,       /* 高铁识别模式*/
    DCXO_PPM_TEMPREATUREMODE,      /* 温补刷新模式*/
    DCXO_PPM_MODE_BUTT
} DCXO_PPM_IDENTIFY_MODE;
typedef UINT16 DCXO_PPM_IDENTIFY_MODE_UINT16;

typedef enum
{
    DCXO_TC_AFCFREQPPM = 0,
    DCXO_TC_POLYCOEFF,
    DCXO_TC_DEFAULTCOEFF,
    DCXO_TC_BUTT
} DCXO_TC_OM_REPORT_MODE;
typedef UINT16 DCXO_TC_OM_REPORT_MODE_UINT16;

/*相关系数门限指示，供RS和CP使用*/
typedef struct
{
    UINT16    usCcInd;                   //相关系数门限指示
    UINT16    usCCPassThrdCnt;          //通过门限2的次数
}AFC_CC_STAT_STRU;

typedef struct
{
    INT32    lReal;//复数的实部
    INT32    lImag;//复数的虚部
}AFC_COMPLEX_STRU;

typedef struct
{
    UINT32    ulCoPower;//相关系数分子部分
    UINT32    ulPower;//相关系数分母部分
}AFC_CC_STRU;

/*RS相关系数门限指示*/
typedef struct
{
    UINT16    usThrd1;     /*门限1*/
    UINT16    usThrd2;     /*门限2*/
    UINT16    usThrd3;     /*门限3*/
    UINT16    usThrd4;     /*门限3*/
    UINT16    usThrd5;     /*门限3*/
    UINT16    usThrd6;     /*门限3*/
    UINT16    usThrd7;     /*门限3*/
    UINT16    usThrd8;     /*门限3*/
}AFC_RSCC_THRE_STRU;

typedef struct
{
    UINT16                        usThreshold;
    UINT16                        usWinLen;
    UINT16                        usDataNum; /* 锁定窗中鉴频数据个数*/
    AFC_LOOP_STATE_ENUM_UINT16    enAFCLoopCurState;//AFC环路状态，内环失锁，内环锁定
}AFC_LOCK_STATE_STRU;


typedef struct
{
    AFC_LOCK_STATE_STRU           stIlUnlockState;

    UINT16                        usRemainFOWinLen;
    UINT16                        usRemainFreqNum; /* 残留频偏窗中鉴频数据个数*/
    UINT16                        usRemainFreqLevel;  //残留频偏分档指示
    UINT16                        usReserved;
}AFC_LOCK_PARA_STRU;
/************************************************************
                           3. Sg数据结构定义
************************************************************/

typedef enum
{
    LPHY_SG_AFC_REPORT_ENA         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_SG, 0x0),
    LPHY_SG_NC_AFC_REPORT_ENA,
    LPHY_SG_AFC_PCC_REPORT_ENA,
    LPHY_SG_AFC_SCC_REPORT_ENA,
    LPHY_SG_AFC_PPM_REPORT_ENA,
    LPHY_SG_AFC_UL_REPORT_ENA,
    LPHY_SG_AFC_ENA,
    LPHY_SG_AFC_PCC_ENA,
    LPHY_SG_AFC_SCC_ENA,
    LPHY_SG_AFC_HST_FO_ENA,
    LPHY_SG_AFC_HST_TEMP_ENA,
    LPHY_SG_AFC_DCXO_TC_ENA,
    LPHY_SG_AFC_DCXO_TC_INTERFACE_ENA,
}LPHY_SG_AFC_ENUM;

typedef struct
{
    UINT16    usCC;
    UINT16    usCCAlpha;
}AFC_ALPHA_FLT_STRU;

typedef struct
{
    AFC_ALPHA_FLT_STRU  stAlphaA;//相关系数分子作限幅的结果,算法图中,A/C
    AFC_ALPHA_FLT_STRU  stAlphaB;//相关系数分子未作限幅的结果,算法图中,B/D
}AFC_ALPHA_STRU;

typedef struct
{
    UINT16                   usAlphaStateFlag;//Alpha滤波初始化标志
    UINT16                   usReserved;
    AFC_ALPHA_STRU           astAlpha[LPHY_MAX_RX_ANTENNA_NUM];                 /*天线0、1的CP Alpha滤波结果*/
}AFC_ALPHA_DATA_STRU;
typedef enum
{
    AFC_PD_UNDONE = 0,
    AFC_PD_INVALID = 1,
    AFC_PD_DONE,
}AFC_PD_DONE_ENUM;
typedef UINT16 AFC_PD_DONE_ENUM_UINT16;


typedef enum
{
    AFC_SAMPLE_RATE_7_68M = 0,
    AFC_SAMPLE_RATE_15_36M,
    AFC_SAMPLE_RATE_30_72M,
    AFC_SAMPLE_RATE_61_44M
}AFC_SAMPLE_RATE_ENUM;
typedef UINT16 AFC_SAMPLE_RATE_ENUM_UINT16;

/*CP相关系数门限指示*/
typedef struct
{
    UINT16    usThrd1;     /*门限1*/
    UINT16    usThrd2;     /*门限2*/
    UINT16    usThrd3;     /*门限3*/
    UINT16    usThrd4;     /*门限4*/
    UINT16    usThrd5;     /*门限5*/
    UINT16    usreserved;
}AFC_CPCC_THRE_STRU;

/**/
typedef struct
{
    AFC_CC_STAT_STRU      astRsCCind[LPHY_MAX_RX_ANTENNA_NUM];    /*天线0、1的RS相关系数门限指示*/
    AFC_RSCC_THRE_STRU    stRSCCThre;
    UINT16                ausCCFlag[LPHY_MAX_RX_ANTENNA_NUM];     /*残留频偏指示*/

    UINT16                usRSCCIndMax;           /*两天线内环环CCInd中的最大值*/
    UINT16                usCCFlagMax;            /*两天线CCFlag中的最大值*/
}AFC_CC_IND_STRU;

typedef struct
{
    UINT16    usIndex;
    UINT16    usCounter;
    UINT16    usIndexLow;
    UINT16    usReserved;
}AFC_KLOWSNR_STRU;

typedef struct
{
    UINT16    usFOHighThreshold;
    UINT16    usFOLowThreshold;
    UINT16    usAdjustStpHigh;
    UINT16    usAdjustStpLow;
}AFC_KHIGHSNR_CFG_STRU;

typedef struct
{
    INT16                         sFilterInFOest;
    UINT16                        usFilterStep;
    UINT16                        usLoopAdjustStepLimit;
    UINT16                        usFilterInCCind;
    INT32                         lCurFOAdj;    //当前频偏调整量
    INT32                         lAccFO;       //频偏调整量累加值
    INT32                         lAccFOReport;
    INT32                         lRemainFO;    //v8r1添加残留频偏变量  xuyoujiang
    INT16                         asRSLockWin[AFC_MAX_RS_WIN_LEN];   /* 窗中rs鉴频数据 */
    //UINT16                        *pusRemainFOThresh;
    AFC_KLOWSNR_STRU              stKlowSNR;
    AFC_KHIGHSNR_CFG_STRU         stKHighSNR;
    /*环路状态*/
    AFC_LOCK_PARA_STRU            stLockPara;

}AFC_LOOP_FILTER_STRU;
typedef struct
{
    UINT16                        usCurPDM;     //环路输出频偏
    UINT16                        usInitPDM;

    UINT16                        usMultiModePdm;
    UINT16                        usPDMConfig;
    INT32                         lInitF0;      //初始频偏
    INT32                         lCsInitF0;      //初始频偏
    INT32                         lInitF0Compensation;      //初始频偏
    UINT32                        ulDeltFOCompensation;
    INT32                         lRFLoopFilterPCCIni;
    INT32                         lRFLoopFilterPCCCur;
    //INT32                         lSitaIni;

    INT32                         lDrxPDM;
	INT32                         lCsInitPDM;

	INT32                         lSccInitFO;
	UINT16                        usSccSampleRateValid;
	AFC_SAMPLE_RATE_ENUM_UINT16   usSccSampleRate;

	AFC_SAMPLE_RATE_ENUM_UINT16   usPccSampleRate;
	AFC_SAMPLE_RATE_ENUM_UINT16   usUlSampleRate;

	UINT16                        usSccTpaCfg;
	UINT16                        usSccMacCfg;

	UINT16                        usHTrainFlag;
	UINT16                        usRev;
}AFC_PDM_CTRL_STRU;


typedef struct
{
    //AFC_LOOP_STATE_ENUM_UINT16    enAFCLoopCurState;//AFC环路状态，内环失锁，外环失锁，外环锁定
    /*环路滤波*/

    AFC_LOOP_FILTER_STRU          stLoopFilter;
    AFC_PDM_CTRL_STRU             stPdmCtrl;

}AFC_LOOP_CTRL_STRU;


/*鉴频结果输出*/
typedef enum
{
     AFC_SDR_RUN = 1,
     AFC_SDR_STOP,
}AFC_PD_CONTROL_ENUM;
typedef UINT16 AFC_PD_CONTROL_ENUM_UINT16;
typedef enum
{
    AFC_EMBMS_HOLD = LPHY_TRUE,
    AFC_EMBMS_UNHOLD = LPHY_FALSE
}AFC_EMBMS_HOLD_CONFIG_ENUM;
typedef UINT16 AFC_EMBMS_HOLD_CONFIG_ENUM_UINT16;
typedef enum
{
    AFC_REFRESH_PDM_SUCCESS = 0,
    AFC_REFRESH_PDM_FAIL_UNLOCK,
    AFC_REFRESH_PDM_FAIL_CC,
    AFC_REFRESH_PDM_FAIL_PAR,
    AFC_REFRESH_PDM_FAIL_TEMP,
}AFC_REFRESH_PDM_CODE_ENUM;
typedef UINT16 AFC_REFRESH_PDM_CODE_ENUM_UINT16;

typedef struct
{

    /*外环BBP输出:*/
    /*CP鉴频叉积和s19,相关系数分子u31分母u22*/
    /*DTXCP鉴频叉积和s19*/
    /*PSS鉴频叉积和s31*/
    /*内环BBP输出*/
    /*RS鉴频叉积和s19,相关系数分子u31分母u22*/

    AFC_COMPLEX_STRU    astPwr[LPHY_MAX_RX_ANTENNA_NUM];         /*天线0外环鉴频叉积和结果，分为实部和虚部*/
    AFC_COMPLEX_STRU    stCordicIn;        /*两天线叉积和合并，Cordic频偏计算模块输入*/
    /*相关系数*/
    AFC_CC_STRU         astCC[LPHY_MAX_RX_ANTENNA_NUM];               /*天线0、1外环相关系数分子和分母*/

    /*Alpha滤波*/
    AFC_ALPHA_DATA_STRU      stAlphaData;                 /*天线0、1的CP Alpha滤波结果*/

    AFC_PD_DONE_ENUM_UINT16       enPDDoneFlag;
    AFC_PD_CONTROL_ENUM_UINT16    enPDCtrl;
    UINT16                        usFirstFrameFlag;
    UINT16                        usFrameCounter;

    AFC_EMBMS_HOLD_CONFIG_ENUM_UINT16 enPdHoldFlag;
    /*鉴频计算结果*/
    INT16                         sPDFOEst;//频偏估计
    UINT16                        usPeriod;//鉴频周期
    UINT16                        usLHz;
    //UINT16    usCounter;//鉴频周期内子帧计数
}AFC_PD_STATE_STRU;
typedef struct
{
    AFC_PD_STATE_STRU       stRSPDState;//AFC内环鉴频状态
    AFC_CC_IND_STRU         stAFCCCInd;
}AFC_PD_RESULT_STRU;
#define AFC_MAX_CCFLAG                     (5)
#define AFC_MAX_CCFLAG_LEVEL               (4)

typedef struct
{
    UINT16  ausPeriod[2];
    UINT16  ausCCFlagWindowslenth[6][5];
    UINT16  ausCCFlagThreNCP[4];
    UINT16  ausCCFlagThreECP[4];
    UINT16  ausRsThrd2Fdd[2][6];
    UINT16  ausRsThrd3Fdd[2][6];
    UINT16  ausRsThrd2TddCfg0[2][6];
    UINT16  ausRsThrd3TddCfg0[2][6];
    UINT16  ausRsThrd2TddNCfg0[2][6];
    UINT16  ausRsThrd3TddNCfg0[2][6];
    UINT16  ausRsThrd4[2];
    UINT16  ausRsThrd5[2];
    UINT16  usRsThrd6;
    UINT16  usRsThrd7;
    UINT16  usRsThrd8;
    UINT16  usRSCCIndThreHL;
}AFC_RS_PARA_CONFIG_STRU;
typedef struct
{
    AFC_PD_RESULT_STRU        stRsPdResult;
    AFC_RS_PARA_CONFIG_STRU   stRsConfig;
    AFC_LOOP_FILTER_STRU      stLoopFilter;
}AFC_PROC_STRU;
typedef struct
{
    INT32    lCrsInitAccFo;
    INT32    lEmbmaThetaInitial;
    INT32    lEmbmaPhaseStep;
    INT32    lEmbmsOutPhase;
    INT32    lEmbmaBaseBandFo;
}AFC_EMBMS_PHASE_STRU;
typedef struct
{
    UINT16   usCellId;
    UINT16   usFreqInfo;
    UINT16   usPDM;
    UINT16   usFilterStep;

    UINT16                        usRemainFreqLevel;  //残留频偏分档指示
    AFC_LOOP_STATE_ENUM_UINT16    enAFCLoopCurState;//AFC环路状态，内环失锁，内环锁定

    INT32    lAccFO;       //频偏调整量累加值
    INT32    lInitF0;

	UINT16   usInitPDM;
	UINT16   usTcFlag;
	INT32    lDrxPDM;
	INT32    lCsInitPDM;
	INT16    sLastTemp;
	INT16    sCurrTemp;

}AFC_BACKUP_CELL_PARA_STRU;
typedef struct
{
    UINT16                    usCellID;
    UINT16                    usFreqInfo;
    AFC_PROC_STRU             stCrsProc;

}AFC_CARRIER_PARA_STRU;
typedef struct
{
    INT32 lPhaseInitNext;
    INT32 lPhaseInit;
    INT32 lPhaseDelta;
    INT32 lPhaseDeltaUl;
    INT32 lPhaseDeltaUlConfig;
    INT32 lPhaseUpPts;
    UINT32 ulOffsetCalcFlag;
    INT32 lOffset0;
    INT32 lOffset1;
    INT32 lPccConverIni;
    INT32 lPccConverStep;
    INT32 lSccConverIni;
    INT32 lSccConverStep;
    INT32 lInitCurPcc;
    INT32 lPhaseStepPcc;
    INT32 lInitCurScc;
    INT32 lPhaseStepScc;
    INT32 lUlAccInitPhase;
    UINT16 usUlConfig;
    UINT16 usRev;
}AFC_TPA_PARA_STRU;


typedef struct
{
    UINT32 ulFOAccAverage;
    INT32  lTcInitFo;
    INT32  lFreqRatio;
    INT16  sPastTmperature;      //上一次查询温度，单位0.1摄氏度
    INT16  sCurrTmperature;      //当前温度
    INT16  sTmperatureDiffCnt;   //温差大于门限计数
    INT16  sFreqOutRangeCnt;
    INT16  sFreqLockErr;         //误锁定指示
    INT16  sRes;

}AFC_DCXO_TEMPERATURE_COMPENSATE;

typedef struct
{
    SINT32 aslAccFoSlidingWindow[AFC_PDM_WINDOW_LEN];
    SINT32 slAccFoSum;
    UINT16 usAccFoDataNum;
    UINT16 usPdPeriodNum;
    UINT16 usReadIdx;
    SINT16 sLastFoTemp;
    SINT16 sCurFoTemp;
    SINT16 sLastTemp;
    UINT16 usTempValid;
    UINT16 usTempReadNum;
    SINT32 slFoComp;
    INT64  lTotalFoVar;
    INT64  lFoVarThresh;
}AFC_HSTRAIN_RESULT_STRU;

typedef struct
{
    SINT32 aslAccFoSlidingWindow[AFC_PDM_WINDOW_LEN];
    SINT32 slAccFoSum;
    UINT16 usAccFoDataNum;
    UINT16 usPdPeriodNum;
    UINT16 usReadIdx;
    SINT16 sLastFoTemp;
    SINT16 sCurFoTemp;
    UINT16 usRev;
    SINT32 slFoComp;
    SINT32 lTotalFoVar;
    SINT32 lFoVarThresh;
}AFC_HST_FO_STRU;

typedef struct
{
    SINT16 sLastTemp;
    UINT16 usTempValid;
    UINT16 usTempReadNum;
    UINT16 usRev;
}AFC_HST_TEMP_STRU;

typedef struct
{
    AFC_HST_FO_STRU   stHstFo;
    AFC_HST_TEMP_STRU stHstTemp;
}AFC_HST_OM_STRU;


typedef struct
{
   INT32  lData;    /*  采样点PPM值*/
   INT16  sTemp;    /*  采样点温度值*/
   INT16  sReserved;
} PPM_SLIDWIN_STRU;

typedef struct
{
   PPM_SLIDWIN_STRU astPpmSlidingWindow[AFC_NON_CDRX_PPM_WINDOW_LEN]; /*滑动窗及窗长64*/
   INT32  lPpmSum;                                           /*  采样点数据和*/
   INT32  lPpmVar;                                           /*  采样点数据方差*/
   UINT16 usPpmDataNum;                                      /*  采样点个数*/
   UINT16 usPpmUpdatePos;                                    /*  最新采样点更新位置*/
   UINT16 usPastDrxState;                                    /*  上个采样点DRX状态*/
   UINT16 usPastPointTimeFrm;                                /*  上个采样点采样时间帧号*/
   UINT16 usPastPointTimeSubFrm;                             /*  上个采样点采样时间子帧号*/
   UINT16 usReserved;
} AFC_DCXO_PPM_POINT_STRU;

typedef struct
{
   UINT16 usHighTrainFlag;                                      /* 高铁识别标志，0非高铁，1高铁*/
   UINT16 usTemperatureFlag;                                    /* 温补刷新标志，0不刷新，1刷新*/
   UINT16 usHighTrainReadPeriodFlag; 					/* 记录NON_CDRX 高铁识别样点时间间隔,0不满足,1满足*/
   UINT16 usHighTrainTemperThrFlag;				    	/* 记录NON_CDRX 高铁识别样点温差,0大于门限,1小于门限*/
} AFC_DCXO_PPM_CONTRL_STRU;

typedef struct
{
    INT32  lPpmVarThr;                  /*方差门限*/
    INT16  sTempThr;                    /*采样点温度差门限*/
	UINT16 usNotHighTrainThr;           /*高铁模式到非高铁模式时间门限(帧号)*/
    UINT16 usPpmDrxReadPeriod;          /*非DRX PPM读入间隔时长，单位ms*/
    UINT16 usPpmNonDrxReadPeriod;       /*CDRX PPM两次采样点满足间隔时长，单位ms*/
}AFC_DCXO_PPMNVPARA_STRU;
//typedef NV_LTE_DCXO_PPM_UPDATE_THRESHOLD_STRU AFC_DCXO_PPMNVPARA_STRU;

typedef struct
{
    AFC_DCXO_PPM_POINT_STRU          astPpmPointResult[2];/*0存储高铁采样点信息，1存温补采样点信息*/
    AFC_DCXO_PPM_CONTRL_STRU         stPpmContrlFlag;
    AFC_DCXO_PPMNVPARA_STRU          stPpmNvPara;
}AFC_DCXO_PPM_PARA_STRU;

typedef struct
{
    UINT16 usFratioSetFlag;
	UINT16 usReserved;
    INT32  lFratio;
    INT32  lLMasterInitFO;
    UINT16 usTcSetFlag;
    UINT16 usInitFOSetFlag;
}AFC_SWITCH_TO_L_MASTER;


typedef struct
{
    INT32  lAccFO;
    INT16  sLastTemperature;
    INT16  sCurrTemperature;
    UINT16 usConfigFlag;
	UINT16 usInitPDM;
	INT32  lCsInitPDM;
	INT32  lDrxPDM;

}AFC_BGS_CONFIG;

typedef struct
{
    INT16  sLastTemperature;
    INT16  sCurrTemperature;
	UINT16 usTCFlag;
	UINT16 usReserved;

}AFC_SWITCHBACK_TC;

typedef struct
{
	UINT8                     		usAfcContinuouseFrmFlag;
	UINT8                     		usRsv;
	AFC_STATE_ENUM_UINT16     		aenAFCState;
	AFC_CARRIER_PARA_STRU     		astCaAfc;
	AFC_TPA_PARA_STRU         		stAfcTpaPara;
}AFC_CC_PARA_STRU;
typedef struct
{
    UINT16                    		usSweepCounter;
    UINT16                    		usAfcMbmsContinuouseFrmFlag;
    AFC_STATE_ENUM_UINT16     		enAFCMbmsState;
    UINT16                          usSccFreqInfo;
    UINT16                          usPccRficFreq;
    UINT16                          usPccRficFreqFlag;
    AFC_PROC_STRU             		stMrsProc;
    AFC_PDM_CTRL_STRU         		stPdmCtrl;
    AFC_EMBMS_PHASE_STRU      		stEmbmsPhase;
    AFC_BACKUP_CELL_PARA_STRU 		stHoBackupPara;
    AFC_BACKUP_CELL_PARA_STRU 		stBgsAnrBackupPara;
    AFC_DCXO_TEMPERATURE_COMPENSATE	stAfcTmperatureComp;
    AFC_SWITCH_TO_L_MASTER			stAfcSwitchToL;
    AFC_BGS_CONFIG            		stAfcBgsConfig;
    //AFC_HSTRAIN_RESULT_STRU         stHSTResult;
}AFC_NONCC_PARA_STRU;
typedef struct
{
    //UINT16                    usLastCellPDM;
    //UINT16                    usLastCellId;
	AFC_CC_PARA_STRU stAfcCc[LPHY_FEATURE_MAX_CARRIER_NUM];
	AFC_NONCC_PARA_STRU stAfcNonCc;
	AFC_DCXO_PPM_PARA_STRU     stDcxoPpmPara;
	#if 0
	AFC_CARRIER_PARA_STRU     astCaAfc[LPHY_FEATURE_MAX_CARRIER_NUM];

    UINT16                    usSweepCounter;
    AFC_STATE_ENUM_UINT16     aenAFCState[LPHY_FEATURE_MAX_CARRIER_NUM];//下一子帧AFC的状态，START/STOP/HOLD
    UINT8                     usAfcContinuouseFrmFlag[LPHY_FEATURE_MAX_CARRIER_NUM];

	AFC_STATE_ENUM_UINT16     enAFCMbmsState;
    UINT16                    usAfcMbmsContinuouseFrmFlag;
    //AFC_PROC_STRU             stCrsProc;
    AFC_PROC_STRU             stMrsProc;

    AFC_PDM_CTRL_STRU         stPdmCtrl;
    AFC_EMBMS_PHASE_STRU      stEmbmsPhase;
    AFC_BACKUP_CELL_PARA_STRU stHoBackupPara;
    AFC_BACKUP_CELL_PARA_STRU stBgsAnrBackupPara;
    AFC_TPA_PARA_STRU         stAfcTpaPara[LPHY_FEATURE_MAX_CARRIER_NUM];
    AFC_DCXO_TEMPERATURE_COMPENSATE stAfcTmperatureComp;     //初始化?
	AFC_SWITCH_TO_L_MASTER    stAfcSwitchToL;
    AFC_BGS_CONFIG            stAfcBgsConfig;
	#endif
}AFC_PARA_STRU;

typedef struct
{
    UINT16                    		usSweepCounter;
    UINT16                          usSccFreqInfo;
    UINT16                          usCurPDM;     //环路输出频偏
    UINT16                          usInitPDM;
    INT32                           lInitF0;      //初始频偏
    INT32                           lCsInitF0;      //初始频偏
    INT32                           lInitF0Compensation;      //初始频偏
    INT32                           lRFLoopFilterPCCCur;
    INT32                           lSccInitFO;
	UINT16                          usSccSampleRateValid;
	AFC_SAMPLE_RATE_ENUM_UINT16     usSccSampleRate;
	AFC_SAMPLE_RATE_ENUM_UINT16     usPccSampleRate;
	AFC_SAMPLE_RATE_ENUM_UINT16     usUlSampleRate;
	UINT16                          usHTrainFlag;
	UINT16                          usRev;

    AFC_BACKUP_CELL_PARA_STRU 		stHoBackupPara;
    AFC_BACKUP_CELL_PARA_STRU 		stBgsAnrBackupPara;
    AFC_DCXO_TEMPERATURE_COMPENSATE	stAfcTmperatureComp;
    AFC_SWITCH_TO_L_MASTER			stAfcSwitchToL;
    AFC_BGS_CONFIG            		stAfcBgsConfig;
}AFC_COMMON_STRU;

typedef struct
{
    UINT16                          usCellID;
    UINT16                          usFreqInfo;
    UINT16                          usPeriod;//鉴频周期
    AFC_STATE_ENUM_UINT16     		enAFCState;
    UINT16                          usCcInd[LPHY_MAX_RX_ANTENNA_NUM];

    INT16                           sFilterInFOest;
    UINT16                          usFilterInCCind;
    INT32                           lCurFOAdj;    //当前频偏调整量
    INT32                           lAccFOReport;
    INT32                           lRemainFO;    //v8r1添加残留频偏变量  xuyoujiang


    INT32                           lPhaseDelta;
    INT32                           lPhaseDeltaUlConfig;
    INT32                           lOffset0;
    INT32                           lOffset1;
    INT32                           lPccConverStep;
    INT32                           lSccConverStep;
    INT32                           lPhaseStepPcc;
    INT32                           lPhaseStepScc;

    UINT16                          usRemainFreqLevel;
    AFC_LOOP_STATE_ENUM_UINT16      enAFCLoopCurState;
    UINT16                          usRemainFOWinLen;
	UINT8                     		usAfcContinuouseFrmFlag;
	UINT8                     		usRsv[1];

}AFC_CACCRIER_STRU;

typedef struct
{
    AFC_COMMON_STRU     stAfcCommon;
    AFC_CACCRIER_STRU   astAfc[LPHY_FEATURE_MAX_CARRIER_NUM];
}AFC_OM_REPORT_STRU;

typedef struct
{
    UINT16      usCellId;      //小区ID
    INT16       sPDFOEst;      //频偏
    UINT16      usCurPDM;      //PDM
    UINT16      usRSCCIndMax;  //相关系数因子
    UINT16      usFilterStep;
    INT16       sFilterInFOest;
    UINT16      usReserved;
    AFC_LOOP_STATE_ENUM_UINT16    enAFCLoopCurState;   //环路锁定标志
    INT32       lInitF0;
    INT32       lAccFO;
}LPHY_NC_AFC_REPORT_STRU;

typedef struct
{
    UINT16                     usFreqInfo;
    LTE_BAND_WIDTH_ENUM_UINT16 enBandwidth;
    UINT16                     usMsrCellNum;
    UINT16                     usTxNum;
    LPHY_NC_AFC_REPORT_STRU    astNcAfcReport[AFC_MAX_NCELL_PER_FREQ_NUM];
}LPHY_SG_NC_AFC_REPORT_ENA_STRU;

typedef struct
{
    DCXO_TC_OM_REPORT_MODE_UINT16  enCalcMode;
    INT16                          sCurrTemp;
    INT32					       lAfcValue;
    INT32                          lDelta;
    UINT32					       aulMantissaDefault[TL_DCXO_POLY_COEF_NUM_SG];  /* 依次存放a0,a1,a2,a3的尾数 */
	UINT16					       ausExponentDefault[TL_DCXO_POLY_COEF_NUM_SG];  /* 依次存放a0,a1,a2,a3的指数 */
}LPHY_SG_AFC_DCXO_TC_STRU;

typedef struct
{
    DCXO_TC_OM_REPORT_MODE_UINT16  enCalcMode;
    INT16                          sCurrTemp;
    INT32					       lAfcValue;
    INT32                          lDelta;
}LPHY_SG_AFC_DCXO_TC_INTERFACE_STRU;
/************************************************************
                           4. TRACE数据结构定义
************************************************************/
typedef enum
{
    LPHY_TRACE_AFC_LOOP_STATE         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_TRACE, 0x1),
    LPHY_TRACE_AFC_OLPD_MODE,
    LPHY_TRACE_AFC_STATE,
    LPHY_TRACE_AFC_PARA_UPDATE,
}LPHY_TRACE_AFC_ENUM;

typedef struct
{
    UINT32      ulLineNum;
    AFC_LOOP_STATE_ENUM_UINT16      enNewLoopState;
    UINT16      usReserved;
}LPHY_TRACE_AFC_LOOP_STATE_STRU;

typedef struct
{
    UINT32      ulLineNum;
    AFC_PD_TYPE_ENUM_UINT16      ulOlpdMode;
}LPHY_TRACE_AFC_OLPD_MODE_STRU;

typedef struct
{
    UINT32      ulLineNum;
    AFC_STATE_ENUM      ulAfcState;
}LPHY_TRACE_AFC_STATE_STRU;
typedef enum
{
    AFC_SWITCH_CELL = 0,
    AFC_SWITCHBACK,
    AFC_INIT_START,
    AFC_UPDATE_DL_PARA,
    AFC_CAMPCELL,
    AFC_CONTIGOUS_CA,
    AFC_NONCONTIGOUS_CA,
    AFC_SCC_START,
    AFC_SCC_STOP,
    AFC_CONTIGOUS_CA_INACTIVE,
	AFC_NONBLIND_NONIRAT_HO,
	AFC_INTER_MEAS,
	AFC_RESUME_TPA,
	AFC_SCC_MEAS_TPA,
}AFC_UPDATE_CELL_CAUSE_ENUM;
typedef UINT16 AFC_UPDATE_CELL_CAUSE_ENUM_UINT16;

typedef struct
{
    AFC_UPDATE_CELL_CAUSE_ENUM_UINT16 enUpdateCause;
    AFC_SAMPLE_RATE_ENUM_UINT16       enSampleRate;
    UINT16                            usFreqInfo;
    UINT16                            usRev;
}LPHY_TRACE_AFC_PARA_UPDATE_STRU;
/************************************************************
                           5. ERROR数据结构定义
************************************************************/
typedef enum
{
    LPHY_ERROR_AFC_ARRAY_INDEX         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_ERROR, 0x1),
    LPHY_ERROR_AFC_CASE,
    LPHY_ERROR_AFC_ZERO_DIV,
    LPHY_WARNING_AFC_RTT_SWITCH_OFF,
}LPHY_ERROR_AFC_ENUM;

typedef struct
{
    UINT32      ulLineNum;//__LINE__
    UINT32      ulIncorrectValue;
}LPHY_ERROR_AFC_ARRAY_INDEX_STRU;

typedef struct
{
    UINT32      ulLineNum;//__LINE__
    UINT32      ulCurrentCase;
    UINT32      ulLastCase;
}LPHY_ERROR_AFC_CASE_STRU;

typedef struct
{
    UINT32      ulLineNum;//__LINE__
}LPHY_ERROR_AFC_ZERO_DIV_STRU;

/************************************************************
                           7. Ind数据结构定义
************************************************************/
typedef enum
{
    LPHY_IND_AFC_PD_STATUS_ENA         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_IND, 0x1),
    LPHY_IND_AFC_LOOP_STATE_ENA,
}LPHY_IND_AFC_ENUM;


typedef struct
{
    AFC_PD_TYPE_ENUM_UINT16       enPDType;
    UINT16                        usAlphaStateFlag;//Alpha滤波初始化标志
    INT16                         sPDFOEst;//频偏估计
    UINT16                        usPeriod;//鉴频周期
    UINT16                        ausCCFlag[LPHY_MAX_RX_ANTENNA_NUM];
    UINT16                        ausDTXFlag[LPHY_MAX_RX_ANTENNA_NUM];
    UINT16                        usCCAlphaA[LPHY_MAX_RX_ANTENNA_NUM];
    UINT16                        usCCAlphaB[LPHY_MAX_RX_ANTENNA_NUM];
    AFC_CC_STAT_STRU              astCCind[LPHY_MAX_RX_ANTENNA_NUM];    /*天线0、1的RS相关系数门限指示*/
    AFC_COMPLEX_STRU              astPwr[LPHY_MAX_RX_ANTENNA_NUM];         /*天线0外环鉴频叉积和结果，分为实部和虚部*/
    AFC_CC_STRU                   astCC[LPHY_MAX_RX_ANTENNA_NUM];               /*天线0、1外环相关系数分子和分母*/
    AFC_RSCC_THRE_STRU            stCCThre;
}LPHY_IND_AFC_PD_STATUS_ENA_STRU;

typedef struct
{
    /*环路滤波*/
    AFC_LOOP_STATE_ENUM_UINT16      enAFCLoopCurState;//AFC环路状态，内环失锁，外环失锁，外环锁定
    UINT16      usLastCellPDM;
    UINT16      usFilterInCCind;
    INT16       sFilterInFOest;

    INT32       lCurFOAdj;    //当前频偏调整量
    INT32       lAccFO;       //频偏调整量累加值
    INT32       lInitF0;      //初始频偏
    AFC_LOCK_PARA_STRU            stLockPara;
} LPHY_IND_AFC_LOOP_STATE_ENA_STRU;

typedef struct
{
    UINT16      usFOestUnderFlg;
    UINT16      usFixRawVelocityFlg;
}AFC_HS_DL_PARA_STRU;

typedef struct
{
    UINT32  ulFilterStateFlag;
    SINT32  slFilterIn;
    SINT32  slFilterCoef;
    SINT32  slACCFOReg;
    SINT16  sFOest;
    UINT16  usFOestPassCtl;
    SINT16  sLastTemp;
    SINT16  sCurTemp;
    SINT32  slFoComp;
}AFC_UL_ALPHA_FLT_STRU;
typedef struct
{
    UINT16      usULPDMConfig;
    UINT16      usDLFreqInfo;
    UINT16      usULFreqInfo;
    UINT16      usFrameType;
    UINT32      ulAFCthres0;
    UINT32      ulAFCthres1;
    SINT32      slULCurBBRotator;
    SINT32      slULLastBBRotator;
    SINT32      slULCurACCFO;
    SINT32      slDLCurACCFO;
    SINT32      slACCFOlongTerm;
    SINT32      slPhaseUL;
    UINT32      ulLowThredCounter;
    AFC_UL_ALPHA_FLT_STRU stULFilter;
}AFC_UL_PARA_STRU;

/************************************************************
                           8. DT路测数据结构定义
************************************************************/
/*typedef enum
{
    LPHY_DT_AFC_REPORT_REQ         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_DT, 0x1)

}LPHY_DT_AFC_REQ_ENUM;*/

typedef struct
{
    AFC_OM_SWITCH_ENUM_UINT16    enAfcReportEn;
    UINT16   usReportPeriod;
}LPHY_DT_AFC_REPORT_REQ_STRU;

typedef enum
{
    LPHY_DT_AFC_REPORT_RESERVED         = OM_CMD_ID(LPHY_AFC_MID, OM_TYPE_DT, 0x0),
    LPHY_DT_AFC_REPORT_IND,
    LPHY_DT_AFC_REPORT_CA_IND

}LPHY_DT_AFC_IND_ENUM;

typedef struct _LPHY_DT_AFC_REPORT_CA_IND_STRU__
{
    UINT8      ucCcValidFlg;
	UINT8      ucCcIdx;
	UINT16     usRsv;

    UINT16     usSFN;
    UINT16     usSubFn;
    UINT16     usPeriod;
    UINT16     usRsv0;
    INT32      lCurFOAdj;
}LPHY_DT_AFC_REPORT_CA_IND_STRU;



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __AFC_OM_DEF_H__ */

