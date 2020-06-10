reset
set ytics 0, 200000000
set xtics
set offsets 0,0,0,0
set ylabel '#Operations' 
set xlabel 'Operation type'

set term png enhanced font 'arial,12'
set terminal pngcairo size 720,400

set grid
set style fill solid
set style histogram clustered gap 3 title offset character 0,0,0
set style data histogram
set output './outputFile/graphs/uniform_512.png'

plot [:][:2000000000]'./outputFile/information/uniform_512.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \

set output './outputFile/graphs/uniform_1024.png'

plot [:][:2000000000]'./outputFile/information/uniform_1024.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \

set output './outputFile/graphs/uniform_2048.png'

plot [:][:2000000000]'./outputFile/information/uniform_2048.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \

set output './outputFile/graphs/uniform_4096.png'

plot [:][:2000000000]'./outputFile/information/uniform_4096.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \

set output './outputFile/graphs/zipf_512.png'

plot [:][:2000000000]'./outputFile/information/zipf_512.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \

set output './outputFile/graphs/zipf_1024.png'

plot [:][:2000000000]'./outputFile/information/zipf_1024.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \

set output './outputFile/graphs/zipf_2048.png'

plot [:][:2000000000]'./outputFile/information/zipf_2048.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \

set output './outputFile/graphs/zipf_4096.png'

plot [:][:2000000000]'./outputFile/information/zipf_4096.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \