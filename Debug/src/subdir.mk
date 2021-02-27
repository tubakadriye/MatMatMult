################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/before_fussion_ikj.c \
../src/blocking2_ijk.c \
../src/blocking3_ijk.c \
../src/cache_blocking_and_loop_unrolling_ijk.c \
../src/cache_blocking_and_loop_unrolling_ikj.c \
../src/cache_blocking_ijk.c \
../src/cache_blocking_ikj.c \
../src/copy_a_ikj.c \
../src/copy_b_jki.c \
../src/fill_one_d_mat.c \
../src/ijk.c \
../src/ikj.c \
../src/ikj_cache_blocking_new.c \
../src/jik.c \
../src/jki.c \
../src/kij.c \
../src/kji.c \
../src/loop_unrolling_and_copy_a_ikj_devectorization.c \
../src/loop_unrolling_and_copyb_jki.c \
../src/loop_unrolling_ijk.c \
../src/loop_unrolling_ikj.c \
../src/loop_unrolling_jki.c \
../src/main_cache_blocking_and_loop_unrolling_w_header.c \
../src/matmult.c \
../src/print_one_d_mat.c \
../src/procedure_inlining_and_devectorization_ikj.c \
../src/procedure_inlining_ijk.c \
../src/procedure_inlining_ikj.c \
../src/transpose.c 

OBJS += \
./src/before_fussion_ikj.o \
./src/blocking2_ijk.o \
./src/blocking3_ijk.o \
./src/cache_blocking_and_loop_unrolling_ijk.o \
./src/cache_blocking_and_loop_unrolling_ikj.o \
./src/cache_blocking_ijk.o \
./src/cache_blocking_ikj.o \
./src/copy_a_ikj.o \
./src/copy_b_jki.o \
./src/fill_one_d_mat.o \
./src/ijk.o \
./src/ikj.o \
./src/ikj_cache_blocking_new.o \
./src/jik.o \
./src/jki.o \
./src/kij.o \
./src/kji.o \
./src/loop_unrolling_and_copy_a_ikj_devectorization.o \
./src/loop_unrolling_and_copyb_jki.o \
./src/loop_unrolling_ijk.o \
./src/loop_unrolling_ikj.o \
./src/loop_unrolling_jki.o \
./src/main_cache_blocking_and_loop_unrolling_w_header.o \
./src/matmult.o \
./src/print_one_d_mat.o \
./src/procedure_inlining_and_devectorization_ikj.o \
./src/procedure_inlining_ijk.o \
./src/procedure_inlining_ikj.o \
./src/transpose.o 

C_DEPS += \
./src/before_fussion_ikj.d \
./src/blocking2_ijk.d \
./src/blocking3_ijk.d \
./src/cache_blocking_and_loop_unrolling_ijk.d \
./src/cache_blocking_and_loop_unrolling_ikj.d \
./src/cache_blocking_ijk.d \
./src/cache_blocking_ikj.d \
./src/copy_a_ikj.d \
./src/copy_b_jki.d \
./src/fill_one_d_mat.d \
./src/ijk.d \
./src/ikj.d \
./src/ikj_cache_blocking_new.d \
./src/jik.d \
./src/jki.d \
./src/kij.d \
./src/kji.d \
./src/loop_unrolling_and_copy_a_ikj_devectorization.d \
./src/loop_unrolling_and_copyb_jki.d \
./src/loop_unrolling_ijk.d \
./src/loop_unrolling_ikj.d \
./src/loop_unrolling_jki.d \
./src/main_cache_blocking_and_loop_unrolling_w_header.d \
./src/matmult.d \
./src/print_one_d_mat.d \
./src/procedure_inlining_and_devectorization_ikj.d \
./src/procedure_inlining_ijk.d \
./src/procedure_inlining_ikj.d \
./src/transpose.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


