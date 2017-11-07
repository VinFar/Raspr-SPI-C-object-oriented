################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Circle.c \
../Rect.c \
../SPI.c \
../Shape.c \
../main_oo.c 

OBJS += \
./Circle.o \
./Rect.o \
./SPI.o \
./Shape.o \
./main_oo.o 

C_DEPS += \
./Circle.d \
./Rect.d \
./SPI.d \
./Shape.d \
./main_oo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


