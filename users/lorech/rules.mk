CONFIG_H += $(USER_PATH)/_config.h

SRC += $(USER_PATH)/lorech.c \
       $(USER_PATH)/keyrecords/mods.c \
       $(USER_PATH)/keyrecords/process_records.c

ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
SRC += $(USER_PATH)/keyrecords/caps_word.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
SRC += $(USER_PATH)/keyrecords/tap_dance.c
endif
