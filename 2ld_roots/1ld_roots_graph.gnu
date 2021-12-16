set terminal png
set output "cosxdiv2_teilor.png"

set grid
plot [0:2*pi] sin(x)
replot [0:2*pi] cos(x) title "cos(x)"
replot "derivative.dat" every ::1 using 1:2 with lines title "cos'(x) (analytical formula)"
replot "derivative.dat" every ::1 using 1:3 with lines title "cos'(x) (finite difference)"
