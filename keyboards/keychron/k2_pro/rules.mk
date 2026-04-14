# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# Work around RTC clock issue without touching chibios
OPT_DEFS += -DRCC_APBENR1_RTCAPBEN

SRC += keyboards/keychron/k2_pro/matrix.c

include keyboards/keychron/common/wireless/bluetooth.mk
include keyboards/keychron/common/keychron_common.mk

VPATH += $(TOP_DIR)/keyboards/keychron
