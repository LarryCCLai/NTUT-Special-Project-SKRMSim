$(../ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_zipf_1E5 > ycsb_workloads/workload_zipf_1E5.txt)
$(..//ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_zipf_1E6 > ycsb_workloads/workload_zipf_1E6.txt)
$(../ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_zipf_1E7 > ycsb_workloads/workload_zipf_1E7.txt)

$(../ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_uniform_1E5 > ycsb_workloads/workload_uniform_1E5.txt)
$(../ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_uniform_1E6 > ycsb_workloads/workload_uniform_1E6.txt)
$(../ycsb-*/bin/ycsb.sh run basic -P ycsb_workloads/workload_uniform_1E7 > ycsb_workloads/workload_uniform_1E7.txt)

#$(bin/ycsb.sh load basic -P workloads/workload_value > workload_value.txt)
