# List of the ChibiOS generic NuMicro NUC122 startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v6m.S

STARTUPINC = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/devices/NUC122 \
             $(CHIBIOS_CONTRIB)/os/common/ext/CMSIS/NUMICRO \
             $(CHIBIOS)/os/common/ext/CMSIS/include

STARTUPLD  = $(CHIBIOS_CONTRIB)/os/common/startup/ARMCMx/compilers/GCC/ld
