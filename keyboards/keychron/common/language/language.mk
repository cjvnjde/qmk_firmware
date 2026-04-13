LANGUAGE_DIR = $(TOP_DIR)/keyboards/keychron/common/language
SRC += \
     $(LANGUAGE_DIR)/language.c \

VPATH += $(LANGUAGE_DIR)

OPT_DEFS += -DLANGUAGE_ENABLE
