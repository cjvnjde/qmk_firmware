SNAP_CLICK_DIR = $(TOP_DIR)/keyboards/keychron/common/snap_click
SRC += \
     $(SNAP_CLICK_DIR)/snap_click.c \

VPATH += $(SNAP_CLICK_DIR)

OPT_DEFS += -DSNAP_CLICK_ENABLE
