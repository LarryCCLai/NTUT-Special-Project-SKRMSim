#workload A: uniform #data:1E6 #operation: 1E7
#==========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/configFile/Naive_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/Naive_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/Naive_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/Naive_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
#DCW
$(./debug/bin/simulator -r ./config/configFile/DCW_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/DCW_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/DCW_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/DCW_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
#FNW
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
#==========================================================================================
#workload B: zipf #data:1E6 #operation: 1E7
#==========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/configFile/Naive_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/Naive_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/Naive_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/Naive_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
#DCW
$(./debug/bin/simulator -r ./config/configFile/DCW_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/DCW_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/DCW_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/DCW_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
#FNW
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
#==========================================================================================