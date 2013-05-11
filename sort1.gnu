set terminal jpeg

set output "bubble.jpg"

set title "Bubble sort vs. Quick sort"
set xlabel "no. of elements"
set ylabel "time in seconds"

set xrange [0:100000]
set yrange [0:100]
set xtics 10000
set ytics 10

plot  'bubbleData.txt' using 1:2 with lines title 'Bubble Sort' lw 3 ,'quickdata.txt' using 1:2 with lines title 'Quick Sort'  lw 3
