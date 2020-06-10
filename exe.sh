printf "Simulation start.\n"
printf "    [Workload A] Data distribution: uniform #data:1E6 #operation: 1E7 \n"
#workload A: uniform #data:1E6 #operation: 1E7
#==========================================================================================
#Naive
printf "        Write strategy: \"Naive\" \n"
printf "            Track capacity: 512, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
printf "completed\n"

#DCW
printf "        Write strategy: \"DCW\" \n"
printf "            Track capacity: 512, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
printf "completed\n"

#FNW
printf "        Write strategy: \"FNW\" \n"
printf "            Track capacity: 512, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
printf "completed\n"

#M-out-of-N-Write
printf "        Write strategy: \"M-out-of-N Write\" \n"
printf "            Track capacity: 512, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
printf "completed\n"
printf "        Write strategy: \"M-out-of-N Write\" \n"
printf "            Track capacity: 512, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_512.txt ./requests/requestFiles/workload_uniform_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_1024.txt ./requests/requestFiles/workload_uniform_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_2048.txt ./requests/requestFiles/workload_uniform_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_4096.txt ./requests/requestFiles/workload_uniform_1E6_1_64.txt)
printf "completed\n\n"


#==========================================================================================
printf "    [Workload B] Data distribution: zipf #data: 1E6 #operation: 1E7 \n"
#workload B: zipf #data:1E6 #operation: 1E7
#==========================================================================================
#Naive
printf "        Write strategy: \"Naive\" \n"
printf "            Track capacity: 512, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Naive_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
printf "completed\n"

#DCW
printf "        Write strategy: \"DCW\" \n"
printf "            Track capacity: 512, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/DCW_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
printf "completed\n"

#FNW
printf "        Write strategy: \"FNW\" \n"
printf "            Track capacity: 512, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 64....."
$(./debug/bin/simulator -r ./config/configFile/Flip_N_Write_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
printf "completed\n"

#M-out-of-N-Write
printf "        Write strategy: \"M-out-of-N Write\" \n"
printf "            Track capacity: 512, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 8....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_8_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
printf "completed\n"
printf "            Track capacity: 512, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_512.txt ./requests/requestFiles/workload_zipf_1E6_1_8.txt)
printf "completed\n"
printf "            Track capacity: 1024, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_1024.txt ./requests/requestFiles/workload_zipf_1E6_1_16.txt)
printf "completed\n"
printf "            Track capacity: 2048, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_2048.txt ./requests/requestFiles/workload_zipf_1E6_1_32.txt)
printf "completed\n"
printf "            Track capacity: 4096, data segment capacity: 16....."
$(./debug/bin/simulator -r ./config/configFile/MOutOfNWrite_16_4096.txt ./requests/requestFiles/workload_zipf_1E6_1_64.txt)
printf "completed\n\n"
#==========================================================================================

printf "Simulation End.\n"

printf "All result files are exported to \'SK-RMSim\outputFile\'. \n"