################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ioLibrary/Internet/httpServer/httpParser.c \
../Core/ioLibrary/Internet/httpServer/httpServer.c \
../Core/ioLibrary/Internet/httpServer/httpUtil.c 

OBJS += \
./Core/ioLibrary/Internet/httpServer/httpParser.o \
./Core/ioLibrary/Internet/httpServer/httpServer.o \
./Core/ioLibrary/Internet/httpServer/httpUtil.o 

C_DEPS += \
./Core/ioLibrary/Internet/httpServer/httpParser.d \
./Core/ioLibrary/Internet/httpServer/httpServer.d \
./Core/ioLibrary/Internet/httpServer/httpUtil.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ioLibrary/Internet/httpServer/httpParser.o: ../Core/ioLibrary/Internet/httpServer/httpParser.c Core/ioLibrary/Internet/httpServer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/httpServer/httpParser.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/httpServer/httpServer.o: ../Core/ioLibrary/Internet/httpServer/httpServer.c Core/ioLibrary/Internet/httpServer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/httpServer/httpServer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/httpServer/httpUtil.o: ../Core/ioLibrary/Internet/httpServer/httpUtil.c Core/ioLibrary/Internet/httpServer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/httpServer/httpUtil.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

