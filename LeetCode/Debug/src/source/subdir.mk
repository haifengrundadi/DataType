################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/source/LeetCode021.cpp \
../src/source/LeetCode104.cpp \
../src/source/LeetCode136.cpp \
../src/source/LeetCode237.cpp 

OBJS += \
./src/source/LeetCode021.o \
./src/source/LeetCode104.o \
./src/source/LeetCode136.o \
./src/source/LeetCode237.o 

CPP_DEPS += \
./src/source/LeetCode021.d \
./src/source/LeetCode104.d \
./src/source/LeetCode136.d \
./src/source/LeetCode237.d 


# Each subdirectory must supply rules for building sources it contributes
src/source/%.o: ../src/source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


