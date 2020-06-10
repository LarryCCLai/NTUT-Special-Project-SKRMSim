# How to compile
1. Git clone the respository
2. Enter the following command
```
make
```

# How to use
1. **Edit config file**  
    * Template as shown in following..
    * Place the config file to the dir SK-RMSim/config/configFile/
```
;********************************************************************************
; Number of racetrack
; options: any positive number
N_racetrack 1

; Number of bits per data, Uint: bit
; fixed 64
dataWidth 64 

; Number of bits per data segment, Uint: bit
; options: 8, 16, 64
dataWidthSegment 64

; Write mode, Type
; options:
; Naive 0
; DCW 1 
; Flip_N_Write 2 
; Permutation_Write 3 
; M_Out_Of_N_Write 4
; Combine_PW_FNW 5
writeMode 5

; Number of data per racetrack
; options: 16 32 
NDR 8 16 32 64
;********************************************************************************
```
2. **Generate request file**
   * **Method1**: Generate request file yourself
     * request format per line: [operation] [track index] [data index] [data]  
       * operation: W, R
       * track index: 0 ~ N-1, where N is based on "Number of racetrack" in config file.
       * deat index: 0 ~ N-1, where N is based on "Number of data per racetrack" in config file.
       * data: 0 ~ 2^63
   * **Method2**: Use YCSB to generate it.  
     * Note that you have to trans the format adapted to SK-RMSim
     * https://github.com/brianfrankcooper/YCSB
   * Place rqeuest file to the dir ``SK-RMSim/requests/requestFiles/``
3. **Execute command**  

    `./debug/bin/simulator -r ./config/configFile/[confige file] ./requests/requestFiles/[request file]`
# Results
The results export to the dir `SK-RMSim\outputFile`

# Others
**test**
```
sudo apt install default-jre
sudo apt install curl
sudo apt install gnuplot
sudo apt install git

curl -O --location https://github.com/brianfrankcooper/YCSB/releases/download/0.17.0/ycsb-0.17.0.tar.gz
tar xfvz ycsb-0.17.0.tar.gz
git clone https://github.com/LarryCCLai/SK-RMSim.git
cd SK-RMSim
make
bash load_Workloads.sh
bash exe.sh
./debug/bin/simulator -g
gnuplot ./print/latency.gp
gnuplot ./print/overhead.gp
gnuplot ./print/results.gp
```
