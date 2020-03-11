# Configuration files directory
ifeq ($(CONFDIR),)
  CONFDIR = .
endif

HALCONF := $(strip $(shell cat $(CONFDIR)/halconf.h $(CONFDIR)/halconf_community.h | egrep -e "\#define"))

# List of all the NUMICRO1x platform files.
PLATFORMSRC  = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
               ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD/hal_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/NUC121 \
              ${CHIBIOS_CONTRIB}/os/hal/ports/NUMICRO/LLD

# Drivers compatible with the platform.
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/GPIOv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/TIMv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/UARTv1/driver.mk
include $(CHIBIOS_CONTRIB)/os/hal/ports/NUMICRO/LLD/USBv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)
