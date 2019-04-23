
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name LED_stream -dir "D:/Xilinx/workspace/LED_stream/LED_stream/planAhead_run_1" -part xc6vlx240tff1156-1
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/Xilinx/workspace/LED_stream/LED_stream/LED.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/Xilinx/workspace/LED_stream/LED_stream} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "LED.ucf" [current_fileset -constrset]
add_files [list {LED.ucf}] -fileset [get_property constrset [current_run]]
link_design
