################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCP23S17/MCP23S17.c 

OBJS += \
./MCP23S17/MCP23S17.o 

C_DEPS += \
./MCP23S17/MCP23S17.d 


# Each subdirectory must supply rules for building sources it contributes
MCP23S17/%.o: ../MCP23S17/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


