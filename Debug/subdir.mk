################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Circle.c \
../MCP3204.c \
../Rect.c \
../Shape.c \
../main_oo.c 

OBJS += \
./Circle.o \
./MCP3204.o \
./Rect.o \
./Shape.o \
./main_oo.o 

C_DEPS += \
./Circle.d \
./MCP3204.d \
./Rect.d \
./Shape.d \
./main_oo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


