#workload A: uniform #data:1E6 #operation: 1E7
#===========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/Naive_512.txt ./requests/requests_workload_uniform_1E6_1_8.txt ./result/Naive_512_uniform_1E6.txt ./outputParams/Naive_512_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Naive_1024.txt ./requests/requests_workload_uniform_1E6_1_16.txt ./result/Naive_1024_uniform_1E6.txt ./outputParams/Naive_1024_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Naive_2048.txt ./requests/requests_workload_uniform_1E6_1_32.txt ./result/Naive_2048_uniform_1E6.txt ./outputParams/Naive_2048_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Naive_4096.txt ./requests/requests_workload_uniform_1E6_1_64.txt ./result/Naive_4096_uniform_1E6.txt ./outputParams/Naive_4096_uniform_1E6.txt)
#DCW
$(./debug/bin/simulator -r ./config/DCW_512.txt ./requests/requests_workload_uniform_1E6_1_8.txt ./result/DCW_512_uniform_1E6.txt ./outputParams/DCW_512_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/DCW_1024.txt ./requests/requests_workload_uniform_1E6_1_16.txt ./result/DCW_1024_uniform_1E6.txt ./outputParams/DCW_1024_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/DCW_2048.txt ./requests/requests_workload_uniform_1E6_1_32.txt ./result/DCW_2048_uniform_1E6.txt ./outputParams/DCW_2048_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/DCW_4096.txt ./requests/requests_workload_uniform_1E6_1_64.txt ./result/DCW_4096_uniform_1E6.txt ./outputParams/DCW_4096_uniform_1E6.txt)
#FNW
$(./debug/bin/simulator -r ./config/Flip_N_Write_512.txt ./requests/requests_workload_uniform_1E6_1_8.txt ./result/Flip_N_Write_512_uniform_1E6.txt ./outputParams/Flip_N_Write_512_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_1024.txt ./requests/requests_workload_uniform_1E6_1_16.txt ./result/Flip_N_Write_1024_uniform_1E6.txt ./outputParams/Flip_N_Write_1024_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_2048.txt ./requests/requests_workload_uniform_1E6_1_32.txt ./result/Flip_N_Write_2048_uniform_1E6.txt ./outputParams/Flip_N_Write_2048_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_4096.txt ./requests/requests_workload_uniform_1E6_1_64.txt ./result/Flip_N_Write_4096_uniform_1E6.txt ./outputParams/Flip_N_Write_4096_uniform_1E6.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_512.txt ./requests/requests_workload_uniform_1E6_1_8.txt ./result/MOutOfNWrite_8_512_uniform_1E6.txt ./outputParams/MOutOfNWrite_8_512_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_1024.txt ./requests/requests_workload_uniform_1E6_1_16.txt ./result/MOutOfNWrite_8_1024_uniform_1E6.txt ./outputParams/MOutOfNWrite_8_1024_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_2048.txt ./requests/requests_workload_uniform_1E6_1_32.txt ./result/MOutOfNWrite_8_2048_uniform_1E6.txt ./outputParams/MOutOfNWrite_8_2048_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_4096.txt ./requests/requests_workload_uniform_1E6_1_64.txt ./result/MOutOfNWrite_8_4096_uniform_1E6.txt ./outputParams/MOutOfNWrite_8_4096_uniform_1E6.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_512.txt ./requests/requests_workload_uniform_1E6_1_8.txt ./result/MOutOfNWrite_16_512_uniform_1E6.txt ./outputParams/MOutOfNWrite_16_512_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_1024.txt ./requests/requests_workload_uniform_1E6_1_16.txt ./result/MOutOfNWrite_16_1024_uniform_1E6.txt ./outputParams/MOutOfNWrite_16_1024_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_2048.txt ./requests/requests_workload_uniform_1E6_1_32.txt ./result/MOutOfNWrite_16_2048_uniform_1E6.txt ./outputParams/MOutOfNWrite_16_2048_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_4096.txt ./requests/requests_workload_uniform_1E6_1_64.txt ./result/MOutOfNWrite_16_4096_uniform_1E6.txt ./outputParams/MOutOfNWrite_16_4096_uniform_1E6.txt)
#PW
$(./debug/bin/simulator -r ./config/Permutation_Write_512.txt ./requests/requests_workload_uniform_1E6_1_8.txt ./result/Permutation_Write_512_uniform_1E6.txt ./outputParams/Permutation_Write_512_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_1024.txt ./requests/requests_workload_uniform_1E6_1_16.txt ./result/Permutation_Write_1024_uniform_1E6.txt ./outputParams/Permutation_Write_1024_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_2048.txt ./requests/requests_workload_uniform_1E6_1_32.txt ./result/Permutation_Write_2048_uniform_1E6.txt ./outputParams/Permutation_Write_2048_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_4096.txt ./requests/requests_workload_uniform_1E6_1_64.txt ./result/Permutation_Write_4096_uniform_1E6.txt ./outputParams/Permutation_Write_4096_uniform_1E6.txt)
#Combine_PW_FNW
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_512.txt ./requests/requests_workload_uniform_1E6_1_8.txt ./result/Combine_PW_FNW_512_uniform_1E6.txt ./outputParams/Combine_PW_FNW_512_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_1024.txt ./requests/requests_workload_uniform_1E6_1_16.txt ./result/Combine_PW_FNW_1024_uniform_1E6.txt ./outputParams/Combine_PW_FNW_1024_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_2048.txt ./requests/requests_workload_uniform_1E6_1_32.txt ./result/Combine_PW_FNW_2048_uniform_1E6.txt ./outputParams/Combine_PW_FNW_2048_uniform_1E6.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_4096.txt ./requests/requests_workload_uniform_1E6_1_64.txt ./result/Combine_PW_FNW_4096_uniform_1E6.txt ./outputParams/Combine_PW_FNW_4096_uniform_1E6.txt)
#==========================================================================================
#workload B: zipf #data:1E6 #operation: 1E7
#===========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/Naive_512.txt ./requests/requests_workload_zipf_1E6_1_8.txt ./result/Naive_512_zipf_1E6.txt ./outputParams/Naive_512_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Naive_1024.txt ./requests/requests_workload_zipf_1E6_1_16.txt ./result/Naive_1024_zipf_1E6.txt ./outputParams/Naive_1024_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Naive_2048.txt ./requests/requests_workload_zipf_1E6_1_32.txt ./result/Naive_2048_zipf_1E6.txt ./outputParams/Naive_2048_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Naive_4096.txt ./requests/requests_workload_zipf_1E6_1_64.txt ./result/Naive_4096_zipf_1E6.txt ./outputParams/Naive_4096_zipf_1E6.txt)
#DCW
$(./debug/bin/simulator -r ./config/DCW_512.txt ./requests/requests_workload_zipf_1E6_1_8.txt ./result/DCW_512_zipf_1E6.txt ./outputParams/DCW_512_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/DCW_1024.txt ./requests/requests_workload_zipf_1E6_1_16.txt ./result/DCW_1024_zipf_1E6.txt ./outputParams/DCW_1024_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/DCW_2048.txt ./requests/requests_workload_zipf_1E6_1_32.txt ./result/DCW_2048_zipf_1E6.txt ./outputParams/DCW_2048_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/DCW_4096.txt ./requests/requests_workload_zipf_1E6_1_64.txt ./result/DCW_4096_zipf_1E6.txt ./outputParams/DCW_4096_zipf_1E6.txt)
#FNW
$(./debug/bin/simulator -r ./config/Flip_N_Write_512.txt ./requests/requests_workload_zipf_1E6_1_8.txt ./result/Flip_N_Write_512_zipf_1E6.txt ./outputParams/Flip_N_Write_512_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_1024.txt ./requests/requests_workload_zipf_1E6_1_16.txt ./result/Flip_N_Write_1024_zipf_1E6.txt ./outputParams/Flip_N_Write_1024_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_2048.txt ./requests/requests_workload_zipf_1E6_1_32.txt ./result/Flip_N_Write_2048_zipf_1E6.txt ./outputParams/Flip_N_Write_2048_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_4096.txt ./requests/requests_workload_zipf_1E6_1_64.txt ./result/Flip_N_Write_4096_zipf_1E6.txt ./outputParams/Flip_N_Write_4096_zipf_1E6.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_512.txt ./requests/requests_workload_zipf_1E6_1_8.txt ./result/MOutOfNWrite_8_512_zipf_1E6.txt ./outputParams/MOutOfNWrite_8_512_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_1024.txt ./requests/requests_workload_zipf_1E6_1_16.txt ./result/MOutOfNWrite_8_1024_zipf_1E6.txt ./outputParams/MOutOfNWrite_8_1024_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_2048.txt ./requests/requests_workload_zipf_1E6_1_32.txt ./result/MOutOfNWrite_8_2048_zipf_1E6.txt ./outputParams/MOutOfNWrite_8_2048_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_4096.txt ./requests/requests_workload_zipf_1E6_1_64.txt ./result/MOutOfNWrite_8_4096_zipf_1E6.txt ./outputParams/MOutOfNWrite_8_4096_zipf_1E6.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_512.txt ./requests/requests_workload_zipf_1E6_1_8.txt ./result/MOutOfNWrite_16_512_zipf_1E6.txt ./outputParams/MOutOfNWrite_16_512_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_1024.txt ./requests/requests_workload_zipf_1E6_1_16.txt ./result/MOutOfNWrite_16_1024_zipf_1E6.txt ./outputParams/MOutOfNWrite_16_1024_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_2048.txt ./requests/requests_workload_zipf_1E6_1_32.txt ./result/MOutOfNWrite_16_2048_zipf_1E6.txt ./outputParams/MOutOfNWrite_16_2048_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_4096.txt ./requests/requests_workload_zipf_1E6_1_64.txt ./result/MOutOfNWrite_16_4096_zipf_1E6.txt ./outputParams/MOutOfNWrite_16_4096_zipf_1E6.txt)
#PW
$(./debug/bin/simulator -r ./config/Permutation_Write_512.txt ./requests/requests_workload_zipf_1E6_1_8.txt ./result/Permutation_Write_512_zipf_1E6.txt ./outputParams/Permutation_Write_512_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_1024.txt ./requests/requests_workload_zipf_1E6_1_16.txt ./result/Permutation_Write_1024_zipf_1E6.txt ./outputParams/Permutation_Write_1024_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_2048.txt ./requests/requests_workload_zipf_1E6_1_32.txt ./result/Permutation_Write_2048_zipf_1E6.txt ./outputParams/Permutation_Write_2048_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_4096.txt ./requests/requests_workload_zipf_1E6_1_64.txt ./result/Permutation_Write_4096_zipf_1E6.txt ./outputParams/Permutation_Write_4096_zipf_1E6.txt)
#Combine_PW_FNW
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_512.txt ./requests/requests_workload_zipf_1E6_1_8.txt ./result/Combine_PW_FNW_512_zipf_1E6.txt ./outputParams/Combine_PW_FNW_512_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_1024.txt ./requests/requests_workload_zipf_1E6_1_16.txt ./result/Combine_PW_FNW_1024_zipf_1E6.txt ./outputParams/Combine_PW_FNW_1024_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_2048.txt ./requests/requests_workload_zipf_1E6_1_32.txt ./result/Combine_PW_FNW_2048_zipf_1E6.txt ./outputParams/Combine_PW_FNW_2048_zipf_1E6.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_4096.txt ./requests/requests_workload_zipf_1E6_1_64.txt ./result/Combine_PW_FNW_4096_zipf_1E6.txt ./outputParams/Combine_PW_FNW_4096_zipf_1E6.txt)
#==========================================================================================
#workload C: zipf #data:1E5 #operation: 1E7
#===========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/Naive_512.txt ./requests/requests_workload_zipf_1E5_1_8.txt ./result/Naive_512_zipf_1E5.txt ./outputParams/Naive_512_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Naive_1024.txt ./requests/requests_workload_zipf_1E5_1_16.txt ./result/Naive_1024_zipf_1E5.txt ./outputParams/Naive_1024_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Naive_2048.txt ./requests/requests_workload_zipf_1E5_1_32.txt ./result/Naive_2048_zipf_1E5.txt ./outputParams/Naive_2048_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Naive_4096.txt ./requests/requests_workload_zipf_1E5_1_64.txt ./result/Naive_4096_zipf_1E5.txt ./outputParams/Naive_4096_zipf_1E5.txt)
#DCW
$(./debug/bin/simulator -r ./config/DCW_512.txt ./requests/requests_workload_zipf_1E5_1_8.txt ./result/DCW_512_zipf_1E5.txt ./outputParams/DCW_512_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/DCW_1024.txt ./requests/requests_workload_zipf_1E5_1_16.txt ./result/DCW_1024_zipf_1E5.txt ./outputParams/DCW_1024_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/DCW_2048.txt ./requests/requests_workload_zipf_1E5_1_32.txt ./result/DCW_2048_zipf_1E5.txt ./outputParams/DCW_2048_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/DCW_4096.txt ./requests/requests_workload_zipf_1E5_1_64.txt ./result/DCW_4096_zipf_1E5.txt ./outputParams/DCW_4096_zipf_1E5.txt)
#FNW
$(./debug/bin/simulator -r ./config/Flip_N_Write_512.txt ./requests/requests_workload_zipf_1E5_1_8.txt ./result/Flip_N_Write_512_zipf_1E5.txt ./outputParams/Flip_N_Write_512_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_1024.txt ./requests/requests_workload_zipf_1E5_1_16.txt ./result/Flip_N_Write_1024_zipf_1E5.txt ./outputParams/Flip_N_Write_1024_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_2048.txt ./requests/requests_workload_zipf_1E5_1_32.txt ./result/Flip_N_Write_2048_zipf_1E5.txt ./outputParams/Flip_N_Write_2048_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_4096.txt ./requests/requests_workload_zipf_1E5_1_64.txt ./result/Flip_N_Write_4096_zipf_1E5.txt ./outputParams/Flip_N_Write_4096_zipf_1E5.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_512.txt ./requests/requests_workload_zipf_1E5_1_8.txt ./result/MOutOfNWrite_8_512_zipf_1E5.txt ./outputParams/MOutOfNWrite_8_512_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_1024.txt ./requests/requests_workload_zipf_1E5_1_16.txt ./result/MOutOfNWrite_8_1024_zipf_1E5.txt ./outputParams/MOutOfNWrite_8_1024_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_2048.txt ./requests/requests_workload_zipf_1E5_1_32.txt ./result/MOutOfNWrite_8_2048_zipf_1E5.txt ./outputParams/MOutOfNWrite_8_2048_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_4096.txt ./requests/requests_workload_zipf_1E5_1_64.txt ./result/MOutOfNWrite_8_4096_zipf_1E5.txt ./outputParams/MOutOfNWrite_8_4096_zipf_1E5.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_512.txt ./requests/requests_workload_zipf_1E5_1_8.txt ./result/MOutOfNWrite_16_512_zipf_1E5.txt ./outputParams/MOutOfNWrite_16_512_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_1024.txt ./requests/requests_workload_zipf_1E5_1_16.txt ./result/MOutOfNWrite_16_1024_zipf_1E5.txt ./outputParams/MOutOfNWrite_16_1024_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_2048.txt ./requests/requests_workload_zipf_1E5_1_32.txt ./result/MOutOfNWrite_16_2048_zipf_1E5.txt ./outputParams/MOutOfNWrite_16_2048_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_4096.txt ./requests/requests_workload_zipf_1E5_1_64.txt ./result/MOutOfNWrite_16_4096_zipf_1E5.txt ./outputParams/MOutOfNWrite_16_4096_zipf_1E5.txt)
#PW
$(./debug/bin/simulator -r ./config/Permutation_Write_512.txt ./requests/requests_workload_zipf_1E5_1_8.txt ./result/Permutation_Write_512_zipf_1E5.txt ./outputParams/Permutation_Write_512_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_1024.txt ./requests/requests_workload_zipf_1E5_1_16.txt ./result/Permutation_Write_1024_zipf_1E5.txt ./outputParams/Permutation_Write_1024_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_2048.txt ./requests/requests_workload_zipf_1E5_1_32.txt ./result/Permutation_Write_2048_zipf_1E5.txt ./outputParams/Permutation_Write_2048_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_4096.txt ./requests/requests_workload_zipf_1E5_1_64.txt ./result/Permutation_Write_4096_zipf_1E5.txt ./outputParams/Permutation_Write_4096_zipf_1E5.txt)
#Combine_PW_FNW
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_512.txt ./requests/requests_workload_zipf_1E5_1_8.txt ./result/Combine_PW_FNW_512_zipf_1E5.txt ./outputParams/Combine_PW_FNW_512_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_1024.txt ./requests/requests_workload_zipf_1E5_1_16.txt ./result/Combine_PW_FNW_1024_zipf_1E5.txt ./outputParams/Combine_PW_FNW_1024_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_2048.txt ./requests/requests_workload_zipf_1E5_1_32.txt ./result/Combine_PW_FNW_2048_zipf_1E5.txt ./outputParams/Combine_PW_FNW_2048_zipf_1E5.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_4096.txt ./requests/requests_workload_zipf_1E5_1_64.txt ./result/Combine_PW_FNW_4096_zipf_1E5.txt ./outputParams/Combine_PW_FNW_4096_zipf_1E5.txt)
#==========================================================================================
#workload D: uniform #data:1E5 #operation: 1E7
#===========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/Naive_512.txt ./requests/requests_workload_uniform_1E5_1_8.txt ./result/Naive_512_uniform_1E5.txt ./outputParams/Naive_512_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Naive_1024.txt ./requests/requests_workload_uniform_1E5_1_16.txt ./result/Naive_1024_uniform_1E5.txt ./outputParams/Naive_1024_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Naive_2048.txt ./requests/requests_workload_uniform_1E5_1_32.txt ./result/Naive_2048_uniform_1E5.txt ./outputParams/Naive_2048_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Naive_4096.txt ./requests/requests_workload_uniform_1E5_1_64.txt ./result/Naive_4096_uniform_1E5.txt ./outputParams/Naive_4096_uniform_1E5.txt)
#DCW
$(./debug/bin/simulator -r ./config/DCW_512.txt ./requests/requests_workload_uniform_1E5_1_8.txt ./result/DCW_512_uniform_1E5.txt ./outputParams/DCW_512_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/DCW_1024.txt ./requests/requests_workload_uniform_1E5_1_16.txt ./result/DCW_1024_uniform_1E5.txt ./outputParams/DCW_1024_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/DCW_2048.txt ./requests/requests_workload_uniform_1E5_1_32.txt ./result/DCW_2048_uniform_1E5.txt ./outputParams/DCW_2048_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/DCW_4096.txt ./requests/requests_workload_uniform_1E5_1_64.txt ./result/DCW_4096_uniform_1E5.txt ./outputParams/DCW_4096_uniform_1E5.txt)
#FNW
$(./debug/bin/simulator -r ./config/Flip_N_Write_512.txt ./requests/requests_workload_uniform_1E5_1_8.txt ./result/Flip_N_Write_512_uniform_1E5.txt ./outputParams/Flip_N_Write_512_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_1024.txt ./requests/requests_workload_uniform_1E5_1_16.txt ./result/Flip_N_Write_1024_uniform_1E5.txt ./outputParams/Flip_N_Write_1024_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_2048.txt ./requests/requests_workload_uniform_1E5_1_32.txt ./result/Flip_N_Write_2048_uniform_1E5.txt ./outputParams/Flip_N_Write_2048_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_4096.txt ./requests/requests_workload_uniform_1E5_1_64.txt ./result/Flip_N_Write_4096_uniform_1E5.txt ./outputParams/Flip_N_Write_4096_uniform_1E5.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_512.txt ./requests/requests_workload_uniform_1E5_1_8.txt ./result/MOutOfNWrite_8_512_uniform_1E5.txt ./outputParams/MOutOfNWrite_8_512_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_1024.txt ./requests/requests_workload_uniform_1E5_1_16.txt ./result/MOutOfNWrite_8_1024_uniform_1E5.txt ./outputParams/MOutOfNWrite_8_1024_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_2048.txt ./requests/requests_workload_uniform_1E5_1_32.txt ./result/MOutOfNWrite_8_2048_uniform_1E5.txt ./outputParams/MOutOfNWrite_8_2048_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_4096.txt ./requests/requests_workload_uniform_1E5_1_64.txt ./result/MOutOfNWrite_8_4096_uniform_1E5.txt ./outputParams/MOutOfNWrite_8_4096_uniform_1E5.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_512.txt ./requests/requests_workload_uniform_1E5_1_8.txt ./result/MOutOfNWrite_16_512_uniform_1E5.txt ./outputParams/MOutOfNWrite_16_512_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_1024.txt ./requests/requests_workload_uniform_1E5_1_16.txt ./result/MOutOfNWrite_16_1024_uniform_1E5.txt ./outputParams/MOutOfNWrite_16_1024_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_2048.txt ./requests/requests_workload_uniform_1E5_1_32.txt ./result/MOutOfNWrite_16_2048_uniform_1E5.txt ./outputParams/MOutOfNWrite_16_2048_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_4096.txt ./requests/requests_workload_uniform_1E5_1_64.txt ./result/MOutOfNWrite_16_4096_uniform_1E5.txt ./outputParams/MOutOfNWrite_16_4096_uniform_1E5.txt)
#PW
$(./debug/bin/simulator -r ./config/Permutation_Write_512.txt ./requests/requests_workload_uniform_1E5_1_8.txt ./result/Permutation_Write_512_uniform_1E5.txt ./outputParams/Permutation_Write_512_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_1024.txt ./requests/requests_workload_uniform_1E5_1_16.txt ./result/Permutation_Write_1024_uniform_1E5.txt ./outputParams/Permutation_Write_1024_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_2048.txt ./requests/requests_workload_uniform_1E5_1_32.txt ./result/Permutation_Write_2048_uniform_1E5.txt ./outputParams/Permutation_Write_2048_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_4096.txt ./requests/requests_workload_uniform_1E5_1_64.txt ./result/Permutation_Write_4096_uniform_1E5.txt ./outputParams/Permutation_Write_4096_uniform_1E5.txt)
#Combine_PW_FNW
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_512.txt ./requests/requests_workload_uniform_1E5_1_8.txt ./result/Combine_PW_FNW_512_uniform_1E5.txt ./outputParams/Combine_PW_FNW_512_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_1024.txt ./requests/requests_workload_uniform_1E5_1_16.txt ./result/Combine_PW_FNW_1024_uniform_1E5.txt ./outputParams/Combine_PW_FNW_1024_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_2048.txt ./requests/requests_workload_uniform_1E5_1_32.txt ./result/Combine_PW_FNW_2048_uniform_1E5.txt ./outputParams/Combine_PW_FNW_2048_uniform_1E5.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_4096.txt ./requests/requests_workload_uniform_1E5_1_64.txt ./result/Combine_PW_FNW_4096_uniform_1E5.txt ./outputParams/Combine_PW_FNW_4096_uniform_1E5.txt)
#==========================================================================================
#workload E: zipf #data:1E7 #operation: 1E7
#===========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/Naive_512.txt ./requests/requests_workload_zipf_1E7_1_8.txt ./result/Naive_512_zipf_1E7.txt ./outputParams/Naive_512_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Naive_1024.txt ./requests/requests_workload_zipf_1E7_1_16.txt ./result/Naive_1024_zipf_1E7.txt ./outputParams/Naive_1024_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Naive_2048.txt ./requests/requests_workload_zipf_1E7_1_32.txt ./result/Naive_2048_zipf_1E7.txt ./outputParams/Naive_2048_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Naive_4096.txt ./requests/requests_workload_zipf_1E7_1_64.txt ./result/Naive_4096_zipf_1E7.txt ./outputParams/Naive_4096_zipf_1E7.txt)
#DCW
$(./debug/bin/simulator -r ./config/DCW_512.txt ./requests/requests_workload_zipf_1E7_1_8.txt ./result/DCW_512_zipf_1E7.txt ./outputParams/DCW_512_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/DCW_1024.txt ./requests/requests_workload_zipf_1E7_1_16.txt ./result/DCW_1024_zipf_1E7.txt ./outputParams/DCW_1024_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/DCW_2048.txt ./requests/requests_workload_zipf_1E7_1_32.txt ./result/DCW_2048_zipf_1E7.txt ./outputParams/DCW_2048_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/DCW_4096.txt ./requests/requests_workload_zipf_1E7_1_64.txt ./result/DCW_4096_zipf_1E7.txt ./outputParams/DCW_4096_zipf_1E7.txt)
#FNW
$(./debug/bin/simulator -r ./config/Flip_N_Write_512.txt ./requests/requests_workload_zipf_1E7_1_8.txt ./result/Flip_N_Write_512_zipf_1E7.txt ./outputParams/Flip_N_Write_512_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_1024.txt ./requests/requests_workload_zipf_1E7_1_16.txt ./result/Flip_N_Write_1024_zipf_1E7.txt ./outputParams/Flip_N_Write_1024_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_2048.txt ./requests/requests_workload_zipf_1E7_1_32.txt ./result/Flip_N_Write_2048_zipf_1E7.txt ./outputParams/Flip_N_Write_2048_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_4096.txt ./requests/requests_workload_zipf_1E7_1_64.txt ./result/Flip_N_Write_4096_zipf_1E7.txt ./outputParams/Flip_N_Write_4096_zipf_1E7.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_512.txt ./requests/requests_workload_zipf_1E7_1_8.txt ./result/MOutOfNWrite_8_512_zipf_1E7.txt ./outputParams/MOutOfNWrite_8_512_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_1024.txt ./requests/requests_workload_zipf_1E7_1_16.txt ./result/MOutOfNWrite_8_1024_zipf_1E7.txt ./outputParams/MOutOfNWrite_8_1024_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_2048.txt ./requests/requests_workload_zipf_1E7_1_32.txt ./result/MOutOfNWrite_8_2048_zipf_1E7.txt ./outputParams/MOutOfNWrite_8_2048_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_4096.txt ./requests/requests_workload_zipf_1E7_1_64.txt ./result/MOutOfNWrite_8_4096_zipf_1E7.txt ./outputParams/MOutOfNWrite_8_4096_zipf_1E7.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_512.txt ./requests/requests_workload_zipf_1E7_1_8.txt ./result/MOutOfNWrite_16_512_zipf_1E7.txt ./outputParams/MOutOfNWrite_16_512_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_1024.txt ./requests/requests_workload_zipf_1E7_1_16.txt ./result/MOutOfNWrite_16_1024_zipf_1E7.txt ./outputParams/MOutOfNWrite_16_1024_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_2048.txt ./requests/requests_workload_zipf_1E7_1_32.txt ./result/MOutOfNWrite_16_2048_zipf_1E7.txt ./outputParams/MOutOfNWrite_16_2048_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_4096.txt ./requests/requests_workload_zipf_1E7_1_64.txt ./result/MOutOfNWrite_16_4096_zipf_1E7.txt ./outputParams/MOutOfNWrite_16_4096_zipf_1E7.txt)
#PW
$(./debug/bin/simulator -r ./config/Permutation_Write_512.txt ./requests/requests_workload_zipf_1E7_1_8.txt ./result/Permutation_Write_512_zipf_1E7.txt ./outputParams/Permutation_Write_512_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_1024.txt ./requests/requests_workload_zipf_1E7_1_16.txt ./result/Permutation_Write_1024_zipf_1E7.txt ./outputParams/Permutation_Write_1024_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_2048.txt ./requests/requests_workload_zipf_1E7_1_32.txt ./result/Permutation_Write_2048_zipf_1E7.txt ./outputParams/Permutation_Write_2048_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_4096.txt ./requests/requests_workload_zipf_1E7_1_64.txt ./result/Permutation_Write_4096_zipf_1E7.txt ./outputParams/Permutation_Write_4096_zipf_1E7.txt)
#Combine_PW_FNW
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_512.txt ./requests/requests_workload_zipf_1E7_1_8.txt ./result/Combine_PW_FNW_512_zipf_1E7.txt ./outputParams/Combine_PW_FNW_512_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_1024.txt ./requests/requests_workload_zipf_1E7_1_16.txt ./result/Combine_PW_FNW_1024_zipf_1E7.txt ./outputParams/Combine_PW_FNW_1024_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_2048.txt ./requests/requests_workload_zipf_1E7_1_32.txt ./result/Combine_PW_FNW_2048_zipf_1E7.txt ./outputParams/Combine_PW_FNW_2048_zipf_1E7.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_4096.txt ./requests/requests_workload_zipf_1E7_1_64.txt ./result/Combine_PW_FNW_4096_zipf_1E7.txt ./outputParams/Combine_PW_FNW_4096_zipf_1E7.txt)
#==========================================================================================


#workload F: uniform #data:1E7 #operation: 1E7
#===========================================================================================
#Naive
$(./debug/bin/simulator -r ./config/Naive_512.txt ./requests/requests_workload_uniform_1E7_1_8.txt ./result/Naive_512_uniform_1E7.txt ./outputParams/Naive_512_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Naive_1024.txt ./requests/requests_workload_uniform_1E7_1_16.txt ./result/Naive_1024_uniform_1E7.txt ./outputParams/Naive_1024_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Naive_2048.txt ./requests/requests_workload_uniform_1E7_1_32.txt ./result/Naive_2048_uniform_1E7.txt ./outputParams/Naive_2048_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Naive_4096.txt ./requests/requests_workload_uniform_1E7_1_64.txt ./result/Naive_4096_uniform_1E7.txt ./outputParams/Naive_4096_uniform_1E7.txt)
#DCW
$(./debug/bin/simulator -r ./config/DCW_512.txt ./requests/requests_workload_uniform_1E7_1_8.txt ./result/DCW_512_uniform_1E7.txt ./outputParams/DCW_512_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/DCW_1024.txt ./requests/requests_workload_uniform_1E7_1_16.txt ./result/DCW_1024_uniform_1E7.txt ./outputParams/DCW_1024_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/DCW_2048.txt ./requests/requests_workload_uniform_1E7_1_32.txt ./result/DCW_2048_uniform_1E7.txt ./outputParams/DCW_2048_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/DCW_4096.txt ./requests/requests_workload_uniform_1E7_1_64.txt ./result/DCW_4096_uniform_1E7.txt ./outputParams/DCW_4096_uniform_1E7.txt)
#FNW
$(./debug/bin/simulator -r ./config/Flip_N_Write_512.txt ./requests/requests_workload_uniform_1E7_1_8.txt ./result/Flip_N_Write_512_uniform_1E7.txt ./outputParams/Flip_N_Write_512_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_1024.txt ./requests/requests_workload_uniform_1E7_1_16.txt ./result/Flip_N_Write_1024_uniform_1E7.txt ./outputParams/Flip_N_Write_1024_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_2048.txt ./requests/requests_workload_uniform_1E7_1_32.txt ./result/Flip_N_Write_2048_uniform_1E7.txt ./outputParams/Flip_N_Write_2048_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Flip_N_Write_4096.txt ./requests/requests_workload_uniform_1E7_1_64.txt ./result/Flip_N_Write_4096_uniform_1E7.txt ./outputParams/Flip_N_Write_4096_uniform_1E7.txt)
#M-out-of-N-Write_8
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_512.txt ./requests/requests_workload_uniform_1E7_1_8.txt ./result/MOutOfNWrite_8_512_uniform_1E7.txt ./outputParams/MOutOfNWrite_8_512_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_1024.txt ./requests/requests_workload_uniform_1E7_1_16.txt ./result/MOutOfNWrite_8_1024_uniform_1E7.txt ./outputParams/MOutOfNWrite_8_1024_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_2048.txt ./requests/requests_workload_uniform_1E7_1_32.txt ./result/MOutOfNWrite_8_2048_uniform_1E7.txt ./outputParams/MOutOfNWrite_8_2048_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_8_4096.txt ./requests/requests_workload_uniform_1E7_1_64.txt ./result/MOutOfNWrite_8_4096_uniform_1E7.txt ./outputParams/MOutOfNWrite_8_4096_uniform_1E7.txt)
#M-out-of-N-Write_16
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_512.txt ./requests/requests_workload_uniform_1E7_1_8.txt ./result/MOutOfNWrite_16_512_uniform_1E7.txt ./outputParams/MOutOfNWrite_16_512_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_1024.txt ./requests/requests_workload_uniform_1E7_1_16.txt ./result/MOutOfNWrite_16_1024_uniform_1E7.txt ./outputParams/MOutOfNWrite_16_1024_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_2048.txt ./requests/requests_workload_uniform_1E7_1_32.txt ./result/MOutOfNWrite_16_2048_uniform_1E7.txt ./outputParams/MOutOfNWrite_16_2048_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/MOutOfNWrite_16_4096.txt ./requests/requests_workload_uniform_1E7_1_64.txt ./result/MOutOfNWrite_16_4096_uniform_1E7.txt ./outputParams/MOutOfNWrite_16_4096_uniform_1E7.txt)
#PW
$(./debug/bin/simulator -r ./config/Permutation_Write_512.txt ./requests/requests_workload_uniform_1E7_1_8.txt ./result/Permutation_Write_512_uniform_1E7.txt ./outputParams/Permutation_Write_512_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_1024.txt ./requests/requests_workload_uniform_1E7_1_16.txt ./result/Permutation_Write_1024_uniform_1E7.txt ./outputParams/Permutation_Write_1024_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_2048.txt ./requests/requests_workload_uniform_1E7_1_32.txt ./result/Permutation_Write_2048_uniform_1E7.txt ./outputParams/Permutation_Write_2048_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Permutation_Write_4096.txt ./requests/requests_workload_uniform_1E7_1_64.txt ./result/Permutation_Write_4096_uniform_1E7.txt ./outputParams/Permutation_Write_4096_uniform_1E7.txt)
#Combine_PW_FNW
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_512.txt ./requests/requests_workload_uniform_1E7_1_8.txt ./result/Combine_PW_FNW_512_uniform_1E7.txt ./outputParams/Combine_PW_FNW_512_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_1024.txt ./requests/requests_workload_uniform_1E7_1_16.txt ./result/Combine_PW_FNW_1024_uniform_1E7.txt ./outputParams/Combine_PW_FNW_1024_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_2048.txt ./requests/requests_workload_uniform_1E7_1_32.txt ./result/Combine_PW_FNW_2048_uniform_1E7.txt ./outputParams/Combine_PW_FNW_2048_uniform_1E7.txt)
$(./debug/bin/simulator -r ./config/Combine_PW_FNW_4096.txt ./requests/requests_workload_uniform_1E7_1_64.txt ./result/Combine_PW_FNW_4096_uniform_1E7.txt ./outputParams/Combine_PW_FNW_4096_uniform_1E7.txt)
#==========================================================================================

