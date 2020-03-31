################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BinarySearchTree.cpp \
../src/Binary_Search_tree.cpp \
../src/Node.cpp 

OBJS += \
./src/BinarySearchTree.o \
./src/Binary_Search_tree.o \
./src/Node.o 

CPP_DEPS += \
./src/BinarySearchTree.d \
./src/Binary_Search_tree.d \
./src/Node.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


