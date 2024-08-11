################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v00x_it.c \
../User/leds.c \
../User/main.c \
../User/system.c \
../User/system_ch32v00x.c 

OBJS += \
./User/ch32v00x_it.o \
./User/leds.o \
./User/main.o \
./User/system.o \
./User/system_ch32v00x.o 

C_DEPS += \
./User/ch32v00x_it.d \
./User/leds.d \
./User/main.d \
./User/system.d \
./User/system_ch32v00x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32V003F4P6test\Debug" -I"C:\MRS_DATA\workspace\CH32V003F4P6test\Core" -I"C:\MRS_DATA\workspace\CH32V003F4P6test\User" -I"C:\MRS_DATA\workspace\CH32V003F4P6test\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

