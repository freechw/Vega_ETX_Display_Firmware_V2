################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/PollingRoutine.c \
../Core/Src/RingBuff.c \
../Core/Src/can.c \
../Core/Src/can_matrix.c \
../Core/Src/data_structures.c \
../Core/Src/errLogging.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/menu.c \
../Core/Src/state_machine.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/test_functions.c \
../Core/Src/tim.c \
../Core/Src/timer.c \
../Core/Src/transmit.c \
../Core/Src/transmitDefinitions.c \
../Core/Src/usart.c \
../Core/Src/vehicleControl.c 

OBJS += \
./Core/Src/PollingRoutine.o \
./Core/Src/RingBuff.o \
./Core/Src/can.o \
./Core/Src/can_matrix.o \
./Core/Src/data_structures.o \
./Core/Src/errLogging.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/menu.o \
./Core/Src/state_machine.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/test_functions.o \
./Core/Src/tim.o \
./Core/Src/timer.o \
./Core/Src/transmit.o \
./Core/Src/transmitDefinitions.o \
./Core/Src/usart.o \
./Core/Src/vehicleControl.o 

C_DEPS += \
./Core/Src/PollingRoutine.d \
./Core/Src/RingBuff.d \
./Core/Src/can.d \
./Core/Src/can_matrix.d \
./Core/Src/data_structures.d \
./Core/Src/errLogging.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/menu.d \
./Core/Src/state_machine.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/test_functions.d \
./Core/Src/tim.d \
./Core/Src/timer.d \
./Core/Src/transmit.d \
./Core/Src/transmitDefinitions.d \
./Core/Src/usart.d \
./Core/Src/vehicleControl.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F105xC -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/PollingRoutine.d ./Core/Src/PollingRoutine.o ./Core/Src/PollingRoutine.su ./Core/Src/RingBuff.d ./Core/Src/RingBuff.o ./Core/Src/RingBuff.su ./Core/Src/can.d ./Core/Src/can.o ./Core/Src/can.su ./Core/Src/can_matrix.d ./Core/Src/can_matrix.o ./Core/Src/can_matrix.su ./Core/Src/data_structures.d ./Core/Src/data_structures.o ./Core/Src/data_structures.su ./Core/Src/errLogging.d ./Core/Src/errLogging.o ./Core/Src/errLogging.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/menu.d ./Core/Src/menu.o ./Core/Src/menu.su ./Core/Src/state_machine.d ./Core/Src/state_machine.o ./Core/Src/state_machine.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/test_functions.d ./Core/Src/test_functions.o ./Core/Src/test_functions.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/timer.d ./Core/Src/timer.o ./Core/Src/timer.su ./Core/Src/transmit.d ./Core/Src/transmit.o ./Core/Src/transmit.su ./Core/Src/transmitDefinitions.d ./Core/Src/transmitDefinitions.o ./Core/Src/transmitDefinitions.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/vehicleControl.d ./Core/Src/vehicleControl.o ./Core/Src/vehicleControl.su

.PHONY: clean-Core-2f-Src

