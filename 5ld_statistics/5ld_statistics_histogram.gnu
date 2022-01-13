set terminal png
set output "statistics_histogram.png"

set xlabel "simbols"
set ylabel "ASCII vērtība"
set title "Datu ASCII vērtību histogramma sakārtotiem datiem"
set grid
set yrange [0:200]
set tics nomirror
set style data histograms
set style fill solid
set style histogram clustered gap 0

plot "statistics.dat" using 2:xtic(1) linecolor 'green' title ""