$(..//ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_zipf_1E6 > ycsb_workloads/workload_zipf_1E6.txt)
$(../ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_uniform_1E6 > ycsb_workloads/workload_uniform_1E6.txt)

printf "Generating request files....\n"
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 8)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 16)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 32)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 64)

$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 8)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 16)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 32)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 64)
printf "Completed."
printf "All request file are exported to 'SK-RMSim\requests\requestFiles' \n"