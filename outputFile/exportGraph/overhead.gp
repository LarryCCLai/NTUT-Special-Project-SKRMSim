reset
set ytics 0, 100, 1700
set xtics
set offsets 0,0.5,0.5,0
set key left
set ylabel '#Overhead region' 
set xlabel 'Track capacity (bits)'

set term png enhanced font 'arial,12'
set terminal pngcairo size 680,400

set grid
set style data histogram
set style fill solid
set style histogram clustered gap 4 title offset character 0,0,0
set boxwidth 1 relative

set output 'Overhead.png'

plot [:][:1700]'../information/overhead.txt' \
using 2:xtic(1) with histogram fs p 1 lt rgb "black" title 'Naive', \
'' using 3:xtic(1) with histogram fs p 2 lt rgb "black" title 'DCW'  , \
'' using 4:xtic(1) with histogram fs p 4 lt rgb "black" title 'FNW'  , \
'' using 5:xtic(1) with histogram fs p 6 lt rgb "black" title 'M-out-of-N-Write, d = 8'  , \
'' using 6:xtic(1) with histogram fs p 7 lt rgb "black" title 'M-out-of-N-Write, d = 16'  , \
'' using ($0-0.34):($2+35):2 with labels title ' ' font "arial, 10" textcolor lt 0 , \
'' using ($0-0.18):($3+35):3 with labels title ' ' font "arial, 10" textcolor lt 0	,\
'' using ($0-0.02):($4+35):4 with labels title ' ' font "arial, 10" textcolor lt 0		,\
'' using ($0+0.15):($5+35):5 with labels title ' ' font "arial, 10" textcolor lt 0	,\
'' using ($0+0.4):($6+35):6 with labels title ' ' font "arial, 10" textcolor lt 0