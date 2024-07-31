################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/button.c \
../Inc/clock.c \
../Inc/led.c \
../Inc/pwm.c \
../Inc/usart.c 

OBJS += \
./Inc/button.o \
./Inc/clock.o \
./Inc/led.o \
./Inc/pwm.o \
./Inc/usart.o 

C_DEPS += \
./Inc/button.d \
./Inc/clock.d \
./Inc/led.d \
./Inc/pwm.d \
./Inc/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/button.cyclo ./Inc/button.d ./Inc/button.o ./Inc/button.su ./Inc/clock.cyclo ./Inc/clock.d ./Inc/clock.o ./Inc/clock.su ./Inc/led.cyclo ./Inc/led.d ./Inc/led.o ./Inc/led.su ./Inc/pwm.cyclo ./Inc/pwm.d ./Inc/pwm.o ./Inc/pwm.su ./Inc/usart.cyclo ./Inc/usart.d ./Inc/usart.o ./Inc/usart.su

.PHONY: clean-Inc

