set terminal png
set output "cosxdiv2_integral.png"

set arrow from 0,-1 to 0,1 lt 2 lw 2 lc rgb "black" nohead
set arrow from 8,-1 to 8,1 lt 2 lw 2 lc rgb "black" nohead

set xlabel "x"
set ylabel "y"
set title "f(x) = cos(x/2)"
set grid
set yrange [-1:1]
set tics nomirror

set xtics ( "-4π" -4*pi, "-3π" -3*pi,"-2π" -2*pi,"-π" (-1)*pi,"0" 0, "π" pi, "2π" 2*pi,"3π" 3*pi,"4π" 4*pi,)
plot cos(x/2),\
    [0:8] cos(x/2) notitle w filledc below,\
    [0:8] cos(x/2) notitle w filledc above