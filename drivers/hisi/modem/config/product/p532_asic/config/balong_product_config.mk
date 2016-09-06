# MD5: 50ecc01955e0549c0f5d3137c1f32422
CFG_BALONG_OBUILD_VERSION:=10
CFG_BUILD_PTABLE:=YES
OBB_SEPARATE := true
CFG_ARCH_TYPE	:=3339
CFG_PRODUCT_NAME                      :="p532_asic"
CFG_PRODUCT_CFG_CHIP_SOLUTION_NAME    :="Balong"
CFG_BUILD_TYPE                        :=RELEASE
CFG_PRODUCT_VERSION                   :=V700R200C31B120
CFG_PRODUCT_VERSION_STR               :="V700R200C31B120"
CFG_PRODUCT_FULL_VERSION_STR          :="Balong V700R200C31B120"
CFG_PRODUCT_FILE_VERSION_STR          :="2.1.6.8"
CFG_PRODUCT_DLOAD_SOFTWARE_VER		:= "21.120.00.00.031"
CFG_CONFIG_VERSION_STUB             :=YES
CFG_HW_VERSION_STUB                 :=0XFF000000
CFG_PXXX_BOARD_TYPE_ONLY_SOC        :=YES
CFG_FEATURE_OBJ_CMP 				:=NO
CFG_FEATURE_OBJ_DUMP				:=NO
CFG_USE_USBLOADER_MERGE 			:=YES
CFG_BSP_ENBALE_PACK_IMAGE			:=YES
CFG_BSP_USB_BURN					:=YES
CFG_PLATFORM := p532
CFG_OS_PATH :=modem/config/product/p532_asic/os
CFG_OS_IMG_FILE:=VXWORKS.6.8.3.IMG.wpj
CFG_OS_LIB:=VXWORKS.6.8.3.LIB.RELEASE
CFG_FTP_REPLY_TIME_OUT:=0
CFG_OS_LINUX_PRODUCT_NAME:=p532_defconfig
CFG_TARGET_BALONG_PRODUCT:=p532
CFG_PRODUCT_CONTROL_VERSION                 :="121"
CFG_PRODUCT_HISILICON_VERSION               :=hi6950
CFG_PRODUCT_NV_SPLITFILE                    :=/binfilesplit "0"
CFG_PRODUCT_NV_FILE_MAX_SIZE                :=/binfileLimitSize "100"
CFG_PRODUCT_NV_BIN_MODEM_NUNBER             :=/bin_modem_number "1"
CFG_PRODUCT_NV_XNV_MODEM_NUNBER             :=/xnv_modem_number "1"
CFG_PRODUCT_NV_XNV_PDT_VERSION              :=hi6950_fpga_p532
CFG_XTENSA_CORE				:=p532_bbe16_nocache
CFG_XTENSA_SYSTEM			:=$(ROOT_XTENSA_PATH_W)/XtDevTools/install/builds/RE-2014.5-linux/p532_bbe16_nocache/config
LPHY_LD_MAP_PUB_PATH        :=modem/phy/lt/Tensilica_LSP/BBE16_NOCACHE_P532_LSP/mainlsp
LPHY_LD_MAP_LTE_PATH        :=modem/phy/lt/Tensilica_LSP/BBE16_NOCACHE_P532_LSP/overlaylsp
LPHY_LD_MAP_TDS_PATH        :=modem/phy/lt/Tensilica_LSP/BBE16_NOCACHE_P532_LSP/overlaylsp
LPHY_LD_SDR_LIB_FILE	    :=BBE16_NOCACHE_P532_02
LPHY_XTENSA_RULES           :=cc_tensilica5.0.5_rules.mk 		
CFG_LPHY_PUB_DTCM_BASE	    :=0x49000000
CFG_LPHY_PUB_ITCM_BASE	    :=0x49100000
CFG_LPHY_PRV_DTCM_BASE	    :=0x49080000
CFG_LPHY_PRV_ITCM_BASE	    :=0x49180000
CFG_LPHY_PUB_DTCM_SIZE		:=0x80000
CFG_LPHY_PUB_ITCM_SIZE		:=0x80000
CFG_LPHY_PRV_DTCM_SIZE		:=0x80000
CFG_LPHY_PRV_ITCM_SIZE		:=0x80000
CFG_LPHY_LTE_DTCM_SIZE		:=0x80000
CFG_LPHY_LTE_ITCM_SIZE		:=0x80000
CFG_LPHY_TDS_DTCM_SIZE		:=0x80000
CFG_LPHY_TDS_ITCM_SIZE		:=0x80000
CFG_LPHY_ALL_IMAG_SIZE		:=0x300000
CFG_LPHY_TOTAL_IMG_SIZE                :=((LPHY_PUB_DTCM_SIZE)+(LPHY_PUB_ITCM_SIZE)+(LPHY_LTE_DTCM_SIZE)*1+(LPHY_LTE_ITCM_SIZE)*1+(LPHY_TDS_DTCM_SIZE)+(LPHY_TDS_ITCM_SIZE))
CFG_TL_PHY_LALG_PATH    	:=modem/include/phy
CFG_TL_PHY_FPGA_P532    	:= YES
CFG_TL_PHY_BBE16_CACHE          := NO
CFG_TL_PHY_6930         	:= YES
CFG_TL_PHY_FEATURE_LTE_LCS  	:= YES
CFG_GU_INC_PATH :=COMM_CODE_GU/Balong_GU_Inc/GUL_CS
CFG_GU_PRODUCT_VERSION :=VERSION_V7R1
CFG_RAT_GU:=0
CFG_RAT_GUL:=1
CFG_RAT_MODE :=RAT_GUL
CFG_GU_RAT_MODE :=RAT_GUL
CFG_PLATFORM_HISI_BALONG :=p532
CFG_TTF_SKB_EXP := NO
CFG_GU_FEATURE_CONFIG_PATH :=modem/config/product/p532_asic/include_gu
CFG_HIFI_INCLUDE                        := YES
CFG_HIFI_LINK_DIR_NAME :=hifi_ld_V7R2_SFT
CFG_XTENSA_CORE_HIFI            :=v7r2_hifi
CFG_PLATFORM_CHIP_TYPE :=p532
CFG_CHIP_MODEM_ARM_ARCH := CORTEX_A9
CFG_BSP_CONFIG_EDA := NO
CFG_BSP_CONFIG_EMU := NO
CFG_BSP_CONFIG_NOT_DDR_BYPASSPLL := NO
CFG_BSP_CONFIG_P532_ASIC := YES
CFG_BSP_CONFIG_P532_FPGA := NO
CFG_BSP_HAS_SEC_FEATURE     := NO
CFG_CONFIG_SMART_SYSTEM_MODEM := NO
CFG_CONFIG_OF := YES
CFG_CONFIG_FASTBOOT_DEBUG := NO
CFG_CONFIG_FASTBOOT_UART_NUM := 1
CFG_CONFIG_GPIO_SYNOPSYS := YES
CFG_CONFIG_COMPRESS_CCORE_IMAGE := YES
CFG_CONFIG_MODULE_VIC := NO
CFG_CONFIG_PCIE_CFG := YES
CFG_CONFIG_CIPHER := YES
CFG_CONFIG_AT_UART := NO
CFG_CONFIG_CSHELL := NO
CFG_CONFIG_IPF    := YES
CFG_CONFIG_PSAM   := NO
CFG_CONFIG_MODULE_BUSSTRESS := NO
CFG_CONFIG_ICC := YES
CFG_CONFIG_RTC_BUILD_CTRL := YES
CFG_CONFIG_RTC_ON_SOC := YES
CFG_CONFIG_RTC_DRV_PL031 := YES
CFG_CONFIG_MEM := YES
CFG_CONFIG_CPUFREQ := NO
CFG_CONFIG_CCORE_REGULATOR := YES
CFG_CONFIG_CCORE_WDT := YES
CFG_CONFIG_ACORE_WDT := YES
CFG_CONFIG_PMIC_HI6551 := YES
CFG_CONFIG_COUL := NO
CFG_CONFIG_USE_TIMER_STAMP:=YES
CFG_CONFIG_SPI := NO
CFG_CONFIG_SFLASH := NO
CFG_CONFIG_ABB := NO
CFG_CONFIG_DSP := NO
CFG_CONFIG_HIFI := NO
CFG_CONFIG_HKADC := NO
CFG_CONFIG_ONOFF := YES
CFG_CONFIG_BBP := NO
CFG_CONFIG_BALONG_RDR := YES
CFG_CONFIG_NVIM := YES
CFG_CONFIG_SC := NO
CFG_FEATURE_NV_FLASH_ON := YES
CFG_FEATURE_NV_EMMC_ON := NO
CFG_FEATURE_NV_LFILE_ON := NO
CFG_FEATURE_NV_RFILE_ON := NO
CFG_FEATURE_UPGRADE_TL := YES
CFG_FEATURE_TLPHY_MAILBOX :=YES
CFG_CONFIG_MAILBOX_TYPE:=YES
CFG_CONFIG_HIFI_MAILBOX:=YES
CFG_CONFIG_PA_RF := NO
CFG_CONFIG_PASTAR := NO
CFG_CONFIG_MIPI := NO
CFG_ENABLE_SHELL_SYM :=YES
CFG_ENABLE_DEBUG :=YES
CFG_RTOSCK_CCORE_COMPONENTS :=bsp_ccore.o
CFG_CCORE_COMPONENTS :=bsp_ccore.o os_ccore.o
CFG_CCORE_MODEM1_COMPONENTS :=bsp_ccore1.o
CFG_CCORE_MODEMUNION_COMPONENTS :=modemcore1_union.o
CFG_BUILD_DRV_ONLY          := NO
CFG_ENABLE_TEST_CODE := NO
CFG_ENABLE_BUILD_VARS := YES
CFG_ENABLE_BUILD_OM := YES
CFG_FEATURE_OM_PHONE := NO
CFG_ENABLE_BUILD_SYSVIEW := YES
CFG_ENABLE_BUILD_CPUVIEW := YES
CFG_ENABLE_BUILD_MEMVIEW := YES
CFG_ENABLE_BUILD_AMON := YES
CFG_ENABLE_BUILD_UTRACE := NO
CFG_ENABLE_BUILD_SOCP := YES
CFG_CONFIG_CCORE_CPU_IDLE := YES
CFG_CONFIG_BSP_TEST_CCORE := NO
CFG_CONFIG_BALONG_CCLK := NO
CFG_FEATURE_E5_ONOFF := NO
CFG_CONFIG_CCORE_PM := NO
CFG_CONFIG_MODULE_IPC := YES
CFG_CONFIG_MODULE_TIMER := YES
CFG_CONFIG_MODULE_SYNC := YES
CFG_CONFIG_LEDS_CCORE := NO
CFG_CONFIG_HAS_CCORE_WAKELOCK := NO
CFG_CONFIG_CCORE_BALONG_PM := NO
CFG_CONFIG_BALONG_EDMA := YES
CFG_CONFIG_BALONG_EDMA_TEST := YES
CFG_CONFIG_IPF_VESION  := 2
CFG_CONFIG_IPF_ADQ_LEN := 3
CFG_CONFIG_IPF_PROPERTY_MBB := YES
CFG_CONFIG_FB_SPI_BALONG := NO
CFG_CONFIG_FB_EMI_BALONG := NO
CFG_CONFIG_FB_1_4_5_INCH_BALONG:=NO
CFG_CONFIG_FB_2_4_INCH_BALONG:=NO
CFG_CONFIG_SLIC := n
CFG_CONFIG_WM8990 := NO
CFG_CONFIG_GPIO_EXPANDER := NO
CFG_CONFIG_TEMPERATURE_PROTECT := NO
CFG_CONFIG_ANTEN := NO
CFG_CONFIG_EFUSE := NO
CFG_CONFIG_BURN_EFUSE_NANDC := NO
CFG_CONFIG_DDM := YES
CFG_CONFIG_TSENSOR := NO
CFG_CONFIG_DESIGNWARE_I2C := YES
CFG_CONFIG_USB_DWC3_VBUS_DISCONNECT:=YES
CFG_USB3_SYNOPSYS_PHY:=YES
CFG_CONFIG_USB_FORCE_HIGHSPEED:=NO
CFG_CONFIG_TCXO_BALONG := NO
CFG_FEATURE_SIM_NOTIFY := NO
CFG_CONFIG_CCORE_I2C := NO
CFG_CONFIG_BALONG_DPM := NO
CFG_CONFIG_BALONG_HPM_TEMP := NO
CFG_CONFIG_HWADP := YES
CFG_PRODUCT_CFG_PTABLE_VER_NAME          := "HI6930_V7R2_UDP"
CFG_PRODUCT_CFG_PTABLE_VER_ID			 := "ptable 1.00"
CFG_PRODUCT_CFG_FLASH_TOTAL_SIZE         := 0x10000000
CFG_PRODUCT_CFG_FLASH_M3BOOT_LEN     	 := 0x40000
CFG_PRODUCT_CFG_FLASH_FASTBOOT_LEN       := 0xC0000
CFG_PRODUCT_CFG_FLASH_NV_LTE_LEN         := 0x400000
CFG_PRODUCT_CFG_FLASH_NV_IMG_LEN         := 0x400000
CFG_PRODUCT_CFG_FLASH_NV_DLD_LEN      	 := 0x300000
CFG_PRODUCT_CFG_FLASH_SEC_STORAGE_LEN    := 0
CFG_PRODUCT_CFG_FLASH_NV_FACTORY_LEN   	 := 0x300000
CFG_PRODUCT_CFG_FLASH_OEMINFO_LEN        := 0x200000
CFG_PRODUCT_CFG_FLASH_YAFFS_USERDATA_LEN := 0x600000
CFG_PRODUCT_CFG_FLASH_YAFFS_ONLINE_LEN   := 0x5A00000
CFG_PRODUCT_CFG_FLASH_BOOTIMG_LEN	 := 0x600000
CFG_PRODUCT_CFG_FLASH_BOOTIMGBAK_LEN	 := 0
CFG_PRODUCT_CFG_FLASH_LOGO_LEN          := 0x200000
CFG_PRODUCT_CFG_FLASH_HIFI_LEN  	 := 0x300000
CFG_PRODUCT_CFG_FLASH_MISC_LEN           := 0x100000
CFG_PRODUCT_CFG_FLASH_M3IMAGE_LEN 	 := 0x100000
CFG_PRODUCT_CFG_FLASH_RESERVE1_LEN  :=   0
CFG_PRODUCT_CFG_FLASH_RESERVE2_LEN  :=   0
CFG_PRODUCT_CFG_FLASH_RESERVE3_LEN  :=   0
CFG_PRODUCT_CFG_FLASH_OM_LEN             := 0xC00000
CFG_PRODUCT_CFG_FLASH_YAFFS_APP_LEN      := 0x1000000
CFG_PRODUCT_CFG_FLASH_YAFFS_WEBUI_LEN 	 := 0x0
CFG_PRODUCT_CFG_FLASH_SYSIMG_LEN         := 0x4000000
CFG_PRODUCT_CFG_FLASH_DTIMG_LEN          := 0x00800000
CFG_PRODUCT_CFG_FLASH_ISO_LEN            := 0x1000000
CFG_PRODUCT_CFG_FLASH_CACHE_LEN   	 := 0x400000
CFG_PRODUCT_CFG_FLASH_RECOVERY_LEN       := 0x400000
CFG_PRODUCT_CFG_FLASH_MULTI_CARRIER_LEN       := 0x00000
CFG_FLASH_PTABLE_OFFSET						 := 0x1F800
CFG_PRODUCT_CFG_FLASH_MODEM_FW_LEN         := 0x01400000
CFG_MCORE_TEXT_START_ADDR               := 0x50400000
CFG_FASTBOOT_ENTRY                      := 0x4fe00000
CFG_FASTBOOT_DDR_ENTRY                  := 0x5FD00000
CFG_PRODUCT_CFG_KERNEL_ENTRY 		:= 0x59008000
CFG_PRODUCT_KERNEL_PARAMS_PHYS		:= 0x59000100
CFG_ONCHIP_FASTBOOT_ADDR                := 0x5F900000
CFG_RTX_KERNEL_ENTRY                    := 0x10000000
CFG_HI_SRAM_MEM_ADDR                    := 0x4fe00000
CFG_HI_SRAM_SIZE                		:= 0x100000
CFG_DRV_SRAM_ADDR               		:= (HI_SRAM_MEM_ADDR)
CFG_DRV_SRAM_SIZE						:= 0x100000
CFG_DDR_MEM_ADDR       		:= 0x50000000
CFG_DDR_MEM_SIZE       		:= 0x10000000
CFG_DDR_APP_ACP_ADDR            := (DDR_MEM_ADDR)
CFG_DDR_APP_ACP_SIZE            := 0x000000
CFG_DDR_GU_ADDR                 := ((DDR_APP_ACP_ADDR) + (DDR_APP_ACP_SIZE))
CFG_DDR_GU_SIZE                 := 0x00C0000
CFG_DDR_UPA_ADDR                := DDR_GU_ADDR
CFG_DDR_UPA_SIZE                := 0x00024000
CFG_DDR_CQI_ADDR                := ((DDR_UPA_ADDR) + (DDR_UPA_SIZE))
CFG_DDR_CQI_SIZE                := 0x00003400
CFG_DDR_APT_ADDR                := ((DDR_CQI_ADDR) + (DDR_CQI_SIZE))
CFG_DDR_APT_SIZE                := 0x00008400
CFG_DDR_ET_ADDR                 := ((DDR_APT_ADDR) + (DDR_APT_SIZE))
CFG_DDR_ET_SIZE                 := 0x00004800
CFG_DDR_NV_ADDR                 := ((DDR_ET_ADDR) + (DDR_ET_SIZE))
CFG_DDR_NV_SIZE                 := 0x00000000
CFG_DDR_ZSP_UP_ADDR             := ((DDR_NV_ADDR) + (DDR_NV_SIZE))
CFG_DDR_ZSP_UP_SIZE             := 0x00008000
CFG_DDR_ECS_TEE_ADDR            := ((DDR_ZSP_UP_ADDR) + (DDR_ZSP_UP_SIZE))
CFG_DDR_ECS_TEE_SIZE            := 0x00001800
CFG_DDR_RESERVE_ADDR            := ((DDR_ECS_TEE_ADDR) + (DDR_ECS_TEE_SIZE))
CFG_DDR_RESERVE_SIZE            := 0x00082800
CFG_DDR_TLPHY_IMAGE_ADDR     	:= ((DDR_RESERVE_ADDR) + (DDR_RESERVE_SIZE))
CFG_DDR_TLPHY_IMAGE_SIZE     	:= 0x340000
CFG_DDR_MCORE_ADDR              := (( DDR_TLPHY_IMAGE_ADDR ) + (DDR_TLPHY_IMAGE_SIZE))
CFG_DDR_MCORE_SIZE              := 0x7F00000
CFG_DDR_MCORE_DTS_ADDR          := ((DDR_MCORE_ADDR) + (DDR_MCORE_SIZE))
CFG_DDR_MCORE_DTS_SIZE          := 0x0100000
CFG_DDR_SHARED_MEM_ADDR         := ((DDR_MCORE_DTS_ADDR) + (DDR_MCORE_DTS_SIZE))
CFG_DDR_SHARED_MEM_SIZE         := 0x400000
CFG_DDR_MNTN_ADDR               := ((DDR_SHARED_MEM_ADDR) + (DDR_SHARED_MEM_SIZE))
CFG_DDR_MNTN_SIZE               := 0x100000
CFG_DDR_LPHY_SDR_ADDR           := ((DDR_MNTN_ADDR) + (DDR_MNTN_SIZE))
CFG_DDR_LPHY_SDR_SIZE           := 0x280000
CFG_DDR_LCS_ADDR                := ((DDR_LPHY_SDR_ADDR) + (DDR_LPHY_SDR_SIZE))
CFG_DDR_LCS_SIZE                := 0x280000
CFG_DDR_HIFI_ADDR               := ((DDR_LCS_ADDR) + (DDR_LCS_SIZE))
CFG_DDR_HIFI_SIZE               := 0x200000
CFG_DDR_ACORE_ADDR              := ((DDR_HIFI_ADDR) + (DDR_HIFI_SIZE))
CFG_DDR_ACORE_SIZE              := 0x2E00000
CFG_DDR_ACORE_DTS_ADDR          := ((DDR_ACORE_ADDR) + (DDR_ACORE_SIZE))
CFG_DDR_ACORE_DTS_SIZE          := 0x0100000
CFG_DDR_SOCP_ADDR               := ((DDR_ACORE_DTS_ADDR) + (DDR_ACORE_DTS_SIZE))
CFG_DDR_SOCP_SIZE               := 0x300000
CFG_DDR_MDM_ACP_ADDR            := ((DDR_SOCP_ADDR) + (DDR_SOCP_SIZE))
CFG_DDR_MDM_ACP_SIZE            := 0x0
CFG_GLOBAL_AXI_TEMP_PROTECT_ADDR        := 0x4FE1FF1C
CFG_GLOBAL_AXI_TEMP_PROTECT_SIZE        := (128)
CFG_DDR_HIFI_MBX_ADDR               := (DDR_SHARED_MEM_ADDR)
CFG_DDR_HIFI_MBX_SIZE               := (0X9800)
CFG_NV_DDR_SIZE                     := 0x200000
CFG_SHM_SIZE_HIFI_MBX               :=(DDR_HIFI_MBX_SIZE)
CFG_SHM_SIZE_HIFI                   :=(10*1024)
CFG_SHM_SIZE_TLPHY                  :=(12*1024)
CFG_SHM_SIZE_TEMPERATURE            :=(3*1024)
CFG_SHM_SIZE_DDM_LOAD               :=(1*1024)
CFG_SHM_SIZE_MEM_APPA9_PM_BOOT      :=(0x10000)
CFG_SHM_SIZE_MEM_MDMA9_PM_BOOT      :=(0x2000)
CFG_SHM_SIZE_TENCILICA_MULT_BAND    :=(0x8000)
CFG_SHM_SIZE_ICC                    :=(0x61800)
CFG_SHM_SIZE_IPF                    :=(0x10000)
CFG_SHM_SIZE_PSAM                   :=(0)
CFG_SHM_SIZE_WAN                    :=(0x8000)
CFG_SHM_SIZE_NV                     :=(NV_DDR_SIZE)
CFG_SHM_SIZE_M3_MNTN                :=(0x20000)
CFG_SHM_SIZE_TIMESTAMP              :=(1*1024)
CFG_SHM_SIZE_IOS                    :=(6*1024)
CFG_SHM_SIZE_RESTORE_AXI            :=(96*1024)
CFG_SHM_SIZE_PMU                    :=(3*1024)
CFG_SHM_SIZE_PTABLE                 :=(2*1024)
CFG_SHM_SIZE_CCORE_RESET            :=(0x400)
CFG_SHM_SIZE_PM_OM                  :=(256*1024)
CFG_SHM_SIZE_M3PM                   :=(0x1000)
CFG_SHM_SIZE_SLICE_MEM              :=(0x1000)
CFG_SHM_SIZE_OSA_LOG                :=(1024)
CFG_SHM_SIZE_WAS_LOG                :=(1024)
CFG_SHM_SIZE_SRAM_BAK               :=(0)
CFG_SHM_SIZE_SRAM_TO_DDR            :=(0)
CFG_SHM_SIZE_M3RSRACC_BD            :=(0)
CFG_SHM_SIZE_SIM_MEMORY             :=(256*1024)
CFG_FEATURE_ON                                  := 1
CFG_FEATURE_OFF                                 := 0
CFG_MEMORY_SIZE_32M                             := 1
CFG_MEMORY_SIZE_64M                             := 2
CFG_MEMORY_SIZE_128M                            := 3
CFG_MEMORY_SIZE_256M                            := 4
CFG_MEMORY_SIZE_512M                            := 5
CFG_FEATURE_HIFI_USE_ICC                        := FEATURE_OFF
CFG_FEATURE_MULTI_MODEM                         := FEATURE_OFF
CFG_FEATURE_SOCP_ON_DEMAND                      := FEATURE_OFF
CFG_FEATURE_SOCP_DECODE_INT_TIMEOUT             := FEATURE_OFF
CFG_FEATURE_RTOSCK                              := FEATURE_ON
CFG_FEATURE_VISP_VPP				:= FEATURE_ON
CFG_FEATURE_GU_DSP_SPLIT                        := FEATURE_OFF
CFG_FEATURE_UE_MODE_CDMA                        := FEATURE_OFF
CFG_FEATURE_CHINA_TELECOM_VOICE_ENCRYPT         := FEATURE_OFF
CFG_FEATURE_CHINA_TELECOM_VOICE_ENCRYPT_TEST_MODE  := FEATURE_OFF
CFG_FEATURE_BASTET                              := FEATURE_OFF
CFG_FEATURE_NV_PARTRION_MULTIPLEX               := FEATURE_ON
CFG_BBP_MASTER_INT_MODE                         := FEATURE_ON
CFG_FEATURE_PHONE_SC                            := FEATURE_OFF
CFG_FEATURE_SC_SEC_UPDATE                       := FEATURE_OFF
CFG_FEATURE_HUAWEI_VP                           := FEATURE_OFF
CFG_FEATURE_LTE_R11                        := FEATURE_ON
CFG_FEATURE_LTE_MBMS                       := FEATURE_OFF
CFG_FEATURE_LTE_NAS_R11                    := FEATURE_OFF
CFG_FEATURE_LPP                            := FEATURE_OFF
CFG_FEATURE_LTE_CDMA_R11                   := FEATURE_OFF
CFG_FEATURE_BALONG_CL                      := FEATURE_UE_MODE_CDMA
CFG_FEATURE_TDS_WCDMA_DYNAMIC_LOAD         := FEATURE_OFF
CFG_FEATURE_CSG                            := FEATURE_OFF
CFG_FEATURE_CSS_CLOUD_MEMORY_IMPROVE           := FEATURE_OFF
CFG_FEATURE_TLPHY_ET                    := FEATURE_OFF
CFG_FEATURE_TLPHY_DPD                   := FEATURE_OFF
