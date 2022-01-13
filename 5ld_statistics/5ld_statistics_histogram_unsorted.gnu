set terminal png
set output "statistics_histogram_unsorted.png"

set xlabel "simbols"
set ylabel "ASCII vērtība"
set title "Datu ASCII vērtību histogramma nesakārtotiem datiem"
set grid
set yrange [0:200]
set tics nomirror
set style data histograms
set style fill solid
set style histogram clustered gap 0

plot "statistics_unsorted.dat" using 2:xtic(1) linecolor 'red' title ""