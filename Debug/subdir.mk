################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LED_Stripe.c \
../ldr_print.c \
../main_oo.c 

OBJS += \
./LED_Stripe.o \
./ldr_print.o \
./main_oo.o 

C_DEPS += \
./LED_Stripe.d \
./ldr_print.d \
./main_oo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


