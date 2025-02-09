SRC += $(USER_PATH)/lorech.c \
       $(USER_PATH)/keyrecords/mods.c \
       $(USER_PATH)/keyrecords/process_records.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
SRC += $(USER_PATH)/keyrecords/tap_dance.c
endif
