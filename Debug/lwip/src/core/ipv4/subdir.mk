################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/core/ipv4/acd.c \
../lwip/src/core/ipv4/autoip.c \
../lwip/src/core/ipv4/dhcp.c \
../lwip/src/core/ipv4/etharp.c \
../lwip/src/core/ipv4/icmp.c \
../lwip/src/core/ipv4/igmp.c \
../lwip/src/core/ipv4/ip4.c \
../lwip/src/core/ipv4/ip4_addr.c \
../lwip/src/core/ipv4/ip4_frag.c 

C_DEPS += \
./lwip/src/core/ipv4/acd.d \
./lwip/src/core/ipv4/autoip.d \
./lwip/src/core/ipv4/dhcp.d \
./lwip/src/core/ipv4/etharp.d \
./lwip/src/core/ipv4/icmp.d \
./lwip/src/core/ipv4/igmp.d \
./lwip/src/core/ipv4/ip4.d \
./lwip/src/core/ipv4/ip4_addr.d \
./lwip/src/core/ipv4/ip4_frag.d 

OBJS += \
./lwip/src/core/ipv4/acd.o \
./lwip/src/core/ipv4/autoip.o \
./lwip/src/core/ipv4/dhcp.o \
./lwip/src/core/ipv4/etharp.o \
./lwip/src/core/ipv4/icmp.o \
./lwip/src/core/ipv4/igmp.o \
./lwip/src/core/ipv4/ip4.o \
./lwip/src/core/ipv4/ip4_addr.o \
./lwip/src/core/ipv4/ip4_frag.o 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/core/ipv4/%.o: ../lwip/src/core/ipv4/%.c lwip/src/core/ipv4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -D_POSIX_SOURCE -DXIP_BOOT_HEADER_DCD_ENABLE=1 -DUSE_SDRAM -DDATA_SECTION_IS_CACHEABLE=1 -DCPU_MIMXRT1166DVM6A_cm7 -DSDK_DEBUGCONSOLE=1 -DXIP_EXTERNAL_FLASH=1 -DXIP_BOOT_HEADER_ENABLE=1 -DLWIP_ENET_FLEXIBLE_CONFIGURATION -DFSL_SDK_ENABLE_DRIVER_CACHE_CONTROL=1 -DFSL_FEATURE_PHYKSZ8081_USE_RMII50M_MODE -DUSE_RTOS=1 -DPRINTF_ADVANCED_ENABLE=1 -DFSL_SDK_DRIVER_QUICK_ACCESS_ENABLE=1 -DLWIP_DISABLE_PBUF_POOL_SIZE_SANITY_CHECKS=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DCPU_MIMXRT1166DVM6A -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\component\phy" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\component\silicon_id" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\drivers" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\lwip\port" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\lwip\src" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\lwip\src\include" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\lwip\src\include\lwip\apps" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\device" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\utilities" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\component\uart" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\component\serial_manager" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\component\lists" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\startup" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\xip" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\CMSIS" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\freertos\freertos-kernel\include" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\drivers\freertos" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\source" -I"C:\Users\os\Documents\MCUXpressoIDE_11.8.0_1165\2_13_RT1160\evkmimxrt1160_lwip_mqtt_freertos_cm7\board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lwip-2f-src-2f-core-2f-ipv4

clean-lwip-2f-src-2f-core-2f-ipv4:
	-$(RM) ./lwip/src/core/ipv4/acd.d ./lwip/src/core/ipv4/acd.o ./lwip/src/core/ipv4/autoip.d ./lwip/src/core/ipv4/autoip.o ./lwip/src/core/ipv4/dhcp.d ./lwip/src/core/ipv4/dhcp.o ./lwip/src/core/ipv4/etharp.d ./lwip/src/core/ipv4/etharp.o ./lwip/src/core/ipv4/icmp.d ./lwip/src/core/ipv4/icmp.o ./lwip/src/core/ipv4/igmp.d ./lwip/src/core/ipv4/igmp.o ./lwip/src/core/ipv4/ip4.d ./lwip/src/core/ipv4/ip4.o ./lwip/src/core/ipv4/ip4_addr.d ./lwip/src/core/ipv4/ip4_addr.o ./lwip/src/core/ipv4/ip4_frag.d ./lwip/src/core/ipv4/ip4_frag.o

.PHONY: clean-lwip-2f-src-2f-core-2f-ipv4

