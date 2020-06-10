echo "Format converting..."
#workload_uniform_1E6
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 8)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 16)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 32)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_uniform_1E6.txt 1 64)
#workload_zipf_1E6
$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 8)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 16)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 32)
$(./debug/bin/simulator -t ./ycsb_workloads/workload_zipf_1E6.txt 1 64)
echo "Completed."

