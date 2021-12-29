################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Project-8/%.obj: ../Project-8/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/yamas/workspace_v11/Lab9" --include_path="C:/Users/yamas/workspace_v11/Lab9/include" --include_path="C:/ti/TivaWare_C_Series-2.2.0.295" --include_path="C:/ti/ccs1040/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Project-8/$(basename $(<F)).d_raw" --obj_directory="Project-8" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


