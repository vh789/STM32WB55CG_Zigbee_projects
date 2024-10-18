################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app_entry.c \
../Core/Src/hw_timerserver.c \
../Core/Src/main.c \
../Core/Src/stm32_lpm_if.c \
../Core/Src/stm32wbxx_hal_msp.c \
../Core/Src/stm32wbxx_it.c \
../Core/Src/stm_logging.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32wbxx.c 

OBJS += \
./Core/Src/app_entry.o \
./Core/Src/hw_timerserver.o \
./Core/Src/main.o \
./Core/Src/stm32_lpm_if.o \
./Core/Src/stm32wbxx_hal_msp.o \
./Core/Src/stm32wbxx_it.o \
./Core/Src/stm_logging.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32wbxx.o 

C_DEPS += \
./Core/Src/app_entry.d \
./Core/Src/hw_timerserver.d \
./Core/Src/main.d \
./Core/Src/stm32_lpm_if.d \
./Core/Src/stm32wbxx_hal_msp.d \
./Core/Src/stm32wbxx_it.d \
./Core/Src/stm_logging.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32wbxx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DZIGBEE_WB -DUSE_HAL_DRIVER -DSTM32WB55xx -c -I../Core/Inc -I../STM32_WPAN/App -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/STM32WBxx_HAL_Driver/Inc -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Utilities/lpm/tiny_lpm -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/utilities -I../Middlewares/ST/STM32_WPAN/zigbee/stack/include/extras -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zgp -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Utilities/sequencer -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/mac -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/key -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/se -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/security -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/stack/include/zcl/general -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/platform -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Middlewares/ST/STM32_WPAN/zigbee/core/inc -IC:/Users/valen/STM32Cube/Repository/STM32Cube_FW_WB_V1.20.0/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app_entry.cyclo ./Core/Src/app_entry.d ./Core/Src/app_entry.o ./Core/Src/app_entry.su ./Core/Src/hw_timerserver.cyclo ./Core/Src/hw_timerserver.d ./Core/Src/hw_timerserver.o ./Core/Src/hw_timerserver.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32_lpm_if.cyclo ./Core/Src/stm32_lpm_if.d ./Core/Src/stm32_lpm_if.o ./Core/Src/stm32_lpm_if.su ./Core/Src/stm32wbxx_hal_msp.cyclo ./Core/Src/stm32wbxx_hal_msp.d ./Core/Src/stm32wbxx_hal_msp.o ./Core/Src/stm32wbxx_hal_msp.su ./Core/Src/stm32wbxx_it.cyclo ./Core/Src/stm32wbxx_it.d ./Core/Src/stm32wbxx_it.o ./Core/Src/stm32wbxx_it.su ./Core/Src/stm_logging.cyclo ./Core/Src/stm_logging.d ./Core/Src/stm_logging.o ./Core/Src/stm_logging.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32wbxx.cyclo ./Core/Src/system_stm32wbxx.d ./Core/Src/system_stm32wbxx.o ./Core/Src/system_stm32wbxx.su

.PHONY: clean-Core-2f-Src

