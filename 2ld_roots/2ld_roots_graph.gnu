set terminal png
set output "cosxdiv2_root.png"

set xlabel "x"
set ylabel "y"
set title "f(x) = cos(x/2)"
set grid
set tics nomirror
set xrange [6:10]
set yrange [-2:2]
set xtics ( "-4π" -4*pi, "-3π" -3*pi,"-2π" -2*pi,"-π" (-1)*pi,"0" 0, "π" pi, "2π" 2*pi,"3π" 3*pi,"4π" 4*pi,)
set object circle at first 9.42474,0 radius char 0.5 \
    fillstyle empty border lc rgb '#aa1100' lw 2

plot cos(x/2)
