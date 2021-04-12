################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTFormat.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTPacket.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.c \
../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.c 

OBJS += \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTFormat.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTPacket.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.o \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.o 

C_DEPS += \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTFormat.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTPacket.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.d \
./Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectClient.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTConnectServer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTDeserializePublish.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTFormat.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTFormat.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTFormat.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTPacket.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTPacket.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTPacket.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSerializePublish.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeClient.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTSubscribeServer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeClient.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.o: ../Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.c Core/ioLibrary/Internet/MQTT/MQTTPacket/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xE -DDEBUG -DUSE_HAL_DRIVER -c -I../Core/ioLibrary/Ethernet/W5500 -I../Core/ioLibrary/Application/loopback -I../Core/ioLibrary/Ethernet -I../Core/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/CMSIS/Include -I/Users/siminggao/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.3/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/ioLibrary/Internet/MQTT/MQTTPacket/src/MQTTUnsubscribeServer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

