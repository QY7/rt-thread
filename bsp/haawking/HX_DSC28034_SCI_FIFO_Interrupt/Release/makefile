################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include rt-thread/components/drivers/serial/subdir.mk
-include rt-thread/components/drivers/misc/subdir.mk
-include rt-thread/components/drivers/ipc/subdir.mk
-include haawking-drivers/haawking-dsc28034_bbb-board/common/subdir.mk
-include haawking-drivers/haawking-dsc28034_bbb-board/DSP2803x_headers/source/subdir.mk
-include haawking-drivers/haawking-dsc28034_bbb-board/DSP2803x_common/source/subdir.mk
-include application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
HX_DSC28034_SCI_FIFO_Interrupt.hex \

SECONDARY_SIZE += \
HX_DSC28034_SCI_FIFO_Interrupt.siz \


# All Target
all: HX_DSC28034_SCI_FIFO_Interrupt.elf secondary-outputs

# Tool invocations
HX_DSC28034_SCI_FIFO_Interrupt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	riscv32-haawking-elf-gcc -march=rv32imc -D__RUNNING_IN_FLASH_ -T DSC28034_BBB_link_FLASH.ld -mabi=ilp32 -mcmodel=medlow -msave-restore --target=riscv32-unknown-elf --sysroot="D:/Software/Haawking/Haawking-IDE-win64-V2.0.0/haawking-tools/compiler/riscv-tc-gcc/riscv64-unknown-elf" --gcc-toolchain="D:/Software/Haawking/Haawking-IDE-win64-V2.0.0/haawking-tools/compiler/riscv-tc-gcc" -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-inline-functions -Wall -Wextra  -g -Wl,--defsym,IDE_VERSION_1_9_2=0 -nostartfiles -nostdlib -Xlinker --gc-sections -L"../haawking-drivers/ldscripts" -L"D:/Software/Haawking/Haawking-IDE-win64-V2.0.0//haawking-tools/haawking-devices-libs/dsc28034" -Wl,-Map,"HX_DSC28034_SCI_FIFO_Interrupt.map" -o "HX_DSC28034_SCI_FIFO_Interrupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'

HX_DSC28034_SCI_FIFO_Interrupt.hex: HX_DSC28034_SCI_FIFO_Interrupt.elf
	@riscv32-haawking-elf-objcopy -O ihex "HX_DSC28034_SCI_FIFO_Interrupt.elf"  "HX_DSC28034_SCI_FIFO_Interrupt.hex"

HX_DSC28034_SCI_FIFO_Interrupt.siz: HX_DSC28034_SCI_FIFO_Interrupt.elf
	riscv32-haawking-elf-size --format=berkeley "HX_DSC28034_SCI_FIFO_Interrupt.elf"

# Other Targets
clean:
	-$(RM) $(SECONDARY_LLVMASM)$(SECONDARY_GCCASM)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) HX_DSC28034_SCI_FIFO_Interrupt.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
