################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/ChainManager.o \
../src/chainfunctions.o 

CPP_SRCS += \
../src/ChainManager.cpp \
../src/chainfunctions.cpp \
../src/chains.cpp 

OBJS += \
./src/ChainManager.o \
./src/chainfunctions.o \
./src/chains.o 

CPP_DEPS += \
./src/ChainManager.d \
./src/chainfunctions.d \
./src/chains.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


