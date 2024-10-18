################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_WPAN/Target/hw_ipcc.c 

OBJS += \
./STM32_WPAN/Target/hw_ipcc.o 

C_DEPS += \
./STM32_WPAN/Target/hw_ipcc.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_WPAN/Target/%.o STM32_WPAN/Target/%.su STM32_WPAN/Target/%.cyclo: ../STM32_WPAN/Target/%.c STM32_WPAN/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DZIGBEE_WB -DUSE_HAL_DRIVER -DSTM32WB55xx -c -I../Core/Inc -I../STM32_WPAN/App -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/STM32WBxx_HAL_Driver/Inc -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Utilities/lpm/tiny_lpm -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/zigbee/stack/include/extras -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zgp -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Utilities/sequencer -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/mac -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/key -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/se -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/security -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/general -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/platform -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/core/inc -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-STM32_WPAN-2f-Target

clean-STM32_WPAN-2f-Target:
	-$(RM) ./STM32_WPAN/Target/hw_ipcc.cyclo ./STM32_WPAN/Target/hw_ipcc.d ./STM32_WPAN/Target/hw_ipcc.o ./STM32_WPAN/Target/hw_ipcc.su

.PHONY: clean-STM32_WPAN-2f-Target

