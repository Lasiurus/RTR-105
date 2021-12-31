# 2.Laboratorijas darbs
Diskrētu viena argumenta funkcijas saknes vērtības (kad f(x)=0) aprēķins izmantojot dihotomijas metodi.

Šajā darbā dihotomijas metode tiek izmantota, lai noteiktu kādai funkcijai konkrētā apgabalā esošas saknes vērtību. Šī metode der tikai vienas saknes aprēķināšanai dotā apgabalā.

## Galvenā daļa
### Koda apraksts 
 **Dotā funkcija - *cos(x/2).**
Kods sastāv no *main()* funkcijas un lietotāja funkcijas *cos_sakne()*.  

```float cos_sakne(float,float,float);```- Aprēķina aptuvenu saknes vērtību ar dihotomijas, metodi, kur:
#### Ievade
- *a* : pētāmā apgabala kreisās robežas vērtība;
- *b* : pētāmā apgabala labās robežas vērtība;
- *delta_x* : funkcijas vērtības precizitāte, jeb cik reizes algoritms tiks izpildīts.

#### Izvade
- *c* ir funkcijas izvade, jeb tuvinātā saknes vērtība, kas katrā cikla solī tiek atjaunota, kā arvien mazāka pētāmā mēroga vidējais aritmētiskais.
 
```void main();```- Ievades formas priekš user input,ko izmanto funkcijas *cos_sakne()* izpildei šeit.



### Kods [ld2_roots.c](https://github.com/Lasiurus/RTR-105/blob/main/2ld_roots/ld2_roots.c)

```#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float cos_sakne(float,float,float);
void main(){
    float delta_x;
    float a,b,c;
    printf("funkcija f(x) = cos(x/2)\n\n");
    printf("Saakuma intervaals (a)?\n");
    scanf("%f",&a);

    printf("Beigu intervaals (b)?\n");
    scanf("%f",&b);

    printf("delta_x veertiba?\n");
    scanf("%f",&delta_x);

    cos_sakne(a,b,delta_x);

}

float cos_sakne(float a,float b,float delta_x){
    float c,f_a,f_b;
    int k=0; //while loop iterējamais
    
    f_a = cos(a/2);
    f_b = cos(b/2);

    if(f_a*f_b>0){
        printf("Interevalaa [%.2f;%.2f] cos(x/2) funkcijai saknju nav vai ir paara skaits\n\n",a,b);
        return 1;
    }

    printf("cos(a/2)=cos(%g)=%7.3f\t\t\t\t cos(b/2)=cos(%g)=%7.3f\n\n",a,cos(a/2),b,cos(b/2));
    printf("\niteraacija(k)\t\ta\t\tb\t\tc\t\tf(c)\n");
    while((b-a)>delta_x){
        k++;
        c=(a+b)/2;
        if(f_a*cos(c/2)>0){
            a=c;
            printf("\t%d\t\t%g\t\t%g\t\t%g\t\t%g\n",k,a,b,c,cos(c/2));
            }
        else{
            b=c;
            printf("\t%d\t\t%g\t\t%g\t\t%g\t\t%g\n",k,a,b,c,cos(c/2));
        }
    }
    printf("\n\nSakne atrodas pie x=%g, jo cos(x/2) ir %10f\n",c,cos(c/2));
    return c;
}
```
### Koda izvade
Algoritma rezultāts tiek sakārtots tabulas veidā. 
Tika izvēlētas robežas vērtības a=6 un b=10, jo šis ir apgabals, kurā atrodama tikai viena sakne, kas ir obligātais nosacījums, lai šī algoritma metode strādātu.
Iegūtā saknes (c) vērtība tiek ielikta standartfunkcijā, kur iegūtā ne nulles vērtība atspoguļo to, kāda precizitāte tika dota, jo ar šo metodi nav iespējams dabūt precīzu nulles vērtību.

```funkcija f(x) = cos(x/2)

Saakuma intervaals (a)?
6
Beigu intervaals (b)?
10
delta_x veertiba?
0.0001
cos(a/2)=cos(6)= -0.990                          cos(b/2)=cos(10)=  0.284


iteraacija(k)           a               b               c               f(c)
        1               8               10              8               -0.653644
        2               9               10              9               -0.210796
        3               9               9.5             9.5             0.0376022
        4               9.25            9.5             9.25            -0.0872778
        5               9.375           9.5             9.375           -0.0248864
        6               9.375           9.4375          9.4375          0.00636098
        7               9.40625         9.4375          9.40625         -0.00926385
        8               9.42188         9.4375          9.42188         -0.00145148
        9               9.42188         9.42969         9.42969         0.00245477
        10              9.42188         9.42578         9.42578         0.000501645
        11              9.42383         9.42578         9.42383         -0.000474918
        12              9.42383         9.4248          9.4248          1.33634e-005
        13              9.42432         9.4248          9.42432         -0.000230777
        14              9.42456         9.4248          9.42456         -0.000108707
        15              9.42468         9.4248          9.42468         -4.76718e-005
        16              9.42474         9.4248          9.42474         -1.71542e-005


Sakne atrodas pie x=9.42474, jo cos(x/2) ir  -0.000017
```


## Pielikums
### Funkcijas grafiks izmantojot gnuplot - [cosxdiv2_root.png](https://github.com/Lasiurus/RTR-105/blob/main/2ld_roots/cosxdiv2_root.png)
![image](https://github.com/Lasiurus/RTR-105/blob/main/2ld_roots/cosxdiv2_root.png)

### Funkcijas grafika kods - [2ld_roots_graph.gnu](https://github.com/Lasiurus/RTR-105/blob/main/2ld_roots/2ld_roots_graph.gnu)
```set terminal png
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
```
