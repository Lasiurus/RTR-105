set terminal png
set output "cosxdiv2_derivative.png"

set xlabel "x"
set ylabel "y"
set title "f(x) = cos(x/2)"
set grid
set yrange [-1:1]
set tics nomirror

set xtics ( "-4π" -4*pi, "-3π" -3*pi,"-2π" -2*pi,"-π" (-1)*pi,"0" 0, "π" pi, "2π" 2*pi,"3π" 3*pi,"4π" 4*pi,)
plot cos(x/2) ,\
    "derivative.dat" every ::1 using 1:3 with lines title "cos'(x/2) (analytical formula)" ,\
    "derivative.dat" every ::1 using 1:4 with lines title "cos'(x/2) (finite difference)" ,\
    "derivative.dat" every ::1 using 1:5 with lines title "cos''(x/2) (analytical formula)" ,\
    "derivative.dat" every ::1 using 1:6 with lines title "cos''(x/2) (finite difference)"
