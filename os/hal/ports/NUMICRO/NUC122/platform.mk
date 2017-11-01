ifeq ($(USE_SMART_BUILD),yes)
HALCONF := $(strip $(shell cat halconf.h halconf_community.h 2>/dev/null | egrep -e "define"))

# List of all the NUMICRO1x platform files.
PLATFORMSRC  = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_st_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_lld.c

ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_pal_lld.c
endif
ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_serial_lld.c
endif
ifneq ($(findstring HAL_USE_USB TRUE,$(HALCONF)),)
PLATFORMSRC += ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_usb_lld.c
endif
else
PLATFORMSRC  = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_pal_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_serial_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_st_lld.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_usb_lld.c
endif

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/NUC122 \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD


