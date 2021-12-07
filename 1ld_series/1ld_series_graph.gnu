set terminal png
set output "cosxdiv2_teilor.png"

set xlabel "x"
set ylabel "y"
set title "f(x) = cos(x/2)"
set grid
set tics nomirror
set xrange [-15:15]
set yrange [-2:2]
set xtics ( "-4π" -4*pi, "-3π" -3*pi,"-2π" -2*pi,"-π" (-1)*pi,"0" 0, "π" pi, "2π" 2*pi,"3π" 3*pi,"4π" 4*pi,)

plot cos(x/2)
