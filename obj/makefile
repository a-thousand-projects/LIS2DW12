################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
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
LIS2WD12.hex \

SECONDARY_LIST += \
LIS2WD12.lst \

SECONDARY_SIZE += \
LIS2WD12.siz \


# All Target
all: LIS2WD12.elf secondary-outputs

# Tool invocations
LIS2WD12.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "C:\MRS_DATA\workspace\LIS2WD12\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"LIS2WD12.map" --specs=nano.specs --specs=nosys.specs -o "LIS2WD12.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lprintf
	@	@
LIS2WD12.hex: LIS2WD12.elf
	@	riscv-none-embed-objcopy -O ihex "LIS2WD12.elf"  "LIS2WD12.hex"
	@	@
LIS2WD12.lst: LIS2WD12.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "LIS2WD12.elf" > "LIS2WD12.lst"
	@	@
LIS2WD12.siz: LIS2WD12.elf
	@	riscv-none-embed-size --format=berkeley "LIS2WD12.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) LIS2WD12.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
