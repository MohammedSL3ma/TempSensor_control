################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer_V2/subdir.mk
-include MCAL/DIO_V1/subdir.mk
-include MCAL/ADC_V1/subdir.mk
-include HAL/LM35_tempSen/subdir.mk
-include HAL/LCD_Handler/subdir.mk
-include HAL/DCM/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
LSS += \
TempSensor_Project.lss \

FLASH_IMAGE += \
TempSensor_Project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TempSensor_Project.elf secondary-outputs

# Tool invocations
TempSensor_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TempSensor_Project.map -mmcu=atmega32 -o "TempSensor_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TempSensor_Project.lss: TempSensor_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TempSensor_Project.elf  >"TempSensor_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

TempSensor_Project.hex: TempSensor_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TempSensor_Project.elf  "TempSensor_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TempSensor_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TempSensor_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TempSensor_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
