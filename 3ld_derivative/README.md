# 3.Laboratorijas darbs
Diskrētu viena argumenta funkcijas atvasinājumu aprēķins izmantojot analītisko un "finite difference" metodi.
## Galvenā daļa

### Kods [ld3_derivative.c](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/ld3_derivative.c)

Kods ir relatīvi vienkāršs. Viss notiek *main()* funkcijā. Kods ir būtībā while loop, kur notiek gan *printf* izvade uz ekrāna, gan *fprintf* izvade failā **derivative.dat**.

```#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    float a,b,x,delta_x;
    FILE *fp;

    printf("funkcija f(x) = cos(x/2)\n\n");
    printf("Saakuma intervaals (a)?\n");
    scanf("%f",&a);

    printf("Beigu intervaals (b)?\n");
    scanf("%f",&b);

    printf("delta_x veertiba?\n");
    scanf("%f",&delta_x);

    printf("        x  ||       cos(x/2)   ||   cos\'(x/2)      |   cos\'(x/2)     ||    cos\'\'(x/2)    |   cos\'\'(x/2)  \n"
           "           ||                  ||analytical formula|finite difference||analytical formula|finite difference\n"
           "    ========================================================================================================\n");
    x=a;

    fp = fopen("derivative.dat", "w");

    while(x<b){
        fprintf(fp,"%10.3f\t%10.3f\t%10.3f\t%10.3f\t%10.3f\t%10.3f\n",x,cos(x/2),-0.5*sin(x/2),(cos((x+delta_x)/2)-cos(x/2))/delta_x,-0.25*cos(x/2),(-0.5*sin((x+delta_x)/2)-(-0.5*sin(x/2)))/delta_x);
        printf("%10.3f\t%10.3f\t %10.3f\t    %10.3f\t       %10.3f\t    %10.3f\n",x,cos(x/2),-0.5*sin(x/2),(cos((x+delta_x)/2)-cos(x/2))/delta_x,-0.25*cos(x/2),(-0.5*sin((x+delta_x)/2)-(-0.5*sin(x/2)))/delta_x);
        x +=delta_x;
      
    }
    fclose(fp);

    return 0;
}
```

### Koda izvade
Tika izvēlētas robežas vērtības a=-15, b=15 un precizitātes, jeb *delta_x* vērtība 1 un 0.1, kur šajā izvadē redzams pie *delta_x*=1.
No lietotāja iegūtā *a* (intervāla sākuma) vērtība tiek pielīdzināta *x* un iterēta par *delta_x* vienībām, līdz beigu intevālam *b*.

Izvade ir noformēta ar "ASCII string art" uzskatāmībai.

Izvade zem rindas ar "=" ir arī izvade uz failu *derivative.dat*.

```funkcija f(x) = cos(x/2)

Saakuma intervaals (a)?
-15
Beigu intervaals (b)?
15
delta_x veertiba?
1
        x  ||       cos(x/2)   ||   cos'(x/2)      |   cos'(x/2)     ||    cos''(x/2)    |   cos''(x/2)  
           ||                  ||analytical formula|finite difference||analytical formula|finite difference
    ========================================================================================================
   -15.000           0.347            0.469              0.407             -0.087               -0.141
   -14.000           0.754            0.328              0.223             -0.188               -0.221
   -13.000           0.977            0.108             -0.016             -0.244               -0.247
   -12.000           0.960           -0.140             -0.252             -0.240               -0.213
   -11.000           0.709           -0.353             -0.425             -0.177               -0.127
   -10.000           0.284           -0.479             -0.494             -0.071               -0.009
    -9.000          -0.211           -0.489             -0.443              0.053                0.110
    -8.000          -0.654           -0.378             -0.283              0.163                0.203
    -7.000          -0.936           -0.175             -0.054              0.234                0.246
    -6.000          -0.990            0.071              0.189              0.247                0.229
    -5.000          -0.801            0.299              0.385              0.200                0.155
    -4.000          -0.416            0.455              0.487              0.104                0.044
    -3.000           0.071            0.499              0.470             -0.018               -0.078
    -2.000           0.540            0.421              0.337             -0.135               -0.181
    -1.000           0.878            0.240              0.122             -0.219               -0.240
     0.000           1.000           -0.000             -0.122             -0.250               -0.240
     1.000           0.878           -0.240             -0.337             -0.219               -0.181
     4.000          -0.416           -0.455             -0.385              0.104                0.155
     5.000          -0.801           -0.299             -0.189              0.200                0.229
     6.000          -0.990           -0.071              0.054              0.247                0.246
     7.000          -0.936            0.175              0.283              0.234                0.203
     8.000          -0.654            0.378              0.443              0.163                0.110
     9.000          -0.211            0.489              0.494              0.053               -0.009
    10.000           0.284            0.479              0.425             -0.071               -0.127
    11.000           0.709            0.353              0.252             -0.177               -0.213
    12.000           0.960            0.140              0.016             -0.240               -0.247
    13.000           0.977           -0.108             -0.223             -0.244               -0.221
    14.000           0.754           -0.328             -0.407             -0.188               -0.141
```


## Pielikums

Visu grafiku dati tiek ņemti no ld3_derivative.c koda izveidotiem datiem, kuri tika saglabāti failā *derivative.dat*.

### Visu funckiju grafiki pie delta_x=1 - [cosxdiv2_derivative_all_delta_1.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_derivative_all_delta_1.png)
![image](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_derivative_all_delta_1.png)

Pēc grafikiem redzams, ka ir novērojama nobīde starp 1. un 2.kārtas atvasinājumu grafikiem pie analītiskās un "finite diference" metodēm.

Var arī secināt, ka analītiskās metodes grafiki priekš 1. un 2.kārtas atvasinājumiem ir precīzāki nekā ar "finite difference" metode pie *delta_x*=1.

Šis šķiet loģiski, jo "finite difference" metode pēc būtības ir precīzāka, kad *delta_x* tiecas uz 0.


[cosxdiv2_1st_derivative_delta_1.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_1st_derivative_delta_1.png)
![image](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_1st_derivative_delta_1.png)

[cosxdiv2_2st_derivative_delta_1.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_2nd_derivative_delta_1.png)
![image](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_2nd_derivative_delta_1.png)

Šajos grafikos var sīkāk redzēt abu metožu precizitāti un atšķirības.

### Visu funckiju grafiki pie delta_x=0.1
[cosxdiv2_derivative_all_delta_01.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_derivative_all_delta_01.png)
![image](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_derivative_all_delta_01.png)

Salīdzinot ar pirmo visu grafiku bildi, šeit abu metožu grafiki jau sāk sakrist viens ar otru un attiecīgi paliek daudz precīzāki. 

Attiecīgi var secināt, ka "finite difference" metode ir objektīva pie mazām delta_x vērtībām (vismaz 0.1 un mazāk).

[cosxdiv2_1st_derivative_delta_01.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_1st_derivative_delta_01.png)
![image](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_1st_derivative_delta_01.png)

[cosxdiv2_2st_derivative_delta_01.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_2nd_derivative_delta_01.png)
![image](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_2nd_derivative_delta_01.png)



### Funkcijas grafika kods - [3ld_deriv_graph.gnu](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/3ld_deriv_graph.gnu)

Šis kods izvada visus vajadzīgos grafikus, jeb kods priekš grafika bildēm [cosxdiv2_derivative_all_delta_1.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_2nd_derivative_delta_1.png) un [cosxdiv2_derivative_all_delta_01.png](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/cosxdiv2_derivative_all_delta_01.png).

Pārējās bildes var iegūt vienkārši izdzēšot liekos grafikus no koda.

```set terminal png
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
```

### Atvasinājumu funkciju datu avota fails [derivative.dat](https://github.com/Lasiurus/RTR-105/blob/main/3ld_derivative/derivative.dat)

Šis konkrētais fails sastāv no datiem, pie koda ievades, kad *a*=-15, *b*=15 un *delta_x* = 1.
