################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/subdir.mk
-include Core/ioLibrary/Internet/httpServer/subdir.mk
-include Core/ioLibrary/Internet/TFTP/subdir.mk
-include Core/ioLibrary/Internet/SNTP/subdir.mk
-include Core/ioLibrary/Internet/SNMP/subdir.mk
-include Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
-include Core/ioLibrary/Internet/MQTT/subdir.mk
-include Core/ioLibrary/Internet/FTPServer/subdir.mk
-include Core/ioLibrary/Internet/FTPClient/subdir.mk
-include Core/ioLibrary/Internet/DNS/subdir.mk
-include Core/ioLibrary/Internet/DHCP/subdir.mk
-include Core/ioLibrary/Ethernet/W5500/subdir.mk
-include Core/ioLibrary/Ethernet/W5300/subdir.mk
-include Core/ioLibrary/Ethernet/W5200/subdir.mk
-include Core/ioLibrary/Ethernet/W5100S/subdir.mk
-include Core/ioLibrary/Ethernet/W5100/subdir.mk
-include Core/ioLibrary/Ethernet/subdir.mk
-include Core/ioLibrary/Application/multicast/subdir.mk
-include Core/ioLibrary/Application/loopback/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := zet6net
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
zet6net.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
zet6net.list \

OBJCOPY_BIN += \
zet6net.bin \


# All Target
all: main-build

# Main-build Target
main-build: zet6net.elf secondary-outputs

# Tool invocations
zet6net.elf: $(OBJS) $(USER_OBJS) /Users/siminggao/Desktop/zet6/STM32F103ZETx_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "zet6net.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"/Users/siminggao/Desktop/zet6/STM32F103ZETx_FLASH.ld" --specs=nosys.specs -Wl,-Map="zet6net.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

zet6net.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "zet6net.list"
	@echo 'Finished building: $@'
	@echo ' '

zet6net.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "zet6net.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
